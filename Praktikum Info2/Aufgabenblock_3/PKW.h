#pragma once
#include "Fahrzeug.h"

class Fahrrad;
class Fahrzeug;
class FzgVerhalten;
class Weg;
class FzgFahren;
class FzgParken;

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

extern double dGlobaleZeit;

class PKW : public Fahrzeug
{
public:
	PKW(void) : Fahrzeug() {vInitialisierung();};
	PKW(string sName) : Fahrzeug(sName) {vInitialisierung();};
	PKW(string sName, double dMaxGeschwindigkeit) : Fahrzeug(sName, dMaxGeschwindigkeit) {vInitialisierung();};
	PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen = 55);
	PKW(const PKW& objekt);
	virtual ~PKW(void);
	virtual void vAbfertigung(void);
	virtual double dTanken(double dMenge=0.0);
	double dVerbrauch();
	virtual double dGeschwindigkeit(void);
	virtual ostream& ostreamAusgabe(ostream& Ausgabe);
	virtual istream& istreamEingabe(istream& Eingabe);
	virtual PKW& operator=(PKW& objekt);
	virtual void vInitialisierung(void);
	virtual void vZeichnen(Weg* pWeg);
	virtual double dGetTankinhalt(void);

protected:
	
private:
	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;

};