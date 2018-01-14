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
	oce.wczytanieOcen(c);
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
		baza.wyszukajStudenta(a,b,c);
		wsk = &men2;
		wsk->menu();
		int wybormenu2;
		cin >> wybormenu2;
		switch (wybormenu2)
		{
		case 1:
		{
			oce.edytowanieOcen();
			oce.zapisOcen(oce,c);
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
		oce.dodajOcene();
		oce.zapisOcen(oce,c);
	}
	break;
	default:
		break;
	}


	system("pause");
	return 0;
}