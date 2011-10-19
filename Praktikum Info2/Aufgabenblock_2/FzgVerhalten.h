#pragma once

class Weg;
class AktivesVO;
class Fahrzeug;
class PKW;
class Fahrrad;

#include <math.h>


class FzgVerhalten
{
public:
	FzgVerhalten(Weg* pWeg);
	~FzgVerhalten(void);
	virtual double dStrecke(Fahrzeug* pFzg, double dZeitraum) = 0;
	Weg* getWegpointer(void);

protected:
	Weg* p_pWeg;

};

