#include "globals.h"
#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void login() {
    char accountNumber[51];
    char password[100];
    int c;
    int index = 0;
    char ch;
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: LOGIN\n");
    printf("ENTER YOUR ACCOUNT NUMBER: ");
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    fgets(accountNumber, sizeof(accountNumber), stdin);
    while (accountNumber[0] == '\n' || accountNumber[0] == ' ') {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        fgets(accountNumber, sizeof(accountNumber), stdin);
    }
    if (accountNumber[strlen(accountNumber) - 1] == '\n') {
        accountNumber[strlen(accountNumber) - 1] = '\0';
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: LOGIN\n");
    printf("ENTER YOUR PASSWORD: ");
    while (1) {
        ch = getch();
        if (ch == '\r' || ch == '\n') {
            password[index] = '\0';
            break;
        } else if (ch == '\b') {
            if (index > 0) {
                index--;
                printf("\b \b");
            }
        } else {
            password[index] = ch;
            index++;
            printf("*");
        }
    }
    system("cls");

    FILE *file = fopen("accounts.csv", "r");
    if (file == NULL) {
        printf("ERROR OPENING FILE. EXITING PROGRAM...\n");
        exit(1);
    }

    char line[1000];
    char *tokens[20];
    int tokenCount;
    while (fgets(line, sizeof(line), file)) {
        tokenCount = 0;
        char *token = strtok(line, ",");
        while (token != NULL) {
            for (int i = strlen(token) - 1; i >= 0; i--) {
                if (token[i] == '\n') {
                    token[i] = '\0';
                }
            }
            tokens[tokenCount] = token;
            tokenCount++;
            token = strtok(NULL, ",");
        }
        if (tokens[9] != NULL && strcmp(tokens[9], accountNumber) == 0) {
            if (strcmp(tokens[10], password) == 0) {
                isLoggedIn = true;
                getAccountInfo(tokens);
                printf("BANK MANAGEMENT SYSTEM: LOGIN\n");
                printf("LOGIN SUCCESSFUL. PRESS ANY KEY TO CONTINUE...\n");
                // printf("NAME: %s\n", account.holder.name);
                // printf("GENDER: %s\n", account.holder.gender);
                // printf("ADDRESS: %s\n", account.holder.address);
                // printf("EMAIL: %s\n", account.holder.email);
                // printf("ACCOUNT TYPE: %s\n", account.type);
                // printf("RACE: %s\n", account.holder.race);
                // printf("PHONE NUMBER: %s\n", account.holder.phoneNumber);
                // printf("AGE: %d\n", account.holder.age);
                // printf("BALANCE: %d\n", account.balance);
                // printf("ACCOUNT NUMBER: %s\n", account.number);
                _getch();
                system("cls");
                break;
            }
        }
    }
    fclose(file);
    if (!isLoggedIn) {
        printf("BANK MANAGEMENT SYSTEM: LOGIN\n");
        printf("LOGIN CANCELLED. PRESS ANY KEY TO CONTINUE...\n");
        _getch();
        system("cls");
        return;
    }
    return;
}

void getAccountInfo(char *tokens[20]) {
    strcpy(account.holder.name, tokens[0]);
    strcpy(account.holder.gender, tokens[1]);
    strcpy(account.holder.address, tokens[2]);
    strcpy(account.holder.email, tokens[3]);
    strcpy(account.type, tokens[4]);
    strcpy(account.holder.race, tokens[5]);
    strcpy(account.holder.phoneNumber, tokens[6]);
    account.holder.age = atoi(tokens[7]);
    account.balance = atoi(tokens[8]);
    strcpy(account.number, tokens[9]);
    strcpy(account.password, tokens[10]);
    return;
}