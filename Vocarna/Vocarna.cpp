#include <iostream>
#include<string>
#include"Skladiste.h"
#include "Kupnja.h"

using namespace std;


int main()
{
	Skladiste s; 
	Kupnja kProizvod;
	
	cout << "----------Vocarna----------" << endl << endl << endl;
	glavniIzbornik:
	cout << "1. Skladiste" << endl << "2. Kupnja" <<endl<<"3. Izlaz"<< endl << endl;
	cout << "Upisite broj opcije u koju zelite uci:  "<<endl;
	int opcija; 
	izbornikOpcija:
	cin >> opcija;

	switch (opcija) {
	case 1:
		system("cls");
		cout << "---Dobrodosli u skladiste--- " << endl<<endl<<endl;
	izbornikOpcijaSkladiste:
		int opcijaSkladiste;
		cout << endl<<endl<<"1. Ispisi sve stavke" << endl << "2. Dodaj stavku" << endl << "3. Obrisi stavku" << endl<< "4. Izmjeni stavku"<<endl<< "5. Povratak u izbornik"<< endl << endl<<endl;
		cout << "Upisite broj opcije u koju zelite uci:  "<<endl;

		cin >> opcija;
		switch (opcija)
		{
		case 1:

			system("cls");
			s.ispisiSkladiste();
			cout << endl << endl << "Odaberite 1 za izlaz ili 2 za povratak u skladiste:"<<endl;
			cin >> opcijaSkladiste;
			if (opcijaSkladiste == 1)
			{
				cout << " Izasli ste iz programa " << endl << endl;
				goto izlaz;
			}
			else
			{
				system("cls");
				goto izbornikOpcijaSkladiste;
			}
		case 2:

			system("cls");
			s.dodajStavku();
			cout << endl << endl << "Odaberite 1 za izlaz ili 2 za povratak u skladiste: "<<endl;
			cin >> opcijaSkladiste;
			if (opcijaSkladiste == 1)
			{
				cout << "  Izasli ste iz programa " << endl << endl;
				goto izlaz;
			}
			else
			{
				system("cls");
				goto izbornikOpcijaSkladiste;
			}
		case 3:
			system("cls");
			s.obrisiStavku();
			cout << endl << endl << "Odaberite 1 za izlaz ili 2 za povratak u skladiste: "<<endl;
			cin >> opcijaSkladiste;
			if (opcijaSkladiste == 1)
			{
				system("cls");
				goto glavniIzbornik;
			}
			else
			{
				system("cls");
				goto izbornikOpcijaSkladiste;
			}
		case 4:
			system("cls");
			s.izmjeniStavku();
			cout <<endl<<endl<<"Odaberite 1 za povratak u glavni izbornik ili 2 za povratak u skladiste: "<<endl;
			cin >> opcijaSkladiste;
			if (opcijaSkladiste == 1)
			{
				system("cls");
				goto glavniIzbornik;
			}
			else
			{
				system("cls");
				goto izbornikOpcijaSkladiste;
			}
		case 5: 
			system("cls");
			goto 	glavniIzbornik;

		default:
			cout <<endl<<endl<< "Molimo vas upisite opciju u koju zelite uci: "<<endl;
			goto izbornikOpcijaSkladiste;
		}
	case 2:
		kupnja:
		system("cls");
		int naredba;
		cout << "---Dobrodosli u izbornik za kupnju--- " << endl<<endl<<endl;
		kProizvod.kupnjaStavke();
		cout << endl << endl << endl << "Hvala vam na kupnji, dodite nam opet!" << endl << endl;

		return 0;
	case 3:
		izlaz:
		system("cls");
		cout << "Dovidenja!"<<endl<<endl<<endl<<endl;
		return 0;
		break;
	default:
		cout << "Molimo vas upisite opciju u koju zelite uci: ";
		goto izbornikOpcija;
	}

}


