#include "Oceny.h"
#include "BazaStudentow.h"
using namespace std;

Oceny::Oceny() {};
Oceny::Oceny(std::string _ocena1, std::string _ocena2, std::string _ocena3, std::string _ocena4, std::string _ocena5)
{
	ocena1 = _ocena1;
	ocena2 = _ocena2;
	ocena3 = _ocena3;
	ocena4 = _ocena4;
	ocena5 = _ocena5;

}
void Oceny::wczytaj(string s)
{
	ifstream plik(s);
	string linie;
	while (getline(plik, linie))
	{
		stringstream wczyt(linie);
		string ocena1, ocena2, ocena3, ocena4, ocena5;
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
		oceny.push_back(Oceny(ocena1,ocena2,ocena3,ocena4,ocena5));
	}
	plik.close();
}
int Oceny::ilosc()
{
	return oceny.size();
}
void Oceny::wypisz()
{

}
void Oceny::dopiszocene()
{
	int ide,nrr;
	string oc;
	cout << "Podaj ID studenta";
	cin >> ide;
	cout << "Podaj nr przedmiotu";
	cin >> nrr;
	cout << "Podaj ocene";
	cin >> oc;
	switch (nrr)
	{
	case 1:
	{
		oceny[ide].ocena1 = oceny[ide].ocena1 + oc;
		break;
	}
	case 2:
	{
		oceny[ide].ocena2 = oceny[ide].ocena2 + oc;
		break;
	}
	case 3:
	{
		oceny[ide].ocena3 = oceny[ide].ocena3 + oc;
		break;
	}
	case 4:
	{
		oceny[ide].ocena4 = oceny[ide].ocena4 + oc;
		break;
	}
	case 5:
	{
		oceny[ide].ocena5 = oceny[ide].ocena5 + oc;
		break;
	}
	default:
		break;
	}
}
void Oceny::zapiszOceny(Oceny& ocenyy, string nazwaPliku)
{
	ofstream zapis(nazwaPliku);
	for (int i = 0; i<ilosc(); i++)
	{
		zapis << oceny[i].ocena1 << " " << oceny[i].ocena2 << " " << oceny[i].ocena3 << " " << oceny[i].ocena4 << " " << oceny[i].ocena5 << endl;
	}
	zapis.close();
}

