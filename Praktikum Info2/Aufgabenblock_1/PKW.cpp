#include "PKW.h"
#include <iostream>
using namespace std;
#include <iomanip>

extern double dGlobaleZeit;

PKW::~PKW(void)
{
	//cout << "Destruiere: " << p_sName << endl;
}

void PKW::vInitialisierung()
{
	p_dVerbrauch = 0;
	p_dTankvolumen = 55;
	p_dTankinhalt = 55/2;
	//cout << "Initialisiere AUTO" << endl;
}

PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen)
{
	this->PKW::vInitialisierung();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
	p_dVerbrauch = dVerbrauch;
	p_dTankvolumen = dTankvolumen;
	p_dTankinhalt = p_dTankvolumen / 2;
	//cout << "Konstruiere: " << p_sName << " mit " << p_dMaxGeschwindigkeit << "km/h " << p_dVerbrauch << "l Verbrauch und " << p_dTankvolumen << "l Tankvolumen" << endl;
}

double PKW::dTanken(double dMenge)
{
	// Menge zu groß oder default?
	if(dMenge+p_dTankinhalt > p_dTankvolumen || dMenge==0.0)
	{
		// Tanke nur so viel, wie passt!
		dMenge=p_dTankvolumen-p_dTankinhalt;
	}
	// Tanke
	p_dTankinhalt+=dMenge;
	cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setprecision(2);
	cout << "Es wurden in " << p_sName << " " << dMenge << "l getankt." << endl;
	cout << resetiosflags(ios::fixed) << resetiosflags(ios::left);
	return dMenge;
}

double PKW::dVerbrauch()
{
	cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setprecision(2);
	//cout << "Es wurden insgesamt " << p_dGesamtStrecke * p_dVerbrauch << "l verbraucht." << endl;
	cout << resetiosflags(ios::fixed) << resetiosflags(ios::left);
	return p_dGesamtStrecke * p_dVerbrauch;
}

void PKW::vAbfertigung()
{
	if(p_dTankinhalt > 0.01)
	{
		// Bisheriger Verbrauch
		double dTemp=this->dVerbrauch();
		this->Fahrzeug::vAbfertigung();
		// Verbrauch nach Abfertigung
		double dTemp2=this->dVerbrauch();
		// Verbrauch im Zeitschritt
		double dVerbrauch = dTemp2-dTemp;
		p_dTankinhalt-=dVerbrauch;
		if(p_dTankinhalt<0)
		{
			p_dTankinhalt=0;
		}
	}
	else
	{
		// Aktualisiere Zeit des Objektes
		p_dGesamtZeit=dGlobaleZeit;
	}
}

void PKW::vAusgabe()
{
	this->Fahrzeug::vAusgabe();
	cout << setw(16) << setiosflags(ios::right) << setiosflags(ios::fixed) << setprecision(2) << this->dVerbrauch();
	cout << setw(16) << p_dTankinhalt << endl;
	cout << resetiosflags(ios::right) << resetiosflags(ios::fixed);
}

double PKW::p_dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

ostream& PKW::ostreamAusgabe(ostream& Ausgabe)
{
	Ausgabe << setw(2) << setiosflags(ios::right) << p_iID;
	Ausgabe << setw(2) << "  ";
	Ausgabe << resetiosflags(ios::right);

	Ausgabe << setiosflags(ios::left);
	Ausgabe << setw(7) << p_sName;
	Ausgabe << setw(3) << ":";
	Ausgabe << resetiosflags(ios::left);

	Ausgabe << setiosflags(ios::fixed) << setprecision(2);
	Ausgabe << setw(6) << setiosflags(ios::right) << p_dMaxGeschwindigkeit;
	Ausgabe << setw(12) <<  p_dGesamtStrecke;
	Ausgabe << resetiosflags(ios::fixed) << resetiosflags(ios::right);

	Ausgabe << setw(16) << setiosflags(ios::right) << setiosflags(ios::fixed) << setprecision(2) << this->dVerbrauch();
	Ausgabe << setw(16) << p_dTankinhalt;
	Ausgabe << resetiosflags(ios::right) << resetiosflags(ios::fixed);

	return Ausgabe;
}

ostream& operator<<(ostream& out, PKW& objekt)
{
	objekt.PKW::ostreamAusgabe(out);
	return out;
}

PKW& PKW::operator=(PKW& objekt)
{
	// Kopiere alle Daten, evtl. interessant für spätere Vergleiche (z.B. vor und nach vAbfertigung())
	// Byteweise macht Probleme wegen des Strings
	this->p_sName = objekt.p_sName;
	this->p_iID = objekt.p_iID;
	this->p_dMaxGeschwindigkeit = objekt.p_dMaxGeschwindigkeit;
	this->p_dGesamtStrecke = objekt.p_dGesamtStrecke;
	this->p_dGesamtZeit = objekt.p_dGesamtZeit;
	this->p_dZeit = objekt.p_dZeit;
	this->p_dVerbrauch = objekt.p_dVerbrauch;
	this->p_dTankinhalt = objekt.p_dTankinhalt;
	this->p_dTankvolumen = objekt.p_dTankvolumen;
	return objekt;
}

PKW::PKW(const PKW& objekt)
{
	// Kopiere alle Daten, evtl. interessant für spätere Vergleiche (z.B. vor und nach vAbfertigung())
	// Byteweise macht Probleme wegen des Strings
	this->p_sName = objekt.p_sName;
	this->p_iID = objekt.p_iID;
	this->p_dMaxGeschwindigkeit = objekt.p_dMaxGeschwindigkeit;
	this->p_dGesamtStrecke = objekt.p_dGesamtStrecke;
	this->p_dGesamtZeit = objekt.p_dGesamtZeit;
	this->p_dZeit = objekt.p_dZeit;
	this->p_dVerbrauch = objekt.p_dVerbrauch;
	this->p_dTankinhalt = objekt.p_dTankinhalt;
	this->p_dTankvolumen = objekt.p_dTankvolumen;
}