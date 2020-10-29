#include "Racun.h"

Racun::Racun()
{
}

Racun::~Racun()
{
}




void Racun::ispisiRacun(list<Stavka> listaKupljenihStavki)
{
	double ukupanRacun = 0;
	cout << endl << endl <<" ------Racun------"<<endl;
	list<Stavka>::iterator itr;
	for (itr = listaKupljenihStavki.begin(); itr != listaKupljenihStavki.end(); ++itr) 
	{
		cout << itr->getnaziv() << ", kolicina: " << itr->getkolicina() << " kg, cijena po komadu:" << itr->getcijena() <<" kn"<< endl;
		ukupanRacun = ukupanRacun + (itr->getkolicina() * itr->getcijena());
	}
	cout << endl << "Suma kupljenih stavki: " << ukupanRacun << " kn" << endl << endl<<endl;
}
