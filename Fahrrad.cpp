#include "Fahrrad.h"
extern double dGlobaleZeit;

Fahrrad::Fahrrad()
{
}

//Constructor with Name and Max speed
Fahrrad::Fahrrad(string p_sName, double p_dMaxGeschwendigkeit) :Fahrzeug::Fahrzeug(p_sName, p_dMaxGeschwendigkeit)
{
}

//Deconstructor
Fahrrad::~Fahrrad()
{
}

//it updates the motor speed with specified constrains in the Skript
double Fahrrad::dGeschwindigkeit() const
{
	int iFull20km = (int)(p_dGesamtStrecke / 20); //counting how many full 20 km the motor drove
	double dGeschwidigkeit = pow(0.9, iFull20km) * p_dMaxgeschwindigkeit; //setting the new speed 10% lower with each 20 km

	if (dGeschwidigkeit < 12) //limit the speed to 12 km
	{
		dGeschwidigkeit = 12;
	}

	return dGeschwidigkeit;
}

//This Function update the car's data simulating driving, taking "speed limits" in consideration
void Fahrrad::vAbfertigung()
{
	if (dGlobaleZeit > p_dZeit)
	{
		p_dGesamtStrecke = p_dGesamtStrecke + ((dGlobaleZeit - p_dZeit) * dGeschwindigkeit());
		p_GesamtZeit = p_GesamtZeit + (dGlobaleZeit - p_dZeit);
		p_dZeit = dGlobaleZeit;
	}
	else p_dZeit = dGlobaleZeit;
}