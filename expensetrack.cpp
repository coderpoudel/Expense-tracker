/**
 * This program keeps the track of the expenses.
 *
 * @filename: Expensetracker.cpp
 * @author  Anup Poudel
 * @version 1.0
 * @since   11/22/2023
 */

#include <iostream>
#include <string>

using namespace std;

struct Expense{
    string date;
    string description;
    double amount;
};

void addExpense(Expense expenses[], int& count) {
    
    string date, description;
    double amount;
    
    cout << "Enter the date: ";
    cin >> date;
    
    cout << "Enter the description: ";
    cin >> description;
    
    cout << "Enter the amount: ";
    cin >> amount;
    
    Expense newExpense;
    newExpense.date = date;
    newExpense.description = description;
    newExpense.amount = amount;
    
    expenses[count] = newExpense;
    count++;
}

void displayExpenses(const Expense expenses[], int count){
    cout << "\nExpense lists:\n";
    for (int i = 0; i < count; ++i){
        cout << "Date: " << expenses[i].date << ", description: " << expenses[i].description << ", Amount: " << expenses[i].amount << endl;
        

    }
}
void displayExpenseSummary(const Expense expenses[], int count) {
    double totalAmount = 0.0;

    for (int i = 0; i < count; ++i) {
        totalAmount += expenses[i].amount;
    }

    cout << "\nTotal Expenses: $" << totalAmount << endl;
}

int main() {
    const int MAX_EXPENSES = 100;
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    do {
        cout << "\n===== Expense Tracker Menu =====\n";
        cout << "1. Add Expense\n";
        cout << "2. Display Expenses\n";
        cout << "3. Display Expense Summary\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExpense(expenses, count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                displayExpenseSummary(expenses, count);
                break;
            case 4:
                cout << "Exiting the Expense Tracker. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}


