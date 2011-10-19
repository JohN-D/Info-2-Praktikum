#include "Kreuzung.h"
#include "Weg.h"
#include "PKW.h"
#include "Fahrrad.h"

Kreuzung::Kreuzung(void)
{
}

Kreuzung::Kreuzung(string sName, double dTankstelle)
{
	p_sName=sName;
	vAnmeldung();
	p_dTankstelle=dTankstelle;
}

Kreuzung::~Kreuzung(void)
{
}

void Kreuzung::vVerbinde(string sHin, string sZur, double dLaenge, Kreuzung* pZiel, Begrenzung limit, bool bUeberholverbot)
{
	Weg* hin = new Weg(sHin, dLaenge, limit, bUeberholverbot);
	Weg* zur = new Weg(sZur, dLaenge, limit, bUeberholverbot);
	hin->vSetRueckweg(zur);
	hin->vSetZiel(pZiel);
	zur->vSetRueckweg(hin);
	zur->vSetZiel(this);
	p_pWege.push_back(hin);
	pZiel->vPushWeg(zur);
}

void Kreuzung::vTanken(Fahrzeug* pFahrzeug)
{
	if(p_dTankstelle > 0)
	{
		p_dTankstelle -= pFahrzeug->dTanken();
		if(p_dTankstelle < 0)
		{
			p_dTankstelle = 0;
		}
	}
}

void Kreuzung::vAnnahme(Fahrzeug* pFahrzeug, double dPause, Weg* pNeuerWeg)
{
	vTanken(pFahrzeug);
	pNeuerWeg->vAnnahme(pFahrzeug, dPause);
}

void Kreuzung::vAbfertigung(void)
{
	list <Weg*>::iterator it;
	for(it = p_pWege.begin(); it != p_pWege.end(); it++)
	{
		(*it)->vAbfertigung();
	}
}

ostream& Kreuzung::ostreamAusgabe(ostream& Ausgabe)
{
	Ausgabe << "Von " << p_iID << " " << setiosflags(ios::fixed) << setprecision(2) << p_sName << " (Tankinhalt: " << p_dTankstelle << "l) gehen folgende Wege ab:" << endl << resetiosflags(ios::fixed);
	list <Weg*>::iterator it;
	for(it = p_pWege.begin(); it != p_pWege.end(); it++)
	{
		Ausgabe << (*(*it)) << endl;
	}
	return Ausgabe;
}
istream& Kreuzung::istreamEingabe(istream& Eingabe)
{
	AktivesVO::istreamEingabe(Eingabe);
	Eingabe>>p_dTankstelle;
	return Eingabe;
}
Weg* Kreuzung::ptZufaelligerWeg(Weg* pHerkunft)
{
	unsigned int iAnzahl = p_pWege.size();
	// SACKGASSE
	if(iAnzahl == 1)
	{
		return pHerkunft->vGetRueckweg();
	}
	// KEINE SACKGASSE
	else
	{
		// LAS VEGAS ALGORITHMUS
		// terminiert, wenn er ein Ergebnis hat
		// kein gültiges Ergebnis durch vorherige Abfrage ausgeschlossen
		
		// DEKLARATIONEN
		int iZufallszahl;
		int iCounter;
		list <Weg*>::iterator it;
		
		while(1)
		{
			// RESETTE ITERATOR
			it = p_pWege.begin();
			// BESTIMME ZUFALLSZAHL ZWISCHEN 0 und ANZAHL-1
			iZufallszahl = rand() % iAnzahl;
			// SETZE ITERATOR AUF DIE STELLE
			for(iCounter = 0; iCounter < iZufallszahl; iCounter++)
			{
				it++;
			}
			// NEUER WEG? => RETURN
			if((*it) != pHerkunft->vGetRueckweg())
			{
				return (*it);
			}
			// NEUER VERSUCH!
		}
	}
}