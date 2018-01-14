#include "BazaStudentow.h"
using namespace std;
int idszukane;
BazaStudentow::BazaStudentow() {};

BazaStudentow::BazaStudentow(int _id, std::string _imie, std::string _nazwisko, std::string _kierunek)
{
	id = _id;
	imie = _imie;
	nazwisko = _nazwisko;
	kierunek = _kierunek;
}

void  BazaStudentow::wczytaj(string s)
{
	ifstream plik(s);
	string linie;
	while (getline(plik, linie))
	{
		stringstream wczyt(linie);
		int id;
		string imie, nazwisko;
		wczyt >> id;
		wczyt.ignore();
		wczyt >> imie;
		wczyt.ignore();
		wczyt >> nazwisko;
		wczyt.ignore();
		wczyt >> kierunek;
		dane.push_back(BazaStudentow(id, imie, nazwisko,kierunek));
	}
	plik.close();
}
void BazaStudentow::wypisz()
{
	for (int i = 0; i < ilosc(); i++)
	{
		cout << dane[i].id << " " << dane[i].imie << " " << dane[i].nazwisko << " " << dane[i].kierunek << endl;
	}
}
int BazaStudentow::ilosc()
{
	return dane.size();
}
void BazaStudentow::zapisStudentow(BazaStudentow& daneStudenta, string nazwaPliku)
{
	ofstream zapis(nazwaPliku);
	for (int i = 0; i<ilosc(); i++)
	{
		zapis << dane[i].id << " " << dane[i].imie << " " << dane[i].nazwisko << " " << dane[i].kierunek << endl;
	}
	zapis.close();
}
void BazaStudentow::nowyStudent(string nazwaPliku)
{
	string newImie, newNazwisko, newKierunek;
	int wyborkierunku;
	cout << "Podaj imie studenta : ";
	cin >> newImie;
	cout << endl;
	cout << "Podaj nazwisko studenta : ";
	cin >> newNazwisko;
	cout << endl;
	cout << "Na jaki kierunek zapisac studenta?    1)Mechatronika   2)Robotyka" << endl;
	cin >> wyborkierunku;
	if (wyborkierunku == 1)
	{
		newKierunek = "Mechatronika";
	}
	else
	{
		newKierunek = "Robotyka";
	}
	dane.push_back(BazaStudentow(ilosc() + 1, newImie, newNazwisko,newKierunek));


}
void BazaStudentow::wyszukajStudenta(string s, string a, string b)
{
	ifstream plik(a);
	string linie;
	int id;
	string przedmiot1, przedmiot2, przedmiot3, przedmiot4, przedmiot5;
	while (getline(plik, linie))
	{
		stringstream wczytanie(linie);
		wczytanie >> id;
		wczytanie.ignore();
		wczytanie >> przedmiot1;
		wczytanie.ignore();
		wczytanie >> przedmiot2;
		wczytanie.ignore();
		wczytanie >> przedmiot3;
		wczytanie.ignore();
		wczytanie >> przedmiot4;
		wczytanie.ignore();
		wczytanie >> przedmiot5;
		przedmiotyM.push_back(Przedmiot(id, przedmiot1, przedmiot2, przedmiot3, przedmiot4, przedmiot5));
	}
	plik.close();
	ifstream plik2(b);
	int ocena1, ocena2, ocena3, ocena4, ocena5,id2;
	while (getline(plik2, linie))
	{
		stringstream wczyt(linie);
		wczyt >> id2;
		wczyt.ignore();
		wczyt >> ocena1;
		wczyt.ignore();
		wczyt >> ocena2;
		wczyt.ignore();
		wczyt >> ocena3;
		wczyt.ignore();
		wczyt >> ocena4;
		wczyt.ignore();
		wczyt >> ocena5;
		wczyt.ignore();
		oc.push_back(Oceny(id2, ocena1, ocena2, ocena3, ocena4, ocena5));
	}
	plik2.close();
	cout << "Po czym chcesz wyszukiwac studenta" << endl << "1) ID" << endl << "2) Nazwisko" << endl;
	int wyszukiwanie;
	cin >> wyszukiwanie;
	if (wyszukiwanie == 1)
	{
		cout << "Wprowadz ID" << endl;
		int idszukane;
		cin >> idszukane;
		system("cls");
		for (int i = 0; i < ilosc(); i++)
		{
			if (idszukane == dane[i].id)
			{
				cout << dane[i].id << " " << dane[i].imie << " " << dane[i].nazwisko << " " << dane[i].kierunek << endl;
				cout << przedmiotyM[idszukane-1].przedmiot1 << " " << oc[idszukane-1].ocena1 << endl;
				cout << przedmiotyM[idszukane-1].przedmiot2 << " " << oc[idszukane-1].ocena2 << endl;
				cout << przedmiotyM[idszukane-1].przedmiot3 << " " << oc[idszukane-1].ocena3 << endl;
				cout << przedmiotyM[idszukane-1].przedmiot4 << " " << oc[idszukane-1].ocena4 << endl;
				cout << przedmiotyM[idszukane-1].przedmiot5 << " " << oc[idszukane-1].ocena5 << endl;
			}		
		}
	}
	else
	{
		cout << "Wprowadz nazwisko" << endl;
		string nazwiskoszukane;
		cin >> nazwiskoszukane;
		system("cls");
		for (int i = 0; i < ilosc(); i++)
		{
			if (nazwiskoszukane == dane[i].nazwisko)
			{
				cout << dane[i].id << " " << dane[i].imie << " " << dane[i].nazwisko << " " << dane[i].kierunek << endl;
				idszukane = dane[i].id;
				cout << przedmiotyM[idszukane-1].przedmiot1 << " " << oc[idszukane - 1].ocena1 << endl;
				cout << przedmiotyM[idszukane-1].przedmiot2 << " " << oc[idszukane - 1].ocena1 << endl;
				cout << przedmiotyM[idszukane-1].przedmiot3 << " " << oc[idszukane - 1].ocena1 << endl;
				cout << przedmiotyM[idszukane-1].przedmiot4 << " " << oc[idszukane - 1].ocena1 << endl;
				cout << przedmiotyM[idszukane-1].przedmiot5 << " " << oc[idszukane - 1].ocena1 << endl;
			}
		}
	}
}
