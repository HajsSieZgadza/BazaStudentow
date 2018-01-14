#ifndef Oceny_H
#define Oceny_H
#include "BazaStudentow.h"
#include "Przedmiot.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

class Oceny : public Przedmiot
{
public:
	std::string ocena1="", ocena2="", ocena3="", ocena4="", ocena5="";
	Oceny();
	Oceny(std::string _ocena1, std::string _ocena2, std::string _ocena3, std::string _ocena4, std::string _ocena5);
	std::vector<Oceny>oceny;
	void wypisz();
	void wczytaj(std::string s);
	int ilosc();
	void dopiszocene();
	void zapiszOceny(Oceny& ocenyy, std::string nazwaPliku);
	


};

#endif

