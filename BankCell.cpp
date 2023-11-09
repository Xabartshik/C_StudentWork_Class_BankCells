#include "BankCell.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
///Ошлаков Данил, ИВТ-22
BankAccount::BankAccount(string accNumber, double amount, string newCurrency, string newOwner)//Создание объекта класса Банковский счёт 
{

        set_Balance(amount);
        set_Currency(newCurrency);
        set_Owner(newOwner);
        set_ID(accNumber);
}

BankAccount::BankAccount()//Создание объекта класса Банковский счёт (без данных)
{

    set_Balance(0);
    set_Currency("");
    set_Owner("");
    set_ID("");
}


string BankAccount::get_ID() const //Возвращает регистрационный номер счета в виде строки
{
    return ID;
}

string BankAccount::get_Owner() const //Возвращает хозяина счета в виде строки
{
    return owner;
}

string BankAccount::get_Currency() const //Возвращает валюту в виде строки
{
    return currency;
}


double BankAccount::get_Balance() const //Возвращает баланс счета в виде double
{
    return balance;
}

void BankAccount::deposit(double amount) //Добавляет amount на balance счета 
{
    balance += amount;
    cout << "Счёт пополнен на " << amount << endl;
}

void BankAccount::withdraw(double amount) //Снимает amount с balance счета. Если недостаточно - пишет, что недостаточно средств
//todo: Написать, чтобы функция автоматически брала кредит под 35 процентов годовых
{
    if (amount <= balance)
    {
        balance -= amount;
    }
    else
    {
        throw std::invalid_argument("Недостаточно средств на счете");
    }
}
void BankAccount::set_Owner(const string & newOwner)//Изменяет owner  на newOwner
{
    owner = newOwner;
}

void BankAccount::set_ID(const string & newID)//Изменяет ID  на newID
{
    ID = newID;
}

void BankAccount::set_Currency(const string & newCurrency)//Изменяет Currency  на newCurrency
{
    currency = newCurrency;
}

string BankAccount::to_string_Balance()const//Вывод количества средств в виде строки
{
    string str_balance = "";
    str_balance += std::to_string(balance) + " " + currency;
    return str_balance;
}

string BankAccount::to_string()const//Вывод сведений о счете в виде строки
{
    string output = "";
    output += "Владелец: " + owner + "; ";
    output += "Баланс: " + std::to_string(balance) + " ";
    output += currency;
    output += " Регистрационный номер: " + ID + ";";
    return output;
}
void BankAccount::set_Balance(double newBalance)//Изменяет balance  на newBalance
{
    balance = newBalance;
}




void displayAccountsList(vector<BankAccount> accounts)//Выводит на экран все созданные счета
{
    for (int i = 0; i < accounts.size(); i++)
    {

        cout << "Счет номер: " << i + 1 << endl;
        cout << accounts[i].to_string();
        cout << endl;

    }
}

//Сохранение объектов в файл
void saveAccounts(const vector<BankAccount>& accounts, const string& filename)
{
    ofstream file(filename, ios::binary);

    if (file.is_open()) {
        for (const BankAccount& account : accounts) {
            file.write(reinterpret_cast<const char*>(&account), sizeof(BankAccount));
        }

        file.close();
    }
    else {
        throw runtime_error("Не удалось открыть файл для сохранения");
    }
}

//Загрузка массива объектов из файла
vector<BankAccount> loadAccounts(const string& filename)
{

    vector<BankAccount> accounts;
    ifstream file(filename, ios::binary);

    if (file.is_open())
    {
        BankAccount account;
        while (file.read(reinterpret_cast<char*>(&account), sizeof(BankAccount)))
        {
            accounts.push_back(account);
        }

        file.close();
    }
    else
    {
        throw runtime_error("Не удалось открыть файл для загрузки");
    }

    return accounts;
}
//Создание динамического массива объектов
void fillDynamicArray(BankAccount** dynamicArray, int size) {
    for (int i = 0; i < size; i++) {
        string accNumber;
        double amount;
        string newCurrency;
        string newOwner;

        // Ввод данных для создания объекта
        cout << "Введите регистрационный номер счёта: ";
        cin >> accNumber;
        cout << "Введите начальное значение баланса: ";
        cin >> amount;
        cout << "Введите тип валюты: ";
        cin >> newCurrency;
        cout << "Введите ФИО хозяина: ";
        cin >> newOwner;

        // Создание объекта с помощью конструктора
        BankAccount* newAccount = new BankAccount(accNumber, amount, newCurrency, newOwner);

        // Сохранение указателя на объект в динамическом массиве
        dynamicArray[i] = newAccount;
    }
}
///Проверка работоспобсности класса
void test_Class()
{
    BankAccount test_acc("444", 8800, "Йена", "Ли Си Цын");
    double test = test_acc.get_Balance();
    assert(abs(test - 8800) <= 0.0000000001);
    string test_str = test_acc.get_ID();
    assert(test_str == "444");
    string test_str = test_acc.get_Owner();
    assert(test_str == "Ли Си Цын");
    string test_str = test_acc.get_Currency();
    assert(test_str == "Йена");


}