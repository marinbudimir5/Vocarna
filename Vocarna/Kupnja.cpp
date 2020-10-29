#include "Kupnja.h"
#include<iostream>
#include<string>

using namespace std;

Kupnja::Kupnja()
{
}

Kupnja::~Kupnja()
{
}

void Kupnja::kupnjaStavke()
{
	string naziv, naredba;
	int kolicina;
	Stavka kupljenoVoce;
	
	objKupnja.ispisiSkladiste();
	do
	{
	upisProizvoda:
		cout << endl << endl << "Upisite naziv proizvoda kojeg zelite kupiti: ";
		cin >> naziv;
		cout << endl << "Upisite kolicinu proizvoda kojeg zelite kupiti: ";
		cin >> kolicina;

		if (objKupnja.provjeriStanje(naziv, kolicina) == false)
		{
			system("cls");
			cout << endl << "---" << endl << "---" << endl << "Nema tog proizvoda ili kolicine, provjerite stanje pa pokusajte ponovo " << endl << "---" << endl << "---" << endl;
			objKupnja.ispisiSkladiste();
			goto upisProizvoda;
		}
		else
		{
			objKupnja.izmjenuKolicinuStavke(naziv, kolicina);
			kupljenoVoce.setnaziv(naziv);
			kupljenoVoce.setkolicina(kolicina);
			kupljenoVoce.setcijena(objKupnja.dohvatiCijenu(naziv));
			listaKupljenihStavki.push_back(kupljenoVoce);
		}

		cout << "Upisite da za kupnju druge stavke ili ne za izlaz: " << endl;
	upisNaredbe:

		cin >> naredba;
		if (naredba != "da" && naredba != "ne")
		{
			cout << " Niste dobro naredbu upisali, upisite da ili ne: " << endl;
			goto upisNaredbe;
		}
	} while (naredba != "ne");

	system("cls");
	objRacun.ispisiRacun(listaKupljenihStavki);

	

}


