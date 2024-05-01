#include "globals.h"
#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void createAccount() {
    int c, choice, result;
    int index = 0;
    char ch;
    int age;
    int balance;
    char accountNumber[50];
    char name[100];
    char gender[100];
    char address[100];
    char email[100];
    char password[100];
    char accountType[100];
    char race[100];
    char phoneNumber[100];

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("ENTER YOUR NAME: ");
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    fgets(name, sizeof(name), stdin);
    while (name[0] == '\n' || name[0] == ' ') {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        fgets(name, sizeof(name), stdin);
    }
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("ENTER YOUR AGE: ");
    result = scanf("%d", &age);
    while (result != 1 || age < 0 || age > 120) {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        while (getchar() != '\n')
            ;
        result = scanf("%d", &age);
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("ENTER YOUR GENDER:\n");
    printf("1. MALE\n");
    printf("2. FEMALE\n");
    printf("3. OTHER\n");
    printf("ENTER YOUR CHOICE: ");
    result = scanf("%d", &choice);
    while (result != 1 || choice < 1 || choice > 3) {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        while (getchar() != '\n')
            ;
        result = scanf("%d", &choice);
    }
    switch (choice) {
    case 1:
        strcpy(gender, "Male");
        break;
    case 2:
        strcpy(gender, "Female");
        break;
    case 3:
        strcpy(gender, "Other");
        break;
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("ENTER YOUR ADDRESS: ");
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    fgets(address, sizeof(address), stdin);
    while (address[0] == '\n' || address[0] == ' ') {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        fgets(address, sizeof(address), stdin);
    }
    if (address[strlen(address) - 1] == '\n') {
        address[strlen(address) - 1] = '\0';
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("ENTER YOUR EMAIL: ");
    fgets(email, sizeof(email), stdin);
    while (email[0] == '\n' || email[0] == ' ') {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        fgets(email, sizeof(email), stdin);
    }
    if (email[strlen(email) - 1] == '\n') {
        email[strlen(email) - 1] = '\0';
    }
    system("cls");

    // printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    // printf("CREATE A PASSWORD: ");
    // fgets(password, sizeof(password), stdin);
    // while (password[0] == '\n' || password[0] == ' ') {
    //     printf("INVALID INPUT. PLEASE TRY AGAIN: ");
    //     fgets(password, sizeof(password), stdin);
    // }
    // if (password[strlen(password) - 1] == '\n') {
    //     password[strlen(password) - 1] = '\0';
    // }
    // system("cls");

    printf("CREATE YOUR PASSWORD: ");
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
    while (password[0] == '\n' || password[0] == ' ' || password[0] == '\0') {
        printf("\nINVALID INPUT. PLEASE TRY AGAIN: ");
        index = 0;
        for (int i = 0; i < sizeof(password); i++) {
            password[i] = '\0';
        }
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
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("ENTER YOUR ACCOUNT TYPE:\n");
    printf("1. SAVINGS\n");
    printf("2. CHECKINGS\n");
    printf("ENTER YOUR CHOICE: ");
    result = scanf("%d", &choice);
    while (result != 1 || choice < 1 || choice > 2) {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        while (getchar() != '\n')
            ;
        result = scanf("%d", &choice);
    }
    switch (choice) {
    case 1:
        strcpy(accountType, "Savings");
        break;
    case 2:
        strcpy(accountType, "Checkings");
        break;
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("ENTER YOUR PHONE NUMBER: ");
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    fgets(phoneNumber, sizeof(phoneNumber), stdin);
    while (phoneNumber[0] == '\n' || phoneNumber[0] == ' ') {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        fgets(phoneNumber, sizeof(phoneNumber), stdin);
    }
    if (phoneNumber[strlen(phoneNumber) - 1] == '\n') {
        phoneNumber[strlen(phoneNumber) - 1] = '\0';
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("ENTER YOUR RACE:\n");
    printf("1. WHITE\n");
    printf("2. BLACK\n");
    printf("3. ASIAN\n");
    printf("4. HISPANIC\n");
    printf("5. OTHER\n");
    printf("ENTER YOUR CHOICE: ");
    result = scanf("%d", &choice);
    while (result != 1 || choice < 1 || choice > 5) {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        while (getchar() != '\n')
            ;
        result = scanf("%d", &choice);
    }
    switch (choice) {
    case 1:
        strcpy(race, "White");
        break;
    case 2:
        strcpy(race, "Black");
        break;
    case 3:
        strcpy(race, "Asian");
        break;
    case 4:
        strcpy(race, "Hispanic");
        break;
    case 5:
        strcpy(race, "Other");
        break;
    }
    system("cls");

    srand(time(NULL));
    for (int i = 0; i < sizeof(accountNumber) - 1; i++) {
        accountNumber[i] = '0' + rand() % 10;
    }
    accountNumber[sizeof(accountNumber) - 1] = '\0';
    balance = 0;

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("PLEASE CONFIRM THE FOLLOWING INFORMATION:\n");
    printf("NAME: %s\n", name);
    printf("GENDER: %s\n", gender);
    printf("ADDRESS: %s\n", address);
    printf("EMAIL: %s\n", email);
    char asterisks[strlen(password) + 1];
    for (int i = 0; i < strlen(password); i++) {
        asterisks[i] = '*';
    }
    asterisks[strlen(password)] = '\0';
    printf("PASSWORD: %s\n", asterisks);
    printf("ACCOUNT TYPE: %s\n", accountType);
    printf("PHONE NUMBER: %s\n", phoneNumber);
    printf("AGE: %d\n", age);
    printf("ACCOUNT NUMBER: %s\n", accountNumber);
    printf("BALANCE: %d\n\n", balance);
    printf("IS THIS INFORMATION CORRECT?\n");
    printf("1. YES\n");
    printf("2. NO\n");
    printf("ENTER YOUR CHOICE: ");
    result = scanf("%d", &choice);
    while (result != 1 || choice < 1 || choice > 2) {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        while (getchar() != '\n')
            ;
        result = scanf("%d", &choice);
    }
    if (choice == 2) {
        system("cls");
        isLoggedIn = false;
        printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
        printf("ACCOUNT CREATION CANCELLED. PRESS ANY KEY TO CONTINUE...\n");
        _getch();
        system("cls");
        return;
    }

    FILE *file = fopen("accounts.csv", "a");
    if (file == NULL) {
        printf("ERROR OPENING FILE: EXITING PROGRAM...\n");
        return;
    }
    fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%d,%d,%s,%s\n", name, gender, address, email, accountType, race, phoneNumber, age, balance, accountNumber, password);
    fclose(file);

    isLoggedIn = true;
    strcpy(account.holder.name, name);
    strcpy(account.holder.gender, gender);
    strcpy(account.holder.address, address);
    strcpy(account.holder.email, email);
    strcpy(account.password, password);
    strcpy(account.type, accountType);
    strcpy(account.holder.race, race);
    strcpy(account.holder.phoneNumber, phoneNumber);
    account.holder.age = age;
    account.balance = balance;
    strcpy(account.number, accountNumber);

    system("cls");
    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("ACCOUNT CREATED SUCCESSFULLY. PRESS ANY KEY TO CONTINUE...\n");
    _getch();
    system("cls");
    return;
}