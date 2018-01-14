#include "Oceny.h"

using namespace std;

Oceny::Oceny(int _id, int _ocena1, int _ocena2, int _ocena3, int _ocena4, int _ocena5)
{
	id = _id;
	ocena1 = _ocena1;
	ocena2 = _ocena2;
	ocena3 = _ocena3;
	ocena4 = _ocena4;
	ocena5 = _ocena5;
}
int Oceny::ilosc()
{
	return oc.size();
}
void Oceny::dodajOcene()
{
	int newocena1=0, newocena2=0, newocena3=0, newocena4=0, newocena5=0;
	oc.push_back(Oceny(ilosc() + 1, newocena1, newocena2, newocena3, newocena4,newocena5));
}
void Oceny::usunOcene()
{
	oc.pop_back();
}
void Oceny::wczytanieOcen(string s)
{
	ifstream plik(s);
	string linie;
	int ocena1, ocena2, ocena3, ocena4, ocena5,id;
	while (getline(plik, linie))
	{
		stringstream wczytanie(linie);
		wczytanie >> id;
		wczytanie.ignore();
		wczytanie >> ocena1;
		wczytanie.ignore();
		wczytanie >> ocena2;
		wczytanie.ignore();
		wczytanie >> ocena3;
		wczytanie.ignore();
		wczytanie >> ocena4;
		wczytanie.ignore();
		wczytanie >> ocena5;
		wczytanie.ignore();
		oc.push_back(Oceny(id,ocena1, ocena2, ocena3, ocena4, ocena5));
	}
	plik.close();
}
void Oceny::zapisOcen(Oceny& oceny, string nazwaPliku)
{
	ofstream zapis(nazwaPliku);
	for (int i = 0; i<ilosc(); i++)
	{
		zapis<< oc[i].id<< " " << oc[i].ocena1 << " " << oc[i].ocena2 << " " << oc[i].ocena3 << " " << oc[i].ocena4 << " " << oc[i].ocena5 << " " << endl;
	}
	zapis.close();
}
void Oceny::edytowanieOcen()
{
	int opcja1,opcja2;
	cout << "Podaj id studenta dla ktorego chcesz zmienic ocene" << endl;
	cin >> opcja1;
	for (int i = 0; i < ilosc(); i++)
	{
		if (opcja1 == oc[i].id)
		{
			cout << "Wybierz nr przedmiotu";
			cin >> opcja2;
			int nocena;
			cout << "Podaj ocene " << endl;
			cin >> nocena;
			switch (opcja2)
			{
			case 1:
			{
				oc[i].ocena1 = nocena;
				break;
			}
			case 2:
			{
				oc[i].ocena2 = nocena;
				break;
			}
			case 3:
			{
				oc[i].ocena3 = nocena;
				break;
			}
			case 4:
			{
				oc[i].ocena4 = nocena;
				break;
			}
			case 5:
			{
				oc[i].ocena5 = nocena;
				break;
			}
			default:
				break;
			}
		}
		break;
	}
}