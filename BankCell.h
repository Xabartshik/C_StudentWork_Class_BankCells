#pragma once

#include <string>
#include <vector>
///������� �����, ���-22
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
    string get_ID() const; //���������� ��������������� ����� ����� � ���� ������
    string get_Owner()const; //���������� ������� ����� � ���� ������
    string get_Currency()const; //���������� ������ � ���� ������
    double get_Balance()const; //���������� ������ ����� � ���� double
    void deposit(double amount);//��������� amount �� balance ����� 
    void withdraw(double amount);//������� amount � balance �����. ���� ������������ - �����, ��� ������������ �������
    //todo: ��������, ����� ������� ������������� ����� ������ ��� 35 ��������� �������
    void set_Owner(const string & newOwner);//�������� owner  �� newOwner
    void set_Currency(const string & newCurrency);//�������� Currency  �� newCurrency
    void set_ID(const string & newID);//�������� ID  �� newID
    void set_Balance(double newBalance);//�������� balance  �� newBalance
    string to_string_Balance()const;//����� ���������� ������� �� �����
    string to_string()const;//����� �������� � ����� �� �����


};

void displayAccountsList(vector<BankAccount> accounts);//������� �� ����� ��� ��������� �����
//�������� ������� �������� �� �����
vector<BankAccount> loadAccounts(const string& filename);
//���������� �������� � ����
void saveAccounts(const vector<BankAccount>& accounts, const string& filename);
//�������� ������������� ������� ��������
void fillDynamicArray(BankAccount** dynamicArray, int size);
///�������� ���������������� ������
void test_Class();