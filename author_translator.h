#pragma once
#include <string>
#include "author.h"
using namespace std;
// ����� �����-����������, ��������� ������ �����
class AuthorTranslator : public Author {
private:
	string languages;
public:
	AuthorTranslator(); // ����������� ��� ����������
	AuthorTranslator(string last_name); // ����������� � 1 ����������
	AuthorTranslator(string last_name, string initials, string biography, string languages); // ����������� �� ����� �����������
	void setAuthorTranslatorData(string last_name, string initials, string biography, string languages); // ������
	void enterAuthorTranslatorData(); // ����� ��� ����������������� ����� ������
	void getAuthorTranslatorData(); // ������ (���������� ������ �������� ������ � ������� ������ �������� ������)
	void getAuthorData() override; // ������ (���������� ������ �������� ������ ��� ������ ������ �������� ������)
	AuthorTranslator& operator=(const Author& other); // ���������� ��������� ������������ ������� ������������ ������ �������� �������� ������
};