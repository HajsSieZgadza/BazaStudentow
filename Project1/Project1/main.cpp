#include <iostream>
#include "BazaStudentow.h"
#include "Przedmiot.h"
#include "Oceny.h"
#include"Menu.h"

using namespace std;
int main()
{
	BazaStudentow baza;
	Przedmiot prz;
	Oceny oce;
	Menu1 men1;
	Menu2 men2;
	Menu *wsk;
	string a = "BazaStudentow.txt", b = "Przedmioty.txt", c = "Oceny.txt";

	baza.wczytaj(a);
	prz.wczytaj(b);
	wsk = &men1;
	wsk->menu();
	int wybormenu;
	cin >> wybormenu;
	switch (wybormenu)
	{
	case 1:
	{
		system("cls");
		baza.wypisz();
	}
	break;
	case 2:
	{
		baza.wyszukajStudenta(a);
		wsk = &men2;
		wsk->menu();
		int wybormenu2;
		cin >> wybormenu2;
		switch (wybormenu2)
		{
		case 1:
		{

			break;
		}
		case 2:
		{

			break;
		}
		default:
			break;
		}

	}
	break;
	case 3:
	{
		baza.nowyStudent(a);
		baza.zapisStudentow(baza,a);
		prz.dopisaniePrzedmiotow(b);
		prz.zapisPrzedmiotow(prz, b);
	}
	break;
	default:
		break;
	}


	system("pause");
	return 0;
}