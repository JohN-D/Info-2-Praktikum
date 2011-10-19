#include "FzgParken.h"
#include <iostream>
#include "Losfahren.h"

FzgParken::FzgParken(Weg* pWeg, double dStartzeitpunkt)
	: FzgVerhalten(pWeg)
{
	p_dStartzeitpunkt=dStartzeitpunkt;
}

FzgParken::~FzgParken(void)
{
}

double FzgParken::dStrecke(Fahrzeug* pFzg, double dZeitraum)
{
	if(p_dStartzeitpunkt-dGlobaleZeit<0.01)
	{
		throw Losfahren(pFzg, p_pWeg);
	}
	else
	{
		return 0.0;
	}
}