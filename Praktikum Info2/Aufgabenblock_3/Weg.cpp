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
#include "Kreuzung.h"

Weg::~Weg(void)
{
}

void Weg::vInitialisierung()
{
	p_dLaenge = 0;
	p_eLimit = Autobahn;
	p_dSchranke = p_dLaenge;
}

Weg::Weg(string sName, double dLaenge, Begrenzung eLimit, bool bUeberholverbot)
{
	vInitialisierung();
	p_sName = sName;
	vAnmeldung();
	p_dLaenge = dLaenge;
	p_eLimit = eLimit;
	p_bUeberholverbot = bUeberholverbot;
}

void Weg::vAbfertigung()
{
	LazyListe <Fahrzeug*>::iterator itL=p_pFahrzeuge.begin();
	p_dSchranke = p_dLaenge;
	while(itL!=p_pFahrzeuge.end())
	{
		try
		{
			(*itL)->vAbfertigung();
			(*itL)->vZeichnen(this);
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
	pFzg->vNeueStrecke(this, dStartzeit);
	p_pFahrzeuge.push_front(pFzg);
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
			break;
		}
	}
}

double Weg::dGetSchranke(void)
{
	return p_dSchranke;
}


void Weg::vSetSchranke(double dSchranke)
{
	p_dSchranke=dSchranke;
}

bool Weg::bGetUeberholverbot(void)
{
	return p_bUeberholverbot;
}