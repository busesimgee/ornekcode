#pragma once
#include "Fahrzeug.h"

//please see PKW.cpp for decumentation

class PKW :
	public Fahrzeug
{
public:
	PKW();
	PKW(string p_sName);
	PKW(string p_sName, double p_dMaxGeschwendigkeit);
	PKW(string p_sName, double p_dMaxGeschwendigkeit, double p_dVerbrauch, double p_dTankvolumen = 55);
	~PKW();
	double dTanken(double dMenge = 999999999999999);
	double dVerbrauch() const;
	void vAbfertigung();
	void vAusgabe();
    
protected:
	double p_dVerbrauch, p_dTankinhalt, p_dTankVolumen;
};
