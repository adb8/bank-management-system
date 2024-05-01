#include "globals.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void createAccount() {
    int c, choice, result;
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
    printf("Enter your name: ");
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    fgets(name, sizeof(name), stdin);
    while (name[0] == '\n' || name[0] == ' ') {
        printf("Invalid name. Please try again: ");
        fgets(name, sizeof(name), stdin);
    }
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("Enter your age: ");
    result = scanf("%d", &age);
    while (result != 1 || age < 0 || age > 120) {
        printf("Invalid age. Please try again: ");
        while (getchar() != '\n')
            ;
        result = scanf("%d", &age);
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("Enter your gender:\n");
    printf("1. Male\n");
    printf("2. Female\n");
    printf("3. Other\n");
    printf("Enter your choice: ");
    result = scanf("%d", &choice);
    while (result != 1 || choice < 1 || choice > 3) {
        printf("Invalid choice. Please try again: ");
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
    printf("Enter your address: ");
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    fgets(address, sizeof(address), stdin);
    while (address[0] == '\n' || address[0] == ' ') {
        printf("Invalid address. Please try again: ");
        fgets(address, sizeof(address), stdin);
    }
    if (address[strlen(address) - 1] == '\n') {
        address[strlen(address) - 1] = '\0';
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("Enter your email: ");
    fgets(email, sizeof(email), stdin);
    while (email[0] == '\n' || email[0] == ' ') {
        printf("Invalid email. Please try again: ");
        fgets(email, sizeof(email), stdin);
    }
    if (email[strlen(email) - 1] == '\n') {
        email[strlen(email) - 1] = '\0';
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
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

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("Enter your account type:\n");
    printf("1. Savings\n");
    printf("2. Checkings\n");
    printf("Enter your choice: ");
    result = scanf("%d", &choice);
    while (result != 1 || choice < 1 || choice > 2) {
        printf("Invalid choice. Please try again: ");
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
    printf("Enter your phone number: ");
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    fgets(phoneNumber, sizeof(phoneNumber), stdin);
    while (phoneNumber[0] == '\n' || phoneNumber[0] == ' ') {
        printf("Invalid phone number. Please try again: ");
        fgets(phoneNumber, sizeof(phoneNumber), stdin);
    }
    if (phoneNumber[strlen(phoneNumber) - 1] == '\n') {
        phoneNumber[strlen(phoneNumber) - 1] = '\0';
    }
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
    printf("Enter your race:\n");
    printf("1. White\n");
    printf("2. Black\n");
    printf("3. Asian\n");
    printf("4. Hispanic\n");
    printf("5. Other\n");
    printf("Enter your choice: ");
    result = scanf("%d", &choice);
    while (result != 1 || choice < 1 || choice > 5) {
        printf("Invalid choice. Please try again: ");
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
    printf("Please confirm the following information:\n");
    printf("Name: %s\n", name);
    printf("Gender: %s\n", gender);
    printf("Address: %s\n", address);
    printf("Email: %s\n", email);
    printf("Password: %s\n", password);
    printf("Account Type: %s\n", accountType);
    printf("Phone Number: %s\n", phoneNumber);
    printf("Age: %d\n", age);
    printf("Account Number: %s\n", accountNumber);
    printf("Balance: %d\n\n", balance);
    printf("Is this information correct?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    result = scanf("%d", &choice);
    while (result != 1 || choice < 1 || choice > 2) {
        printf("Invalid choice. Please try again: ");
        while (getchar() != '\n')
            ;
        result = scanf("%d", &choice);
    }
    if (choice == 2) {
        system("cls");
        isLoggedIn = false;
        printf("BANK MANAGEMENT SYSTEM: ACCOUNT CREATION\n");
        printf("Account creation cancelled\n");
        Sleep(2000);
        return;
    }

    FILE *file = fopen("accounts.csv", "a");
    fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%d,%d,%s\n", name, gender, address, email, accountType, race, phoneNumber, age, balance, accountNumber, password);
    fclose(file);
    system("cls");

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
    printf("Account created successfully\n");
    Sleep(2000);
    return;
}