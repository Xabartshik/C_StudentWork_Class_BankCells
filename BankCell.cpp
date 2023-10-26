#include "BankCell.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

BankAccount::BankAccount(string accNumber, double amount, string newCurrency, string newOwner)//�������� ������� ������ ���������� ���� 
{

    ID = accNumber;
    balance = amount;
    currency = newCurrency;
    owner = newOwner;
}

BankAccount::BankAccount()//�������� ������� ������ ���������� ���� (��� ������)
{

    ID = "";
    balance = 0;
    currency = "";
    owner = "";
}


string BankAccount::get_ID() //���������� ��������������� ����� ����� � ���� ������
{
    return ID;
}

double BankAccount::get_Balance()  //���������� ������ ����� � ���� double
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
void BankAccount::set_Owner(string newOwner)//�������� owner  �� newOwner
{
    owner = newOwner;
}

void BankAccount::set_ID(string newID)//�������� ID  �� newID
{
    ID = newID;
}

void BankAccount::set_Currency(string newCurrency)//�������� Currency  �� newCurrency
{
    currency = newCurrency;
}

string BankAccount::to_string_Balance()//����� ���������� ������� � ���� ������
{
    string str_balance = "";
    str_balance += std::to_string(balance) + " " + currency;
    return str_balance;
}

string BankAccount::to_string()//����� �������� � ����� � ���� ������
{
    string output = "";
    output += "��������: " + owner + "; ";
    output += "������: " + std::to_string(balance) + "; ";
    output += currency;
    output += "��������������� �����: " + ID + ";";
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
