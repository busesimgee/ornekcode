#include "PKW.h"




PKW::PKW() :Fahrzeug::Fahrzeug()  //Initialisierungsliste 
{
	p_dTankVolumen = 55;
	p_dTankinhalt = p_dTankVolumen / 2;

}

//Constructor with Name
PKW::PKW(string p_sName) :Fahrzeug::Fahrzeug(p_sName)
{
	p_dTankVolumen = 55;
	p_dTankinhalt = p_dTankVolumen / 2;
}

//Constructor with Name and Max speed
PKW::PKW(string p_sName, double p_dMaxGeschwendigkeit) :Fahrzeug::Fahrzeug(p_sName, p_dMaxGeschwendigkeit)
{
	p_dTankVolumen = 55;
	p_dTankinhalt = p_dTankVolumen / 2;
}
PKW::PKW(string p_sName, double p_dMaxGeschwendigkeit, double p_dVerbrauch, double p_dTankvolumen ): Fahrzeug::Fahrzeug(p_sName, p_dMaxGeschwendigkeit), p_dVerbrauch(p_dVerbrauch), p_dTankVolumen(p_dTankVolumen)
{
	p_dTankinhalt = p_dTankVolumen / 2;
}
double PKW::dTanken(double dMenge)
{
	if ((p_dTankinhalt + dMenge) < p_dTankVolumen) //if the amount of specified feul is less that full
	{
		p_dTankinhalt = p_dTankinhalt + dMenge;
		return dMenge;
	}
	else //if the amount is more or not specified
	{
		p_dTankinhalt = p_dTankVolumen;
		return p_dTankVolumen;
	}
}
double PKW::dVerbrauch() const  //SHIHA
{
	return (p_dGesamtStrecke * p_dVerbrauch / 100);
}
void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0)
	{
		double dGesamtStreckeTemp = p_dGesamtStrecke;

		Fahrzeug::vAbfertigung();

		p_dTankinhalt -= (p_dGesamtStrecke - dGesamtStreckeTemp) * p_dVerbrauch / 100;

		if (p_dTankinhalt < 0) p_dTankinhalt = 0;
	}
}
void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << setprecision(2) << fixed
		<< resetiosflags(ios::left) << setiosflags(ios::left) 
		<< setw(8) << p_dMaxgeschwindigkeit << " "
		<< setw(10) << dVerbrauch() << " "
		<< setw(10) << p_dTankinhalt << " "
		<< endl;
}


PKW::~PKW()
{
}