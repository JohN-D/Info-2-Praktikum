#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "AktivesVO.h"
#include "Weg.h"
#include "Streckenende.h"

FzgFahren::~FzgFahren(void)
{
}

double FzgFahren::dStrecke(Fahrzeug* pFzg, double dZeitraum)
{
	double dRestweg = p_pWeg->getLaenge() - pFzg->getAbschnittStrecke();
	if(dRestweg<0.01)
	{
		throw Streckenende(pFzg, p_pWeg);
	}
	double dMoeglStrecke = pFzg->dGeschwindigkeit()*dZeitraum;
	if(dMoeglStrecke>dRestweg)
	{
		return dRestweg;
	}
	else
	{
		return dMoeglStrecke;
	}
}