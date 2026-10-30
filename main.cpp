#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

// Class encapsulation for a single core Expense Entity
class Expense {
private:
    string category;
    double amount;
    string date;
    string description;

public:
    Expense(string cat, double amt, string dt, string desc) 
        : category(cat), amount(amt), date(dt), description(desc) {}

    string getCategory() const { return category; }
    double getAmount() const { return amount; }
    string getDate() const { return date; }
    string getDescription() const { return description; }

    void display() const {
        cout << "| " << setw(14) << left << category 
             << "| " << setw(14) << fixed << setprecision(2) << amount 
             << "| " << setw(12) << date 
             << "| " << setw(22) << left << description << " |" << endl;
    }
};

// Orchestrator Engine Class handling structural business logic and File I/O
class SmartExpenseTracker {
private:
    vector<Expense> expenses;
    double monthlyBudget;
    double totalSpent;
    const string storageFile = "expense_ledger.txt";

    void commitToStorage() const {
        ofstream outFile(storageFile, ios::trunc);
        if (!outFile) return;
        
        outFile << monthlyBudget << "\n";
        for (const auto& exp : expenses) {
            outFile << exp.getCategory() << "," 
                    << exp.getAmount() << "," 
                    << exp.getDate() << "," 
                    << exp.getDescription() << "\n";
        }
        outFile.close();
    }

    // Helper method to draw analytical ASCII bars
    void renderProgressBar(double percentage) const {
        int barWidth = 20;
        int filledLength = round((percentage / 100.0) * barWidth);
        if (filledLength > barWidth) filledLength = barWidth;
        if (filledLength < 0) filledLength = 0;

        cout << "Budget Utilization: [";
        for (int i = 0; i < barWidth; ++i) {
            if (i < filledLength) cout << "█";
            else cout << "░";
        }
        cout << "] " << fixed << setprecision(1) << percentage << "%\n";
    }

public:
    SmartExpenseTracker() : monthlyBudget(0.0), totalSpent(0.0) {
        ifstream inFile(storageFile);
        if (!inFile) return;

        string line;
        if (getline(inFile, line)) {
            stringstream ss(line);
            ss >> monthlyBudget;
        }

        while (getline(inFile, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string cat, amtStr, dt, desc;
            
            getline(ss, cat, ',');
            getline(ss, amtStr, ',');
            getline(ss, dt, ',');
            getline(ss, desc, ',');

            if (amtStr.empty()) continue;
            double amt = stod(amtStr);
            expenses.push_back(Expense(cat, amt, dt, desc));
            totalSpent += amt;
        }
        inFile.close();
    }

    void configureBudget() {
        cout << "\n[Config] Enter Monthly Capital Budget Limit (INR): ";
        while (!(cin >> monthlyBudget) || monthlyBudget < 0) {
            cout << "[!] Invalid Amount! Please enter a positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        commitToStorage();
        cout << ">>> Budget metrics successfully set to: " << fixed << setprecision(2) << monthlyBudget << " INR <<<\n";
    }

    void registerExpense() {
        string cat, dt, desc;
        double amt;

        cout << "\nEnter Expense Category (Food, Travel, Utility, Rent): ";
        cin.ignore();
        getline(cin, cat);
        
        cout << "Enter Transaction Amount (INR): ";
        while (!(cin >> amt) || amt <= 0) {
            cout << "[!] Invalid Input! Enter a positive numeric value: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "Enter Date (DD/MM/YYYY): ";
        cin >> dt;
        cout << "Enter Transaction Context/Description: ";
        cin.ignore();
        getline(cin, desc);

        expenses.push_back(Expense(cat, amt, dt, desc));
        totalSpent += amt;
        commitToStorage();

        cout << "\n>>> Transaction log recorded successfully! <<<\n";
        
        if (monthlyBudget > 0) {
            double usagePercent = (totalSpent / monthlyBudget) * 100;
            renderProgressBar(usagePercent);
            
            double balanceBudget = monthlyBudget - totalSpent;
            if (balanceBudget < 0) {
                cout << " [⚠️ CRITICAL BREACH] Budget ceiling exceeded by " << abs(balanceBudget) << " INR!\n";
            } else if (totalSpent >= monthlyBudget * 0.85) {
                cout << " [⚠️ WARNING] Risk Level High. Exceeded 85% safety milestone! Free Liquidity: " << balanceBudget << " INR\n";
            } else {
                cout << " -> Allocated Buffer Remaining: " << balanceBudget << " INR\n";
            }
        }
    }

    void generateTransactionRoster() const {
        if (expenses.empty()) {
            cout << "\n[System Logs] Active transaction roster is empty.\n";
            return;
        }

        cout << "\n-----------------------------------------------------------------------\n";
        cout << "| Category      | Amount (INR)  | Date        | Description            |\n";
        cout << "-----------------------------------------------------------------------\n";
        for (const auto& exp : expenses) {
            exp.display();
        }
        cout << "-----------------------------------------------------------------------\n";
        cout << "Aggregate Net Expenditure: " << fixed << setprecision(2) << totalSpent << " INR\n";
        if (monthlyBudget > 0) {
            renderProgressBar((totalSpent / monthlyBudget) * 100);
        }
    }

    void executeAnalyticsEngine() const {
        if (expenses.empty()) {
            cout << "\n[Analytics] Zero data nodes compiled. Analysis matrix setup failed.\n";
            return;
        }

        vector<string> systemCategories;
        vector<double> dynamicCategoryTotals;

        for (const auto& exp : expenses) {
            bool matchesExistingNode = false;
            for (size_t i = 0; i < systemCategories.size(); ++i) {
                if (systemCategories[i] == exp.getCategory()) {
                    dynamicCategoryTotals[i] += exp.getAmount();
                    matchesExistingNode = true;
                    break;
                }
            }
            if (!matchesExistingNode) {
                systemCategories.push_back(exp.getCategory());
                dynamicCategoryTotals.push_back(exp.getAmount());
            }
        }

        cout << "\n=============================================\n";
        cout << "       DESCRIPTIVE SPECTRUM ANALYTICS        \n";
        cout << "=============================================\n";
        cout << "| Target Class   | Net Spend (INR) | Vector %  |\n";
        cout << "---------------------------------------------\n";
        for (size_t i = 0; i < systemCategories.size(); ++i) {
            double distributionVectorShare = (dynamicCategoryTotals[i] / totalSpent) * 100;
            cout << "| " << setw(15) << left << systemCategories[i]
                 << "| " << setw(16) << fixed << setprecision(2) << dynamicCategoryTotals[i]
                 << "| " << setw(8) << setprecision(1) << distributionVectorShare << "% |" << endl;
        }
        cout << "=============================================\n";
    }
};

// Security Subsystem Module
bool authenticateSession() {
    string username, password;
    int attempts = 3;
    
    cout << "\n=========================================\n";
    cout << "       SECURE ENGINE AUTHENTICATION      \n";
    cout << "=========================================\n";
    
    while (attempts > 0) {
        cout << "Enter Admin Username: ";
        cin >> username;
        cout << "Enter Secure Password: ";
        cin >> password;
        
        if (username == "admin" && password == "tracker123") {
            cout << "\n>>> Access Granted! Handshake Protocol Verified. <<<\n";
            return true;
        } else {
            attempts--;
            cout << "\n[!] Authentication Failed. Retries remaining: " << attempts << "\n\n";
        }
    }
    cout << ">>> Security Threat Detected! Terminating session framework. <<<\n";
    return false;
}

int main() {
    if (!authenticateSession()) {
        return 0;
    }

    SmartExpenseTracker kernelEngine;
    int processSignal;

    while (true) {
        cout << "\n=========================================\n";
        cout << "      ENTERPRISE SMART EXPENSE ENGINE     \n";
        cout << "=========================================\n";
        cout << "1. Initialize Monthly Financial Budget\n";
        cout << "2. Record New Asset Transaction Log\n";
        cout << "3. Render Ledger Transaction Roster\n";
        cout << "4. Compile Dynamic Expenditure Vector Analysis\n";
        cout << "5. Kill Process Runtime Instance (Exit)\n";
        cout << "=========================================\n";
        cout << "Execute Vector Code (1-5): ";
        
        while (!(cin >> processSignal)) {
            cout << "[!] Invalid Option! Please choose between 1-5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (processSignal) {
            case 1: 
                kernelEngine.configureBudget(); 
                break;
            case 2: 
                kernelEngine.registerExpense(); 
                break;
            case 3: 
                kernelEngine.generateTransactionRoster(); 
                break;
            case 4: 
                kernelEngine.executeAnalyticsEngine(); 
                break;
            case 5:

cout << "\nSaving localized states... Process termination clean.\n";
return 0;
default:
cout << "\nRuntime Error: Invalid operational stack index selection.\n";
}
}
return 0;
}
