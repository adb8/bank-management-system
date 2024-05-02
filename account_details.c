#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "globals.h"

void account_details() {
    printf("BANK MANAGEMENT SYSTEM: ACCOUNT DETAILS\n");
    printf("NAME: %s\n", account.holder.name);
    printf("AGE: %d\n", account.holder.age);
    printf("GENDER: %s\n", account.holder.gender);
    printf("ADDRESS: %s\n", account.holder.address);
    printf("EMAIL: %s\n", account.holder.email);
    printf("RACE: %s\n", account.holder.race);
    printf("PHONE NUMBER: %s\n", account.holder.phoneNumber);
    printf("ACCOUNT TYPE: %s\n", account.type);
    printf("BALANCE: %d\n", account.balance);
    printf("ACCOUNT NUMBER: %s\n", account.number);
    printf("PRESS ANY KEY TO CONTINUE...");
    _getch();
    system("cls");
    return;
}