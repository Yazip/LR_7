#pragma once
#include <iostream>
#include <string>
using namespace std;
// Класс издатель
template <typename T>
class Publisher {
private:
	string name;
	string address;
	T phone_num;
	string email;
	static int publisher_count;
public:
	Publisher(); // Конструктор без параметров
	Publisher(string name); // Конструктор с 1 параметром
	Publisher(string name, string address, T phone_num, string email); // Конструктор со всеми параметрами
	void setPublisherData(string name, string address, T phone_num, string email); // Сеттер
	void enterPublisherData(); // Метод для пользовательского ввода данных
	void getPublisherData(); // Геттер
	static int getPublisherCount(); // Статический геттер для получения кол-ва объектов
};
template <typename T>
int Publisher<T>::publisher_count = 0;
// Конструктор без параметров
template <typename T>
Publisher<T>::Publisher() {
	name = "";
	address = "";
	email = "";
	++publisher_count;
}
// Конструктор с 1 параметром
template <typename T>
Publisher<T>::Publisher(string name) {
	try {
		if (name.empty()) {
			throw invalid_argument("Название не может быть пустым");
		}
		this->name = name;
		++publisher_count;
	}
	catch (const invalid_argument& e) {
		cout << "Некорректный аргумент: " << e.what() << endl;
	}
}
// Конструктор со всеми параметрами
template <typename T>
Publisher<T>::Publisher(string name, string address, T phone_num, string email) {
	Publisher::setPublisherData(name, address, phone_num, email);
	++publisher_count;
}
// Сеттер
template <typename T>
void Publisher<T>::setPublisherData(string name, string address, T phone_num, string email) {
	this->name = name;
	this->address = address;
	this->phone_num = phone_num;
	this->email = email;
}
// Метод для пользовательского ввода данных
template <typename T>
void Publisher<T>::enterPublisherData() {
	cout << endl;
	cout << "Введите название издателя:" << endl;
	getline(cin, name);
	cout << "Введите адрес издателя:" << endl;
	getline(cin, address);
	cout << "Введите номер телефона издателя:" << endl;
	getline(cin, phone_num);
	cout << "Введите электронную почту издателя:" << endl;
	getline(cin, email);
	cout << endl;
	cout << "Издатель " << name << " был успешно создан!" << endl;
}
// Геттер
template <typename T>
void Publisher<T>::getPublisherData() {
	cout << endl;
	cout << "Информация об издателе:" << endl;
	cout << "Название: " << name << endl;
	cout << "Адрес: " << address << endl;
	cout << "Номер телефона: " << phone_num << endl;
	cout << "Электронная почта: " << email << endl;
}
// Статический геттер для получения кол-ва объектов
template <typename T>
int Publisher<T>::getPublisherCount() {
	return publisher_count;
}