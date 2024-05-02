#include "globals.h"
#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void transfer() {
    int result;
    char c;
    char lines[1000][1000];
    int lineCount = 0;
    char name[100];
    char gender[100];
    char address[100];
    char email[100];
    char accountType[100];
    char race[100];
    char phoneNumber[100];
    char password[100];
    int age;
    int balance;
    char accountNumber[50];
    int amount;
    char transferTo[51];

    system("cls");
    printf("BANK MANAGEMENT SYSTEM: TRANSFER\n");
    printf("ENTER AMOUNT TO TRANSFER: ");
    result = scanf("%d", &amount);
    while (result != 1 || amount < 0) {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        while (getchar() != '\n')
            ;
        result = scanf("%d", &amount);
    }

    printf("ENTER ACCOUNT NUMBER TO TRANSFER TO: ");
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    fgets(transferTo, sizeof(transferTo), stdin);
    while (transferTo[0] == '\n' || transferTo[0] == ' ') {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        fgets(transferTo, sizeof(transferTo), stdin);
    }
    if (transferTo[strlen(transferTo) - 1] == '\n') {
        transferTo[strlen(transferTo) - 1] = '\0';
    }

    FILE *file = fopen("accounts.csv", "r");
    if (file == NULL) {
        printf("ERROR OPENING FILE. EXITING PROGRAM...\n");
        exit(1);
    }

    bool foundTransferTo = false;
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%[^,],%[^,\n]\n", name, gender, address, email, accountType, race, phoneNumber, &age, &balance, accountNumber, password) != EOF) {
        if (strcmp(accountNumber, account.number) == 0) {
            if (balance < amount) {
                system("cls");
                printf("BANK MANAGEMENT SYSTEM: TRANSFER\n");
                printf("INSUFFICIENT BALANCE. TRANSFER FAILED\n");
                printf("PRESS ANY KEY TO CONTINUE...");
                _getch();
                system("cls");
                return;
            }
            balance -= amount;
        }
        if (strcmp(accountNumber, transferTo) == 0) {
            balance += amount;
            foundTransferTo = true;
        }
        sprintf(lines[lineCount], "%s,%s,%s,%s,%s,%s,%s,%d,%d,%s,%s\n", name, gender, address, email, accountType, race, phoneNumber, age, balance, accountNumber, password);
        lineCount++;
    }
    fclose(file);

    if (!foundTransferTo) {
        system("cls");
        printf("BANK MANAGEMENT SYSTEM: TRANSFER\n");
        printf("ACCOUNT NUMBER TO TRANSFER TO NOT FOUND. TRANSFER FAILED\n");
        printf("PRESS ANY KEY TO CONTINUE...");
        _getch();
        system("cls");
        return;
    }

    account.balance -= amount;
    file = fopen("accounts.csv", "w");
    if (file == NULL) {
        printf("ERROR OPENING FILE. EXITING PROGRAM...\n");
        exit(1);
    }
    for (int i = 0; i < lineCount; i++) {
        fprintf(file, "%s", lines[i]);
    }
    fclose(file);

    system("cls");
    printf("BANK MANAGEMENT SYSTEM: TRANSFER\n");
    printf("TRANSFER SUCCESSFUL. NEW BALANCE: %d\n", balance);
    printf("PRESS ANY KEY TO CONTINUE...");
    _getch();
    system("cls");
    return;
}