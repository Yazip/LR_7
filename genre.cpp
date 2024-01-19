#include <iostream>
#include <string>
#include "genre.h"
using namespace std;
int Genre::genre_count = 0;
// Конструктор без параметров
Genre::Genre() {
	name = "";
	description = "";
	++genre_count;
}
// Конструктор с 1 параметром
Genre::Genre(string name) {
	this->name = name;
	++genre_count;
}
// Конструктор со всеми параметрами
Genre::Genre(string name, string description) {
	Genre::setGenreData(name, description);
	++genre_count;
}
// Сеттер
void Genre::setGenreData(string name, string description) {
	this->name = name;
	this->description = description;
}
// Метод для пользовательского ввода данных
void Genre::enterGenreData() {
	cout << endl;
	cout << "Введите название жанра:" << endl;
	getline(cin, name);
	cout << "Введите описание жанра:" << endl;
	getline(cin, description);
	cout << endl;
	cout << "Жанр " << name << " был успешно создан!" << endl;
}
// Статический геттер для получения кол-ва объектов
int Genre::getGenreCount() {
	return genre_count;
}
// Перегрузка оператора +: объединение жанров
Genre Genre::operator+(const Genre& other) {
	Genre result;
	result.name = this->name + "-" + other.name;
	result.description = "Объединение описаний: 1) " + this->description + " 2) " + other.description;
	return result;
}
// Замена метода Display перегрузкой "<<"
ostream& operator<<(ostream& os, const Genre& genre) {
	os << "\n";
	os << "Название: " << genre.name << "\n";
	os << "Описание: " << genre.description << "\n";
	return os;
}