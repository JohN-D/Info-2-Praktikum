#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Kreuzung.h"

Streckenende::Streckenende(void)
{
}


Streckenende::~Streckenende(void)
{
}

void Streckenende::vBearbeiten(void)
{
	cout << "STRECKENENDE " << endl << (*p_pFahrzeug) << endl << (*p_pWeg) << endl << endl;
	p_pWeg->vAbgabe(p_pFahrzeug);
	Kreuzung* pZielKreuzung = p_pWeg->vGetZiel();
	Weg* pNeuerWeg = pZielKreuzung->ptZufaelligerWeg(p_pWeg);
	pZielKreuzung->vAnnahme(p_pFahrzeug, 0, pNeuerWeg);
	cout << setiosflags(ios::fixed) << setprecision(2) << setiosflags(ios::left);
	cout << endl << setw(11) << "ZEIT" << ": " << dGlobaleZeit << endl;
	cout << setw(11) << "KREUZUNG" << ": " << pZielKreuzung->getName() << " " << pZielKreuzung->dGetTankstelle() << endl;
	cout << setw(11) << "WECHSEL" << ": " << p_pWeg->getName() << " -> " << pNeuerWeg->getName() << endl;
	cout << (*p_pFahrzeug) << endl << endl; 
	cout << resetiosflags(ios::fixed) << resetiosflags(ios::left);
}