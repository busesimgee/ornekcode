#pragma once
#include <iostream> 
#include <string > 
#include<iomanip>

using namespace std;
extern double dGlobalezeit;


class Fahrzeug
{
public:
	Fahrzeug();
	Fahrzeug(string p_sName);
	Fahrzeug(string p_sName, double p_dMaxgeschwindigkeit );
	~Fahrzeug();
	static void vAus() ; 
	virtual void vAusgabe();
	virtual void vAbfertigung();
	virtual double dTanken(double dMenge = 999999999999);
	virtual double dGeschwindigkeit() const;
protected:
	string p_sName;
	int p_iID;
	double p_dMaxgeschwindigkeit;
	double p_dGesamtStrecke;
	double p_GesamtZeit;
	double p_dZeit;
private:
	
	static int p_iMaxID;
	
	void vInitialisierung();
};