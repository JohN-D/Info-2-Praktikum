#pragma once
#include "AktivesVO.h"

class Weg;
class FzgVerhalten;
class Fahrrad;
class PKW;
class FzgFahren;
class FzgParken;

#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

extern double dGlobaleZeit;

class Fahrzeug : public AktivesVO
{
public:
	Fahrzeug(void) : AktivesVO() {vInitialisierung();};
	Fahrzeug(string sName);
	Fahrzeug(string sName, double dMaxGeschwindigkeit);
	Fahrzeug(const Fahrzeug& objekt);
	virtual ~Fahrzeug(void);
	virtual double dTanken(double dMenge=0.0);
	virtual double dGeschwindigkeit();
	virtual void vAbfertigung(void);
	bool operator<(Fahrzeug& objekt);
	virtual Fahrzeug& operator=(Fahrzeug& objekt);
	virtual ostream& ostreamAusgabe(ostream& Ausgabe);
	virtual istream& istreamEingabe(istream& Eingabe);
	virtual void vInitialisierung(void);
	// Fahrzeug auf neuem Weg => Zeiger verweist nun auf neue Instanz
	// Die alte Instanz bleibt bestehen, kein Zeiger zeigt mehr auf diese Speicherstelle
	void vNeueStrecke(Weg* pWeg);
	void vNeueStrecke(Weg* pWeg, double dStartzeit);
	double getAbschnittStrecke(void);
	virtual void vZeichnen(Weg* pWeg);
	virtual double dGetTankinhalt(void);
	FzgVerhalten* GetVerhalten(void) {return p_pVerhalten;}

protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dAbschnittStrecke;
	FzgVerhalten* p_pVerhalten;

};