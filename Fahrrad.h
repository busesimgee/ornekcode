#pragma once
#include "Fahrzeug.h"




class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(string p_sName, double p_dMaxGeschwendigkeit);
	 virtual double dGeschwindigkeit() const;
	void vAbfertigung();
	virtual ~Fahrrad();
	
};

