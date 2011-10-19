#pragma once
#include "fahrzeug.h"
#include <math.h>
#include <iostream>
#include <iomanip>

class Weg;

using namespace std;

class Fahrrad :	public Fahrzeug
{
public:
	Fahrrad(void) : Fahrzeug() {}
	Fahrrad(string sName) : Fahrzeug(sName) {}
	Fahrrad(string sName, double dMaxGeschwindigkeit) : Fahrzeug(sName, dMaxGeschwindigkeit) {}
	Fahrrad(const Fahrrad& objekt) : Fahrzeug(objekt) {}
	virtual ~Fahrrad(void);
	virtual double dGeschwindigkeit(void);
	virtual ostream& ostreamAusgabe(ostream& Ausgabe);
	virtual istream& istreamEingabe(istream& Eingabe);
	virtual void vZeichnen(Weg* pWeg);

protected:


};