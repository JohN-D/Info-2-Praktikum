#pragma once
#include "aktivesvo.h"
#include "Weg.h"
#include <list>
class Fahrzeug;

class Kreuzung : public AktivesVO

{
public:
	Kreuzung(void);
	Kreuzung(string sName, double dTankstelle = 0.0);
	~Kreuzung(void);
	void vAnnahme(Fahrzeug* pFahrzeug, double dPause, Weg* pNeuerWeg);
	void vTanken(Fahrzeug* pFahrzeug);
	// HIN: zur anderen Kruezung
	// ZUR: zurück zur this-Kreuzung
	void vVerbinde(string sHin, string sZur, double dLaenge, Kreuzung* pZiel, Begrenzung limit, bool bUeberholverbot);
	void vPushWeg(Weg* wegfuehrend)		{ p_pWege.push_back(wegfuehrend); }
	virtual void vAbfertigung(void);
	virtual ostream& ostreamAusgabe(ostream& Ausgabe);
	virtual istream& istreamEingabe(istream& Eingabe);
	Weg* ptZufaelligerWeg(Weg* pHerkunft);
	double dGetTankstelle(void) {return p_dTankstelle;}
	Weg* pGetWeg(void)			{return *(p_pWege.begin());}

	virtual bool bIsKreuzung(void) {return true;}

private:
	double p_dTankstelle;
	list<Weg*> p_pWege;		// Liste aller wegführenden Wege

};

