#include <iostream>
#include <string>
#include <algorithm>
#include "book.h"
using namespace std;
int Book::book_count = 0;
// Конструктор без параметров
Book::Book() {
	author_last_name = "";
	author_initials = "";
	title = "";
	genre_name = "";
	page_count = 0;
	++book_count;
}
// Конструктор с 1 параметром
Book::Book(string title) {
	this->title = title;
	++book_count;
}
// Конструктор со всеми параметрами
Book::Book(string author_last_name, string author_initials, string title, string genre_name, int page_count) {
	Book::setBookData(author_last_name, author_initials, title, genre_name, page_count);
	++book_count;
}
// Сеттер
void Book::setBookData(string author_last_name, string author_initials, string title, string genre_name, int page_count) {
	this->author_last_name = author_last_name;
	this->author_initials = author_initials;
	this->title = title;
	this->genre_name = genre_name;
	this->page_count = page_count;
}
// Метод для пользовательского ввода данных
void Book::enterBookData() {
	cout << endl;
	cout << "Введите фамилию автора:" << endl;
	getline(cin, author_last_name);
	cout << "Введите инициалы автора:" << endl;
	getline(cin, author_initials);
	cout << "Введите название книги:" << endl;
	getline(cin, title);
	cout << "Введите название жанра:" << endl;
	getline(cin, genre_name);
	cout << "Введите кол-во страниц (не меньше 0):" << endl;
	while ((cin >> page_count).fail() || (0 > page_count)) {
		cin.clear();
		cout << "Ошибка. Введите кол-во страниц (не меньше 0):" << endl;
		cin.ignore();
	}
	cin.ignore();
	cout << endl;
	cout << "Книга " << title << " была успешно создана!" << endl;
}
// Геттер
void Book::getBookData() {
	cout << endl;
	cout << "Информация о книге:" << endl;
	cout << "Фамилия автора: " << author_last_name << endl;
	cout << "Инициалы автора: " << author_initials << endl;
	cout << "Название книги: " << title << endl;
	cout << "Название жанра: " << genre_name << endl;
	cout << "Кол-во страниц: " << page_count << endl;
}
// Метод для сравнения названий книг
bool Book::isTitlesSame(string title) {
	// Создание копий названий книг для поиска (чтобы не портить их первоначальный вид ф-ей transform)
	string book_title_field_copy = this->title;
	string book_title_param_copy = title;
	// Приведение строк к одному регистру
	transform(book_title_field_copy.begin(), book_title_field_copy.end(), book_title_field_copy.begin(), tolower);
	transform(book_title_param_copy.begin(), book_title_param_copy.end(), book_title_param_copy.begin(), tolower);
	// Возврат результата сравнения
	return (book_title_field_copy == book_title_param_copy);
}
// Метод для сравнения фамилий автора
bool Book::isAuthorLastNamesSame(string author_last_name) {
	// Создание копий фамилий автора для поиска (чтобы не портить их первоначальный вид ф-ей transform)
	string author_last_name_field_copy = this->author_last_name;
	string author_last_name_param_copy = author_last_name;
	// Приведение строк к одному регистру
	transform(author_last_name_field_copy.begin(), author_last_name_field_copy.end(), author_last_name_field_copy.begin(), tolower);
	transform(author_last_name_param_copy.begin(), author_last_name_param_copy.end(), author_last_name_param_copy.begin(), tolower);
	// Возврат результата сравнения
	return (author_last_name_field_copy == author_last_name_param_copy);
}
// Метод для сравнения названий жанра
bool Book::isGenreNamesSame(string genre_name) {
	// Создание копий названий жанра для поиска (чтобы не портить их первоначальный вид ф-ей transform)
	string genre_name_field_copy = this->genre_name;
	string genre_name_param_copy = genre_name;
	// Приведение строк к одному регистру
	transform(genre_name_field_copy.begin(), genre_name_field_copy.end(), genre_name_field_copy.begin(), tolower);
	transform(genre_name_param_copy.begin(), genre_name_param_copy.end(), genre_name_param_copy.begin(), tolower);
	// Возврат результата сравнения
	return (genre_name_field_copy == genre_name_param_copy);
}
// Статический геттер для получения кол-ва объектов
int Book::getBookCount() {
	return book_count;
}
// Функция поиска книг по названию и автору
void findBooksByTitleAndAuthor(Book books[], int book_count, string book_title, string author_last_name) {
	Book found_books[300];
	int j = 0;
	for (int i = 0; i < book_count; i++) { // Цикл поиска нужных книг
		// Сравнение заданных значений полей и полей из массива книг
		if ((books[i].isTitlesSame(book_title)) && (books[i].isAuthorLastNamesSame(author_last_name))) {
			found_books[j] = books[i]; // Добавление книги в массив найденных книг
			++j;
		}
	}
	// Вывод найденных книг если они есть
	if (j) {
		cout << endl;
		cout << "Найдено " << j << " книг автора " << author_last_name << " с названием \"" << book_title << "\":" << endl;
		for (int k = 0; k < j; k++) {
			cout << endl;
			cout << "Книга " << (k + 1) << endl;
			cout << endl;
			found_books[k].getBookData();
			cout << "-------------------------" << endl;
		}
	}
	// Иначе вывод сообщения об их отсутствии
	else {
		cout << endl;
		cout << "Ничего не найдено!" << endl;
	}
}
// Функция поиска книг по автору
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
		cout << "Найдено " << j << " книг автора " << author_last_name << ":" << endl;
		for (int k = 0; k < j; k++) {
			cout << endl;
			cout << "Книга " << (k + 1) << endl;
			cout << endl;
			found_books[k].getBookData();
			cout << "-------------------------" << endl;
		}
	}
	else {
		cout << endl;
		cout << "Ничего не найдено!" << endl;
	}
}
// Функция поиска книг по жанру
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
		cout << "Найдено " << j << " книг жанра " << genre_name << ":" << endl;
		for (int k = 0; k < j; k++) {
			cout << endl;
			cout << "Книга " << (k + 1) << endl;
			cout << endl;
			found_books[k].getBookData();
			cout << "-------------------------" << endl;
		}
	}
	else {
		cout << endl;
		cout << "Ничего не найдено!" << endl;
	}
}
// Переопределение виртуального метода из базового абстрактного класса
void Book::read() {
	cout << "Книга прочитана" << endl;
}
// Перегрузка префиксного оператора ++: увеличение кол-ва страниц на 1
Book& Book::operator++() {
	this->page_count++;
	return *this;
}
// Перегрузка постфиксного оператора ++: увеличение кол-ва страниц на 1
Book Book::operator++(int) {
	Book temp = *this;
	++(*this);
	return temp;
}