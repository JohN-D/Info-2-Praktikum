#include "FzgVerhalten.h"

#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "AktivesVO.h"
#include "Weg.h"


FzgVerhalten::FzgVerhalten(Weg* pWeg)
{
	p_pWeg=pWeg;
}


FzgVerhalten::~FzgVerhalten(void)
{
}

Weg* FzgVerhalten::getWegpointer()
{
	return p_pWeg;
}