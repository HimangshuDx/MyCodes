#include <iostream>
#include <chrono>
#include <thread>

void timer(int seconds) {
    for (int i = seconds; i >= 0; --i) {
        std::cout << "Time left: " << i << " seconds\r" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "\nTimer finished!\n";
}

int main() {
    int seconds;
    std::cout << "Enter the number of seconds for the timer: ";
    std::cin >> seconds;

    std::cout << "Starting timer...\n";
    timer(seconds);

    return 0;
}