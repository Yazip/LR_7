#include "literature.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;
int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Author author1("Шукшин", "В.М.", "Родился...");
	Author author2("Шолохов", "М.А.", "Родился...");
	AuthorTranslator author_translator1("Маршак", "С.Я.", "Родился...", "Английский");
	AuthorTranslator author_translator2("Чуковский", "К.И.", "Родился...", "Английский");
	vector<Author*> authorVector;
	authorVector.push_back(&author1);
	authorVector.push_back(&author2);
	authorVector.push_back(&author_translator1);
	authorVector.push_back(&author_translator2);
	sort(authorVector.begin(), authorVector.end(), [](Author* a, Author* b) {
		return a->getAuthorLastName() < b->getAuthorLastName();
	});
	cout << "Отсортированный по фамилиям по алфавиту контейнер с объектами классов Author и AuthorTranslator:\n";
	for (const auto& author : authorVector) {
		author->getAuthorData();
	}
	string searchLastName = "Шолохов";
	auto it = find_if(authorVector.begin(), authorVector.end(), [&searchLastName](Author* author) {
		return author->getAuthorLastName() == searchLastName;
	});
	if (it != authorVector.end()) {
		cout << "\nАвтор найден: " << endl;
		(*it)->getAuthorData();
	}
	else {
		cout << "\nАвтор не найден.\n";
	}
	_getch();
	return 0;
}