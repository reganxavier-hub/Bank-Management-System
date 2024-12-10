/* Bank Management System
* Author: Regan
* Date: 10-12-2024
* Description: Bank Management System in C
* This program simulates a basic bank management system where users can:
* 1. Create new bank accounts
* 2. View details of all accounts
* Future enhancements could include deposit, withdrawal, and file storage functionality. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for bank account details
typedef struct bank_account {
    long long account_number; // Use long long for a 10-digit number
    char name[50];
    char branch_name[50];
    char state[50];
    double balance;
} bank_account;

// Function prototypes
void create_account(bank_account *accounts, int *account_count);
void display_account(bank_account *accounts, int account_count);
void deposit(bank_account *accounts, int account_count);
void withdraw(bank_account *accounts, int account_count);
int prompt_return_to_menu();

#define MAX_ACCOUNTS 100

int main() {
    bank_account accounts[MAX_ACCOUNTS];
    int account_count = 0;
    int choice;

    srand(time(NULL)); // Seed random number generator

    printf("Welcome to Indian Bank Management System\n");

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Create New Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("------------------\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(accounts, &account_count);
                break;
            case 2:
                display_account(accounts, account_count);
                break;
            case 3:
                deposit(accounts, account_count);
                break;
            case 4:
                withdraw(accounts, account_count);
                break;
            case 5:
                printf("\nThank you for banking with us!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Ask if the user wants to return to the main menu
        if (!prompt_return_to_menu()) {
            printf("\nThank you for banking with us!\n");
            break;
        }
    }
    return 0;
}

// Function to create a new account
void create_account(bank_account *accounts, int *account_count) {
    if (*account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create more accounts.\n");
        return;
    }

    printf("\n--- Create Account ---\n");

    // Generate a random 10-digit account number
    accounts[*account_count].account_number = (rand() % 9000000000) + 1000000000;

    printf("Generated Account Number: %lld\n", accounts[*account_count].account_number);
    printf("Enter Name: ");
    scanf(" %[^\n]", accounts[*account_count].name); // Read full name with spaces
    printf("Enter Branch Name: ");
    scanf(" %[^\n]", accounts[*account_count].branch_name); // Read branch name with spaces
    printf("Enter State: ");
    scanf(" %[^\n]", accounts[*account_count].state); // Read state with spaces
    printf("Enter Initial Deposit: Rs.");
    scanf("%lf", &accounts[*account_count].balance);

    (*account_count)++;
    printf("Account created successfully!\n");
}

// Function to display all accounts in a table format
void display_account(bank_account *accounts, int account_count) {
    if (account_count == 0) {
        printf("No accounts available!\n");
        return;
    }

    printf("\n--- Account Details ---\n");

    // Print the table header
    printf("----------------------------------------------------------------------------------------\n");
    printf("| %-12s | %-15s | %-20s | %-15s | %-10s |\n", 
           "Account No", "Name", "Branch", "State", "Balance");
    printf("----------------------------------------------------------------------------------------\n");

    // Print each account's details
    for (int i = 0; i < account_count; i++) {
        printf("| %-12lld | %-15s | %-20s | %-15s | %-10.2f |\n",
               accounts[i].account_number, accounts[i].name, 
               accounts[i].branch_name, accounts[i].state, 
               accounts[i].balance);
    }
    printf("----------------------------------------------------------------------------------------\n");
}

// Function to deposit money into an account
void deposit(bank_account *accounts, int account_count) {
    long long account_number;
    double amount;
    printf("\nEnter Account Number: ");
    scanf("%lld", &account_number);

    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter Amount to Deposit: ");
            scanf("%lf", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful! \n\nUpdated Balance: Rs.%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to withdraw money from an account
void withdraw(bank_account *accounts, int account_count) {
    long long account_number;
    double amount;
    printf("\nEnter Account Number: ");
    scanf("%lld", &account_number);

    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter Amount to Withdraw: ");
            scanf("%lf", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance.\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! Updated Balance: Rs.%.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to prompt user to return to the main menu
int prompt_return_to_menu() {
    char choice;
    printf("\nReturn to Main Menu? (Y/N): ");
    scanf(" %c", &choice);
    return (choice == 'Y' || choice == 'y');
}
