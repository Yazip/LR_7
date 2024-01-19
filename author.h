#pragma once
#include <string>
using namespace std;
// ����� �����
class Author {
protected:
	string last_name;
	string initials;
	string biography;
	static int author_count;
public:
	Author(); // ����������� ��� ����������
	Author(string last_name); // ����������� � 1 ����������
	Author(string last_name, string initials, string biography); // ����������� �� ����� �����������
	void setAuthorData(string last_name, string initials, string biography); // ������
	void enterAuthorData(); // ����� ��� ����������������� ����� ������
	virtual void getAuthorData(); // ������
	static int getAuthorCount(); // ����������� ������ ��� ��������� ���-�� ��������
	void getAuthorLastNamePtr(string* last_name); // ������ ��� ��������� ������� ������ ����� ���������
	void getAuthorLastNameRef(string& last_name); // ������ ��� ��������� ������� ������ ����� ������
	string getAuthorLastName(); // ������ ��� ��������� ������� ������ � ��������� ����
	friend void getAuthorBiography(const Author&); // ������������� �-�� ��������� ��������� ������
	Author& operator=(const Author& other); // ���������� ��������� "=" �������� ������
};