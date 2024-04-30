#include <stdbool.h>
#include <stdio.h>
#include <time.h>

bool isLoggedIn = false;
bool isRunning = true;
int choice, result;
int age, balance;
char accountNumber[50];
char name[100], gender[100], address[100], email[100], password[100], accountType[100], race[100], phoneNumber[100];

void createAccount() {
    printf("Create Account\n");
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    while (name[0] == '\n' || name[0] == ' ') {
        printf("Invalid name. Please try again: ");
        fgets(name, sizeof(name), stdin);
    }

    printf("Enter your age: ");
    result = scanf("%d", &age);
    while (result != 1 || age < 0 || age > 120) {
        printf("Invalid age. Please try again: ");
        while (getchar() != '\n')
            ;
        result = scanf("%d", &age);
    }

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

    printf("Enter your address: ");
    fgets(address, sizeof(address), stdin);
    while (address[0] == '\n' || address[0] == ' ') {
        printf("Invalid address. Please try again: ");
        fgets(address, sizeof(address), stdin);
    }

    printf("Enter your email: ");
    fgets(email, sizeof(email), stdin);
    while (email[0] == '\n' || email[0] == ' ') {
        printf("Invalid email. Please try again: ");
        fgets(email, sizeof(email), stdin);
    }

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    while (password[0] == '\n' || password[0] == ' ') {
        printf("Invalid password. Please try again: ");
        fgets(password, sizeof(password), stdin);
    }

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

    printf("Enter your phone number: ");
    fgets(phoneNumber, sizeof(phoneNumber), stdin);
    while (phoneNumber[0] == '\n' || phoneNumber[0] == ' ') {
        printf("Invalid phone number. Please try again: ");
        fgets(phoneNumber, sizeof(phoneNumber), stdin);
    }

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

    srand(time(NULL));
    for (int i = 0; i < sizeof(accountNumber) - 1; i++) {
        accountNumber[i] = '0' + rand() % 10;
    }
    accountNumber[sizeof(accountNumber) - 1] = '\0';
}

void seeAccountDetails() {
    printf("Account details\n");
}

void editAccount() {
    printf("Account edited\n");
}

void login() {
    printf("Logged in\n");
}

void deposit() {
    printf("Deposited\n");
}

void withdraw() {
    printf("Withdrawn\n");
}

void transfer() {
    printf("Transferred\n");
}

void deleteAccount() {
    printf("Account deleted\n");
}

void logout() {
    printf("Logged out\n");
}

bool menu() {
    int choice;
    int result;
    printf("Menu\n");
    if (!isLoggedIn) {
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
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
            createAccount();
            break;
        case 2:
            login();
            break;
        case 3:
            isRunning = false;
            break;
        }
    } else if (isLoggedIn) {
        printf("1. See Account Details\n");
        printf("2. Edit Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Transfer\n");
        printf("6. Delete Account\n");
        printf("7. Logout\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        result = scanf("%d", &choice);
        while (result != 1 || choice < 1 || choice > 8) {
            printf("Invalid choice. Please try again: ");
            while (getchar() != '\n')
                ;
            result = scanf("%d", &choice);
        }
        switch (choice) {
        case 1:
            seeAccountDetails();
            break;
        case 2:
            editAccount();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            transfer();
            break;
        case 6:
            deleteAccount();
            break;
        case 7:
            logout();
            break;
        case 8:
            isRunning = false;
            break;
        }
    }
}

int main() {
    printf("Welcome to the Bank\n");
    while (isRunning) {
        menu();
    }
    printf("Thank you for choosing this Bank\n");
    return 0;
}