#include <iostream>
#include <list>
using namespace std;
class BankAcc
{
public:
    int accountNumber;
    double balance;
    double interestRate;
    BankAcc(int accNum, double bal, double intRate)
    {
        accountNumber = accNum;
        balance = bal;
        interestRate = intRate;
    }
    void deposit(int dep)
    {
        balance += dep;
    }
    void withdraw(double sum)
    {
        balance = 0;
    }
    double getBalance()
    {
        return balance;
    }
    double getInterest()
    {
        double rate = balance * interestRate * (1 / 12);
        return rate;
    }
    void setInterestRate(double intRate)
    {
        interestRate = intRate;
    }
    int getAccountNumber()
    {
        return accountNumber;
    };
};
bool transfer(BankAcc& in, BankAcc& out, double sum) {
    if (out.balance >= sum) {
        out.balance = out.balance - sum;
        in.balance = in.balance + sum;
        return true;
    }
    else {
        return false;
    }
}
void displayMenu()
{
    cout << "Добро пожаловать в систему управления банковским счетом" << endl;
    cout << "1. Внести деньги" << endl;
    cout << "2. Снять деньги" << endl;
    cout << "3. Проверить баланс" << endl;
    cout << "4. Рассчитать проценты" << endl;
    cout << "5. Перевести средства" << endl;
    cout << "6. Выход" << endl;
    cout << "Пожалуйста, выберите опцию: ";
}

int main()
{
    setlocale(LC_ALL, "Rus");
    BankAcc account1(12345, 1000.00, 0.05);
    BankAcc account2(54321, 500.00, 0.04);

    int choice;
    double amount;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Введите сумму для пополнения";
            cin >> amount;
            account1.deposit(amount);
            cout << "Внесение прошло успешно. Текущий баланс: " << account1.getBalance() << endl;
            break;
        case 2:
            cout << "Введите сумму для вывода: ";
            cin >> amount;
            account1.withdraw(amount);
            cout << "Снятие прошло успешно. Текущий баланс: " << account1.getBalance() << endl;
            break;
        case 3:
            cout << "Текущий баланс: " << account1.getBalance() << endl;
            break;
        case 4:
            cout << "Проценты за месяц: " << account1.getInterest() << endl;
            break;
        case 5:
            cout << "Введите сумму для перевода: ";
            cin >> amount;
            if (transfer(account1, account2, amount))
            {
                cout << "Перевод прошел успешно." << endl;
            }
            else
            {
                cout << "Недостаточно средств для перевода." << endl;
            }
            break;
        case 6:
            cout << "Завершение программы. До свидания!" << endl;
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}
