//Это та самая рабочая версия, написанная на UTF-8. И хер я больше в саблайм зайду, где UTF-8 - гребанная ISO-88592-1

#include <iostream>
#include <vector>
#include <locale.h>
#include "BankCell.h"
#include <windows.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    vector<BankAccount> accounts;//Вектор для хранения нескольких объектов класса BankAccount
    accounts.push_back(BankAccount("100", 1000.0, "Рупия", "Иван"));
    accounts.push_back(BankAccount("101", 1500.0, "Юань", "Наташа"));
    int choice;//Переменная выбора действий для работы со счетами
    int choice_edit;//Переменная выбора действий для работы с изменением счета
    double amount;//Переменная для деняк
    string newID;//Переменная для ввода регистрационного счёта
    string newOwner;//Переменная для ввода нового хозяина счета
    string newCurrency;//Переменная для ввода нового хозяина счета
    int accountIndex;//Переменная для работы с вектором счетов
    string filename;//Переменная для ввода/вывода массива обьектов в файл
    do {


        cout << "Работа с банковским счётом" << endl;
        cout << "1. Отобразить список счетов" << endl;
        cout << "2. Положить средства" << endl;
        cout << "3. Снять средства" << endl;
        cout << "4. Отобразить баланс" << endl;
        cout << "5. Создать новый счет" << endl;
        cout << "6. Удалить счет" << endl;
        cout << "7. Изменение информации о счете" << endl;
        cout << "8. Загрузка из файла" << endl;
        cout << "9. Сохранение в файл" << endl;
        cout << "10. Выход" << endl;
        cout << "Введите ваш выбор: " << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Существующие счета: " << endl;
            cout << endl;
            displayAccountsList(accounts);
            break;
        case 2:
            cout << "Введите номер аккаунта: " << endl;
            accountIndex--;
            cout << "Введите количество средств, которые вы желаете положить на счет: " << endl;
            cin >> amount;
            accounts[accountIndex].deposit(amount);
            break;
        case 3:
            cout << "Введите номер аккаунта: " << endl;
            cin >> accountIndex;
            accountIndex--;
            cout << "Введите количество средств, которые вы желаете снять со счета: " << endl;
            cin >> amount;
            accounts[accountIndex].withdraw(amount);
            break;
        case 4:
            cout << "Введите номер аккаунта: " << endl;
            cin >> accountIndex;
            accountIndex--;
            accounts[accountIndex].to_string_Balance();
            break;
        case 5:

            cout << "Введите регистрационный номер: " << endl;
            cin >> newID;
            cout << "Введите ФИО владельца: " << endl;
            cin >> newOwner;
            cout << "Введите баланс на счете: " << endl;
            cin >> amount;
            cout << "Введите валюту: " << endl;
            cin >> newCurrency;
            accounts.push_back(BankAccount(newID, amount, newCurrency, newOwner));

            break;
        case 6:
            cout << "Введите номер аккаунта: " << endl;
            cin >> accountIndex;
            accountIndex--;
            accounts.erase(accounts.begin() + accountIndex);
            cout << "Удаление прошло успешно" << endl;
            break;
        case 7:
            cout << "Введите номер аккаунта: " << endl;
            cin >> accountIndex;
            accountIndex--;

            do {
                cout << "Работа с изменением значений банковского счета" << endl;
                cout << "1. Изменить регистрационный счет" << endl;
                cout << "2. Изменить ФИО владельца" << endl;
                cout << "3. Изменить баланс" << endl;
                cout << "4. Изменить валюту" << endl;
                cout << "5. Выход" << endl;
                cin >> choice_edit;
                switch (choice_edit) {
                case 1:
                    cout << "Введите новый регистрационный счет: " << endl;
                    cin >> newID;
                    accounts[accountIndex].set_ID(newID);

                    break;
                case 2:
                    cout << "Введите ФИО нового владельца: " << endl;
                    cin >> newOwner;
                    accounts[accountIndex].set_Owner(newOwner);
                    break;
                case 3:
                    cout << "Введите новое значение баланса: " << endl;
                    cin >> amount;
                    accounts[accountIndex].set_Balance(amount);
                    break;
                case 4:
                    cout << "Введите новую валюту: " << endl;
                    cin >> newCurrency;
                    accounts[accountIndex].set_Currency(newCurrency);
                    break;
                case 5:
                    cout << "Завершение редактирования информации о счете" << endl;
                    break;
                }
            } while (choice_edit != 5);


            break;
        case 8:
            cout << "Введите название файла ввода" << endl;
            cin >> filename;
            loadAccounts(filename);
            cout << "Загрузка завершена успешно" << endl;
            break;
        case 9:
            cout << "Введите название файла вывода" << endl;
            cin >> filename;
            saveAccounts(accounts, filename);
            cout << "Сохранение завершено успешно" << endl;
            break;
        case 10:

            cout << "Конец программы. Прощайте." << endl;
            break;
        default:
            cout << "Неизвестный параметр выбора. Попробуйте снова." << endl;
            break;
        }

        cout << endl;
    } while (choice != 10);

    return 0;
}