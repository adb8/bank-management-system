#include "globals.h"
#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void editAccount() {
    int c, result, index, choice;
    char ch;
    char name[100];
    int age;
    char gender[100];
    char address[100];
    char email[100];
    char password[100];
    char accountType[100];
    char phoneNumber[100];
    char race[100];

    char readName[100];
    char readGender[100];
    char readAddress[100];
    char readEmail[100];
    char readAccountType[100];
    char readRace[100];
    char readPhoneNumber[100];
    int readAge;
    char readPassword[100];
    char readAccountNumber[50];
    int readBalance;

    system("cls");
    printf("BANK MANAGEMENT SYSTEM: EDIT ACCOUNT\n");
    printf("1. EDIT NAME\n");
    printf("2. EDIT AGE\n");
    printf("3. EDIT GENDER\n");
    printf("4. EDIT ADDRESS\n");
    printf("5. EDIT EMAIL\n");
    printf("6. EDIT RACE\n");
    printf("7. EDIT PHONE NUMBER\n");
    printf("8. EDIT ACCOUNT TYPE\n");
    printf("9. EDIT PASSWORD\n");
    printf("10. BACK\n");
    printf("ENTER YOUR CHOICE: ");

    result = scanf("%d", &choice);
    while (result != 1 || choice < 1 || choice > 10) {
        printf("INVALID INPUT. PLEASE TRY AGAIN: ");
        while (getchar() != '\n')
            ;
        result = scanf("%d", &choice);
    }

    FILE *file = fopen("accounts.csv", "r");
    if (file == NULL) {
        printf("ERROR OPENING FILE. EXITING PROGRAM...\n");
        exit(1);
    }

    switch (choice) {
    case 1:
        system("cls");
        printf("BANK MANAGEMENT SYSTEM: EDIT ACCOUNT\n");
        printf("ENTER YOUR NEW NAME: ");
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
        break;

    case 2:
        system("cls");
        printf("BANK MANAGEMENT SYSTEM: EDIT ACCOUNT\n");
        printf("ENTER YOUR NEW AGE: ");
        result = scanf("%d", &age);
        while (result != 1 || age < 0 || age > 120) {
            printf("INVALID INPUT. PLEASE TRY AGAIN: ");
            while (getchar() != '\n')
                ;
            result = scanf("%d", &age);
        }
        break;

    case 3:
        system("cls");
        printf("BANK MANAGEMENT SYSTEM: EDIT ACCOUNT\n");
        printf("ENTER YOUR NEW GENDER: ");
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        fgets(gender, sizeof(gender), stdin);
        while (gender[0] == '\n' || gender[0] == ' ') {
            printf("INVALID INPUT. PLEASE TRY AGAIN: ");
            fgets(gender, sizeof(gender), stdin);
        }
        if (gender[strlen(gender) - 1] == '\n') {
            gender[strlen(gender) - 1] = '\0';
        }
        break;

    case 4:
        system("cls");
        printf("BANK MANAGEMENT SYSTEM: EDIT ACCOUNT\n");
        printf("ENTER YOUR NEW ADDRESS: ");
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
        break;

    case 5:
        system("cls");
        printf("BANK MANAGEMENT SYSTEM: EDIT ACCOUNT\n");
        printf("ENTER YOUR NEW EMAIL: ");
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        fgets(email, sizeof(email), stdin);
        while (email[0] == '\n' || email[0] == ' ') {
            printf("INVALID INPUT. PLEASE TRY AGAIN: ");
            fgets(email, sizeof(email), stdin);
        }
        if (email[strlen(email) - 1] == '\n') {
            email[strlen(email) - 1] = '\0';
        }
        break;

    case 6:
        system("cls");
        printf("BANK MANAGEMENT SYSTEM: EDIT ACCOUNT\n");
        printf("ENTER YOUR NEW RACE: ");
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        fgets(race, sizeof(race), stdin);
        while (race[0] == '\n' || race[0] == '\0') {
            printf("INVALID INPUT. PLEASE TRY AGAIN: ");
            fgets(race, sizeof(race), stdin);
        }
        if (race[strlen(race) - 1] == '\n') {
            race[strlen(race) - 1] = '\0';
        }
        break;

    case 7:
        system("cls");
        printf("BANK MANAGEMENT SYSTEM: EDIT ACCOUNT\n");
        printf("ENTER YOUR NEW PHONE NUMBER: ");
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
        break;

    case 8:
        system("cls");
        printf("BANK MANAGEMENT SYSTEM: EDIT ACCOUNT\n");
        printf("ENTER YOUR NEW ACCOUNT TYPE: ");
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        fgets(accountType, sizeof(accountType), stdin);
        while (accountType[0] == '\n' || accountType[0] == ' ') {
            printf("INVALID INPUT. PLEASE TRY AGAIN: ");
            fgets(accountType, sizeof(accountType), stdin);
        }
        if (accountType[strlen(accountType) - 1] == '\n') {
            accountType[strlen(accountType) - 1] = '\0';
        }
        break;

    case 9:
        system("cls");
        printf("BANK MANAGEMENT SYSTEM: EDIT ACCOUNT\n");
        printf("ENTER YOUR NEW PASSWORD: ");
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
        break;

    case 10:
        return;
    }

    system("cls");
    char lines[1000][1000];
    int lineCount = 0;
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%[^,],%[^,\n]\n", readName, readGender, readAddress, readEmail, readAccountType, readRace, readPhoneNumber, &readAge, &readBalance, readAccountNumber, readPassword) != EOF) {
        if (strcmp(readAccountNumber, account.number) == 0) {
            switch (choice) {
            case 1:
                strcpy(readName, name);
                strcpy(account.holder.name, name);
                break;
            case 2:
                readAge = age;
                account.holder.age = age;
                break;
            case 3:
                strcpy(readGender, gender);
                strcpy(account.holder.gender, gender);
                break;
            case 4:
                strcpy(readAddress, address);
                strcpy(account.holder.address, address);
                break;
            case 5:
                strcpy(readEmail, email);
                strcpy(account.holder.email, email);
                break;
            case 6:
                strcpy(readRace, race);
                strcpy(account.holder.race, race);
                break;
            case 7:
                strcpy(readPhoneNumber, phoneNumber);
                strcpy(account.holder.phoneNumber, phoneNumber);
                break;
            case 8:
                strcpy(readAccountType, accountType);
                strcpy(account.type, accountType);
                break;
            case 9:
                strcpy(readPassword, password);
                strcpy(account.password, password);
                break;
            }
        }
        sprintf(lines[lineCount], "%s,%s,%s,%s,%s,%s,%s,%d,%d,%s,%s\n", readName, readGender, readAddress, readEmail, readAccountType, readRace, readPhoneNumber, readAge, readBalance, readAccountNumber, readPassword);
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
    system("cls");

    printf("BANK MANAGEMENT SYSTEM: EDIT ACCOUNT\n");
    printf("ACCOUNT %s SUCCESSFULLY EDITED\n", choice == 1 ? "NAME" : choice == 2 ? "AGE"
                                                                  : choice == 3   ? "GENDER"
                                                                  : choice == 4   ? "ADDRESS"
                                                                  : choice == 5   ? "EMAIL"
                                                                  : choice == 6   ? "RACE"
                                                                  : choice == 7   ? "PHONE NUMBER"
                                                                  : choice == 8   ? "ACCOUNT TYPE"
                                                                                  : "PASSWORD");
    printf("PRESS ANY KEY TO CONTINUE...");
    _getch();
    system("cls");
    return;
}