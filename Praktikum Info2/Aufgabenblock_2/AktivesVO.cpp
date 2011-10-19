#include "AktivesVO.h"

AktivesVO::AktivesVO(void)
{
	vInitialisierung();
	//cout << "AktivesVO(void)" << endl;
}

AktivesVO::~AktivesVO(void)
{
}

ostream& AktivesVO::ostreamAusgabe(ostream& Ausgabe)
{
	Ausgabe << setw(2) << setiosflags(ios::right) << p_iID;
	Ausgabe << setw(2) << "  ";
	Ausgabe << resetiosflags(ios::right);

	Ausgabe << setiosflags(ios::left);
	Ausgabe << setw(7) << p_sName;
	Ausgabe << setw(3) << ":";
	Ausgabe << resetiosflags(ios::left);

	return Ausgabe;
}

ostream& operator<<(ostream& out, AktivesVO& objekt)
{
	objekt.ostreamAusgabe(out);
	return out;
}

void AktivesVO::vInitialisierung()
{
	p_sName = "";
	p_iMaxID++;
	p_iID = p_iMaxID;
	p_dGesamtZeit = 0;
	p_dZeit = 0;
}

string AktivesVO::getName(void)
{
	return p_sName;
}