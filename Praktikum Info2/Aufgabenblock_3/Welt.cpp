#include "Welt.h"
#include "SimuClient.h"


Welt::Welt(void)
{
}


Welt::~Welt(void)
{
}

void Welt::vEinlesenMitGrafik(istream& Eingabe)
{
	string sSwitch;
	AktivesVO* neuesElement;
	int X, Y, iAnzahl;
	while(!Eingabe.eof())
	{
		Eingabe >> sSwitch; 
		if (sSwitch == "KREUZUNG")
		{
			neuesElement = new Kreuzung;
			Eingabe >> (*neuesElement) >> X >> Y;
			p_pKreuzungen.push_back((Kreuzung*) neuesElement);	//explizieter typecast!
			bZeichneKreuzung(X, Y);
		}
		else if (sSwitch == "PKW")
		{
			neuesElement = new PKW;
			string sStartkreuzung;
			double startZeit;

			Eingabe>>*neuesElement>>sStartkreuzung>>startZeit;
			Kreuzung *Startkreuzung = (Kreuzung*) AktivesVO::ptObjekt(sStartkreuzung);
			Startkreuzung->vAnnahme((Fahrzeug*)neuesElement, startZeit, Startkreuzung->pGetWeg());
		}
		else if(sSwitch == "FAHRRAD")
		{
			neuesElement = new Fahrrad;
			string sStartkreuzung;
			double startZeit;

			Eingabe>>*neuesElement>>sStartkreuzung>>startZeit;
			Kreuzung *Startkreuzung = (Kreuzung*) AktivesVO::ptObjekt(sStartkreuzung);
			Startkreuzung->vAnnahme((Fahrzeug*)neuesElement, startZeit, Startkreuzung->pGetWeg());
		}
		else if(sSwitch == "STRASSE")
		{
			string nameQuellK, nameZielK, nameWeg1, nameWeg2;
			int Uverbot;
			double laenge;
			int Begr;
			bool bUverbot;
			Begrenzung limit;

			Eingabe >> nameQuellK >>nameZielK>>nameWeg1>>nameWeg2>>laenge>>Begr>>Uverbot>>iAnzahl;

			int Punkte[12];
			for (int i = 0; i < 2*iAnzahl; i++)
			{
				Eingabe >> Punkte[i];
			}
			

			Kreuzung* QuellKreuzung = (Kreuzung*) AktivesVO::ptObjekt(nameQuellK);
			Kreuzung* ZielKreuzung = (Kreuzung*) AktivesVO::ptObjekt(nameZielK);

			if(!QuellKreuzung->bIsKreuzung() || !ZielKreuzung->bIsKreuzung())
			{
				throw ("Eines der Elemente ist keine Kreuzung");
			}

			switch(Uverbot)
			{
			case 0:
				bUverbot = false;
				break;
			case 1:
				bUverbot = true;
				break;
			default:
				throw ("ÜEBERHOLVERBOT UNGUELTIG");
				break;		
			}

			switch(Begr)
			{
				case 1:
					limit = Innerorts;
					break;
				case 2:	
					limit = Landstraße;
					break;
				case 3:
					limit = Autobahn;
					break;
				default:
					throw ("KEIN GUELTIGES GESCHWINDIGKEITSLIMIT");
					break;
			}
			QuellKreuzung->vVerbinde(nameWeg1, nameWeg2, laenge, ZielKreuzung, limit, bUverbot);

			bZeichneStrasse(nameWeg1, nameWeg2, laenge, iAnzahl, Punkte);
		} else
		{
			throw ("Fehleingabe in quelldatei");
		}
	}

}

void Welt::vEinlesen(istream& Eingabe)
{
	string sSwitch;
	AktivesVO* neuesElement;
	while(!Eingabe.eof())
	{
		Eingabe >> sSwitch; 
		if (sSwitch == "KREUZUNG")
		{
			neuesElement = new Kreuzung;
			Eingabe >> (*neuesElement);
			p_pKreuzungen.push_back((Kreuzung*) neuesElement);	//explizieter typecast!
		}
		else if (sSwitch == "PKW")
		{
			neuesElement = new PKW;
			string sStartkreuzung;
			double startZeit;

			Eingabe>>*neuesElement>>sStartkreuzung>>startZeit;
			Kreuzung *Startkreuzung = (Kreuzung*) AktivesVO::ptObjekt(sStartkreuzung);
			Startkreuzung->vAnnahme((Fahrzeug*)neuesElement, startZeit, Startkreuzung->pGetWeg());
		}
		else if(sSwitch == "FAHRRAD")
		{
			neuesElement = new Fahrrad;
			string sStartkreuzung;
			double startZeit;

			Eingabe>>*neuesElement>>sStartkreuzung>>startZeit;
			Kreuzung *Startkreuzung = (Kreuzung*) AktivesVO::ptObjekt(sStartkreuzung);
			Startkreuzung->vAnnahme((Fahrzeug*)neuesElement, startZeit, Startkreuzung->pGetWeg());
		}
		else if(sSwitch == "STRASSE")
		{
			string nameQuellK, nameZielK, nameWeg1, nameWeg2;
			int Uverbot;
			bool bUverbot;
			double laenge;
			int Begr;
			Begrenzung limit;

			Eingabe >> nameQuellK >>nameZielK>>nameWeg1>>nameWeg2>>laenge>>Begr>>Uverbot;

			Kreuzung* QuellKreuzung = (Kreuzung*) AktivesVO::ptObjekt(nameQuellK);
			Kreuzung* ZielKreuzung = (Kreuzung*) AktivesVO::ptObjekt(nameZielK);

			if(!QuellKreuzung->bIsKreuzung() || !ZielKreuzung->bIsKreuzung())
			{
				throw ("Eines der Elemente ist keine Kreuzung");
			}

			switch(Uverbot)
			{
			case 0:
				bUverbot = false;
				break;
			case 1:
				bUverbot = true;
				break;
			default:
				throw ("ÜEBERHOLVERBOT UNGUELTIG");
				break;
			}

			switch(Begr)
			{
				case 1:
					limit = Innerorts;
					break;
				case 2:	
					limit = Landstraße;
					break;
				case 3:
					limit = Autobahn;
					break;
				default:
					throw ("KEIN GUELTIGES GESCHWINDIGKEITSLIMIT");
					break;
			}
			QuellKreuzung->vVerbinde(nameWeg1, nameWeg2, laenge, ZielKreuzung, limit, Uverbot);
		} else
		{
			throw ("Fehleingabe in quelldatei");
		}
	}

}

void Welt::vSimulation(void)
{
	list<Kreuzung*>::iterator it;

	for(it = p_pKreuzungen.begin(); it != p_pKreuzungen.end(); it++)
	{
		(*it)->vAbfertigung();
	}
}
