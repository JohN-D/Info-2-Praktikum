#include "FahrAusnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"

FahrAusnahme::FahrAusnahme(void)
{
}


FahrAusnahme::~FahrAusnahme(void)
{
}


FahrAusnahme::FahrAusnahme(Fahrzeug* pFahrzeug, Weg* pWeg)
	: p_pFahrzeug(pFahrzeug), p_pWeg(pWeg)
{

}