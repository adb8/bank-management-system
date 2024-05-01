#ifndef GLOBALS_H
#define GLOBALS_H
#include <stdbool.h>
#include <stdio.h>

struct accountHolder {
    char name[100];
    int age;
    char gender[100];
    char address[100];
    char email[100];
    char race[100];
    char phoneNumber[100];
};

struct Account {
    char number[50];
    char type[100];
    int balance;
    char password[100];
    struct accountHolder holder;
};

extern struct Account account;
extern bool isLoggedIn;
extern bool isRunning;

#endif