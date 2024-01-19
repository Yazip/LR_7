#pragma once
#include <string>
using namespace std;
// Класс жанр
class Genre {
private:
	string name;
	string description;
	static int genre_count;
public:
	Genre(); // Конструктор без параметров
	Genre(string name); // Конструктор с 1 параметром
	Genre(string name, string description); // Конструктор со всеми параметрами
	void setGenreData(string name, string description); // Сеттер
	void enterGenreData(); // Метод для пользовательского ввода данных
	static int getGenreCount(); // Статический геттер для получения кол-ва объектов
	Genre operator+(const Genre& other); // Перегрузка оператора +: объединение жанров
	friend ostream& operator<<(ostream& os, const Genre& genre); // Замена метода Display перегрузкой "<<"
};