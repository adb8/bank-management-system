#include "globals.h"
#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void delete_account() {
    FILE *file = fopen("accounts.csv", "r");
    if (file == NULL) {
        printf("ERROR OPENING FILE. EXITING PROGRAM...\n");
        exit(1);
    }

    char lines[1000][1000];
    int lineCount = 0;
    char name[100], gender[100], address[100], email[100], accountType[100], race[100], phoneNumber[100], password[100];
    int age, balance;
    char accountNumber[50];

    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%[^,],%[^,\n]\n", name, gender, address, email, accountType, race, phoneNumber, &age, &balance, accountNumber, password) != EOF) {
        if (strcmp(accountNumber, account.number) == 0) {
            continue;
        }
        sprintf(lines[lineCount], "%s,%s,%s,%s,%s,%s,%s,%d,%d,%s,%s\n", name, gender, address, email, accountType, race, phoneNumber, age, balance, accountNumber, password);
        lineCount++;
    }
    fclose(file);

    file = fopen("accounts.csv", "w");
    if (file == NULL) {
        printf("ERROR OPENING FILE. EXITING PROGRAM...\n");
        exit(1);
    }
    for (int i = 0; i < lineCount; i++) {
        fprintf(file, "%s", lines[i]);
    }
    fclose(file);
    
    isLoggedIn = false;
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

    system("cls");
    printf("BANK MANAGEMENT SYSTEM: ACCOUNT DELETION\n");
    printf("ACCOUNT DELETION SUCCESSFUL\n");
    printf("PRESS ANY KEY TO CONTINUE...");
    _getch();
    system("cls");
    return;
}