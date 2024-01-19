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
	Author author1("������", "�.�.", "�������...");
	Author author2("�������", "�.�.", "�������...");
	AuthorTranslator author_translator1("������", "�.�.", "�������...", "����������");
	AuthorTranslator author_translator2("���������", "�.�.", "�������...", "����������");
	vector<Author*> authorVector;
	authorVector.push_back(&author1);
	authorVector.push_back(&author2);
	authorVector.push_back(&author_translator1);
	authorVector.push_back(&author_translator2);
	sort(authorVector.begin(), authorVector.end(), [](Author* a, Author* b) {
		return a->getAuthorLastName() < b->getAuthorLastName();
	});
	cout << "��������������� �� �������� �� �������� ��������� � ��������� ������� Author � AuthorTranslator:\n";
	for (const auto& author : authorVector) {
		author->getAuthorData();
	}
	string searchLastName = "�������";
	auto it = find_if(authorVector.begin(), authorVector.end(), [&searchLastName](Author* author) {
		return author->getAuthorLastName() == searchLastName;
	});
	if (it != authorVector.end()) {
		cout << "\n����� ������: " << endl;
		(*it)->getAuthorData();
	}
	else {
		cout << "\n����� �� ������.\n";
	}
	_getch();
	return 0;
}