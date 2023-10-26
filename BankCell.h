#pragma once

#include <string>
#include <vector>

using namespace std;
//����� ��� ������� ���������� ����
class BankAccount {
private:
    string ID;//��������������� ����� �����
    string owner;//������ �����
    double balance;//������ �� �����
    string currency;//��� ������


public:
    BankAccount(string accNumber, double amount, string newCurrency, string newOwner);//�������� ������� ������ ���������� ���� 
    BankAccount();//�������� ������� ������ ���������� ���� (��� ������)
    string get_ID(); //���������� ��������������� ����� ����� � ���� ������
    double get_Balance(); //���������� ������ ����� � ���� double
    void deposit(double amount);//��������� amount �� balance ����� 
    void withdraw(double amount);//������� amount � balance �����. ���� ������������ - �����, ��� ������������ �������
    //todo: ��������, ����� ������� ������������� ����� ������ ��� 35 ��������� �������
    void set_Owner(string newOwner);//�������� owner  �� newOwner
    void set_Currency(string newCurrency);//�������� Currency  �� newCurrency
    void set_ID(string newID);//�������� ID  �� newID
    void set_Balance(double newBalance);//�������� balance  �� newBalance
    string to_string_Balance();//����� ���������� ������� �� �����
    string to_string();//����� �������� � ����� �� �����


};

void displayAccountsList(vector<BankAccount> accounts);//������� �� ����� ��� ��������� �����
//�������� ������� �������� �� �����
vector<BankAccount> loadAccounts(const string& filename);
//���������� �������� � ����
void saveAccounts(const vector<BankAccount>& accounts, const string& filename);