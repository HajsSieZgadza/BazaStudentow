#ifndef BazaStudentow_H
#define BazaStudentow_H
#include "Przedmiot.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<sstream>
#include<iostream>

class BazaStudentow : public Przedmiot
{
public:
	std::vector<BazaStudentow> dane;
	int id;
	std::string imie, nazwisko,kierunek;
	BazaStudentow();
	BazaStudentow(int _id, std::string _imie, std::string _nazwisko, std::string _kierunek);
	int ilosc();
	void wczytaj(std::string s);
	void wypisz();
	void zapisStudentow(BazaStudentow& daneStudenta, std::string nazwaPliku);
	void nowyStudent(std::string nazwaPliku);
	void wyszukajStudenta(std::string s);

};


#endif 
