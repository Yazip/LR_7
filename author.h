#pragma once
#include <string>
using namespace std;
// Класс автор
class Author {
protected:
	string last_name;
	string initials;
	string biography;
	static int author_count;
public:
	Author(); // Конструктор без параметров
	Author(string last_name); // Конструктор с 1 параметром
	Author(string last_name, string initials, string biography); // Конструктор со всеми параметрами
	void setAuthorData(string last_name, string initials, string biography); // Сеттер
	void enterAuthorData(); // Метод для пользовательского ввода данных
	virtual void getAuthorData(); // Геттер
	static int getAuthorCount(); // Статический геттер для получения кол-ва объектов
	void getAuthorLastNamePtr(string* last_name); // Геттер для получения фамилии автора через указатель
	void getAuthorLastNameRef(string& last_name); // Геттер для получения фамилии автора через ссылку
	string getAuthorLastName(); // Геттер для получения фамилии автора в строковом виде
	friend void getAuthorBiography(const Author&); // Дружественная ф-ия получения биографии автора
	Author& operator=(const Author& other); // Перегрузка оператора "=" базового класса
};