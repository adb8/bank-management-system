#include "globals.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void deposit() {
    int amount;
    system("cls");
    printf("BANK MANAGEMENT SYSTEM: DEPOSIT\n");

    printf("ENTER AMOUNT TO DEPOSIT IN DOLLARS: ");
    int result = scanf("%d", &amount);
    while (result != 1 || amount < 0) {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        while (getchar() != '\n')
            ;
        result = scanf("%d", &amount);
    }
    account.balance += amount;

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
            balance = account.balance;
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

    printf("DEPOSIT SUCCESSFUL. NEW BALANCE: %d\n", account.balance);
    Sleep(2000);
    system("cls");
    return;
}