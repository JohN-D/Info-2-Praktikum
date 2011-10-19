#include "Fahrrad.h"
#include <math.h>
#include <iostream>
using namespace std;
#include <iomanip>

Fahrrad::~Fahrrad(void)
{
	//cout << "Destruiere: " << p_sName << endl;
}

double Fahrrad::p_dGeschwindigkeit()
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

void Fahrrad::vAusgabe()
{
	this->Fahrzeug::vAusgabe();
	cout << setiosflags(ios::right) << setiosflags(ios::fixed);
	cout << setw(16) << "";
	cout << setw(16) << "";
	cout << setw(10) << setiosflags(ios::right) << setiosflags(ios::fixed) << this->p_dGeschwindigkeit() << endl;
	cout << resetiosflags(ios::right) << resetiosflags(ios::fixed);
}

ostream& Fahrrad::ostreamAusgabe(ostream& Ausgabe)
{
	Ausgabe << setw(2) << setiosflags(ios::right) << p_iID;
	Ausgabe << setw(2) << "  ";
	Ausgabe << resetiosflags(ios::right);

	Ausgabe << setiosflags(ios::left);
	Ausgabe << setw(7) << p_sName;
	Ausgabe << setw(3) << ":";
	Ausgabe << resetiosflags(ios::left);

	Ausgabe << setiosflags(ios::fixed) << setprecision(2);
	Ausgabe << setw(6) << setiosflags(ios::right) << p_dMaxGeschwindigkeit;
	Ausgabe << setw(12) <<  p_dGesamtStrecke;
	Ausgabe << resetiosflags(ios::fixed) << resetiosflags(ios::right);

	Ausgabe << setiosflags(ios::right) << setiosflags(ios::fixed);
	Ausgabe << setw(16) << "";
	Ausgabe << setw(16) << "";
	Ausgabe << setw(10) << setiosflags(ios::right) << setiosflags(ios::fixed) << this->p_dGeschwindigkeit();
	Ausgabe << resetiosflags(ios::right) << resetiosflags(ios::fixed);

	return Ausgabe;
}

ostream& operator<<(ostream& out, Fahrrad& objekt)
{
	objekt.Fahrrad::ostreamAusgabe(out);
	return out;
}