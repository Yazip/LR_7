#pragma once
#include <string>
#include "publication.h"
using namespace std;
// ����� �����
class Book : public Publication {
private:
	string author_last_name;
	string author_initials;
	string title;
	string genre_name;
	int page_count;
	static int book_count;
public:
	Book(); // ����������� ��� ����������
	Book(string title); // ����������� � 1 ����������
	Book(string author_last_name, string author_initials, string title, string genre_name, int page_count); // ����������� �� ����� �����������
	void setBookData(string author_last_name, string author_initials, string title, string genre_name, int page_count); // ������
	void enterBookData(); // ����� ��� ����������������� ����� ������
	void getBookData(); // ������
	bool isTitlesSame(string title); // ����� ��� ��������� �������� ����
	bool isAuthorLastNamesSame(string author_last_name); // ����� ��� ��������� ������� ������
	bool isGenreNamesSame(string genre_name); // ����� ��� ��������� �������� �����
	static int getBookCount(); // ����������� ������ ��� ��������� ���-�� ��������
	void read() override; // ��������������� ������������ ������ �� �������� ������������ ������
	Book& operator++(); // ���������� ����������� ��������� ++: ���������� ���-�� ������� �� 1
	Book operator++(int); // ���������� ������������ ��������� ++: ���������� ���-�� ������� �� 1
};
// ������� ������ ���� �� �������� � ������
void findBooksByTitleAndAuthor(Book books[], int book_count, string book_title, string author_last_name);
// ������� ������ ���� �� ������
void findBooksByAuthor(Book books[], int book_count, string author_last_name);
// ������� ������ ���� �� �����
void findBooksByGenre(Book books[], int book_count, string genre_name);