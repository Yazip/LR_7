#pragma once
#include <string>
using namespace std;
// ����� ����
class Genre {
private:
	string name;
	string description;
	static int genre_count;
public:
	Genre(); // ����������� ��� ����������
	Genre(string name); // ����������� � 1 ����������
	Genre(string name, string description); // ����������� �� ����� �����������
	void setGenreData(string name, string description); // ������
	void enterGenreData(); // ����� ��� ����������������� ����� ������
	static int getGenreCount(); // ����������� ������ ��� ��������� ���-�� ��������
	Genre operator+(const Genre& other); // ���������� ��������� +: ����������� ������
	friend ostream& operator<<(ostream& os, const Genre& genre); // ������ ������ Display ����������� "<<"
};