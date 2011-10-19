#pragma once
#include <string>

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;


class AktivesVO
{
public:
	AktivesVO(void);
	~AktivesVO(void);
	virtual void vAbfertigung(void) {};
	virtual ostream& ostreamAusgabe(ostream& Ausgabe);
	virtual istream& istreamEingabe(istream& Eingabe);
	virtual void vInitialisierung(void);
	string getName(void);
	static AktivesVO* ptObjekt(string name);
	void vAnmeldung(void);

	virtual bool bIsKreuzung(void) { return false;}
	
	static map<string, AktivesVO*> VOMap;

protected:
	static int p_iMaxID;
	
	string p_sName;
	int p_iID;
	double p_dGesamtZeit;
	double p_dZeit;
	

};

ostream& operator<<(ostream& stream, AktivesVO& objekt); 
istream& operator>>(istream& stream, AktivesVO& objekt); 