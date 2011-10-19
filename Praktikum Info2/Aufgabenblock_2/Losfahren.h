#pragma once
#include "fahrausnahme.h"

class Losfahren : public FahrAusnahme
{
public:
	Losfahren(void);
	~Losfahren(void);
	virtual void vBearbeiten(void);
	Losfahren(Fahrzeug* pFahrzeug, Weg* pWeg) : FahrAusnahme(pFahrzeug, pWeg) {};
	
};

