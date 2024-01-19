#pragma once
#include <string>
#include "publication.h"
using namespace std;
// Класс журнал
class Magazine : public Publication {
private:
	string publisher_name;
	string title;
	string frequency;
	int page_count;
	float price;
	static int magazine_count;
public:
	Magazine(); // Конструктор без параметров
	Magazine(string title); // Конструктор с 1 параметром
	Magazine(string publisher_name, string title, string frequency, int page_count, float price); // Конструктор со всеми параметрами
	void setMagazineData(string publisher_name, string title, string frequency, int page_count, float price); // Сеттер
	void enterMagazineData(); // Метод для пользовательского ввода данных
	void getMagazineData(); // Геттер
	bool isPublisherNamesSame(string publisher_name); // Метод для сравнения названий издателя
	static int getMagazineCount(); // Статический геттер для получения кол-ва объектов
	void read() override; // Переопределение виртуального метода из базового абстрактного класса
};
// Функция поиска журналов по издателю
void findMagazinesByPublisher(Magazine magazines[], int magazine_count, string publisher_name);