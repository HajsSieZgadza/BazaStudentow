#include "Przedmiot.h"

using namespace std;
Przedmiot::Przedmiot() {};
Przedmiot::Przedmiot(int _id,string _przedmiot1, string _przedmiot2, string _przedmiot3, string _przedmiot4, string _przedmiot5)
{
	id = _id;
	przedmiot1 = _przedmiot1;
	przedmiot2 = _przedmiot2;
	przedmiot3 = _przedmiot3;
	przedmiot4 = _przedmiot4;
	przedmiot5 = _przedmiot5;
}
int Przedmiot::ilosc()
{
	return przedmiotyM.size();
}
void Przedmiot::wczytaj(string s)
{
	ifstream plik(s);
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
		przedmiotyM.push_back(Przedmiot(id,przedmiot1, przedmiot2, przedmiot3, przedmiot4, przedmiot5));
	}
	plik.close();
}
void Przedmiot::dopisaniePrzedmiotow(std::string s)
{
	string newPrzedmiot1, newPrzedmiot2, newPrzedmiot3, newPrzedmiot4, newPrzedmiot5;

	cout << "Podaj nazwe przedmiotu 1 : ";
	cin >> newPrzedmiot1;
	cout << "Podaj nazwe przedmiotu 2 : ";
	cin >> newPrzedmiot2;
	cout << "Podaj nazwe przedmiotu 3 : ";
	cin >> newPrzedmiot3;
	cout << "Podaj nazwe przedmiotu 4 : ";
	cin >> newPrzedmiot4;
	cout << "Podaj nazwe przedmiotu 5 : ";
	cin >> newPrzedmiot5;
	przedmiotyM.push_back(Przedmiot(ilosc() + 1, newPrzedmiot1, newPrzedmiot2, newPrzedmiot3, newPrzedmiot4, newPrzedmiot5));
}
void Przedmiot::zapisPrzedmiotow(Przedmiot& przedmioty, string nazwaPliku)
{
	ofstream zapis(nazwaPliku);
	for (int i = 0; i< ilosc(); i++)
	{
		zapis<<przedmiotyM[i].id <<" "<< przedmiotyM[i].przedmiot1 << " " << przedmiotyM[i].przedmiot2 << " " << przedmiotyM[i].przedmiot3 << " " << przedmiotyM[i].przedmiot4 << " " << przedmiotyM[i].przedmiot5 << endl;
	}
	zapis.close();
}