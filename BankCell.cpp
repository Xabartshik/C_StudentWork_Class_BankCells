#include "BankCell.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

BankAccount::BankAccount(string accNumber, double amount, string newCurrency, string newOwner)//Создание объекта класса Банковский счёт 
{

    ID = accNumber;
    balance = amount;
    currency = newCurrency;
    owner = newOwner;
}

BankAccount::BankAccount()//Создание объекта класса Банковский счёт (без данных)
{

    ID = "";
    balance = 0;
    currency = "";
    owner = "";
}


string BankAccount::get_ID() //Возвращает регистрационный номер счета в виде строки
{
    return ID;
}

double BankAccount::get_Balance()  //Возвращает баланс счета в виде double
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
void BankAccount::set_Owner(string newOwner)//Изменяет owner  на newOwner
{
    owner = newOwner;
}

void BankAccount::set_ID(string newID)//Изменяет ID  на newID
{
    ID = newID;
}

void BankAccount::set_Currency(string newCurrency)//Изменяет Currency  на newCurrency
{
    currency = newCurrency;
}

string BankAccount::to_string_Balance()//Вывод количества средств в виде строки
{
    string str_balance = "";
    str_balance += std::to_string(balance) + " " + currency;
    return str_balance;
}

string BankAccount::to_string()//Вывод сведений о счете в виде строки
{
    string output = "";
    output += "Владелец: " + owner + "; ";
    output += "Баланс: " + std::to_string(balance) + "; ";
    output += currency;
    output += "Регистрационный номер: " + ID + ";";
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
