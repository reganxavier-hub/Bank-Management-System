/* Bank Management System
* Author: Regan
* Date: 10-12-2024
* Description: Simple Bank Management System in C
* This program simulates a basic bank management system where users can:
* 1. Create new bank accounts
* 2. View details of all accounts
* Future enhancements could include deposit, withdrawal, and file storage functionality. */

#include <stdio.h>

// Define the maximum number of accounts that can be stored
#define MAX_ACCOUNTS 100

// Structure to store bank account details
typedef struct bank_account 
{
    int ac_number; // Account number
    char holder_name[50]; // Name of the account holder
    double balance; // Account balance
} bank_account;

// Function prototypes
void create_account(bank_account * account, int * account_count); // Function to create a new account
void display_all_accounts(bank_account * account, int account_count); // Function to display all accounts

// Function to create a new bank account
void create_account(bank_account * account, int * account_count) 
{
    // Check if the maximum account limit has been reached
    if ( * account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Upgrade your account limit!\n");
        return;
    }

    printf("\n---Create New Account---\n");

    // Input account details
    printf("Enter new account number: ");
    scanf("%d", & account[ * account_count].ac_number);
    printf("Enter the name: ");
    scanf("%s", account[ * account_count].holder_name);
    printf("Enter initial deposit (in Rs): ");
    scanf("%lf", & account[ * account_count].balance);

    ( * account_count) ++; // Increment the account count
    printf("\nAccount created successfully!\n");
}

// Function to display all bank accounts
void display_all_accounts(bank_account * account, int account_count) 
{
    // Check if there are no accounts
    if (account_count == 0) 
    {
        printf("No accounts found!\n");
        return;
    }

    printf("\n---Account Details---\n");

    // Loop through all accounts and display their details
    for (int i = 0; i < account_count; i++) 
    {
        printf("Account number: %d\n", account[i].ac_number);
        printf("Account holder name: %s\n", account[i].holder_name);
        printf("Balance: Rs. %.2lf\n", account[i].balance);
        printf("-------------------------\n");
    }
}

int main() {
    printf("Welcome to Bank Management System\n");

    int choice = 0; // Variable to store menu choice
    int account_count = 0; // Keeps track of the number of accounts created
    bank_account accounts[MAX_ACCOUNTS]; // Array to store bank accounts

    while (1) 
    {
        // Display the main menu
        printf("\n---Main Menu---\n");
        printf("1. Create a new Account\n");
        printf("2. Deposit Money (Coming Soon)\n");
        printf("3. Withdraw Money (Coming Soon)\n");
        printf("4. Display all Accounts\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", & choice);

        // Handle menu options
        switch (choice) 
        {
        case 1:
            create_account(accounts, & account_count); // Create a new account
            break;
        case 4:
            display_all_accounts(accounts, account_count); // Display all accounts
            break;
        case 5:
            printf("Exiting the program. Thank you!\n");
            return 0; // Exit the program
        default:
            printf("Invalid choice. Please try again!\n");
        }
    }

    return 0;
}
