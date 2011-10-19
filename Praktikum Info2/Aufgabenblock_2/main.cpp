#pragma warning(disable: 4786)
#include "AktivesVO.h"
#include "Fahrrad.h"
#include "Fahrzeug.h"
#include "FzgVerhalten.h"
#include "PKW.h"
#include "Weg.h"
#include "SimuClient.h"

#include "LazyListe.h"
#include "LazyAktion.h"

#include <Windows.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

double dGlobaleZeit = 0.0;
int AktivesVO::p_iMaxID=0;

void vAufgabe_3();
void vAufgabe_4();
void vAufgabe_5();
void vAufgabe_6();
void vAufgabe_6a();

void main()
{
	//vAufgabe_3();
	//vAufgabe_4();
	//vAufgabe_5();
	vAufgabe_6();
	//vAufgabe_6a();
	system("PAUSE");
}

void vAufgabe_6a()
{
	LazyListe<int> liste;
	for(int i=0; i<25; i++)
	{
		liste.push_front((int) (rand()%10 + 1));	
	}
	liste.vAktualisieren();
	for(LazyListe<int>::iterator it = liste.begin(); it != liste.end(); it++)
	{
		cout << *it << " ";
	}
	for(LazyListe<int>::iterator it = liste.begin(); it != liste.end(); it++)
	{
		if((*it)>5)
		{
			liste.erase(it);
		}
	}
	cout << endl << "Ausgabe VOR Aktualisierung" << endl;
	for(LazyListe<int>::iterator it = liste.begin(); it != liste.end(); it++)
	{
		cout << *it << " ";
	}
	liste.vAktualisieren();
	cout << endl << "Ausgabe NACH Aktualisierung" << endl;
	for(LazyListe<int>::iterator it = liste.begin(); it != liste.end(); it++)
	{
		cout << *it << " ";
	}
	liste.push_back(42);
	liste.push_front(77);
	liste.vAktualisieren();
	cout << endl << "Ausgabe mit zwei neuen Zahlen" << endl;
	for(LazyListe<int>::iterator it = liste.begin(); it != liste.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void vAufgabe_6()
{
	bInitialisiereGrafik(800, 500);
	int Koordinaten[4]={700, 250, 100, 250};
	bZeichneStrasse("StrasseHin", "StrasseZur", 500, 2, Koordinaten);
	vSetzeZeit(0);
	Weg StrasseHin("StrasseHin", 500, Autobahn);
	Weg StrasseZurueck("StrasseZur", 500, Autobahn);
	PKW Auto1("Auto1", 140, 2);
	PKW Fahr1("Fahr1", 30);
	StrasseHin.vAnnahme(&Auto1, 1);
	StrasseZurueck.vAnnahme(&Fahr1);
	StrasseHin.vAbfertigung();
	StrasseZurueck.vAbfertigung();
	Auto1.vZeichnen(&StrasseHin);
	Fahr1.vZeichnen(&StrasseZurueck);
	for(int i=0; i<100; i++)
	{
		Sleep(500);
		dGlobaleZeit+=0.3;
		vSetzeZeit(dGlobaleZeit);
		StrasseHin.vAbfertigung();
		StrasseZurueck.vAbfertigung();
		Auto1.vZeichnen(&StrasseHin);
		Fahr1.vZeichnen(&StrasseZurueck);
	}
	vBeendeGrafik();
}

void vAufgabe_5()
{
	bInitialisiereGrafik(800, 500);
	int Koordinaten[4]={700, 250, 100, 250};
	bZeichneStrasse("StrasseHin", "StrasseZur", 500, 2, Koordinaten);
	vSetzeZeit(0);
	Weg StrasseHin("StrasseHin", 500, Innerorts);
	Weg StrasseZurueck("StrasseZur", 500, Innerorts);
	PKW Auto1("Auto1", 140, 7);
	PKW Fahr1("Fahr1", 30);
	StrasseHin.vAnnahme(&Auto1, 1);
	StrasseZurueck.vAnnahme(&Fahr1);
	Auto1.vZeichnen(&StrasseHin);
	Fahr1.vZeichnen(&StrasseZurueck);
	StrasseHin.vAbfertigung();
	StrasseZurueck.vAbfertigung();
	for(int i=0; i<100; i++)
	{
		Sleep(500);
		dGlobaleZeit+=0.3;
		vSetzeZeit(dGlobaleZeit);
		StrasseHin.vAbfertigung();
		StrasseZurueck.vAbfertigung();
		Auto1.vZeichnen(&StrasseHin);
		Fahr1.vZeichnen(&StrasseZurueck);
		system("PAUSE");
	}
	vBeendeGrafik();
}

void vAufgabe_4()
{
	Weg Strasse("Strasse", 200, Innerorts);
	PKW Auto1("Auto1", 140, 7);
	PKW Fahr1("Auto2", 70, 0.08);
	Strasse.vAnnahme(&Auto1);
	Strasse.vAnnahme(&Fahr1, 2);
	cout << Strasse << endl << Auto1 << endl << Fahr1 << endl << endl;
	for(int i=0; i<10; i++)
	{
		dGlobaleZeit+=0.5;
		Strasse.vAbfertigung();
		cout << Strasse << endl << Auto1 << endl << Fahr1 << endl << endl;
		system("PAUSE");
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