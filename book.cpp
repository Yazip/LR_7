#include <iostream>
#include <string>
#include <algorithm>
#include "book.h"
using namespace std;
int Book::book_count = 0;
// ����������� ��� ����������
Book::Book() {
	author_last_name = "";
	author_initials = "";
	title = "";
	genre_name = "";
	page_count = 0;
	++book_count;
}
// ����������� � 1 ����������
Book::Book(string title) {
	this->title = title;
	++book_count;
}
// ����������� �� ����� �����������
Book::Book(string author_last_name, string author_initials, string title, string genre_name, int page_count) {
	Book::setBookData(author_last_name, author_initials, title, genre_name, page_count);
	++book_count;
}
// ������
void Book::setBookData(string author_last_name, string author_initials, string title, string genre_name, int page_count) {
	this->author_last_name = author_last_name;
	this->author_initials = author_initials;
	this->title = title;
	this->genre_name = genre_name;
	this->page_count = page_count;
}
// ����� ��� ����������������� ����� ������
void Book::enterBookData() {
	cout << endl;
	cout << "������� ������� ������:" << endl;
	getline(cin, author_last_name);
	cout << "������� �������� ������:" << endl;
	getline(cin, author_initials);
	cout << "������� �������� �����:" << endl;
	getline(cin, title);
	cout << "������� �������� �����:" << endl;
	getline(cin, genre_name);
	cout << "������� ���-�� ������� (�� ������ 0):" << endl;
	while ((cin >> page_count).fail() || (0 > page_count)) {
		cin.clear();
		cout << "������. ������� ���-�� ������� (�� ������ 0):" << endl;
		cin.ignore();
	}
	cin.ignore();
	cout << endl;
	cout << "����� " << title << " ���� ������� �������!" << endl;
}
// ������
void Book::getBookData() {
	cout << endl;
	cout << "���������� � �����:" << endl;
	cout << "������� ������: " << author_last_name << endl;
	cout << "�������� ������: " << author_initials << endl;
	cout << "�������� �����: " << title << endl;
	cout << "�������� �����: " << genre_name << endl;
	cout << "���-�� �������: " << page_count << endl;
}
// ����� ��� ��������� �������� ����
bool Book::isTitlesSame(string title) {
	// �������� ����� �������� ���� ��� ������ (����� �� ������� �� �������������� ��� �-�� transform)
	string book_title_field_copy = this->title;
	string book_title_param_copy = title;
	// ���������� ����� � ������ ��������
	transform(book_title_field_copy.begin(), book_title_field_copy.end(), book_title_field_copy.begin(), tolower);
	transform(book_title_param_copy.begin(), book_title_param_copy.end(), book_title_param_copy.begin(), tolower);
	// ������� ���������� ���������
	return (book_title_field_copy == book_title_param_copy);
}
// ����� ��� ��������� ������� ������
bool Book::isAuthorLastNamesSame(string author_last_name) {
	// �������� ����� ������� ������ ��� ������ (����� �� ������� �� �������������� ��� �-�� transform)
	string author_last_name_field_copy = this->author_last_name;
	string author_last_name_param_copy = author_last_name;
	// ���������� ����� � ������ ��������
	transform(author_last_name_field_copy.begin(), author_last_name_field_copy.end(), author_last_name_field_copy.begin(), tolower);
	transform(author_last_name_param_copy.begin(), author_last_name_param_copy.end(), author_last_name_param_copy.begin(), tolower);
	// ������� ���������� ���������
	return (author_last_name_field_copy == author_last_name_param_copy);
}
// ����� ��� ��������� �������� �����
bool Book::isGenreNamesSame(string genre_name) {
	// �������� ����� �������� ����� ��� ������ (����� �� ������� �� �������������� ��� �-�� transform)
	string genre_name_field_copy = this->genre_name;
	string genre_name_param_copy = genre_name;
	// ���������� ����� � ������ ��������
	transform(genre_name_field_copy.begin(), genre_name_field_copy.end(), genre_name_field_copy.begin(), tolower);
	transform(genre_name_param_copy.begin(), genre_name_param_copy.end(), genre_name_param_copy.begin(), tolower);
	// ������� ���������� ���������
	return (genre_name_field_copy == genre_name_param_copy);
}
// ����������� ������ ��� ��������� ���-�� ��������
int Book::getBookCount() {
	return book_count;
}
// ������� ������ ���� �� �������� � ������
void findBooksByTitleAndAuthor(Book books[], int book_count, string book_title, string author_last_name) {
	Book found_books[300];
	int j = 0;
	for (int i = 0; i < book_count; i++) { // ���� ������ ������ ����
		// ��������� �������� �������� ����� � ����� �� ������� ����
		if ((books[i].isTitlesSame(book_title)) && (books[i].isAuthorLastNamesSame(author_last_name))) {
			found_books[j] = books[i]; // ���������� ����� � ������ ��������� ����
			++j;
		}
	}
	// ����� ��������� ���� ���� ��� ����
	if (j) {
		cout << endl;
		cout << "������� " << j << " ���� ������ " << author_last_name << " � ��������� \"" << book_title << "\":" << endl;
		for (int k = 0; k < j; k++) {
			cout << endl;
			cout << "����� " << (k + 1) << endl;
			cout << endl;
			found_books[k].getBookData();
			cout << "-------------------------" << endl;
		}
	}
	// ����� ����� ��������� �� �� ����������
	else {
		cout << endl;
		cout << "������ �� �������!" << endl;
	}
}
// ������� ������ ���� �� ������
void findBooksByAuthor(Book books[], int book_count, string author_last_name) {
	Book found_books[300];
	int j = 0;
	for (int i = 0; i < book_count; i++) {
		if (books[i].isAuthorLastNamesSame(author_last_name)) {
			found_books[j] = books[i];
			++j;
		}
	}
	if (j) {
		cout << endl;
		cout << "������� " << j << " ���� ������ " << author_last_name << ":" << endl;
		for (int k = 0; k < j; k++) {
			cout << endl;
			cout << "����� " << (k + 1) << endl;
			cout << endl;
			found_books[k].getBookData();
			cout << "-------------------------" << endl;
		}
	}
	else {
		cout << endl;
		cout << "������ �� �������!" << endl;
	}
}
// ������� ������ ���� �� �����
void findBooksByGenre(Book books[], int book_count, string genre_name) {
	Book found_books[300];
	int j = 0;
	for (int i = 0; i < book_count; i++) {
		if (books[i].isGenreNamesSame(genre_name)) {
			found_books[j] = books[i];
			++j;
		}
	}
	if (j) {
		cout << endl;
		cout << "������� " << j << " ���� ����� " << genre_name << ":" << endl;
		for (int k = 0; k < j; k++) {
			cout << endl;
			cout << "����� " << (k + 1) << endl;
			cout << endl;
			found_books[k].getBookData();
			cout << "-------------------------" << endl;
		}
	}
	else {
		cout << endl;
		cout << "������ �� �������!" << endl;
	}
}
// ��������������� ������������ ������ �� �������� ������������ ������
void Book::read() {
	cout << "����� ���������" << endl;
}
// ���������� ����������� ��������� ++: ���������� ���-�� ������� �� 1
Book& Book::operator++() {
	this->page_count++;
	return *this;
}
// ���������� ������������ ��������� ++: ���������� ���-�� ������� �� 1
Book Book::operator++(int) {
	Book temp = *this;
	++(*this);
	return temp;
}