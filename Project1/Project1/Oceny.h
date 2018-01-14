#ifndef Oceny_H
#define Oceny_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

class Oceny 
{
public:
	std::vector<Oceny> oc;
	int id, ocena1, ocena2, ocena3, ocena4, ocena5;
	Oceny() {};
	Oceny(int id,int _ocena1, int _ocena2, int _ocena3, int _ocena4, int _ocena5);
	void dodajOcene();
	void usunOcene();
	void wczytanieOcen(std::string s);
	void zapisOcen(Oceny& daneStudenta, std::string nazwaPliku);
	int ilosc();
	void edytowanieOcen();
};

#endif

