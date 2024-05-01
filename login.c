#include "globals.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void login() {
    char accountNumber[51];
    char password[100];
    int c;
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: LOGIN\n");
    printf("Enter your account number: ");
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    fgets(accountNumber, sizeof(accountNumber), stdin);
    while (accountNumber[0] == '\n' || accountNumber[0] == ' ') {
        printf("Invalid account number. Please try again: ");
        fgets(accountNumber, sizeof(accountNumber), stdin);
    }
    if (accountNumber[strlen(accountNumber) - 1] == '\n') {
        accountNumber[strlen(accountNumber) - 1] = '\0';
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: LOGIN\n");
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    while (password[0] == '\n' || password[0] == ' ') {
        printf("Invalid password. Please try again: ");
        fgets(password, sizeof(password), stdin);
    }
    if (password[strlen(password) - 1] == '\n') {
        password[strlen(password) - 1] = '\0';
    }
    system("cls");

    FILE *file = fopen("accounts.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        for (int i = 0; i < 9; i++) {
            token = strtok(NULL, ",");
        }
        for (int i = strlen(token) - 1; i >= 0; i--) {
            if (token[i] == '\n') {
                token[i] = '\0';
            }
        }
        if (token != NULL && strcmp(token, accountNumber) == 0) {
            token = strtok(NULL, ",");
            for (int i = strlen(token) - 1; i >= 0; i--) {
                if (token[i] == '\n') {
                    token[i] = '\0';
                }
            }
            if (strcmp(token, password) == 0) {
                isLoggedIn = true;
                getAccountInfo(accountNumber);
                printf("BANK MANAGEMENT SYSTEM: LOGIN\n");
                printf("Login successful\n");
                // printf("Name: %s\n", account.holder.name);
                // printf("Gender: %s\n", account.holder.gender);
                // printf("Address: %s\n", account.holder.address);
                // printf("Email: %s\n", account.holder.email);
                // printf("Account type: %s\n", account.type);
                // printf("Race: %s\n", account.holder.race);
                // printf("Phone number: %s\n", account.holder.phoneNumber);
                // printf("Age: %d\n", account.holder.age);
                // printf("Balance: %d\n", account.balance);
                // printf("Account number: %s\n", account.number);
                Sleep(2000);
                system("cls");
                break;
            }
        }
    }
    fclose(file);
    if (!isLoggedIn) {
        printf("BANK MANAGEMENT SYSTEM: LOGIN\n");
        printf("Login cancelled: Invalid credentials\n");
        Sleep(2000);
        system("cls");
    }
    return;
}

void getAccountInfo(char accountNumber[50]) {
    FILE *file = fopen("accounts.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        if (token != NULL && strcmp(token, accountNumber)) {
            strcpy(account.holder.name, token);
            token = strtok(NULL, ",");
            strcpy(account.holder.gender, token);
            token = strtok(NULL, ",");
            strcpy(account.holder.address, token);
            token = strtok(NULL, ",");
            strcpy(account.holder.email, token);
            token = strtok(NULL, ",");
            strcpy(account.type, token);
            token = strtok(NULL, ",");
            strcpy(account.holder.race, token);
            token = strtok(NULL, ",");
            strcpy(account.holder.phoneNumber, token);
            token = strtok(NULL, ",");
            account.holder.age = atoi(token);
            token = strtok(NULL, ",");
            account.balance = atoi(token);
            token = strtok(NULL, ",");
            strcpy(account.number, token);
            break;
        }
    }
    fclose(file);
    return;
}