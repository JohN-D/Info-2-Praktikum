#pragma once
class Fahrzeug;
class Weg;

class FahrAusnahme
{
public:
	FahrAusnahme(void);
	FahrAusnahme(Fahrzeug* pFahrzeug, Weg* pWeg);
	~FahrAusnahme(void);
	virtual void vBearbeiten(void) = 0;

protected:
	Fahrzeug* p_pFahrzeug;
	Weg* p_pWeg;

};

