#pragma once
#include <string>
#include "publication.h"
using namespace std;
// ����� ������
class Magazine : public Publication {
private:
	string publisher_name;
	string title;
	string frequency;
	int page_count;
	float price;
	static int magazine_count;
public:
	Magazine(); // ����������� ��� ����������
	Magazine(string title); // ����������� � 1 ����������
	Magazine(string publisher_name, string title, string frequency, int page_count, float price); // ����������� �� ����� �����������
	void setMagazineData(string publisher_name, string title, string frequency, int page_count, float price); // ������
	void enterMagazineData(); // ����� ��� ����������������� ����� ������
	void getMagazineData(); // ������
	bool isPublisherNamesSame(string publisher_name); // ����� ��� ��������� �������� ��������
	static int getMagazineCount(); // ����������� ������ ��� ��������� ���-�� ��������
	void read() override; // ��������������� ������������ ������ �� �������� ������������ ������
};
// ������� ������ �������� �� ��������
void findMagazinesByPublisher(Magazine magazines[], int magazine_count, string publisher_name);