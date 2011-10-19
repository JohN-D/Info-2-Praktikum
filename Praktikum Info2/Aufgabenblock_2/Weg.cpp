#pragma warning(disable: 4786)
#include "Weg.h"

#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "AktivesVO.h"
#include "FzgVerhalten.h"
#include "Losfahren.h"
#include "Streckenende.h"
#include "LazyAktion.h"
#include "LazyListe.h"

Weg::~Weg(void)
{
}

void Weg::vInitialisierung()
{
	p_dLaenge = 0;
	p_eLimit = Autobahn;
}

Weg::Weg(string sName, double dLaenge, Begrenzung eLimit)
{
	vInitialisierung();
	p_sName = sName;
	p_dLaenge = dLaenge;
	p_eLimit = eLimit;
}

void Weg::vAbfertigung()
{
	LazyListe <Fahrzeug*>::iterator itL=p_pFahrzeuge.begin();
	while(itL!=p_pFahrzeuge.end())
	{
		try
		{
			(*itL)->vAbfertigung();
		}
		// nur ein catch-Block nötig, da während der Laufzeit die korrekte virtual-Methode von vBearbeiten genommen wird
		// Exception steckt in den Tochterklassen von FahrAusnahme
		catch (FahrAusnahme& exception)
		{
			exception.vBearbeiten();
		}
		// GEHE ZUM NAECHSTEN KNOTEN
		itL++;
	}
	p_pFahrzeuge.vAktualisieren();
}

ostream& Weg::ostreamAusgabe(ostream& Ausgabe)
{
	AktivesVO::ostreamAusgabe(Ausgabe);

	Ausgabe << setw(10) << setiosflags(ios::right) << setiosflags(ios::fixed) << setprecision(2) << p_dLaenge;
	
	Ausgabe << " ( ";
	
	LazyListe <Fahrzeug*>::iterator itL;
	for(itL=p_pFahrzeuge.begin(); itL!=p_pFahrzeuge.end(); itL++)
	{
		Ausgabe << (*itL)->getName() << " ";
	}
	Ausgabe << ")";

	Ausgabe << resetiosflags(ios::right) << resetiosflags(ios::fixed);

	return Ausgabe;
}

ostream& operator<<(ostream& out, Weg& objekt)
{
	objekt.Weg::ostreamAusgabe(out);
	return out;
}

void Weg::vAnnahme(Fahrzeug* pFzg)
{
	p_pFahrzeuge.push_back(pFzg);
	pFzg->vNeueStrecke(this);
}

double Weg::getLaenge()
{
	return p_dLaenge;
}

void Weg::vAnnahme(Fahrzeug* pFzg, double dStartzeit)
{
	p_pFahrzeuge.push_front(pFzg);
	pFzg->vNeueStrecke(this, dStartzeit);
}

Begrenzung Weg::getBegrenzung()
{
	return p_eLimit;
}

void Weg::vAbgabe(Fahrzeug* pFahrzeug)
{
	LazyListe<Fahrzeug*>::iterator it;
	for(it=p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		if((*it)==pFahrzeug)
		{
			p_pFahrzeuge.erase(it);
		}
	}
}