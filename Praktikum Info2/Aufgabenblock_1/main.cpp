#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include <vector>
#include <math.h>

double dGlobaleZeit = 0.0;
int Fahrzeug::p_iMaxID=0;

void vAufgabe_1();
void vAufgabe_1_deb();
void vAufgabe_2();
void vAufgabe_3();

void main()
{
	//vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	//vAufgabe_3();
	system("PAUSE");
}

void vAufgabe_1()
{
	// Objekterzeugung durch Deklaration
	Fahrzeug Auto1;
	Fahrzeug Auto2("Karto", 140);

	// dynamische Objekterzeugung
	Fahrzeug* p1 = new Fahrzeug();
	cout << "Name fuer das Fahrzeug: ";
	string sName;
	cin >> sName;
	Fahrzeug* p2 = new Fahrzeug(sName, 50);

	// Ausgabe Spaltenbeschriftung
	cout << setiosflags(ios::left);
	cout << setw(4) << "ID";
	cout << setw(7) << "Name";
	cout << setw(3) << ":";
	cout << setw(9) << "MaxKmH";
	cout << setw(19) << "GesamtStrecke" << endl;
	cout << setw(42) << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << resetiosflags(ios::left);

	// Ausgabe der Elemente
	Auto1.vAusgabe();
	cout << endl;
	Auto2.vAusgabe();
	cout << endl;
	p1->vAusgabe();
	cout << endl;
	p2->vAusgabe();
	cout << endl;

	// Ausgabe nach Zeitschritten
	for(unsigned int i=0; i<5; i++)
	{
		// Berechnung nächster Zeitschritt
		dGlobaleZeit += 0.5;
		Auto1.vAbfertigung();
		Auto2.vAbfertigung();
		p1->vAbfertigung();
		p2->vAbfertigung();

		// Ausgabe Zeit
		cout << setw(5) << setiosflags(ios::left) << "Zeit: ";
		cout << resetiosflags(ios::left);
		cout << setw(5) << setiosflags(ios::right) << setiosflags(ios::fixed) << setprecision(2) << dGlobaleZeit << endl;
		cout << resetiosflags(ios::right) << resetiosflags(ios::fixed);
		
		// Ausgabe nächster Zeitschritt
		Auto1.vAusgabe();
		cout << endl;
		Auto2.vAusgabe();
		cout << endl;
		p1->vAusgabe();
		cout << endl;
		p2->vAusgabe();
		cout << endl;
	}

	// Destruieren
	delete p2;
	delete p1;
}

void vAufgabe_1_deb(void)
{
	// Ausgabe Spaltenbeschriftung
	cout << setiosflags(ios::left);
	cout << setw(4) << "ID";
	cout << setw(7) << "Name";
	cout << setw(3) << ":";
	cout << setw(9) << "MaxKmH";
	cout << setw(19) << "GesamtStrecke" << endl;
	cout << setw(42) << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << resetiosflags(ios::left);

	// Dynamische Erzeugung der Objekte, Pointer in Array
	Fahrzeug* Auto[4];
	for(int i=0; i<4; i++)
	{
		Auto[i]= new Fahrzeug();
	}
	
	cout << setw(42) << setiosflags(ios::left) << "Neue Ausgabe: " << endl;
	resetiosflags(ios::left);

	// Manipulation von Auto[2]
	Auto[2]=0;

	// Erneute Ausgabe
	for(int i=0; i<4; i++)
	{
		Auto[i]->vAusgabe();
		cout << endl;
	}
}

void vAufgabe_2()
{
	// Deklarationen
	string sName;
	double dMaxGeschwindigkeit, dVerbrauch, dTankvolumen;
	unsigned int iAutos, iFahrraeder, iGesamt;
	
	// Bestimmung der Anzahlen und Erzeugung des Vektors
	cout << "Anzahl der Autos      : ";
	cin >> iAutos;
	cout << "Anzahl der Fahrraeder : ";
	cin >> iFahrraeder;
	iGesamt = iAutos + iFahrraeder;
	vector<Fahrzeug*> feld(iGesamt);

	// Dynamische Erzeugung der Objekte mit interaktiver Parametereingabe
	for(unsigned int i=0; i<iGesamt; i++)
	{
		// Erzeugung der PKWs
		if(i<iAutos)
		{
			cout << "Konstruiere Auto     ->" << endl;
			cout << "Name                  : ";
			cin >> sName;
			cout << "Maximalgeschwindigkeit: ";
			cin >> dMaxGeschwindigkeit;
			cout << "Verbrauch             : ";
			cin >> dVerbrauch;
			cout << "Tankvolumen           : ";
			cin >> dTankvolumen;
			feld[i] = new PKW(sName, dMaxGeschwindigkeit, dVerbrauch, dTankvolumen);
		}
		// Erzeugung der Fahrräder
		else
		{
			cout << "Konstruiere Fahrrad  ->" << endl;
			cout << "Name                  : ";
			cin >> sName;
			cout << "Maximalgeschwindigkeit: ";
			cin >> dMaxGeschwindigkeit;
			feld[i] = new Fahrrad(sName, dMaxGeschwindigkeit);
		}
	}

	// Ausgabe Spaltenbeschriftung
	cout << setiosflags(ios::left) << endl;
	cout << setw(4) << "ID";
	cout << setw(7) << "Name";
	cout << setw(3) << ":";
	cout << setw(9) << "MaxKmH";
	cout << setw(15) << "GesamtStrecke";
	cout << setw(18) << "Gesamtverbrauch";
	cout << setw(12) << "Tankinhalt";
	cout << setw(10) << "Momentang." << endl;
	cout << setw(82) << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << resetiosflags(ios::left);

	// Schrittweise Abfertigung und Ausgabe
	for(unsigned int i=0; i<10; i++)
	{
		cout << "Zeit: " << dGlobaleZeit << endl;
		// Bearbeitung aller Elemente
		for(unsigned int j=0; j<iGesamt; j++)
		{
			// TANKEN?
			if(fabs(dGlobaleZeit - 3.0) < 0.01)
			{
				cout << "TANKEN" << endl;
				feld[j]->dTanken();
			}
			feld[j]->vAbfertigung();
			feld[j]->vAusgabe();
		}
		dGlobaleZeit+=0.5;
	}
}

void vAufgabe_3()
{
	// Erzeugung der Objekte
	Fahrzeug Fahrzeug1("Fahr1", 20);
	Fahrzeug Fahrzeug2("Fahr2", 30);
	PKW Auto1("Auto1", 30, 0.7);
	PKW Auto2("Auto2", 40, 0.8, 40);
	Fahrrad Rad1("Rad1", 20);
	Fahrrad Rad2("Rad2", 30);
	
	// Abfertigung nach Zeitschritt
	dGlobaleZeit+=0.5;
	cout << "ABFERTIGUNG" << endl;
	Fahrzeug1.vAbfertigung();
	Fahrzeug2.vAbfertigung();
	Auto1.vAbfertigung();
	Auto2.vAbfertigung();
	Rad1.vAbfertigung();
	Rad2.vAbfertigung();
	
	// Vergleiche
	cout << Fahrzeug1 << endl << Auto1 << endl;
	if(Fahrzeug1<Auto1)
	{
		cout << "Fahr1 ist nicht so weit wie Auto1 gefahren." << endl;
	}
	else
	{
		cout << "Fahr1 ist weiter als Auto1 gefahren." << endl;
	}
	cout << Rad2 << endl << Auto2 << endl;
	if(Rad2<Auto2)
	{
		cout << "Rad2 ist nicht so weit wie Auto2 gefahren." << endl << endl;
	}
	else
	{
		cout << "Rad2 ist weiter als Auto2 gefahren." << endl << endl;
	}

	cout << "Befehl: Fahrzeug1=Fahrzeug2;" << endl;
	cout << Fahrzeug1 << endl << Fahrzeug2 << endl;
	Fahrzeug1=Fahrzeug2;
	cout << "Ausgabe von Fahrzeug1 (kompletter Klon):" << endl;
	cout << Fahrzeug1 << endl << endl;

	cout << "Befehl: Rad1=Rad2;" << endl;
	cout << Rad1 << endl << Rad2 << endl;
	Rad1=Rad2;
	cout << "Ausgabe von Rad1 (kompletter Klon):" << endl;
	cout << Rad1 << endl << endl;

	cout << "Befehl: Auto1=Auto2;" << endl;
	cout << Auto1 << endl << Auto2 << endl;
	Auto1=Auto2;
	cout << "Ausgabe von Auto1 (kompletter Klon):" << endl;
	cout << Auto1 << endl << endl;

	cout << "COPY-KONSTRUKTOR; Kopie von Fahrzeug1" << endl;
	Fahrzeug Kopie(Fahrzeug1);
	cout << Kopie << endl << endl;

	cout << "COPY-KONSTRUKTOR; Kopie von Fahrrad1" << endl;
	Fahrrad Kopie2(Rad1);
	cout << Kopie2 << endl << endl;

	cout << "COPY-KONSTRUKTOR; Kopie von Auto1" << endl;
	PKW Kopie3(Auto1);
	cout << Kopie3 << endl << endl;
}