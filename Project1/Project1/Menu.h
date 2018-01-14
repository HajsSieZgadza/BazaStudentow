#ifndef Menu_h
#define Menu_h
#include<iostream>
class Menu
{
public:
	virtual void menu() = 0;
};

class Menu1 : public Menu
{
public:
	virtual void menu();
};

class Menu2 : public Menu
{
public:
	virtual void menu();
};
#endif // !Menu_h

