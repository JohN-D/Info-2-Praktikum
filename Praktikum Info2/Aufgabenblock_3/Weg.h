#pragma warning(disable: 4786)

#pragma once
#include "AktivesVO.h"

class Fahrzeug;
class PKW;
class Fahrrad;
class FzgVerhalten;
class Kreuzung;

#include "LazyListe.h"
#include <list>

using namespace std;

static const enum Begrenzung {Innerorts=50, Landstraﬂe=100, Autobahn=1337};

class Weg :	public AktivesVO
{

public:
	Weg(void) : AktivesVO() {vInitialisierung();};
	Weg(string sName, double dLaenge, Begrenzung eLimit=Autobahn, bool bUeberholverbot=true);
	~Weg(void);
	virtual void vAbfertigung(void);
	virtual ostream& ostreamAusgabe(ostream& Ausgabe);
	void vInitialisierung(void);
	void vAnnahme(Fahrzeug* pFzg);
	void vAnnahme(Fahrzeug* pFzg, double dStartzeit);
	double getLaenge(void);
	Begrenzung getBegrenzung(void);
	void vAbgabe(Fahrzeug* pFahrzeug);
	double dGetSchranke(void);
	void vSetSchranke(double dSchranke);
	bool bGetUeberholverbot(void);
	void vSetZiel(Kreuzung* pZiel)		{p_pZiel = pZiel;}
	void vSetRueckweg(Weg* pRueckweg)	{p_pRueckweg = pRueckweg;}
	Kreuzung* vGetZiel(void)			{return p_pZiel;}
	Weg* vGetRueckweg(void)				{return p_pRueckweg;}

protected:
	double p_dLaenge;
	// Pointer, weil die Objekte dynamisch erzeugt und bewegt werden
	// Verschieben oder Kopieren ist zu umst‰ndlich
	LazyListe<Fahrzeug*> p_pFahrzeuge;
	Begrenzung p_eLimit;
	bool p_bUeberholverbot;
	double p_dSchranke;
	Kreuzung* p_pZiel;
	Weg* p_pRueckweg;

};