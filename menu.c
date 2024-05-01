#include "globals.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void menu() {
    int choice;
    int result;
    system("cls");
    system("cls");
    printf("BANK MANAGEMENT SYSTEM: MENU\n");
    printf("Please select an option from below:\n");
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
        if (choice != 3) {
            system("cls");
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
        if (choice != 8) {
            system("cls");
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