#pragma warning(disable: 4786)
#include "AktivesVO.h"
#include "Fahrrad.h"
#include "Fahrzeug.h"
#include "FzgVerhalten.h"
#include "PKW.h"
#include "Weg.h"
#include "SimuClient.h"
#include "Welt.h"

#include "LazyListe.h"
#include "LazyAktion.h"
#include "Kreuzung.h"

#include <Windows.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

double dGlobaleZeit = 0.0;
int AktivesVO::p_iMaxID=0;


void vAufgabe_7();
void vAufgabe_7b();	
void vAufgabe_8();
void vAufgabe_9();


void main()
{
	//vAufgabe_7();	
	//vAufgabe_7b();
	//vAufgabe_8();
	vAufgabe_9();
	system("PAUSE");
}

void vAufgabe_9()
{
	bInitialisiereGrafik(1000, 1000);
	ifstream infile("SimuDisplay.dat");
	Welt world;

	try
	{
		world.vEinlesenMitGrafik(infile);
	}
	catch(const char* sError)
	{
		cout<<sError;
	}
	while(dGlobaleZeit < 500)
	{
		world.vSimulation();
		dGlobaleZeit+=0.3;
		vSetzeZeit(dGlobaleZeit);
		
	}

}


void vAufgabe_8()
{
	// ERZEUGUNG KREUZUNGEN
	Kreuzung Kr1("Kr1");
	Kreuzung Kr2("Kr2", 1000);
	Kreuzung Kr3("Kr3");
	Kreuzung Kr4("Kr4");

	// VERBINDUNG DER KREUZUNGEN
	Kr1.vVerbinde("W12", "W21", 40, &Kr2, Innerorts, true);
	Kr2.vVerbinde("W23a", "W32a", 115, &Kr3, Autobahn, false);
	Kr2.vVerbinde("W23b", "W32b", 40, &Kr3, Innerorts, true);
	Kr2.vVerbinde("W24", "W42", 55, &Kr4, Innerorts, true);
	Kr3.vVerbinde("W34", "W43", 85, &Kr4, Autobahn, false);
	Kr4.vVerbinde("W44a", "W44b", 130, &Kr4, Landstraße, false);

	// ERZEUGUNG VON FAHRZEUGEN
	PKW Auto1("Auto1", 170, 7);
	PKW Auto2("Auto2", 120, 5);
	PKW Auto3("Auto3", 110, 8);
	PKW Auto4("Auto4", 230, 9);
	PKW Auto5("Auto5", 200, 5);
	PKW Auto6("Auto6", 190, 5);
	Fahrrad Fahr1("Fahr1", 30);
	Fahrrad Fahr2("Fahr2", 20);
	Fahrrad Fahr3("Fahr3", 50);

	// ANNAHME AUF DIE KREUZUNGEN
	Kr1.vAnnahme(&Auto1, 0, Kr1.pGetWeg());
	Kr1.vAnnahme(&Auto2, 0, Kr1.pGetWeg());
	Kr2.vAnnahme(&Auto3, 1, Kr2.pGetWeg());
	Kr3.vAnnahme(&Auto4, 3, Kr3.pGetWeg());
	Kr4.vAnnahme(&Auto5, 2, Kr4.pGetWeg());
	Kr2.vAnnahme(&Fahr1, 0, Kr2.pGetWeg());
	Kr3.vAnnahme(&Fahr2, 1, Kr3.pGetWeg());
	Kr4.vAnnahme(&Fahr3, 2, Kr4.pGetWeg());

	Kr1.vAbfertigung();
	Kr2.vAbfertigung();
	Kr3.vAbfertigung();
	Kr4.vAbfertigung();

	// AUSGABE DER KREUZUNGEN
	cout << Kr1 << endl;
	cout << Kr2 << endl;
	cout << Kr3 << endl;
	cout << Kr4 << endl;

	// Felder für Straßenzüge erzeugen
	int iStrasse1[4]  = {680,300,680,40};
	int iStrasse2[12] = {680,570,850,570,970,500,970,390,850,300,680,300};
	int iStrasse3[4]  = {680,570,680,300};
	int iStrasse4[4]  = {320,300,680,300};
	int iStrasse5[10] = {320,300,320,420,350,510,500,570,680,570};
	int iStrasse6[14] = {320,300,170,300,70,250,80,90,200,60,320,150,320,300};
	
	// ERZEUGE GRAFIKAUSGABE
	bInitialisiereGrafik(1024, 768);
	// Straßen zeichnen
	bZeichneStrasse("W21" ,"W12" , 40 , 2, iStrasse1);
	bZeichneStrasse("W32a","W23a", 115, 6, iStrasse2);
	bZeichneStrasse("W32b","W23b", 40 , 2, iStrasse3);
	bZeichneStrasse("W42" ,"W24" , 55 , 2, iStrasse4);
	bZeichneStrasse("W43" ,"W34" , 85 , 5, iStrasse5);
	bZeichneStrasse("W44a","W44b", 130, 7, iStrasse6);
	// Kreuzungen zeichnen
	bZeichneKreuzung(680,40);
	bZeichneKreuzung(680,300);
	bZeichneKreuzung(680,570);
	bZeichneKreuzung(320,300);

	// ABFERTIGUNG DER NAECHSTEN SCHRITTE
	for(int i=0; i<100000; i++)
	{
		//system("PAUSE");
		Sleep(10);
		dGlobaleZeit+=0.1;
		vSetzeZeit(dGlobaleZeit);
		Kr1.vAbfertigung();
		Kr2.vAbfertigung();
		Kr3.vAbfertigung();
		Kr4.vAbfertigung();
	}

	


}

void vAufgabe_7b()
{
	// ERZEUGUNG DER UMGEBUNG
	Weg StrasseHin("StrasseHin", 500, Landstraße);
	Weg StrasseZur("StrasseZur", 500, Landstraße);
	bInitialisiereGrafik(800, 500);
	int Koordinaten[4]={700, 250, 100, 250};
	bZeichneStrasse("StrasseHin", "StrasseZur", 500, 2, Koordinaten);
	vSetzeZeit(0);

	// ERZEUGUNG DER OBJEKTE
	PKW Auto1("Auto1", 50, 10);
	PKW Auto2("Auto2", 100, 2);
	StrasseHin.vAnnahme(&Auto1, 2);
	StrasseHin.vAnnahme(&Auto2, 4);
	StrasseHin.vAbfertigung();
	StrasseZur.vAbfertigung();
	Auto1.vZeichnen(&StrasseHin);
	Auto2.vZeichnen(&StrasseHin);

	// ABFERTIGUNG DER NAECHSTEN SCHRITTE
	for(int i=0; i<30; i++)
	{
		Sleep(500);
		dGlobaleZeit+=0.5;
		vSetzeZeit(dGlobaleZeit);
		StrasseHin.vAbfertigung();
		StrasseZur.vAbfertigung();
		Auto1.vZeichnen(&StrasseHin);
		Auto2.vZeichnen(&StrasseHin);
	}


}


void vAufgabe_7()
{
	// ERZEUGUNG DER UMGEBUNG
	Weg StrasseHin("StrasseHin", 500, Innerorts);
	Weg StrasseZur("StrasseZur", 500, Innerorts);
	bInitialisiereGrafik(800, 500);
	int Koordinaten[4]={700, 250, 100, 250};
	bZeichneStrasse("StrasseHin", "StrasseZur", 500, 2, Koordinaten);
	vSetzeZeit(0);

	// ERZEUGUNG DER OBJEKTE
	PKW Auto1("Auto1", 140, 5);
	PKW Auto2("Auto2", 200, 6);
	Fahrrad Fahr1("Fahr1", 50);
	StrasseHin.vAnnahme(&Auto1, 3);
	StrasseHin.vAnnahme(&Auto2, 15);
	StrasseHin.vAnnahme(&Fahr1, 2);
	StrasseHin.vAbfertigung();
	StrasseZur.vAbfertigung();
	Auto1.vZeichnen(&StrasseHin);
	Auto2.vZeichnen(&StrasseHin);
	Fahr1.vZeichnen(&StrasseHin);

	// ABFERTIGUNG DER NAECHSTEN SCHRITTE
	for(int i=0; i<30; i++)
	{
		Sleep(500);
		dGlobaleZeit+=1;
		vSetzeZeit(dGlobaleZeit);
		StrasseHin.vAbfertigung();
		StrasseZur.vAbfertigung();
		Auto1.vZeichnen(&StrasseHin);
		Auto2.vZeichnen(&StrasseHin);
		Fahr1.vZeichnen(&StrasseHin);
	}



}