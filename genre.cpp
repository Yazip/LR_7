#include <iostream>
#include <string>
#include "genre.h"
using namespace std;
int Genre::genre_count = 0;
// ����������� ��� ����������
Genre::Genre() {
	name = "";
	description = "";
	++genre_count;
}
// ����������� � 1 ����������
Genre::Genre(string name) {
	this->name = name;
	++genre_count;
}
// ����������� �� ����� �����������
Genre::Genre(string name, string description) {
	Genre::setGenreData(name, description);
	++genre_count;
}
// ������
void Genre::setGenreData(string name, string description) {
	this->name = name;
	this->description = description;
}
// ����� ��� ����������������� ����� ������
void Genre::enterGenreData() {
	cout << endl;
	cout << "������� �������� �����:" << endl;
	getline(cin, name);
	cout << "������� �������� �����:" << endl;
	getline(cin, description);
	cout << endl;
	cout << "���� " << name << " ��� ������� ������!" << endl;
}
// ����������� ������ ��� ��������� ���-�� ��������
int Genre::getGenreCount() {
	return genre_count;
}
// ���������� ��������� +: ����������� ������
Genre Genre::operator+(const Genre& other) {
	Genre result;
	result.name = this->name + "-" + other.name;
	result.description = "����������� ��������: 1) " + this->description + " 2) " + other.description;
	return result;
}
// ������ ������ Display ����������� "<<"
ostream& operator<<(ostream& os, const Genre& genre) {
	os << "\n";
	os << "��������: " << genre.name << "\n";
	os << "��������: " << genre.description << "\n";
	return os;
}