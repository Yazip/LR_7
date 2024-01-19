#pragma once
#include <iostream>
#include <string>
using namespace std;
// ����� ��������
template <typename T>
class Publisher {
private:
	string name;
	string address;
	T phone_num;
	string email;
	static int publisher_count;
public:
	Publisher(); // ����������� ��� ����������
	Publisher(string name); // ����������� � 1 ����������
	Publisher(string name, string address, T phone_num, string email); // ����������� �� ����� �����������
	void setPublisherData(string name, string address, T phone_num, string email); // ������
	void enterPublisherData(); // ����� ��� ����������������� ����� ������
	void getPublisherData(); // ������
	static int getPublisherCount(); // ����������� ������ ��� ��������� ���-�� ��������
};
template <typename T>
int Publisher<T>::publisher_count = 0;
// ����������� ��� ����������
template <typename T>
Publisher<T>::Publisher() {
	name = "";
	address = "";
	email = "";
	++publisher_count;
}
// ����������� � 1 ����������
template <typename T>
Publisher<T>::Publisher(string name) {
	try {
		if (name.empty()) {
			throw invalid_argument("�������� �� ����� ���� ������");
		}
		this->name = name;
		++publisher_count;
	}
	catch (const invalid_argument& e) {
		cout << "������������ ��������: " << e.what() << endl;
	}
}
// ����������� �� ����� �����������
template <typename T>
Publisher<T>::Publisher(string name, string address, T phone_num, string email) {
	Publisher::setPublisherData(name, address, phone_num, email);
	++publisher_count;
}
// ������
template <typename T>
void Publisher<T>::setPublisherData(string name, string address, T phone_num, string email) {
	this->name = name;
	this->address = address;
	this->phone_num = phone_num;
	this->email = email;
}
// ����� ��� ����������������� ����� ������
template <typename T>
void Publisher<T>::enterPublisherData() {
	cout << endl;
	cout << "������� �������� ��������:" << endl;
	getline(cin, name);
	cout << "������� ����� ��������:" << endl;
	getline(cin, address);
	cout << "������� ����� �������� ��������:" << endl;
	getline(cin, phone_num);
	cout << "������� ����������� ����� ��������:" << endl;
	getline(cin, email);
	cout << endl;
	cout << "�������� " << name << " ��� ������� ������!" << endl;
}
// ������
template <typename T>
void Publisher<T>::getPublisherData() {
	cout << endl;
	cout << "���������� �� ��������:" << endl;
	cout << "��������: " << name << endl;
	cout << "�����: " << address << endl;
	cout << "����� ��������: " << phone_num << endl;
	cout << "����������� �����: " << email << endl;
}
// ����������� ������ ��� ��������� ���-�� ��������
template <typename T>
int Publisher<T>::getPublisherCount() {
	return publisher_count;
}