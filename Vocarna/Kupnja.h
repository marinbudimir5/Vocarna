#pragma once
#include "Skladiste.h"
#include "Racun.h"
#include<list>

class Kupnja
{
public:
	Kupnja();
	~Kupnja();
	void kupnjaStavke();

private:
	Skladiste objKupnja;
	list<Stavka> listaKupljenihStavki;
	Racun objRacun;
};

