#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "AktivesVO.h"
#include "Weg.h"
#include "Streckenende.h"
#include "Losfahren.h"

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
	
	if(pFzg->dGetTankinhalt()<0.01)
	{
		return 0;
	}

	double dReturn;
	double dMoeglStrecke = pFzg->dGeschwindigkeit()*dZeitraum;
	if(dMoeglStrecke>dRestweg)
	{
		dReturn = dRestweg;
	}
	else
	{
		dReturn = dMoeglStrecke;
	}

	double dNeuePos;
	if(p_pWeg->bGetUeberholverbot() == true)
	{
		dNeuePos= dReturn+pFzg->getAbschnittStrecke();
		if(dNeuePos > p_pWeg->dGetSchranke())
		{
			dReturn = p_pWeg->dGetSchranke()-pFzg->getAbschnittStrecke();
		}
		p_pWeg->vSetSchranke(dNeuePos);
	}
	return dReturn;
}