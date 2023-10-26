#ifndef BANKCELL_H
#define BANKCELL_H

#include <string>
#include <vector>

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
    string get_ID(); //Возвращает регистрационный номер счета в виде строки
    double get_Balance(); //Возвращает баланс счета в виде double
    void deposit(double amount);//Добавляет amount на balance счета 
    void withdraw(double amount);//Снимает amount с balance счета. Если недостаточно - пишет, что недостаточно средств
//todo: Написать, чтобы функция автоматически брала кредит под 35 процентов годовых
    void set_Owner(string newOwner);//Изменяет owner  на newOwner
    void set_Currency(string newCurrency);//Изменяет Currency  на newCurrency
    void set_ID(string newID);//Изменяет ID  на newID
    void set_Balance(double newBalance);//Изменяет balance  на newBalance
    string to_string_Balance();//Вывод количества средств на экран
    string to_string();//Вывод сведений о счете на экран


};

void displayAccountsList(vector<BankAccount> accounts);//Выводит на экран все созданные счета
//Загрузка массива объектов из файла
vector<BankAccount> loadAccounts(const string& filename);
//Сохранение объектов в файл
void saveAccounts(const vector<BankAccount>& accounts, const string& filename);
#endif