/*
    C++ CAR SIMULATION GAME
    -----------------------
    A console-only car simulation game (no graphics library required).
    Works on Windows, Linux, and Mac. Compile with g++ and run in a terminal.

    Modes:
      1) Free Drive Simulation - realistic dashboard: gears, RPM, throttle, fuel, stalling.
      2) Highway Dodge Race     - arcade lane-dodging game with increasing speed.

    Controls are shown on-screen in each mode.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <cctype>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

// ------------------------------------------------------------------
// Cross-platform non-blocking keyboard input
// ------------------------------------------------------------------
#ifndef _WIN32
int kbhitUnix() {
    termios oldt{}, newt{};
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

char getchUnix() {
    termios oldt{}, newt{};
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = static_cast<char>(getchar());
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

bool keyPressed() {
#ifdef _WIN32
    return _kbhit() != 0;
#else
    return kbhitUnix() != 0;
#endif
}

char readKey() {
#ifdef _WIN32
    return _getch();
#else
    return getchUnix();
#endif
}

void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void sleepMs(int ms) {
#ifdef _WIN32
    Sleep(static_cast<DWORD>(ms));
#else
    usleep(ms * 1000);
#endif
}

void waitForEnter() {
    std::cout << "\nPress Enter to return to the menu...";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// ------------------------------------------------------------------
// Helper: draw an ASCII progress bar
// ------------------------------------------------------------------
std::string bar(double value, double maxValue, int width, char fill = '#') {
    if (value < 0) value = 0;
    if (value > maxValue) value = maxValue;
    int filled = static_cast<int>((value / maxValue) * width);
    std::string s = "[";
    for (int i = 0; i < width; i++) s += (i < filled ? fill : ' ');
    s += "]";
    return s;
}

// ====================================================================
// MODE 1: FREE DRIVE SIMULATION
// ====================================================================
struct Car {
    int gear = 0;          // 0 = Neutral, 1-6 = gears
    double rpm = 800.0;
    double speed = 0.0;    // km/h
    double throttle = 0.0; // 0-100
    double fuel = 45.0;    // liters
    double distance = 0.0; // km
    bool stalled = false;
};

const double GEAR_RATIOS[7] = {0.0, 3.8, 2.5, 1.8, 1.3, 1.0, 0.8};

void updateCar(Car &car, double dt) {
    double ratio = (car.gear >= 1 && car.gear <= 6) ? GEAR_RATIOS[car.gear] : 0.0;
    const double enginePower = 90.0;

    double accel;
    if (car.gear >= 1) {
        double drive = (car.throttle / 100.0) * enginePower * ratio;
        double drag = 0.02 * car.speed * car.speed / 100.0;
        double rolling = 0.5;
        accel = drive - drag - rolling;
    } else {
        double drag = 0.02 * car.speed * car.speed / 100.0;
        accel = -drag - 1.0; // coasting down in neutral
    }

    car.speed += accel * dt;
    if (car.speed < 0) car.speed = 0;

    // RPM behavior
    if (car.gear == 0) {
        car.rpm = 800 + car.throttle * 40; // revs freely in neutral
    } else {
        car.rpm = 800 + (car.speed * GEAR_RATIOS[car.gear] * 60);
    }
    if (car.rpm > 7500) car.rpm = 7500;
    if (car.rpm < 0) car.rpm = 0;

    // Stall check: in gear, too slow, low revs, no throttle
    if (car.gear >= 1 && car.speed < 3.0 && car.rpm < 1000.0 && car.throttle < 10.0) {
        car.stalled = true;
    }

    // Fuel consumption
    double consumption = 0.0008 * (car.throttle + 10.0) * dt * (1.0 + car.rpm / 7000.0);
    car.fuel -= consumption;
    if (car.fuel < 0) car.fuel = 0;

    // Distance (speed is km/h, dt is seconds)
    car.distance += car.speed * (dt / 3600.0);
}

void handleDriveInput(Car &car, bool &running) {
    while (keyPressed()) {
        char c = static_cast<char>(std::tolower(readKey()));
        if (c == 'w') {
            car.throttle += 20;
            if (car.throttle > 100) car.throttle = 100;
        } else if (c == 's') {
            car.throttle -= 30;
            if (car.throttle < 0) car.throttle = 0;
        } else if (c == 'a') {
            if (car.gear > 0) car.gear--;
        } else if (c == 'd') {
            if (car.gear < 6) car.gear++;
        } else if (c == 'r') {
            car.stalled = false;
            car.rpm = 800;
            car.gear = 0;
        } else if (c == 'q') {
            running = false;
        }
    }
}

void renderDrive(const Car &car, double tripGoal) {
    clearScreen();
    std::cout << "=========== CAR SIMULATION: FREE DRIVE ===========\n\n";
    std::cout << "Gear     : " << (car.gear == 0 ? "N" : std::to_string(car.gear)) << "\n";
    std::cout << "Speed    : " << bar(car.speed, 200, 30) << " " << static_cast<int>(car.speed) << " km/h\n";
    std::cout << "RPM      : " << bar(car.rpm, 7500, 30) << " " << static_cast<int>(car.rpm) << " rpm"
               << (car.rpm > 7000 ? "  !! REDLINE !!" : "") << "\n";
    std::cout << "Throttle : " << bar(car.throttle, 100, 30) << " " << static_cast<int>(car.throttle) << "%\n";
    std::cout << "Fuel     : " << bar(car.fuel, 45, 30) << " " << std::fixed << std::setprecision(1) << car.fuel << " L\n";
    std::cout << "Distance : " << bar(car.distance, tripGoal, 30) << " " << std::fixed << std::setprecision(2)
               << car.distance << " / " << tripGoal << " km\n";

    if (car.stalled) {
        std::cout << "\n*** ENGINE STALLED! Shift to Neutral and press R to restart. ***\n";
    }

    std::cout << "\nControls: [W] Gas  [S] Brake  [A] Shift Down  [D] Shift Up  [R] Restart Engine  [Q] Quit to Menu\n";
}

void driveSimulation() {
    Car car;
    const double tripGoal = 30.0; // km
    bool running = true;

    while (running) {
        handleDriveInput(car, running);
        if (!running) break;

        car.throttle *= 0.88; // simulate pedal easing off unless refreshed by key presses

        if (!car.stalled) {
            updateCar(car, 0.2);
        } else {
            car.throttle = 0;
            car.rpm = 0;
            car.speed *= 0.9;
        }

        renderDrive(car, tripGoal);

        if (car.fuel <= 0) {
            std::cout << "\nYou ran out of fuel after " << std::fixed << std::setprecision(2)
                       << car.distance << " km. Game Over.\n";
            break;
        }
        if (car.distance >= tripGoal) {
            std::cout << "\nTrip complete! You covered " << tripGoal << " km with "
                       << std::fixed << std::setprecision(1) << car.fuel << " L of fuel remaining.\n";
            break;
        }

        sleepMs(200);
    }

    waitForEnter();
}

// ====================================================================
// MODE 2: HIGHWAY DODGE RACE
// ====================================================================
struct Obstacle {
    int lane;
    double row;
};

void renderRace(int playerLane, const std::vector<Obstacle> &obstacles, double score, double speedKmh, int height) {
    clearScreen();
    std::cout << "=========== HIGHWAY DODGE RACE ===========\n";
    std::cout << "Score: " << static_cast<int>(score) << " m     Speed: " << static_cast<int>(speedKmh) << " km/h\n\n";

    const std::string laneTemplate = "|   |   |   |";
    std::vector<std::string> grid(height, laneTemplate);

    for (const auto &o : obstacles) {
        int r = static_cast<int>(o.row);
        if (r >= 0 && r < height) {
            int pos = 2 + o.lane * 4;
            if (pos < static_cast<int>(grid[r].size())) grid[r][pos] = 'X';
        }
    }

    for (int i = 0; i < height; i++) std::cout << grid[i] << "\n";

    std::string playerRow = laneTemplate;
    int pos = 2 + playerLane * 4;
    playerRow[pos] = 'C';
    std::cout << playerRow << "  <-- YOU\n";

    std::cout << "\nControls: [A] Move Left  [D] Move Right  [Q] Quit\n";
}

void highwayDodge() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int playerLane = 1;
    std::vector<Obstacle> obstacles;
    double score = 0.0;
    double speedKmh = 40.0;
    const int height = 12;
    bool running = true;
    bool crashed = false;
    int spawnCounter = 0;
    const int baseTickMs = 150;

    while (running) {
        while (keyPressed()) {
            char c = static_cast<char>(std::tolower(readKey()));
            if (c == 'a') { if (playerLane > 0) playerLane--; }
            else if (c == 'd') { if (playerLane < 2) playerLane++; }
            else if (c == 'q') running = false;
        }
        if (!running) break;

        speedKmh += 0.05; // gradual difficulty increase
        double moveStep = 0.3 + speedKmh / 150.0;

        for (auto &o : obstacles) o.row += moveStep;

        // Collision check: obstacle reaching the player's row in the player's lane
        for (const auto &o : obstacles) {
            if (o.row >= height - 1.0 && o.row < height + 1.0 && o.lane == playerLane) {
                crashed = true;
                running = false;
            }
        }

        // Remove obstacles that have passed off-screen
        obstacles.erase(
            std::remove_if(obstacles.begin(), obstacles.end(),
                            [height](const Obstacle &o) { return o.row > height + 1; }),
            obstacles.end());

        // Spawn new obstacles, faster as speed increases
        spawnCounter++;
        int spawnEvery = std::max(3, 12 - static_cast<int>(speedKmh / 20));
        if (spawnCounter >= spawnEvery) {
            spawnCounter = 0;
            if (std::rand() % 100 < 70) {
                Obstacle o;
                o.lane = std::rand() % 3;
                o.row = 0;
                obstacles.push_back(o);
            }
        }

        score += moveStep * 2;

        if (running) {
            renderRace(playerLane, obstacles, score, speedKmh, height);
            int dynamicTick = std::max(60, baseTickMs - static_cast<int>(speedKmh));
            sleepMs(dynamicTick);
        }
    }

    if (crashed) {
        std::cout << "\n*** CRASH! Game Over. Final Score: " << static_cast<int>(score) << " m ***\n";
    } else {
        std::cout << "\nYou quit the race. Final Score: " << static_cast<int>(score) << " m\n";
    }

    waitForEnter();
}

// ====================================================================
// MAIN MENU
// ====================================================================
int main() {
    while (true) {
        clearScreen();
        std::cout << "======================================\n";
        std::cout << "        C++ CAR SIMULATION GAME       \n";
        std::cout << "======================================\n\n";
        std::cout << "1. Free Drive Simulation (realistic dashboard)\n";
        std::cout << "2. Highway Dodge Race (arcade)\n";
        std::cout << "3. Exit\n\n";
        std::cout << "Choose an option: ";

        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") driveSimulation();
        else if (choice == "2") highwayDodge();
        else if (choice == "3") break;
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}