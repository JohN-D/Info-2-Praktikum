#include "Fahrrad.h"
#include "SimuClient.h"
#include "Weg.h"

Fahrrad::~Fahrrad(void)
{
	//cout << "Destruiere: " << p_sName << endl;
}

double Fahrrad::dGeschwindigkeit()
{
	int iTeilstrecken = (int) p_dGesamtStrecke / 20;
	double temp = p_dMaxGeschwindigkeit*pow(0.9, iTeilstrecken);
	if(temp<12)
	{
		temp=12;
	}
	//cout << "Die Geschwindigkeit betraegt jetzt: " << temp << "km/h." << endl;
	return temp;
}

ostream& Fahrrad::ostreamAusgabe(ostream& Ausgabe)
{
	Fahrzeug::ostreamAusgabe(Ausgabe);

	Ausgabe << setw(16) << "";
	Ausgabe << setw(12) << "";
	Ausgabe << setw(10) << setiosflags(ios::right) << setiosflags(ios::fixed) << dGeschwindigkeit();
	Ausgabe << resetiosflags(ios::right) << resetiosflags(ios::fixed);

	return Ausgabe;
}

istream& Fahrrad::istreamEingabe(istream& Eingabe)
{
	Fahrzeug::istreamEingabe(Eingabe);
	return Eingabe;
}


ostream& operator<<(ostream& out, Fahrrad& objekt)
{
	objekt.Fahrrad::ostreamAusgabe(out);
	return out;
}

void Fahrrad::vZeichnen(Weg* pWeg)
{
	double dTemp=p_dAbschnittStrecke/pWeg->getLaenge();
	if(dTemp<0.01)
	{
		dTemp=0.001;
	}
	bZeichneFahrrad(p_sName, pWeg->getName(), dTemp, dGeschwindigkeit());
}