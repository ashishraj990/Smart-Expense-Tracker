#  Smart Expense Tracker

A lightweight, secure command-line application written in C++ to track daily expenses, manage monthly budgets, and analyze spending habits. The application features user authentication and local file-based data persistence.

## 💻 System Flow & Terminal Output

Here is how the application runs in the terminal step-by-step:

### 1. User Authentication
=========================================
      SECURE ENGINE AUTHENTICATION       
=========================================
Enter Admin Username: admin
Enter Secure Password: tracker123

>>> Access Granted! Handshake Protocol Verified. <<<

### 2. Main Dashboard Options
=========================================
        PERSONAL EXPENSE TRACKER        
=========================================
1. Initialize Monthly Financial Budget
2. Record New Asset Transaction Log
3. Render Ledger Transaction Roster
4. Compile Dynamic Expenditure Vector Analysis
5. Kill Process Runtime Instance (Exit)
=========================================
Execute Vector Code (1-5): 1

### 3. Setting Up the Monthly Budget
[Config] Enter Monthly Capital Budget Limit (INR): 50000
>>> Budget metrics successfully set to: 50000.00 INR <<<

### 4. Logging a New Expense
Enter Expense Category (Food, Travel, Utility, Rent): Food
Enter Transaction Amount (INR): 4500
Enter Date (DD/MM/YYYY): 30/10/2026
Enter Transaction Context/Description: Dinner with friends

>>> Transaction log recorded successfully! <<<
Budget Utilization: [█░░░░░░░░░░░░░░░░░░░] 9.0%
 -> Allocated Buffer Remaining: 45500.00 INR

### 5. Automated Budget Threshold Alerts
The system automatically monitors your wallet limit and triggers warnings based on usage:

* **Warning Level (85% Budget Consumed):**
```text
>>> Transaction log recorded successfully! <<<
Budget Utilization: [█████████████████░░░] 87.0%
 [⚠️ WARNING] Risk Level High. Exceeded 85% safety milestone! Free Liquidity: 6500.00 INR
```

* **Critical Level (Budget Overdraft):**
```text
>>> Transaction log recorded successfully! <<<
Budget Utilization: [████████████████████] 105.4%
 [⚠️ CRITICAL BREACH] Budget ceiling exceeded by 2700.00 INR!
```

### 6. View Complete Transaction Ledger
-----------------------------------------------------------------------

| Category      | Amount (INR)  | Date       | Description            |
-----------------------------------------------------------------------

| Food          | 4500.00       | 30/10/2026 | Dinner with friends    |
| Utility       | 3200.00       | 31/10/2026 | Broadband Internet     |
| Travel        | 1500.00       | 02/11/2026 | Cab to Office          |
-----------------------------------------------------------------------
Aggregate Net Expenditure: 9200.00 INR
Budget Utilization: [███░░░░░░░░░░░░░░░░░] 18.4%

### 7. Category-Wise Breakdown Analytics
=============================================
        DESCRIPTIVE SPECTRUM ANALYTICS       
=============================================

| Target Class   | Net Spend (INR) | Vector % |
---------------------------------------------

| Food           | 4500.00         | 48.9%    |
| Utility        | 3200.00         | 34.8%    |
| Travel         | 1500.00         | 16.3%    |
=============================================

### 8. Data Saving & Application Exit
Execute Vector Code (1-5): 5

Saving localized states... Process termination clean.
