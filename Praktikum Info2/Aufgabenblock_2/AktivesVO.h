#pragma once
#include <string>
using namespace std;
#include <iostream>
#include <iomanip>

class AktivesVO
{
public:
	AktivesVO(void);
	~AktivesVO(void);
	virtual void vAbfertigung(void) {};
	virtual ostream& ostreamAusgabe(ostream& Ausgabe);
	virtual void vInitialisierung(void);
	string getName(void);
	
protected:
	static int p_iMaxID;
	string p_sName;
	int p_iID;
	double p_dGesamtZeit;
	double p_dZeit;
	

};

ostream& operator<<(ostream& stream, AktivesVO& objekt); 