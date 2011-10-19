#pragma once
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "Kreuzung.h"



class Welt
{
public:
	Welt(void);
	~Welt(void);

	void vEinlesen(istream& Eingabe);
	void Welt::vEinlesenMitGrafik(istream& Eingabe);
	void vSimulation(void);

protected:
	list<Kreuzung*> p_pKreuzungen;
};

