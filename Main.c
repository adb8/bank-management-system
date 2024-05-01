#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "globals.h"
#include <windows.h>

void seeAccountDetails() {
    printf("To be implemented\n");
    Sleep(2000);
}
void editAccount() {
    printf("To be implemented\n");
    Sleep(2000);
}
void deposit() {
    printf("To be implemented\n");
    Sleep(2000);
}
void withdraw() {
    printf("To be implemented\n");
    Sleep(2000);
}
void transfer() {
    printf("To be implemented\n");
    Sleep(2000);
}
void deleteAccount() {
    printf("To be implemented\n");
    Sleep(2000);
}
void logout() {
    printf("To be implemented\n");
    Sleep(2000);
}

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