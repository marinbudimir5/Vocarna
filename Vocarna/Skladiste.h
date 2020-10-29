#pragma once
#include<list>
#include"Stavka.h"



using namespace std;
class Skladiste
{
public:
	Skladiste();
	~Skladiste();
	
	void ispisiSkladiste();
	void obrisiStavku();
	void dodajStavku();
	void izmjeniStavku();
	bool provjeriStanje(string naziv,int kolicina);
	void izmjenuKolicinuStavke(string naziv,int kolicina);
	double dohvatiCijenu(string naziv);




private:
	list <Stavka> popisStavki;
	void dohvatiStavke();
};

