#include "Losfahren.h"
#include <iostream>
#include "Fahrzeug.h"
#include "Weg.h"

using namespace std;

Losfahren::Losfahren(void)
{
}


Losfahren::~Losfahren(void)
{
}

void Losfahren::vBearbeiten(void)
{
	cout << "LOSFAHREN: " << endl << (*p_pFahrzeug) << endl << (*p_pWeg) << endl << endl;
	p_pWeg->vAbgabe(p_pFahrzeug);
	p_pWeg->vAnnahme(p_pFahrzeug);

}