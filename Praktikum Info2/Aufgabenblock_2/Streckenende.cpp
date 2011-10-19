#include "Streckenende.h"
#include "Fahrzeug.h";
#include "Weg.h";

Streckenende::Streckenende(void)
{
}


Streckenende::~Streckenende(void)
{
}

void Streckenende::vBearbeiten(void)
{
	cout << "STRECKENENDE: " << endl << (*p_pFahrzeug) << endl << (*p_pWeg) << endl << endl;
	p_pWeg->vAbgabe(p_pFahrzeug);
}