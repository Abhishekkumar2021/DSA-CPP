/**
 * @file Banking_managemnt_sytem.cpp
 * @brief This file contains the implementation of a banking management system using OOP concepts.
 * 
 * The system consists of classes for Account, Transaction, Customer and Bank. 
 * The Account class contains information about the account number, balance, deposit and withdrawal methods.
 * The Transaction class contains information about the time, type, amount, balance and description of a transaction.
 * The Customer class contains information about the customer's name, username, email, password, account and transactions.
 * The Bank class contains a vector of customers and methods to add customers, display customers, deposit, withdraw and change password.
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// The Account class contains information about the account number, balance, deposit and withdrawal methods.
class Account
{
private:
    int accountNumber;
    float balance;

public:
    // The constructor for the Account class that takes in the account number and balance as parameters.
    Account(int accountNumber, float balance)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }
    // The deposit method that takes in the amount to be deposited as a parameter.
    void deposit(float amount) { balance += amount; }

    // The withdraw method that takes in the amount to be withdrawn as a parameter and checks if the balance is sufficient. If the balance is sufficient, the amount is withdrawn, else an error message is displayed.
    void withdraw(float amount)
    {
        if (balance - amount < 500)
        {
            cout << "Insufficient Balance" << endl;
        }
        else
        {
            balance -= amount;
        }
    }
    // The getBalance method that returns the current balance.
    int getBalance() { return balance; }
    // The display method that displays the account number and balance.
    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
    // The getAccountNumber method that returns the account number.
    int getAccountNumber() { return accountNumber; }
};

// The Transaction class contains information about the time, type, amount, balance and description of a transaction.
class Transaction
{
private:
    string time;
    string type;
    float amount;
    float balance;
    string description;

public:
    // The constructor for the Transaction class that takes in the time, type, amount, balance and description as parameters.
    Transaction(string time, string type, float amount,
                float balance, string description)
    {
        this->time = time;
        this->type = type;
        this->amount = amount;
        this->balance = balance;
        this->description = description;
    }
    // The display method that displays the time, type, amount, balance and description.
    void display()
    {
        cout << "Time: " << time << endl;
        cout << "Type: " << type << endl;
        cout << "Amount: " << amount << endl;
        cout << "Balance: " << balance << endl;
        cout << "Description: " << description << endl;
    }
    // The getTime method that returns the time.
    string getTime() { return time; }
    string getType() { return type; }
    float getAmount() { return amount; }
    float getBalance() { return balance; }
    string getDescription() { return description; }
};

// The Customer class contains information about the customer's name, username, email, password, account and transactions.
class Customer
{
private:
    string name;
    string username;
    string email;
    string password;
    Account account;
    vector<Transaction> transactions;

public:
    // The constructor for the Customer class that takes in the name, username, password, email and account as parameters.
    Customer(string name, string username, string password,
             string email, Account account)
        : account(account)
    {
        this->name = name;
        this->username = username;
        this->password = password;
        this->email = email;
    }
    // The display method that displays the name, username, password, email and account.
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "Email: " << email << endl;
        account.display();
    }
    // The deposit method that takes in the amount to be deposited as a parameter and adds a transaction to the transactions vector.
    void deposit(float amount)
    {
        account.deposit(amount);
        time_t now = time(0);
        char *dt = ctime(&now);
        Transaction transaction(dt, "Deposit", amount,
                                account.getBalance(),
                                "Deposit");
        transactions.push_back(transaction);
    }
    // The withdraw method that takes in the amount to be withdrawn as a parameter and adds a transaction to the transactions vector.
    void withdraw(float amount)
    {
        account.withdraw(amount);
        time_t now = time(0);
        char *dt = ctime(&now);
        Transaction transaction(dt, "Withdraw", amount,
                                account.getBalance(),
                                "Withdraw");
        transactions.push_back(transaction);
    }
    // The changePassword method that takes in the new password as a parameter and changes the password.
    void changePassword(string password)
    {
        this->password = password;
    }
    // The getName method that returns the name.
    string getName() { return name; }
    // The getUsername method that returns the username.
    string getUsername() { return username; }
    // The getPassword method that returns the password.
    string getPassword() { return password; }
    // The getEmail method that returns the email.
    string getEmail() { return email; }
    // The getAccount method that returns the account.
    Account getAccount() { return account; }
    // The getTransactions method that returns the transactions vector.
    vector<Transaction> getTransactions()
    {
        return transactions;
    }
    // The getBalance method that returns the balance.
    float getBalance() { return account.getBalance(); }
    // The checkPassword method that takes in the password as a parameter and returns true if the password is correct, else returns false.
    bool checkPassword(string password)
    {
        return this->password == password;
    }
    // The getTransaction method that takes in the index as a parameter and returns the transaction at that index.
    Transaction getTransaction(int index)
    {
        if (index < transactions.size())
        {
            return transactions[index];
        }
        cout << "Invalid Index" << endl;
        return Transaction("", "", 0, 0, "");
    }
    // The getTransactionSize method that returns the size of the transactions vector.
    int getTransactionSize() { return transactions.size(); }
};

// The Bank class contains a vector of customers and methods to add customers, display customers, deposit, withdraw and change password.
class Bank
{
private:
    vector<Customer> customers;
    int nextAccountNumber;

public:
    // The constructor for the Bank class that initializes the nextAccountNumber to 1.
    Bank() { nextAccountNumber = 1; }
    // The addCustomer method that takes in the customer as a parameter and adds the customer to the customers vector.
    void addCustomer(Customer customer)
    {
        customers.push_back(customer);
        nextAccountNumber++;
    }
    // The displayCustomers method that displays all the customers.
    void displayCustomers()
    {
        for (int i = 0; i < customers.size(); i++)
        {
            customers[i].display();
        }
    }
    // The displayCustomer method that takes in the username as a parameter and displays the customer with that username.
    void displayCustomer(string username)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getUsername() == username)
            {
                customers[i].display();
            }
        }
    }
    // The deposit method that takes in the username and amount as parameters and deposits the amount to the customer with that username.
    void deposit(string username, float amount)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getUsername() == username)
            {
                customers[i].deposit(amount);
            }
        }
    }
    // The withdraw method that takes in the username and amount as parameters and withdraws the amount from the customer with that username.
    void withdraw(string username, float amount)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getUsername() == username)
            {
                customers[i].withdraw(amount);
            }
        }
    }
    // The changePassword method that takes in the username, password and newPassword as parameters and changes the password of the customer with that username.
    void changePassword(string username, string password,
                        string newPassword)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getUsername() == username && customers[i].checkPassword(password))
            {
                customers[i].changePassword(newPassword);
            }
        }
    }
    // The displayTransactions method that takes in the username as a parameter and displays all the transactions of the customer with that username.
    void displayTransactions(string username)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getUsername() == username)
            {
                for (int j = 0; j < customers[i]
                                        .getTransactions()
                                        .size();
                     j++)
                {
                    customers[i]
                        .getTransactions()[j]
                        .display();
                }
            }
        }
    }
    // The getNextAccountNumber method that returns the nextAccountNumber.
    int getNextAccountNumber() { return nextAccountNumber; }
    // The deleteCustomer method that takes in the username and password as parameters and deletes the customer with that username and password.
    void deleteCustomer(string username, string password)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getUsername() == username)
            {
                if (customers[i].checkPassword(password))
                {
                    customers.erase(customers.begin() + i);
                }
            }
        }
    }
    // The getBalance method that takes in the username as a parameter and returns the balance of the customer with that username.
    float getBalance(string username)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getUsername() == username)
            {
                return customers[i].getBalance();
            }
        }
        return 0;
    }
    // The userExist method that takes in the username and password as parameters and returns true if the customer with that username and password exists, else returns false.
    bool userExist(string username, string password)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getUsername() == username && customers[i].checkPassword(password))
            {
                return true;
            }
        }
        return false;
    }
    // The getCustomer method that takes in the index as a parameter and returns the customer at that index.
    int getNumberOfCustomers() { return customers.size(); }
    // The getCustomer method that takes in the index as a parameter and returns the customer at that index.
    Customer getCustomer(int i) { return customers[i]; }
    // The getCustomerIndex method that takes in the username as a parameter and returns the index of the customer with that username.
    int getCustomerIndex(string username)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getUsername() == username)
            {
                return i;
            }
        }
        return -1;
    }
};
// The Database class contains methods to fetch from file, add customer, add transaction, delete customer and change password.
class Database
{
    ofstream customerWrite;
    ifstream customerRead;
    ofstream accountWrite;
    ifstream accountRead;

public:
    // The constructor for the Database class that opens the customer.dat and account.dat files.
    Database()
    {
        customerWrite.open("customer.dat", ios::app);
        customerRead.open("customer.dat");
        accountWrite.open("account.dat", ios::app);
        accountRead.open("account.dat");
    }
    // The destructor for the Database class that closes the customer.dat and account.dat files.
    ~Database()
    {
        customerWrite.close();
        customerRead.close();
        accountWrite.close();
        accountRead.close();
    }
    // The fetchFromFile method that takes in the bank as a parameter and fetches the data from the customer.dat, account.dat and transaction.dat files.
    void fetchFromFile(Bank &bank)
    {
        string name, username, password, email;
        int accountNumber;
        float balance;
        while (customerRead >> name >> username >> password >> email)
        {
            accountRead >> accountNumber >> balance;
            Account account(accountNumber, balance);
            Customer customer(name, username, password,
                              email, account);
            bank.addCustomer(customer);
        }
        for (int i = 0; i < bank.getNumberOfCustomers();
             i++)
        {
            string time, type, description;
            float amount, balance;
            ifstream transactionRead;
            transactionRead.open(bank.getCustomer(i)
                                     .getAccount()
                                     .getAccountNumber() +
                                 ".dat");
            while (transactionRead >> time >> type >> amount >> balance >> description)
            {
                Transaction transaction(time, type, amount,
                                        balance,
                                        description);
                bank.getCustomer(i)
                    .getTransactions()
                    .push_back(transaction);
            }
        }
    }
    // The addCustomer method that takes in the customer as a parameter and adds the customer to the customer.dat and account.dat files.
    void addCustomer(Customer customer)
    {
        customerWrite << customer.getName() << " "
                      << customer.getUsername() << " "
                      << customer.getPassword() << " "
                      << customer.getEmail() << endl;
        accountWrite
            << customer.getAccount().getAccountNumber()
            << " " << customer.getAccount().getBalance()
            << endl;
    }
    // The addTransaction method that takes in the customer and transaction as parameters and adds the transaction to the transaction.dat file.
    void addTransaction(Customer customer,
                        Transaction transaction)
    {
        ofstream transactionWrite;
        transactionWrite.open(
            to_string(
                customer.getAccount().getAccountNumber()) +
                ".dat",
            ios::app);
        transactionWrite << transaction.getTime() << " "
                         << transaction.getType() << " "
                         << transaction.getAmount() << " "
                         << transaction.getBalance() << " "
                         << transaction.getDescription()
                         << endl;
        transactionWrite.close();
    }
    // The deleteCustomer method that takes in the customer as a parameter and deletes the customer from the customer.dat and account.dat files.
    void deleteCustomer(Customer customer)
    {
        ofstream tempCustomerWrite;
        tempCustomerWrite.open("tempCustomer.dat");
        ifstream tempCustomerRead;
        tempCustomerRead.open("tempCustomer.dat");
        ofstream tempAccountWrite;
        tempAccountWrite.open("tempAccount.dat");
        ifstream tempAccountRead;
        tempAccountRead.open("tempAccount.dat");
        string name, username, password, email;
        int accountNumber;
        float balance;
        while (customerRead >> name >> username >> password >> email)
        {
            accountRead >> accountNumber >> balance;
            if (customer.getAccount().getAccountNumber() != accountNumber)
            {
                tempCustomerWrite << name << " " << username
                                  << " " << password << " "
                                  << email << endl;
                tempAccountWrite << accountNumber << " "
                                 << balance << endl;
            }
        }
        customerWrite.close();
        customerRead.close();
        accountWrite.close();
        accountRead.close();
        remove("customer.dat");
        remove("account.dat");
        rename("tempCustomer.dat", "customer.dat");
        rename("tempAccount.dat", "account.dat");
        customerWrite.open("customer.dat", ios::app);
        customerRead.open("customer.dat");
        accountWrite.open("account.dat", ios::app);
        accountRead.open("account.dat");
    }
    // The changePassword method that takes in the customer and newPassword as parameters and changes the password of the customer in the customer.dat and account.dat files.
    void changePassword(Customer customer,
                        string newPassword)
    {
        ofstream tempCustomerWrite;
        tempCustomerWrite.open("tempCustomer.dat");
        ifstream tempCustomerRead;
        tempCustomerRead.open("tempCustomer.dat");
        ofstream tempAccountWrite;
        tempAccountWrite.open("tempAccount.dat");
        ifstream tempAccountRead;
        tempAccountRead.open("tempAccount.dat");
        string name, username, password, email;
        int accountNumber;
        float balance;
        while (customerRead >> name >> username >> password >> email)
        {
            accountRead >> accountNumber >> balance;
            if (customer.getAccount().getAccountNumber() == accountNumber)
            {
                tempCustomerWrite << name << " " << username
                                  << " " << newPassword
                                  << " " << email << endl;
                tempAccountWrite << accountNumber << " "
                                 << balance << endl;
            }
            else
            {
                tempCustomerWrite << name << " " << username
                                  << " " << password << " "
                                  << email << endl;
                tempAccountWrite << accountNumber << " "
                                 << balance << endl;
            }
        }
        customerWrite.close();
        customerRead.close();
        accountWrite.close();
        accountRead.close();
        remove("customer.dat");
        remove("account.dat");
        rename("tempCustomer.dat", "customer.dat");
        rename("tempAccount.dat", "account.dat");
        customerWrite.open("customer.dat", ios::app);
        customerRead.open("customer.dat");
        accountWrite.open("account.dat", ios::app);
        accountRead.open("account.dat");
    }
};

// The Menu class contains methods to display the main menu, admin menu, user menu and after login menu.
class Menu
{
public:
    // The mainMenu method that displays the main menu.
    static void mainMenu()
    {
        cout << "\n*********************************"
             << endl;
        cout << "Welcome to the Banking System\n";
        cout << "1. Admin\n";
        cout << "2. Customer\n";
        cout << "3. Exit\n";
        cout << "*********************************" << endl;
        cout << "Enter your choice: ";
    }
    // The adminMenu method that displays the admin menu.
    static void adminMenu()
    {
        cout << "\n*********************************"
             << endl;
        cout << "Welcome to the Admin Menu\n";
        cout << "1. Add Customer\n";
        cout << "2. Delete Customer\n";
        cout << "3. Modify Customer\n";
        cout << "4. View Customer\n";
        cout << "5. View All Customers\n";
        cout << "6. Exit\n";
        cout << "*********************************" << endl;
        cout << "Enter your choice: ";
    }
    // The userMenu method that displays the user menu.
    static void userMenu()
    {
        cout << "\n*********************************"
             << endl;
        cout << "Welcome to the Customer Menu\n";
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "*********************************" << endl;
        cout << "Enter your choice: ";
    }
    // The afterLoginMenu method that displays the after login menu.
    static void afterLoginMenu()
    {
        cout << "\n*********************************"
             << endl;
        cout << "Welcome to the Customer Menu\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Change Password\n";
        cout << "4. Check Balance\n";
        cout << "5. View Transactions\n";
        cout << "6. Custome details\n";
        cout << "7. Logout\n";
        cout << "*********************************" << endl;
        cout << "Enter your choice: ";
    }
};
// The signalHandler function that handles the SIGINT signal.
void signalHandler(int signum)
{
    cout << "\nBye Bye\n";
    exit(signum);
}
// The main function that contains the menu driven program.
int main()
{
    Database database;  // Database object
    signal(SIGINT, signalHandler);  // Register signal handler
    Bank bank;  // Bank object
    database.fetchFromFile(bank);   // Fetch data from file
    // Menu driven program
    while (true)
    {
        int choice;
        Menu::mainMenu();
        cin >> choice;
        switch (choice)
        {
        // Admin
        case 1:
        {
            string adminPassword;
            cout << "Enter the admin password: ";
            cin >> adminPassword;
            if (adminPassword == "admin")
            {
                while (true)
                {
                    int adminChoice;
                    Menu::adminMenu();
                    cin >> adminChoice;
                    switch (adminChoice)
                    {
                    // Add Customer
                    case 1:
                    {
                        string name, username, password,
                            email;
                        cout << "Enter the name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter the username: ";
                        cin >> username;
                        cout << "Enter the password: ";
                        cin >> password;
                        cout << "Enter email address: ";
                        cin >> email;
                        Account account(
                            bank.getNextAccountNumber(), 0);
                        Customer customer(name, username,
                                          password, email,
                                          account);
                        bank.addCustomer(customer);
                        database.addCustomer(customer);
                        cout << "Succesfully created the "
                                "account\n";
                        break;
                    }
                    // Delete Customer
                    case 2:
                    {
                        string username, password;
                        cout << "Enter the username: ";
                        cin >> username;
                        cout << "Enter the password: ";
                        cin >> password;
                        bank.deleteCustomer(username,
                                            password);
                        database.deleteCustomer(
                            bank.getCustomer(
                                bank.getCustomerIndex(
                                    username)));
                        cout << "Succesfully deleted the "
                                "account\n";
                        break;
                    }
                    // Modify Customer
                    case 3:
                    {
                        string username, password,
                            newPassword;
                        cout << "Enter the username: ";
                        cin >> username;
                        cout << "Enter the current "
                                "password: ";
                        cin >> password;
                        cout << "Enter the new password: ";
                        cin >> newPassword;
                        bank.changePassword(username,
                                            password,
                                            newPassword);
                        database.changePassword(
                            bank.getCustomer(
                                bank.getCustomerIndex(
                                    username)),
                            newPassword);
                        cout << "Succesfully changed the "
                                "password\n";
                        break;
                    }
                    // View Customer
                    case 4:
                    {
                        string username;
                        cout << "Enter the username: ";
                        cin >> username;
                        bank.displayCustomer(username);
                        break;
                    }
                    // View All Customers
                    case 5:
                    {
                        bank.displayCustomers();
                        break;
                    }
                    // Exit
                    case 6:
                    {
                        goto end;
                        break;
                    }
                    // Default
                    default:
                    {
                        cout << "Invalid choice\n";
                        break;
                    }
                    }
                }
            end:
                break;
            }
            else
            {
                cout << "Invalid password\n";
            }
            break;
        }
        // Customer
        case 2:
        {
            while (true)
            {
                int userChoice;
                Menu::userMenu();
                cin >> userChoice;
                switch (userChoice)
                {
                // Create Account
                case 1:
                {
                    string name, username, password, email;
                    cout << "Enter the name: ";
                    cin >> name;
                    cout << "Enter the username: ";
                    cin >> username;
                    cout << "Enter the password: ";
                    cin >> password;
                    cout << "Enter email address: ";
                    cin >> email;
                    Account account(
                        bank.getNextAccountNumber(), 0);
                    Customer customer(name, username,
                                      password, email,
                                      account);
                    bank.addCustomer(customer);
                    database.addCustomer(customer);
                    cout << "Succesfully created the "
                            "account\n";
                    break;
                }
                // Login
                case 2:
                {
                    string username, password;
                    cout << "Enter the username: ";
                    cin >> username;
                    cout << "Enter the password: ";
                    cin >> password;
                    if (!bank.userExist(username,
                                        password))
                    {
                        cout << "Invalid credentials!\n";
                        break;
                    }
                    int afterLoginChoice;
                    while (true)
                    {
                        Menu::afterLoginMenu();
                        cin >> afterLoginChoice;
                        switch (afterLoginChoice)
                        {
                        // Deposit
                        case 1:
                        {
                            float amount;
                            cout << "Enter the amount to "
                                    "deposit: ";
                            cin >> amount;
                            bank.deposit(username, amount);
                            Customer customer = bank.getCustomer(
                                bank.getCustomerIndex(
                                    username));
                            database.addTransaction(
                                customer,
                                customer.getTransaction(
                                    customer
                                        .getTransactionSize() -
                                    1));
                            cout << "Succesfully deposited "
                                    "the amount\n";
                            break;
                        }
                        // Withdraw
                        case 2:
                        {
                            float amount;
                            cout << "Enter the amount to "
                                    "withdraw: ";
                            cin >> amount;
                            bank.withdraw(username, amount);
                            Customer customer = bank.getCustomer(
                                bank.getCustomerIndex(
                                    username));
                            database.addTransaction(
                                customer,
                                customer.getTransaction(
                                    customer
                                        .getTransactionSize() -
                                    1));
                            cout << "Succesfully withdrew "
                                    "the amount\n";
                            break;
                        }
                        // Change Password
                        case 3:
                        {
                            string newPassword;
                            cout << "Enter the new "
                                    "password: ";
                            cin >> newPassword;
                            bank.changePassword(
                                username, password,
                                newPassword);
                            database.changePassword(
                                bank.getCustomer(
                                    bank.getCustomerIndex(
                                        username)),
                                newPassword);
                            break;
                        }
                        // Check Balance
                        case 4:
                        {
                            cout
                                << "Your balance is: "
                                << bank.getBalance(username)
                                << endl;
                            break;
                        }
                        // View Transactions
                        case 5:
                        {
                            bank.displayTransactions(
                                username);
                            break;
                        }
                        // Customer details
                        case 6:
                        {
                            bank.displayCustomer(username);
                            break;
                        }
                        // Logout
                        case 7:
                        {
                            goto out;
                        }
                        // Default
                        default:
                        {
                            cout << "Invalid choice\n";
                            break;
                        }
                        }
                    }
                out:
                    break;
                }
                // Exit
                case 3:
                {
                    goto leave;
                    break;
                }
                // Default
                default:
                {
                    cout << "Invalid choice\n";
                    break;
                }
                }
            }
        leave:
            break;
        }
        // Exit
        case 3:
        {
            exit(0);
            break;
        }
        // Default
        default:
        {
            cout << "Invalid choice\n";
            break;
        }
        }
    }
}