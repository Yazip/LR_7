#include <iostream>
#include <string>
#include "author.h"
using namespace std;
int Author::author_count = 0;
// ����������� ��� ����������
Author::Author() {
	last_name = "";
	initials = "";
	biography = "";
	++author_count;
}
// ����������� � 1 ����������
Author::Author(string last_name) {
	this->last_name = last_name;
	++author_count;
}
// ����������� �� ����� �����������
Author::Author(string last_name, string initials, string biography) {
	Author::setAuthorData(last_name, initials, biography);
	++author_count;
}
// ������
void Author::setAuthorData(string last_name, string initials, string biography) {
	this->last_name = last_name;
	this->initials = initials;
	this->biography = biography;
}
// ����� ��� ����������������� ����� ������
void Author::enterAuthorData() {
	cout << endl;
	cout << "������� ������� ������:" << endl;
	getline(cin, last_name);
	cout << "������� �������� ������:" << endl;
	getline(cin, initials);
	cout << "������� ��������� ������:" << endl;
	getline(cin, biography);
	cout << endl;
	cout << "����� " << last_name << " " << initials << " ��� ������� ������!" << endl;
}
// ������
void Author::getAuthorData() {
	cout << endl;
	cout << "���������� �� ������:" << endl;
	cout << "�������: " << last_name << endl;
	cout << "��������: " << initials << endl;
	cout << "���������: " << biography << endl;
}
// ����������� ������ ��� ��������� ���-�� ��������
int Author::getAuthorCount() {
	return author_count;
}
// ������ ��� ��������� ������� ������ ����� ���������
void Author::getAuthorLastNamePtr(string* last_name) {
	*last_name = this->last_name;
}
// ������ ��� ��������� ������� ������ ����� ������
void Author::getAuthorLastNameRef(string& last_name) {
	last_name = this->last_name;
}
// ������ ��� ��������� ������� ������ � ��������� ����
string Author::getAuthorLastName() {
	return last_name;
}
// ������������� �-�� ��������� ��������� ������
void getAuthorBiography(const Author& author) {
	cout << "��������� ������ �����: " << author.biography << endl;
}
// ���������� ��������� "=" �������� ������
Author& Author::operator=(const Author& other) {
	if (this != &other) {
		last_name = other.last_name;
		initials = other.initials;
		biography = other.biography;
	}
	return *this;
}