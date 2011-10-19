#pragma once
#include "Fahrzeug.h"
#include <string>
using namespace std;

class PKW : public Fahrzeug
{
public:
	PKW(void) : Fahrzeug() {};
	PKW(string sName) : Fahrzeug(sName) {};
	PKW(string sName, double dMaxGeschwindigkeit) : Fahrzeug(sName, dMaxGeschwindigkeit) {};
	PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen = 55);
	PKW(const PKW& objekt);
	virtual ~PKW(void);
	virtual void vAusgabe(void);
	virtual void vAbfertigung(void);
	double dTanken(double dMenge=0.0);
	double dVerbrauch();
	virtual double p_dGeschwindigkeit(void);
	ostream& ostreamAusgabe(ostream& Ausgabe);
	virtual PKW& operator=(PKW& objekt);

protected:
	virtual void vInitialisierung(void);

private:
	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;

};