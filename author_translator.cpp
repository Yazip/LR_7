#include <iostream>
#include <string>
#include "author_translator.h"
using namespace std;
// ����������� ��� ����������
AuthorTranslator::AuthorTranslator() : Author(), languages("") {}
// ����������� � 1 ����������
AuthorTranslator::AuthorTranslator(string last_name) : Author(last_name) {}
// ����������� �� ����� �����������
AuthorTranslator::AuthorTranslator(string last_name, string initials, string biography, string languages) : Author(last_name, initials, biography), languages(languages) {}
// ������
void AuthorTranslator::setAuthorTranslatorData(string last_name, string initials, string biography, string languages) {
	setAuthorData(last_name, initials, biography);
	this->languages = languages;
}
// ����� ��� ����������������� ����� ������
void AuthorTranslator::enterAuthorTranslatorData() {
	cout << endl;
	cout << "������� ������� ������:" << endl;
	getline(cin, last_name);
	cout << "������� �������� ������:" << endl;
	getline(cin, initials);
	cout << "������� ��������� ������:" << endl;
	getline(cin, biography);
	cout << "������� �����, ������� ������������ �������-������������:" << endl;
	getline(cin, languages);
	cout << endl;
	cout << "�����-���������� " << last_name << " " << initials << " ��� ������� ������!" << endl;
}
// ������ (���������� ������ �������� ������ � ������� ������ �������� ������)
void AuthorTranslator::getAuthorTranslatorData() {
	Author::getAuthorData();
	cout << "�����: " << languages << endl;
}
// ������ (���������� ������ �������� ������ ��� ������ ������ �������� ������)
void AuthorTranslator::getAuthorData() {
	cout << endl;
	cout << "���������� �� ������:" << endl;
	cout << "�������: " << last_name << endl;
	cout << "��������: " << initials << endl;
	cout << "���������: " << biography << endl;
	cout << "�����: " << languages << endl;
}
// ���������� ��������� ������������ ������� ������������ ������ �������� �������� ������
AuthorTranslator& AuthorTranslator::operator=(const Author& other) {
	if (this != &other) {
		*static_cast<Author*>(this) = other;
	}
	return *this;
}