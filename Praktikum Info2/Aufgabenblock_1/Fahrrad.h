#pragma once
#include "fahrzeug.h"

class Fahrrad :	public Fahrzeug
{
public:
	Fahrrad(void) : Fahrzeug() {}
	Fahrrad(string sName) : Fahrzeug(sName) {}
	Fahrrad(string sName, double dMaxGeschwindigkeit) : Fahrzeug(sName, dMaxGeschwindigkeit) {}
	Fahrrad(const Fahrrad& objekt) : Fahrzeug(objekt) {}
	virtual ~Fahrrad(void);
	virtual double p_dGeschwindigkeit(void);
	virtual void vAusgabe(void);
	ostream& ostreamAusgabe(ostream& Ausgabe);

protected:

};