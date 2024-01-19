#include <iostream>
#include <string>
#include <algorithm>
#include "magazine.h"
using namespace std;
int Magazine::magazine_count = 0;
// Конструктор без параметров
Magazine::Magazine() {
	publisher_name = "";
	title = "";
	frequency = "";
	page_count = 0;
	price = 0.0f;
	++magazine_count;
}
// Конструктор с 1 параметром
Magazine::Magazine(string title) {
	this->title = title;
	++magazine_count;
}
// Конструктор со всеми параметрами
Magazine::Magazine(string publisher_name, string title, string frequency, int page_count, float price) {
	Magazine::setMagazineData(publisher_name, title, frequency, page_count, price);
	++magazine_count;
}
// Сеттер
void Magazine::setMagazineData(string publisher_name, string title, string frequency, int page_count, float price) {
	this->publisher_name = publisher_name;
	this->title = title;
	this->frequency = frequency;
	this->page_count = page_count;
	this->price = price;
}
// Метод для пользовательского ввода данных
void Magazine::enterMagazineData() {
	cout << endl;
	cout << "Введите название издателя:" << endl;
	getline(cin, publisher_name);
	cout << "Введите название журнала:" << endl;
	getline(cin, title);
	cout << "Введите периодичность:" << endl;
	getline(cin, frequency);
	cout << "Введите кол-во страниц (не меньше 0):" << endl;
	while ((cin >> page_count).fail() || (0 > page_count)) {
		cin.clear();
		cout << "Ошибка. Введите кол-во страниц (не меньше 0):" << endl;
		cin.ignore();
	}
	cin.ignore();
	cout << "Введите цену (не меньше 0):" << endl;
	while ((cin >> price).fail() || (0.0f > price)) {
		cin.clear();
		cout << "Ошибка. Введите цену (не меньше 0):" << endl;
		cin.ignore();
	}
	cin.ignore();
	cout << endl;
	cout << "Журнал " << title << " был успешно создан!" << endl;
}
// Геттер
void Magazine::getMagazineData() {
	cout << endl;
	cout << "Информация о журнале:" << endl;
	cout << "Издатель: " << publisher_name << endl;
	cout << "Название журнала: " << title << endl;
	cout << "Периодичность: " << frequency << endl;
	cout << "Кол-во страниц: " << page_count << endl;
	cout << "Цена: " << price << endl;
}
// Метод для сравнения названий издателя
bool Magazine::isPublisherNamesSame(string publisher_name) {
	// Создание копий названий издателя для поиска (чтобы не портить их первоначальный вид ф-ей transform)
	string publisher_name_field_copy = this->publisher_name;
	string publisher_name_param_copy = publisher_name;
	// Приведение строк к одному регистру
	transform(publisher_name_field_copy.begin(), publisher_name_field_copy.end(), publisher_name_field_copy.begin(), tolower);
	transform(publisher_name_param_copy.begin(), publisher_name_param_copy.end(), publisher_name_param_copy.begin(), tolower);
	// Возврат результата сравнения
	return (publisher_name_field_copy == publisher_name_param_copy);
}
// Статический геттер для получения кол-ва объектов
int Magazine::getMagazineCount() {
	return magazine_count;
}
// Переопределение виртуального метода из базового абстрактного класса
void Magazine::read() {
	cout << "Журнал прочитан" << endl;
}
// Функция поиска журналов по издателю
void findMagazinesByPublisher(Magazine magazines[], int magazine_count, string publisher_name) {
	Magazine found_magazines[300];
	int j = 0;
	for (int i = 0; i < magazine_count; i++) {
		if (magazines[i].isPublisherNamesSame(publisher_name)) {
			found_magazines[j] = magazines[i];
			++j;
		}
	}
	if (j) {
		cout << endl;
		cout << "Найдено " << j << " журналов издателя " << publisher_name << ":" << endl;
		for (int k = 0; k < j; k++) {
			cout << endl;
			cout << "Журнал " << (k + 1) << endl;
			cout << endl;
			found_magazines[k].getMagazineData();
			cout << "-------------------------" << endl;
		}
	}
	else {
		cout << endl;
		cout << "Ничего не найдено!" << endl;
	}
}