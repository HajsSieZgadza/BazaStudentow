#ifndef Przedmiot_H
#define Przedmiot_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

class Przedmiot 
	
{
public:
	int id;
	std::string przedmiot1, przedmiot2, przedmiot3, przedmiot4, przedmiot5;
	std::vector<Przedmiot> przedmiotyM;
	Przedmiot();
	Przedmiot(int _id,std::string _przedmiot1, std::string _przedmiot2, std::string _przedmiot3, std::string _przedmiot4, std::string _przedmiot5);
	void wczytaj(std::string s);
	void dopisaniePrzedmiotow(std::string s);
	void zapisPrzedmiotow(Przedmiot& przedmioty, std::string nazwaPliku);
	int ilosc();
};

#endif // !1