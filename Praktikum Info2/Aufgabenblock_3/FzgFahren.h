#pragma once
#include "fzgverhalten.h"

class FzgFahren :	public FzgVerhalten
{
public:
	FzgFahren(Weg* pWeg) : FzgVerhalten(pWeg) {};
	~FzgFahren(void);
	virtual double dStrecke(Fahrzeug* pFzg, double dZeitraum);


};

