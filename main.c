#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "globals.h"
#include <windows.h>

bool isLoggedIn = false;
bool isRunning = true;
struct Account account;

int main() {
    srand(time(NULL));
    while (isRunning) {
        menu();
    }
    return 0;
}