#include <iostream>

using namespace std;

class Bank {
protected:
    double balance;
public:
    virtual double getBalance()=0;
    virtual void addMoney(size_t money)=0;
    virtual void withdraw(size_t money)=0;
};

class LocalBank : public Bank {
    double BankId;
public:
    LocalBank(double id) {
        BankId = id;
    }
    double getBalance() override {
        return balance;
    }
    void addMoney(size_t money) override {
        balance += money;
    }
    void withdraw(size_t money)override{
        balance -= money;
    }
};

class Proxy : public Bank {
    Bank* _bank;
public:
    Proxy(Bank* bank) {
        _bank = bank;
    }
    double getBalance() override {
        return _bank->getBalance();
    }
    void addMoney(size_t money) override {
        cout << "Proxy: you don't have permission to add money!" << endl;
    }
    void withdraw(size_t money) override {
        cout << "Proxy: you don't have permission to withdraw money!" << endl;
    }
};


// int main() {
//     Bank* myBank = new LocalBank(123);
//     Bank* bank = new Proxy(myBank);
//     cout<<"Choose activity: 1.Add money to your account\n 2.get money\n 3.exit\n ";
//     int x;
//     cin>>x;
//     switch (x)
//     {
//     case 1:
//         cout<<"Type ampunt of money: ";
//         double i;
//         cin>>i;
//         myBank->addMoney(i);
//         cout << "Your balance is: " << bank->getBalance() << endl;
//         break;
//     case 2:

//         break;
//     default:
//         break;
//     }
//     cout << "Your balance is: " << bank->getBalance() << endl;
//     bank->addMoney(1500);
// }
