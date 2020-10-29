#pragma once
#include<string>
#include <iostream>

using namespace std;
class Stavka
{
public:

	
	Stavka();
	~Stavka();
	string formatirajNaziv(string naziv);
	string getnaziv();
	void setnaziv(string n);
	int getkolicina();
	void setkolicina(int k);
	double getcijena();
	void setcijena(double c);

private:
	string naziv;
	int kolicina;
	double cijena;
};

