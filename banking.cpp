#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Account {
    int accountNumber;
    string name;
    double balance;

    Account(int accNum, string accName, double initialBalance) {
        accountNumber = accNum;
        name = accName;
        balance = initialBalance;
    }
};

class BankingSystem {
private:
    vector<Account> accounts;
    int nextAccountNumber = 1001;

public:
 
    void createAccount(string name, double initialDeposit) {
        if (initialDeposit < 0) {
            cout << "Initial deposit cannot be negative!" << endl;
            return;
        }
        accounts.push_back(Account(nextAccountNumber, name, initialDeposit));
        cout << "Account created successfully! Account Number: " << nextAccountNumber << endl;
        nextAccountNumber++;
    }

  
    Account* findAccount(int accountNumber) {
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }

   
    void deposit(int accountNumber, double amount) {
        Account* account = findAccount(accountNumber);
        if (account == nullptr) {
            cout << "Account not found!" << endl;
            return;
        }
        if (amount <= 0) {
            cout << "Deposit amount must be positive!" << endl;
            return;
        }
        account->balance += amount;
        cout << "Deposited " << amount << " successfully! New balance: " << account->balance << endl;
    }

    
    void withdraw(int accountNumber, double amount) {
        Account* account = findAccount(accountNumber);
        if (account == nullptr) {
            cout << "Account not found!" << endl;
            return;
        }
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive!" << endl;
            return;
        }
        if (amount > account->balance) {
            cout << "Insufficient balance!" << endl;
            return;
        }
        account->balance -= amount;
        cout << "Withdrew " << amount << " successfully! Remaining balance: " << account->balance << endl;
    }

   
    void checkBalance(int accountNumber) {
        Account* account = findAccount(accountNumber);
        if (account == nullptr) {
            cout << "Account not found!" << endl;
            return;
        }
        cout << "Account Number: " << account->accountNumber << ", Name: " << account->name << ", Balance: " << account->balance << endl;
    }

   
    void listAccounts() {
        if (accounts.empty()) {
            cout << "No accounts found!" << endl;
            return;
        }
        cout << "Listing all accounts:" << endl;
        for (const auto& account : accounts) {
            cout << "Account Number: " << account.accountNumber << ", Name: " << account.name << ", Balance: " << account.balance << endl;
        }
    }
};


int main() {
    BankingSystem bank;
    int choice;

    while (true) {
        cout << "\n--- Banking System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. List All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) {
            cout << "Thank you for using the Banking System. Goodbye!" << endl;
            break;
        }

        switch (choice) {
            case 1: {
                string name;
                double initialDeposit;
                cout << "Enter account holder name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter initial deposit amount: ";
                cin >> initialDeposit;
                bank.createAccount(name, initialDeposit);
                break;
            }
            case 2: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bank.deposit(accountNumber, amount);
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;
            }
            case 4: {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                bank.checkBalance(accountNumber);
                break;
            }
            case 5:
                bank.listAccounts();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
