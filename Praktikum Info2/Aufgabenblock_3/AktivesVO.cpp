#include "AktivesVO.h"

using namespace std;

map<string, AktivesVO*> AktivesVO::VOMap;		//damit auch statisch zugegriffen werden kann


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

istream& AktivesVO::istreamEingabe(istream& in)
{
	if(p_sName != "")
	{
		throw "Name bereits definiert";
	} else {
		in>>p_sName;
	}
	vAnmeldung();
	return in;
}

ostream& operator<<(ostream& out, AktivesVO& objekt)
{
	objekt.ostreamAusgabe(out);
	return out;
}

istream& operator>>(istream& in, AktivesVO& objekt)
{
	objekt.istreamEingabe(in);
	return in;
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

void AktivesVO::vAnmeldung(void)
{
	if(VOMap.find(p_sName) != VOMap.end())
	{
		throw "Name bereits vergeben";
	} else 
	{
		VOMap[p_sName] = this;
	}
	cout<< "ANMELDE:   "<<this->p_sName<<endl;
}

AktivesVO* AktivesVO::ptObjekt(string name)
{
	if(!VOMap.count(name))
		throw ("Element in VOMap nicht vorhanden");
	return VOMap.find(name)->second;
}