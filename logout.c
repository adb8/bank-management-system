#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include "globals.h"

void logout() {
    isLoggedIn = false;
    system("cls");

    account.holder.name[0] = '\0';
    account.holder.gender[0] = '\0';
    account.holder.age = 0;
    account.holder.address[0] = '\0';
    account.holder.email[0] = '\0';
    account.type[0] = '\0';
    account.holder.race[0] = '\0';
    account.holder.phoneNumber[0] = '\0';
    account.balance = 0;
    account.number[0] = '\0';
    account.password[0] = '\0';

    printf("BANK MANAGEMENT SYSTEM: LOGOUT\n");
    printf("LOGGED OUT SUCCESSFULLY\n");
    printf("PRESS ANY KEY TO CONTINUE...");
    _getch();
    system("cls");
    return;
}