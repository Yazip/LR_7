#pragma once
#include <string>
#include "publication.h"
using namespace std;
// Класс книга
class Book : public Publication {
private:
	string author_last_name;
	string author_initials;
	string title;
	string genre_name;
	int page_count;
	static int book_count;
public:
	Book(); // Конструктор без параметров
	Book(string title); // Конструктор с 1 параметром
	Book(string author_last_name, string author_initials, string title, string genre_name, int page_count); // Конструктор со всеми параметрами
	void setBookData(string author_last_name, string author_initials, string title, string genre_name, int page_count); // Сеттер
	void enterBookData(); // Метод для пользовательского ввода данных
	void getBookData(); // Геттер
	bool isTitlesSame(string title); // Метод для сравнения названий книг
	bool isAuthorLastNamesSame(string author_last_name); // Метод для сравнения фамилий автора
	bool isGenreNamesSame(string genre_name); // Метод для сравнения названий жанра
	static int getBookCount(); // Статический геттер для получения кол-ва объектов
	void read() override; // Переопределение виртуального метода из базового абстрактного класса
	Book& operator++(); // Перегрузка префиксного оператора ++: увеличение кол-ва страниц на 1
	Book operator++(int); // Перегрузка постфиксного оператора ++: увеличение кол-ва страниц на 1
};
// Функция поиска книг по названию и автору
void findBooksByTitleAndAuthor(Book books[], int book_count, string book_title, string author_last_name);
// Функция поиска книг по автору
void findBooksByAuthor(Book books[], int book_count, string author_last_name);
// Функция поиска книг по жанру
void findBooksByGenre(Book books[], int book_count, string genre_name);