#include <iostream>
#include <string>
#include "author.h"
using namespace std;
int Author::author_count = 0;
// Конструктор без параметров
Author::Author() {
	last_name = "";
	initials = "";
	biography = "";
	++author_count;
}
// Конструктор с 1 параметром
Author::Author(string last_name) {
	this->last_name = last_name;
	++author_count;
}
// Конструктор со всеми параметрами
Author::Author(string last_name, string initials, string biography) {
	Author::setAuthorData(last_name, initials, biography);
	++author_count;
}
// Сеттер
void Author::setAuthorData(string last_name, string initials, string biography) {
	this->last_name = last_name;
	this->initials = initials;
	this->biography = biography;
}
// Метод для пользовательского ввода данных
void Author::enterAuthorData() {
	cout << endl;
	cout << "Введите фамилию автора:" << endl;
	getline(cin, last_name);
	cout << "Введите инициалы автора:" << endl;
	getline(cin, initials);
	cout << "Введите биографию автора:" << endl;
	getline(cin, biography);
	cout << endl;
	cout << "Автор " << last_name << " " << initials << " был успешно создан!" << endl;
}
// Геттер
void Author::getAuthorData() {
	cout << endl;
	cout << "Информация об авторе:" << endl;
	cout << "Фамилия: " << last_name << endl;
	cout << "Инициалы: " << initials << endl;
	cout << "Биография: " << biography << endl;
}
// Статический геттер для получения кол-ва объектов
int Author::getAuthorCount() {
	return author_count;
}
// Геттер для получения фамилии автора через указатель
void Author::getAuthorLastNamePtr(string* last_name) {
	*last_name = this->last_name;
}
// Геттер для получения фамилии автора через ссылку
void Author::getAuthorLastNameRef(string& last_name) {
	last_name = this->last_name;
}
// Геттер для получения фамилии автора в строковом виде
string Author::getAuthorLastName() {
	return last_name;
}
// Дружественная ф-ия получения биографии автора
void getAuthorBiography(const Author& author) {
	cout << "Биография автора книги: " << author.biography << endl;
}
// Перегрузка оператора "=" базового класса
Author& Author::operator=(const Author& other) {
	if (this != &other) {
		last_name = other.last_name;
		initials = other.initials;
		biography = other.biography;
	}
	return *this;
}