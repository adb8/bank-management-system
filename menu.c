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
    printf("PLEASE SELECT AN OPTION FROM BELOW:\n");
    if (!isLoggedIn) {
        printf("1. CREATE ACCOUNT\n");
        printf("2. LOGIN\n");
        printf("3. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        result = scanf("%d", &choice);
        while (result != 1 || choice < 1 || choice > 3) {
            printf("INVALID INPUT. PLEASE TRY AGAIN: ");
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
        printf("1. SEE ACCOUNT DETAILS\n");
        printf("2. EDIT ACCOUNT DETAILS\n");
        printf("3. DEPOSIT\n");
        printf("4. WITHDRAW\n");
        printf("5. TRANSFER\n");
        printf("6. DELETE ACCOUNT\n");
        printf("7. LOGOUT\n");
        printf("8. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        result = scanf("%d", &choice);
        while (result != 1 || choice < 1 || choice > 8) {
            printf("INVALID INPUT. PLEASE TRY AGAIN: ");
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