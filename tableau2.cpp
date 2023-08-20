#include <iostream>
#include <windows.h>
using namespace std;

void menu() {
    cout << "Appuie sur X pour activer et desactiver\n";
}

int main() {
    menu();

    bool click = false;

    while (true) {
        if (GetAsyncKeyState('X') & 0x8000) {
            click = !click; // Toggle the click state
            Sleep(200);     // Sleep to avoid rapid toggling due to key repetition
        }

        if (click) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(10);
        }
    }

    return 0;
}