#include "Fahrzeug.h"

#include<iomanip> 


int Fahrzeug::p_iMaxID = 0;
extern double dGlobaleZeit;

Fahrzeug::Fahrzeug()
{
	vInitialisierung();
	
	cout << "Die Name ist :" << p_sName << endl;
	cout << "Die ID ist :" << p_iID << endl;
}
Fahrzeug::Fahrzeug(string sName)
{
	vInitialisierung();
	this->p_sName = sName;

	cout << "Die Name ist :" << p_sName <<endl;
	cout << "Die ID ist :" << p_iID<< endl;
}

Fahrzeug::Fahrzeug(string p_sName, double p_dMaxgeschwindigkeit)
{
	vInitialisierung();
	this->p_sName = p_sName;
	this->p_dMaxgeschwindigkeit = p_dMaxgeschwindigkeit;
	cout << "Die Name ist :" << p_sName << endl;
	cout << "Die ID ist :" << p_iID << endl;

}


 void Fahrzeug::vInitialisierung()
{
	p_iID = ++p_iMaxID;
	p_sName = "";
	p_dMaxgeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_GesamtZeit = 0;
	p_dZeit = 0;

}

void Fahrzeug::vAus() 
{
	cout << setprecision(2) << fixed
		<< resetiosflags(ios::left) << setiosflags(ios::left) << setw(2) << "ID" << " "
		<< setw(12) << "Name" << " "
		<< setw(8) << "Max Kmh" << " "
		<< setw(10) << "GesamtStrecke" << " "
		<< setw(10) << "Verbrauch" << " "
		<< setw(10) << "Tankinhalt" << " "
		<< setw(8) << "Kmh" << " " 
		<< endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}
void Fahrzeug::vAusgabe()
{
	cout << setprecision(2) << fixed
		<< resetiosflags(ios::left) << setiosflags(ios::left) << setw(2) << p_iID << " "
		<< setw(12) << p_sName << " "
		<< setw(8) << p_dMaxgeschwindigkeit << " "
		<< setw(10) << p_dGesamtStrecke << " "
		<< setw(8) << dGeschwindigkeit() << " "
		<< endl;
	


}


void Fahrzeug::vAbfertigung()
{
	if (dGlobaleZeit > p_dZeit)
	{
		p_dGesamtStrecke = p_dGesamtStrecke + ((dGlobaleZeit - p_dZeit) * p_dMaxgeschwindigkeit);
		p_GesamtZeit = p_GesamtZeit + (dGlobaleZeit - p_dZeit);
		p_dZeit = dGlobaleZeit;
	}
	else p_dZeit = dGlobaleZeit;

}

double Fahrzeug::dTanken(double dMenge) //AUfgabe 2
{
	return 0.0;
}

double Fahrzeug::dGeschwindigkeit() const
{
	return p_dMaxgeschwindigkeit;
}






Fahrzeug::~Fahrzeug()
{
}
