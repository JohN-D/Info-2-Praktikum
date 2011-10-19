#include "Fahrzeug.h"
#include "FzgFahren.h"
#include "FzgParken.h"

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
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dAbschnittStrecke = 0;
	p_pVerhalten = NULL;
}

double Fahrzeug::dTanken(double dMenge)
{
	cout << p_sName << " ist kein Auto: Nichts getankt." << endl;
	return 0;
}

double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

bool Fahrzeug::operator<(Fahrzeug& objekt)
{
	if (p_dGesamtStrecke < objekt.p_dGesamtStrecke)
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
	p_sName = objekt.p_sName;
	p_iID = objekt.p_iID;
	p_dMaxGeschwindigkeit = objekt.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = objekt.p_dGesamtStrecke;
	p_dGesamtZeit = objekt.p_dGesamtZeit;
	p_dZeit = objekt.p_dZeit;
	p_dAbschnittStrecke = objekt.p_dAbschnittStrecke;
	p_iMaxID--;
	return *this;
}

Fahrzeug::Fahrzeug(const Fahrzeug& objekt)
{
	// Kopiere alle Daten, evtl. interessant für spätere Vergleiche (z.B. vor und nach vAbfertigung())
	// Byteweise macht Probleme wegen des Strings
	p_sName = objekt.p_sName;
	p_iID = objekt.p_iID;
	p_dMaxGeschwindigkeit = objekt.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = objekt.p_dGesamtStrecke;
	p_dGesamtZeit = objekt.p_dGesamtZeit;
	p_dZeit = objekt.p_dZeit;
	p_dAbschnittStrecke = objekt.p_dAbschnittStrecke;
}

ostream& Fahrzeug::ostreamAusgabe(ostream& Ausgabe)
{
	AktivesVO::ostreamAusgabe(Ausgabe);
	
	Ausgabe << setiosflags(ios::fixed) << setprecision(2);
	Ausgabe << setw(6) << setiosflags(ios::right) << p_dMaxGeschwindigkeit;
	Ausgabe << setw(12) <<  p_dGesamtStrecke;
	Ausgabe << setw(8) << p_dAbschnittStrecke;
	Ausgabe << resetiosflags(ios::fixed) << resetiosflags(ios::right);

	return Ausgabe;
}

void Fahrzeug::vAbfertigung(void)
{
	if(fabs(dGlobaleZeit - p_dGesamtZeit) > 0.01)
	{
		// Bestimmung delta t
		double dDeltaT =  dGlobaleZeit - p_dZeit;
		// s = v*delta t
		double dTemp = p_pVerhalten->dStrecke(this, dDeltaT);
		p_dAbschnittStrecke += dTemp;
		p_dGesamtStrecke += dTemp;
		p_dGesamtZeit += dDeltaT;
		p_dZeit = dGlobaleZeit;
	}
}

ostream& operator<<(ostream& out, Fahrzeug& objekt)
{
	objekt.ostreamAusgabe(out);
	return out;
}

void Fahrzeug::vNeueStrecke(Weg* pWeg)
{
	// Verhinderung der Speicherlöcher
	if(pWeg != NULL)
	{
		delete p_pVerhalten;
	}
	p_pVerhalten=new FzgFahren(pWeg);
}

double Fahrzeug::getAbschnittStrecke()
{
	return p_dAbschnittStrecke;
}

void Fahrzeug::vNeueStrecke(Weg* pWeg, double dStartzeit)
{
	// Verhinderung der Speicherlöcher
	if(pWeg != NULL)
	{
		delete p_pVerhalten;
	}
	p_pVerhalten=new FzgParken(pWeg, dStartzeit);
}

void Fahrzeug::vZeichnen(Weg* pWeg)
{

}