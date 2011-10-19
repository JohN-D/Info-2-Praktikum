#pragma once
#include <string>
using namespace std;

class Fahrzeug
{
public:
	Fahrzeug(void);
	Fahrzeug(string sName);
	Fahrzeug(string sName, double dMaxGeschwindigkeit);
	Fahrzeug(const Fahrzeug& objekt);
	virtual ~Fahrzeug(void);
	virtual void vAbfertigung(void);
	virtual double dTanken(double dMenge=0.0);
	virtual double p_dGeschwindigkeit();
	virtual void vAusgabe(void);
	ostream& ostreamAusgabe(ostream& Ausgabe);
	bool operator<(Fahrzeug& objekt);
	virtual Fahrzeug& operator=(Fahrzeug& objekt);

protected:
	string p_sName;
	int p_iID;
	static int p_iMaxID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	virtual void vInitialisierung(void);
};

ostream& operator<<(ostream& stream, Fahrzeug& objekt); 