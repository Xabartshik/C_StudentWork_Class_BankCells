#include "BankCell.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
///������� �����, ���-22
BankAccount::BankAccount(string accNumber, double amount, string newCurrency, string newOwner)//�������� ������� ������ ���������� ���� 
{

        set_Balance(amount);
        set_Currency(newCurrency);
        set_Owner(newOwner);
        set_ID(accNumber);
}

BankAccount::BankAccount()//�������� ������� ������ ���������� ���� (��� ������)
{

    set_Balance(0);
    set_Currency("");
    set_Owner("");
    set_ID("");
}


string BankAccount::get_ID() const //���������� ��������������� ����� ����� � ���� ������
{
    return ID;
}

string BankAccount::get_Owner() const //���������� ������� ����� � ���� ������
{
    return owner;
}

string BankAccount::get_Currency() const //���������� ������ � ���� ������
{
    return currency;
}


double BankAccount::get_Balance() const //���������� ������ ����� � ���� double
{
    return balance;
}

void BankAccount::deposit(double amount) //��������� amount �� balance ����� 
{
    balance += amount;
    cout << "���� �������� �� " << amount << endl;
}

void BankAccount::withdraw(double amount) //������� amount � balance �����. ���� ������������ - �����, ��� ������������ �������
//todo: ��������, ����� ������� ������������� ����� ������ ��� 35 ��������� �������
{
    if (amount <= balance)
    {
        balance -= amount;
    }
    else
    {
        throw std::invalid_argument("������������ ������� �� �����");
    }
}
void BankAccount::set_Owner(const string & newOwner)//�������� owner  �� newOwner
{
    owner = newOwner;
}

void BankAccount::set_ID(const string & newID)//�������� ID  �� newID
{
    ID = newID;
}

void BankAccount::set_Currency(const string & newCurrency)//�������� Currency  �� newCurrency
{
    currency = newCurrency;
}

string BankAccount::to_string_Balance()const//����� ���������� ������� � ���� ������
{
    string str_balance = "";
    str_balance += std::to_string(balance) + " " + currency;
    return str_balance;
}

string BankAccount::to_string()const//����� �������� � ����� � ���� ������
{
    string output = "";
    output += "��������: " + owner + "; ";
    output += "������: " + std::to_string(balance) + " ";
    output += currency;
    output += " ��������������� �����: " + ID + ";";
    return output;
}
void BankAccount::set_Balance(double newBalance)//�������� balance  �� newBalance
{
    balance = newBalance;
}




void displayAccountsList(vector<BankAccount> accounts)//������� �� ����� ��� ��������� �����
{
    for (int i = 0; i < accounts.size(); i++)
    {

        cout << "���� �����: " << i + 1 << endl;
        cout << accounts[i].to_string();
        cout << endl;

    }
}

//���������� �������� � ����
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
        throw runtime_error("�� ������� ������� ���� ��� ����������");
    }
}

//�������� ������� �������� �� �����
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
        throw runtime_error("�� ������� ������� ���� ��� ��������");
    }

    return accounts;
}
//�������� ������������� ������� ��������
void fillDynamicArray(BankAccount** dynamicArray, int size) {
    for (int i = 0; i < size; i++) {
        string accNumber;
        double amount;
        string newCurrency;
        string newOwner;

        // ���� ������ ��� �������� �������
        cout << "������� ��������������� ����� �����: ";
        cin >> accNumber;
        cout << "������� ��������� �������� �������: ";
        cin >> amount;
        cout << "������� ��� ������: ";
        cin >> newCurrency;
        cout << "������� ��� �������: ";
        cin >> newOwner;

        // �������� ������� � ������� ������������
        BankAccount* newAccount = new BankAccount(accNumber, amount, newCurrency, newOwner);

        // ���������� ��������� �� ������ � ������������ �������
        dynamicArray[i] = newAccount;
    }
}
///�������� ���������������� ������
void test_Class()
{
    BankAccount test_acc("444", 8800, "����", "�� �� ���");
    double test = test_acc.get_Balance();
    assert(abs(test - 8800) <= 0.0000000001);
    string test_str = test_acc.get_ID();
    assert(test_str == "444");
    string test_str = test_acc.get_Owner();
    assert(test_str == "�� �� ���");
    string test_str = test_acc.get_Currency();
    assert(test_str == "����");


}