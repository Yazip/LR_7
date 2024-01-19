#include <iostream>
#include <string>
#include <algorithm>
#include "magazine.h"
using namespace std;
int Magazine::magazine_count = 0;
// ����������� ��� ����������
Magazine::Magazine() {
	publisher_name = "";
	title = "";
	frequency = "";
	page_count = 0;
	price = 0.0f;
	++magazine_count;
}
// ����������� � 1 ����������
Magazine::Magazine(string title) {
	this->title = title;
	++magazine_count;
}
// ����������� �� ����� �����������
Magazine::Magazine(string publisher_name, string title, string frequency, int page_count, float price) {
	Magazine::setMagazineData(publisher_name, title, frequency, page_count, price);
	++magazine_count;
}
// ������
void Magazine::setMagazineData(string publisher_name, string title, string frequency, int page_count, float price) {
	this->publisher_name = publisher_name;
	this->title = title;
	this->frequency = frequency;
	this->page_count = page_count;
	this->price = price;
}
// ����� ��� ����������������� ����� ������
void Magazine::enterMagazineData() {
	cout << endl;
	cout << "������� �������� ��������:" << endl;
	getline(cin, publisher_name);
	cout << "������� �������� �������:" << endl;
	getline(cin, title);
	cout << "������� �������������:" << endl;
	getline(cin, frequency);
	cout << "������� ���-�� ������� (�� ������ 0):" << endl;
	while ((cin >> page_count).fail() || (0 > page_count)) {
		cin.clear();
		cout << "������. ������� ���-�� ������� (�� ������ 0):" << endl;
		cin.ignore();
	}
	cin.ignore();
	cout << "������� ���� (�� ������ 0):" << endl;
	while ((cin >> price).fail() || (0.0f > price)) {
		cin.clear();
		cout << "������. ������� ���� (�� ������ 0):" << endl;
		cin.ignore();
	}
	cin.ignore();
	cout << endl;
	cout << "������ " << title << " ��� ������� ������!" << endl;
}
// ������
void Magazine::getMagazineData() {
	cout << endl;
	cout << "���������� � �������:" << endl;
	cout << "��������: " << publisher_name << endl;
	cout << "�������� �������: " << title << endl;
	cout << "�������������: " << frequency << endl;
	cout << "���-�� �������: " << page_count << endl;
	cout << "����: " << price << endl;
}
// ����� ��� ��������� �������� ��������
bool Magazine::isPublisherNamesSame(string publisher_name) {
	// �������� ����� �������� �������� ��� ������ (����� �� ������� �� �������������� ��� �-�� transform)
	string publisher_name_field_copy = this->publisher_name;
	string publisher_name_param_copy = publisher_name;
	// ���������� ����� � ������ ��������
	transform(publisher_name_field_copy.begin(), publisher_name_field_copy.end(), publisher_name_field_copy.begin(), tolower);
	transform(publisher_name_param_copy.begin(), publisher_name_param_copy.end(), publisher_name_param_copy.begin(), tolower);
	// ������� ���������� ���������
	return (publisher_name_field_copy == publisher_name_param_copy);
}
// ����������� ������ ��� ��������� ���-�� ��������
int Magazine::getMagazineCount() {
	return magazine_count;
}
// ��������������� ������������ ������ �� �������� ������������ ������
void Magazine::read() {
	cout << "������ ��������" << endl;
}
// ������� ������ �������� �� ��������
void findMagazinesByPublisher(Magazine magazines[], int magazine_count, string publisher_name) {
	Magazine found_magazines[300];
	int j = 0;
	for (int i = 0; i < magazine_count; i++) {
		if (magazines[i].isPublisherNamesSame(publisher_name)) {
			found_magazines[j] = magazines[i];
			++j;
		}
	}
	if (j) {
		cout << endl;
		cout << "������� " << j << " �������� �������� " << publisher_name << ":" << endl;
		for (int k = 0; k < j; k++) {
			cout << endl;
			cout << "������ " << (k + 1) << endl;
			cout << endl;
			found_magazines[k].getMagazineData();
			cout << "-------------------------" << endl;
		}
	}
	else {
		cout << endl;
		cout << "������ �� �������!" << endl;
	}
}