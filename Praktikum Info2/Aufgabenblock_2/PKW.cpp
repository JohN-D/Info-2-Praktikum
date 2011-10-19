#include "PKW.h"
#include "FzgVerhalten.h"
#include "FzgFahren.h"
#include "FzgParken.h"
#include "Weg.h"
#include "SimuClient.h"

PKW::~PKW(void)
{
	//cout << "Destruiere: " << p_sName << endl;
}

void PKW::vInitialisierung()
{
	p_dVerbrauch = 0;
	p_dTankvolumen = 55;
	p_dTankinhalt = 27.5;
	//cout << "Initialisiere AUTO" << endl;
}

PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen)
{
	vInitialisierung();
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
	return p_dGesamtStrecke / 100 * p_dVerbrauch;
}

void PKW::vAbfertigung()
{
	if(p_dTankinhalt > 0.01)
	{
		// Bisheriger Verbrauch
		double dTemp=dVerbrauch();
		this->Fahrzeug::vAbfertigung();
		// Verbrauch nach Abfertigung
		double dTemp2=dVerbrauch();
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

double PKW::dGeschwindigkeit()
{
	Weg* temp = p_pVerhalten->getWegpointer();
	Begrenzung limit = temp->getBegrenzung();
	if(p_dMaxGeschwindigkeit>limit)
	{
		return limit;
	}
	else
	{
		return p_dMaxGeschwindigkeit;
	}
}

ostream& PKW::ostreamAusgabe(ostream& Ausgabe)
{
	Fahrzeug::ostreamAusgabe(Ausgabe);

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
	p_sName = objekt.p_sName;
	p_iID = objekt.p_iID;
	p_dMaxGeschwindigkeit = objekt.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = objekt.p_dGesamtStrecke;
	p_dGesamtZeit = objekt.p_dGesamtZeit;
	p_dZeit = objekt.p_dZeit;
	p_dVerbrauch = objekt.p_dVerbrauch;
	p_dTankinhalt = objekt.p_dTankinhalt;
	p_dTankvolumen = objekt.p_dTankvolumen;
	return objekt;
}

PKW::PKW(const PKW& objekt)
{
	// Kopiere alle Daten, evtl. interessant für spätere Vergleiche (z.B. vor und nach vAbfertigung())
	// Byteweise macht Probleme wegen des Strings
	p_sName = objekt.p_sName;
	p_iID = objekt.p_iID;
	p_dMaxGeschwindigkeit = objekt.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = objekt.p_dGesamtStrecke;
	p_dGesamtZeit = objekt.p_dGesamtZeit;
	p_dZeit = objekt.p_dZeit;
	p_dVerbrauch = objekt.p_dVerbrauch;
	p_dTankinhalt = objekt.p_dTankinhalt;
	p_dTankvolumen = objekt.p_dTankvolumen;
	p_iMaxID--;
}

void PKW::vZeichnen(Weg* pWeg)
{
	double dTemp=p_dAbschnittStrecke/pWeg->getLaenge();
	if(dTemp<0.01)
	{
		dTemp=0.001;
	}
	bZeichnePKW(p_sName, pWeg->getName(), dTemp, dGeschwindigkeit(), p_dTankinhalt);
}