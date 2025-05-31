#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int account_id;
    char customer_name[100];
    double balance;
} Account;

Account bank[MAX_ACCOUNTS];
int account_count = 0;

void initialize_bank() {
    bank[0] = (Account){1, "Alice", 1500.0};
    bank[1] = (Account){2, "Baby", 2500.5};
    bank[2] = (Account){3, "Abhi", 1000.0};
    account_count = 3;
}

void display_accounts() {
    if (account_count == 0) {
        printf("No bank accounts available.\n");
        return;
    }
    printf("Customer Accounts:\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account ID: %d | Name: %s | Balance: $%.2f\n", bank[i].account_id, bank[i].customer_name, bank[i].balance);
    }
}

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Bank storage full! Cannot create more accounts.\n");
        return;
    }
    Account new_account;
    new_account.account_id = account_count + 1;

    printf("Enter Customer Name: ");
    getchar(); // consume leftover newline
    fgets(new_account.customer_name, sizeof(new_account.customer_name), stdin);
    new_account.customer_name[strcspn(new_account.customer_name, "\n")] = 0; // remove newline

    new_account.balance = 0.0;

    bank[account_count] = new_account;
    account_count++;
    printf("Account created successfully with Account ID %d.\n", new_account.account_id);
}

Account* find_account(int id) {
    for (int i = 0; i < account_count; i++) {
        if (bank[i].account_id == id) {
            return &bank[i];
        }
    }
    return NULL;
}

void deposit() {
    int id;
    double amount;
    printf("Enter Account ID to deposit: ");
    scanf("%d", &id);
    Account* acc = find_account(id);

    if (acc == NULL) {
        printf("Account ID %d not found.\n", id);
        return;
    }
    printf("Enter deposit amount: ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }
    acc->balance += amount;
    printf("Amount $%.2f deposited. New balance: $%.2f\n", amount, acc->balance);
}

void withdraw() {
    int id;
    double amount;
    printf("Enter Account ID to withdraw: ");
    scanf("%d", &id);
    Account* acc = find_account(id);

    if (acc == NULL) {
        printf("Account ID %d not found.\n", id);
        return;
    }
    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Invalid withdrawal amount.\n");
        return;
    }
    if (amount > acc->balance) {
        printf("Insufficient balance. Current balance: $%.2f\n", acc->balance);
        return;
    }
    acc->balance -= amount;
    printf("Amount $%.2f withdrawn. New balance: $%.2f\n", amount, acc->balance);
}

void view_account_details() {
    int id;
    printf("Enter Account ID to view details: ");
    scanf("%d", &id);
    Account* acc = find_account(id);

    if (acc == NULL) {
        printf("Account ID %d not found.\n", id);
        return;
    }
    printf("Account Details:\n");
    printf("Account ID: %d\n", acc->account_id);
    printf("Customer Name: %s\n", acc->customer_name);
    printf("Balance: $%.2f\n", acc->balance);
}

int main() {
    int choice;
    initialize_bank();

    do {
        printf("\nBank Management System\n");
        printf("1. Display All Accounts\n");
        printf("2. Create New Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. View Account Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_accounts();
                break;
            case 2:
                create_account();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                view_account_details();
                break;
            case 6:
                printf("Exiting Bank Management System.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}