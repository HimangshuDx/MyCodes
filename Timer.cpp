#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
using namespace std;

void timer(int seconds) 
{
    for (int i = seconds; i >= 0; --i) {
        cout << "Time left: " << i << " seconds\r" << flush;
        Sleep(1000);
    }
    cout << "\n\nTimer finished!\n";
}

int main() {
    int seconds;
    cout << "\n\nEnter the number of seconds for the timer: ";
    cin >> seconds;

    cout << "Starting timer...\n\n1";
    timer(seconds);

    return 0;
}