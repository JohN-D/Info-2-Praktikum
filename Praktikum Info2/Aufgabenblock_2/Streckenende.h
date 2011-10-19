#pragma once
#include "fahrausnahme.h"

class Fahrzeug;
class Weg;

class Streckenende : public FahrAusnahme
{
public:
	Streckenende(void);
	~Streckenende(void);
	virtual void vBearbeiten(void);
	Streckenende(Fahrzeug* pFahrzeug, Weg* pWeg) : FahrAusnahme(pFahrzeug, pWeg) {};

};

