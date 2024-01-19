#include <iostream>
#include <string>
#include "author_translator.h"
using namespace std;
// Конструктор без параметров
AuthorTranslator::AuthorTranslator() : Author(), languages("") {}
// Конструктор с 1 параметром
AuthorTranslator::AuthorTranslator(string last_name) : Author(last_name) {}
// Конструктор со всеми параметрами
AuthorTranslator::AuthorTranslator(string last_name, string initials, string biography, string languages) : Author(last_name, initials, biography), languages(languages) {}
// Сеттер
void AuthorTranslator::setAuthorTranslatorData(string last_name, string initials, string biography, string languages) {
	setAuthorData(last_name, initials, biography);
	this->languages = languages;
}
// Метод для пользовательского ввода данных
void AuthorTranslator::enterAuthorTranslatorData() {
	cout << endl;
	cout << "Введите фамилию автора:" << endl;
	getline(cin, last_name);
	cout << "Введите инициалы автора:" << endl;
	getline(cin, initials);
	cout << "Введите биографию автора:" << endl;
	getline(cin, biography);
	cout << "Введите языки, которые используются автором-переводчиком:" << endl;
	getline(cin, languages);
	cout << endl;
	cout << "Автор-переводчик " << last_name << " " << initials << " был успешно создан!" << endl;
}
// Геттер (перегрузка метода базового класса с вызовом метода базового класса)
void AuthorTranslator::getAuthorTranslatorData() {
	Author::getAuthorData();
	cout << "Языки: " << languages << endl;
}
// Геттер (перегрузка метода базового класса без вызова метода базового класса)
void AuthorTranslator::getAuthorData() {
	cout << endl;
	cout << "Информация об авторе:" << endl;
	cout << "Фамилия: " << last_name << endl;
	cout << "Инициалы: " << initials << endl;
	cout << "Биография: " << biography << endl;
	cout << "Языки: " << languages << endl;
}
// Перегрузка оператора присваивания объекту производного класса объектов базового класса
AuthorTranslator& AuthorTranslator::operator=(const Author& other) {
	if (this != &other) {
		*static_cast<Author*>(this) = other;
	}
	return *this;
}