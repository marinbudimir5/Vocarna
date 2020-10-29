#include "Skladiste.h"
#include<sstream>
#include"Stavka.h"
#include<string>
#include<fstream>
#include<iostream>


using namespace std;




Skladiste::Skladiste()
{
}

Skladiste::~Skladiste()
{
}



void procitajDatoteku(ifstream &in, list <Stavka> &popisStavki)
{
	string naziv, kolicina, cijena;
	while (getline(in,naziv,';'))
	{
		getline(in, kolicina, ';');
		getline(in, cijena);
		
		stringstream k(kolicina);
		stringstream c(cijena);
		int kol;
		double cij;
		k >> kol;
		c >> cij;
		Stavka voce;
		voce.setnaziv(naziv);
		voce.setkolicina(kol);
		voce.setcijena(cij);
		popisStavki.push_back(voce); 
	}
}


bool provjeraPostojecegNaziva(list<Stavka> &popisStavki,string &naziv)
{
	
	list<Stavka>::iterator it;
	for (it = popisStavki.begin(); it != popisStavki.end(); ++it)
	{
		if (it->getnaziv() == naziv)
		{
			return true;
		}
	}

	return false;

}

void ispisiListuStavki(list<Stavka> &popisStavki)
{
	
	list<Stavka>::iterator it;
	for (it = popisStavki.begin(); it != popisStavki.end(); ++it)
	{
		cout << "Naziv: " << it->getnaziv() << " Kolicina: " << it->getkolicina() << " kg , Cijena: " << it->getcijena()<<" kn" << endl;
	}

}

void ispisiUDatoteku(list<Stavka>& popisStavki)
{
	ofstream out("inventar.txt");
	if (!out)
	{
		cout << "Pogreska: Datoteka nije ucitana" << endl;
	}
	
	list<Stavka>::iterator it;
	for (it = popisStavki.begin(); it != popisStavki.end(); ++it)
	{
		out << it->getnaziv() << ";" << it->getkolicina() << ";" << it->getcijena() << endl;
	}
	out.close();
}


void Skladiste::dohvatiStavke()
{
	ifstream in("inventar.txt");
	if (!in)
	{
		cout << "Krivo ste unijeli stavku" << endl;
	}
	procitajDatoteku(in, popisStavki);
	in.close();
}



void Skladiste::ispisiSkladiste()
{
	
	if (popisStavki.empty())
	{
		dohvatiStavke();
	}

	
	ispisiListuStavki(popisStavki);
}






void Skladiste::obrisiStavku()
{
	 
	Stavka objBrisanje;
	string naredba;

	
	if (popisStavki.empty())
	{
		dohvatiStavke();
	}
	
	ispisiListuStavki(popisStavki);

	
	cout << "----------------" << endl << endl;
	cout << "Upisite naziv stavke koju zelite obrisati: "<<endl;
	
	do
	{
		string naziv;
		cin >> naziv;
	
		naziv = objBrisanje.formatirajNaziv(naziv);
		list<Stavka>::iterator itr;
		for (itr = popisStavki.begin();itr != popisStavki.end();++itr)
		{
			if (itr->getnaziv() == naziv)
			{
				itr = popisStavki.erase(itr); 
			}
		}
		cout << "Uspjesno ste obrisali stavku!" << endl;
		cout << "Upisite da za brisanje druge stavke ili ne za izlaz: " << endl;
	upisNaredbe:
		
		cin >> naredba;
		if (naredba != "da" && naredba != "ne")
		{
			cout << " Niste dobro naredbu upisali, upisite da ili ne: " << endl;
			goto upisNaredbe;
		}
	} while (naredba != "ne");


	

	ispisiUDatoteku(popisStavki);
}









void Skladiste::dodajStavku()
{
	
	if (popisStavki.empty())
	{
		dohvatiStavke();
	}
	

	cout << " Dodavanje nove stavke: " << endl;
	string naredba;
	do {
		Stavka novoVoce;

		cout << " Upisite naziv: " << endl;
		string naziv;
	    upisNaziva:
		cin >> naziv;
		naziv=novoVoce.formatirajNaziv(naziv);
		
		if (provjeraPostojecegNaziva(popisStavki, naziv) == true)
		{
			cout << "Vec postoji taj naziv, molimo upisite ponovo: "<<endl;
			goto upisNaziva;
		}
		
		novoVoce.setnaziv(naziv);


		cout << " Upisite kolicinu: " << endl;
		int kolicina;
		cin >> kolicina;
		novoVoce.setkolicina(kolicina);
		cout << " Upisite cijenu: " << endl;
		double cijena;
		cin >> cijena;
		novoVoce.setcijena(cijena);
		
		popisStavki.push_back(novoVoce);
		cout << endl << endl << "Upisite da za dodavanje novih stavki ili ne za izlaz: " << endl;
		upisNaredbe:
		cin >> naredba;
		if (naredba != "da" && naredba != "ne")
		{
			cout << " Niste dobro naredbu upisali, upisite da ili ne: " << endl;
			goto upisNaredbe;
		}
	} while (naredba != "ne");

	
	ispisiUDatoteku(popisStavki);

}

void Skladiste::izmjeniStavku()
{
	
	Stavka objFormatiranje;
	string naredba;
	
	if (popisStavki.empty())
	{
		dohvatiStavke();
	}
	
	ispisiListuStavki(popisStavki);
	cout << "----------------" << endl << endl;
	cout << "Upisite naziv stavke koju zelite izmijeniti: "<<endl;
	do
	{
		string naziv;
		cin >> naziv;
		//formatiranje naziva 
		naziv = objFormatiranje.formatirajNaziv(naziv);
		list<Stavka>::iterator itr;
		for (itr = popisStavki.begin();itr != popisStavki.end();++itr)
		{
			if (itr->getnaziv() == naziv) 
			{
				int kolicina;
				double cijena;
				cout << "Molimo vas promijenite kolicinu: ";
				cin >> kolicina;
				itr->setkolicina(kolicina);
				cout << "Molimo vas promijenite cijenu: ";
				cin >> cijena;
				itr->setcijena(cijena);
			}
		}
		cout << "Uspjesno ste promijenili stavku!" << endl<<endl;
		cout << "Upisite da za izmjenu stavke ili ne za izlaz: " << endl;
	upisNaredbe:
		cin >> naredba;
		if (naredba != "da" && naredba != "ne")
		{
			cout << " Niste dobro naredbu upisali, upisite da ili ne: " << endl;
			goto upisNaredbe;
		}
	} while (naredba!="ne");


	
	
	ispisiUDatoteku(popisStavki);
}

bool Skladiste::provjeriStanje(string naziv, int kolicina)
{
	Stavka stanje;
	list<Stavka>::iterator itr;
	naziv = stanje.formatirajNaziv(naziv);
	for (itr = popisStavki.begin();itr != popisStavki.end();++itr)
	{
		if (itr->getnaziv() == naziv)
		{
			if (itr->getkolicina() - kolicina >= 0)
			{
				return true;
			}
		}
	}
	
	return false;
}

void Skladiste::izmjenuKolicinuStavke(string naziv, int kolicina)
{
	
	Stavka objFormatiranje;
	if (popisStavki.empty())
	{
		dohvatiStavke();
	}
		naziv = objFormatiranje.formatirajNaziv(naziv);
		list<Stavka>::iterator itr;
		for (itr = popisStavki.begin();itr != popisStavki.end();++itr)
		{
			if (itr->getnaziv() == naziv)
			{
				itr->setkolicina(itr->getkolicina()-kolicina);
				
			}
		}

		
	ispisiUDatoteku(popisStavki);
}

double Skladiste::dohvatiCijenu(string naziv)
{

	Stavka objFormatiranje;
	naziv = objFormatiranje.formatirajNaziv(naziv);
	list<Stavka>::iterator itr;
	for (itr = popisStavki.begin();itr != popisStavki.end();++itr)
	{
		if (itr->getnaziv() == naziv)
		{
			return itr->getcijena();
		}
	}

	return 0;
}
