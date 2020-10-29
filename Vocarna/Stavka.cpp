#include "Stavka.h"


Stavka::Stavka()
{
}

Stavka::~Stavka()
{
}




string Stavka::formatirajNaziv(string neformatiraniNaziv)
{
	string temp1, temp2;
	temp1 = toupper(neformatiraniNaziv[0]); 
	temp2 = neformatiraniNaziv.substr(1, neformatiraniNaziv.size() - 1);
	for (int i = 0;i < neformatiraniNaziv.size();i++)
	{
		temp2[i] = tolower(temp2[i]);
	}
	return temp1 + temp2;
}


string Stavka::getnaziv()
{
	return naziv;
}

void Stavka::setnaziv(string n)
{
	naziv = formatirajNaziv(n);
}
int Stavka::getkolicina()
{
	return kolicina;
}


void Stavka::setkolicina(int k)
{
	if (k < 0)
	{
		cout << "Greska pri unosu kolicine, kolicina je postavljena na nulu" << endl;
		k = 0;
	}
	kolicina = k;
}


double Stavka::getcijena()
{
	return cijena;
}

void Stavka::setcijena(double c)
{
	if (c < 0)
	{
		c = 0;
		cout << "Pogreska pri unosu cijene, cijena je postavljena na nulu" << endl;
	}
	cijena = c;
}





