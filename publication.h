#pragma once
#include <string>
using namespace std;
// Абстрактный класс издание
class Publication {
public:
	virtual void read() = 0; // Виртуальный метод для чтения
};