#pragma once

#include <string>
#include <vector>
///Ошлаков Данил, ИВТ-22
using namespace std;
//Класс для обьекта Банковский счет
class BankAccount {
private:
    string ID;//Регистрационный номер счёта
    string owner;//Хозяин счёта
    double balance;//Баланс на счету
    string currency;//Тип валюты


public:
    BankAccount(string accNumber, double amount, string newCurrency, string newOwner);//Создание объекта класса Банковский счёт 
    BankAccount();//Создание объекта класса Банковский счёт (без данных)
    string get_ID() const; //Возвращает регистрационный номер счета в виде строки
    string get_Owner()const; //Возвращает хозяина счета в виде строки
    string get_Currency()const; //Возвращает валюту в виде строки
    double get_Balance()const; //Возвращает баланс счета в виде double
    void deposit(double amount);//Добавляет amount на balance счета 
    void withdraw(double amount);//Снимает amount с balance счета. Если недостаточно - пишет, что недостаточно средств
    //todo: Написать, чтобы функция автоматически брала кредит под 35 процентов годовых
    void set_Owner(const string & newOwner);//Изменяет owner  на newOwner
    void set_Currency(const string & newCurrency);//Изменяет Currency  на newCurrency
    void set_ID(const string & newID);//Изменяет ID  на newID
    void set_Balance(double newBalance);//Изменяет balance  на newBalance
    string to_string_Balance()const;//Вывод количества средств на экран
    string to_string()const;//Вывод сведений о счете на экран


};

void displayAccountsList(vector<BankAccount> accounts);//Выводит на экран все созданные счета
//Загрузка массива объектов из файла
vector<BankAccount> loadAccounts(const string& filename);
//Сохранение объектов в файл
void saveAccounts(const vector<BankAccount>& accounts, const string& filename);
//Создание динамического массива объектов
void fillDynamicArray(BankAccount** dynamicArray, int size);
///Проверка работоспобсности класса
void test_Class();