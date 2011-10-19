#pragma once
#include "fzgverhalten.h"
#include <stdlib.h>
using namespace std;

extern double dGlobaleZeit;

class FzgParken : public FzgVerhalten
{
public:
	FzgParken(Weg* pWeg) : FzgVerhalten(pWeg) {};
	FzgParken(Weg* pWeg, double dStartzeitpunkt);
	~FzgParken(void);
	virtual double dStrecke(Fahrzeug* pFzg, double dZeitraum);

private:
	double p_dStartzeitpunkt;
};

