#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ExpenseTracker {
public:

 float income = 0;
    float totalExpense = 0;

    void addIncome() {
        float amount;

        cout << "\nEnter your real Income\n";
        cin >> amount;
        if(amount <= 0){
            cout <<"\nInvalid amount\n";
            return;
        }
         income += amount;
         

    

        cout << "Income added successfully!\n";

        transactions.push_back("Income: " + to_string(amount));
    }

    void addexpense(){
        float amount;
        int category;

        cout <<"\nEnter Expence amount:\n";
        cin >> amount;

         if(amount <= 0){
            cout <<"\nInvalid amount\n";
            return;
        }

        cout <<"\n Where did you spend money\n";
        cout<< "-----------------------------" <<endl;
         cout << "1. Food\n";
        cout << "2. Shopping\n";
        cout << "3. Travel\n";
        cout << "4. Education\n";
        cout << "5. Bills\n";
        cout << "6. Other\n";
        cout<< "-----------------------------" <<endl;

        cout << "\nChoose Category\n ";
        cin>> category;

        string place;
         switch (category) {
            case 1: place = "Food"; break;
            case 2: place = "Shopping"; break;
            case 3: place = "Travel"; break;
            case 4: place = "Education"; break;
            case 5: place = "Bills"; break;
            case 6: place = "Other"; break;
            default:
                cout << "Invalid category!\n";
                return;
        }
         if (amount > income - totalExpense) {
            cout << "Insufficient balance!\n";
            return;
        }

        totalExpense += amount;

        cout << "Expense added successfully!\n";
        cout << "Category: " << place << endl;
        cout << "Amount: " << amount << endl;
        transactions.push_back("Expense: " + place + " - " + to_string(amount));


    }     
vector<string> transactions;

void viewTransactions() {
    cout << "\n----- View Transactions -----\n";

    if (transactions.empty()) {
        cout << "No transactions yet!\n";
        return;
    }

    for (int i = 0; i < transactions.size(); i++) {
        cout << transactions[i] << endl;
    }
}

    
};

int main() {
    ExpenseTracker obj;

    int choice;

    while (true) {
        cout << "\n-----------Expense Tracker---------\n";
        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. View Transactions\n";
        cout << "4. View Balance\n";
        cout << "5. Exit\n";

        cout << "Enter choice -> ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.addIncome();
                break;

            case 2:
                obj.addexpense();
                break;

            case 3:
               obj.viewTransactions();
                break;

            case 4:
          cout<< "-----------------------------" <<endl;     
          cout << "Total Income: " << obj.income << endl;
          cout << "Total Expense: " << obj.totalExpense << endl;
          cout << "Remaining Balance: " << obj.income - obj.totalExpense << endl;
           cout<< "-----------------------------" <<endl;  
          break;

            case 5:
                cout << "\nThank You!\n";
                return 0;

            default:
                cout << "\nInvalid Choice.\n";
        }
    }

    return 0;
}
