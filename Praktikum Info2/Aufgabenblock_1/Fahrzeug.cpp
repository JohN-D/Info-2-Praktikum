#include "Fahrzeug.h"
#include <iostream>
using namespace std;
#include <iomanip>
#include <math.h>

extern double dGlobaleZeit;

Fahrzeug::Fahrzeug(void)
{
	vInitialisierung();
	p_sName = "";
	//cout << "VOID-KONSTRUKTOR" << p_sName << endl;
}

Fahrzeug::Fahrzeug(string sName)
{
	vInitialisierung();
	p_sName = sName;
	//cout << "Konstruiere: " << p_sName << endl;
}

Fahrzeug::Fahrzeug(string sName, double dMaxGeschwindigkeit)
{
	vInitialisierung();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
	//cout << "Konstruiere: " << p_sName << " mit " << p_dMaxGeschwindigkeit << " km/h" << endl;
}

Fahrzeug::~Fahrzeug(void)
{
	//cout << "Destruiere: " << p_sName << endl;
}

void Fahrzeug::vInitialisierung(void)
{
	p_sName = "";
	p_iMaxID++;
	p_iID = p_iMaxID;
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dZeit = 0;
	//cout << "Initialisiere FAHRZEUG" << endl;
}

void Fahrzeug::vAusgabe(void)
{
	cout << setw(2) << setiosflags(ios::right) << p_iID;
	cout << setw(2) << "  ";
	cout << resetiosflags(ios::right);

	cout << setiosflags(ios::left);
	cout << setw(7) << p_sName;
	cout << setw(3) << ":";
	cout << resetiosflags(ios::left);

	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << setw(6) << setiosflags(ios::right) << p_dMaxGeschwindigkeit;
	cout << setw(12) <<  p_dGesamtStrecke;
	cout << resetiosflags(ios::fixed) << resetiosflags(ios::right);
}

void Fahrzeug::vAbfertigung(void)
{
	if(fabs(dGlobaleZeit - p_dGesamtZeit) > 0.01)
	{
		// Bestimmung delta t
		double dDeltaT =  dGlobaleZeit - p_dGesamtZeit;
		// s = v*delta t
		p_dGesamtStrecke += dDeltaT * p_dGeschwindigkeit();
		p_dGesamtZeit += dDeltaT;
		p_dZeit = dGlobaleZeit;
	}
}

double Fahrzeug::dTanken(double dMenge)
{
	cout << p_sName << " ist kein Auto: Nichts getankt." << endl;
	return 0;
}

double Fahrzeug::p_dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

ostream& Fahrzeug::ostreamAusgabe(ostream& Ausgabe)
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
	return Ausgabe;
}

ostream& operator<<(ostream& out, Fahrzeug& objekt)
{
	objekt.ostreamAusgabe(out);
	return out;
}

bool Fahrzeug::operator<(Fahrzeug& objekt)
{
	if (this->p_dGesamtStrecke < objekt.p_dGesamtStrecke)
	{
		//cout << "KLEINER" << endl;
		return true;
	}
	//cout << "GROESSER" << endl;
	return false;
}

Fahrzeug& Fahrzeug::operator=(Fahrzeug& objekt)
{
	// Kopiere alle Daten, evtl. interessant für spätere Vergleiche (z.B. vor und nach vAbfertigung())
	// Byteweise macht Probleme wegen des Strings
	this->p_sName = objekt.p_sName;
	this->p_iID = objekt.p_iID;
	this->p_dMaxGeschwindigkeit = objekt.p_dMaxGeschwindigkeit;
	this->p_dGesamtStrecke = objekt.p_dGesamtStrecke;
	this->p_dGesamtZeit = objekt.p_dGesamtZeit;
	this->p_dZeit = objekt.p_dZeit;
	return *this;
}

Fahrzeug::Fahrzeug(const Fahrzeug& objekt)
{
	// Kopiere alle Daten, evtl. interessant für spätere Vergleiche (z.B. vor und nach vAbfertigung())
	// Byteweise macht Probleme wegen des Strings
	this->p_sName = objekt.p_sName;
	this->p_iID = objekt.p_iID;
	this->p_dMaxGeschwindigkeit = objekt.p_dMaxGeschwindigkeit;
	this->p_dGesamtStrecke = objekt.p_dGesamtStrecke;
	this->p_dGesamtZeit = objekt.p_dGesamtZeit;
	this->p_dZeit = objekt.p_dZeit;
}