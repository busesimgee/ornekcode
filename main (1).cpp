#include<iostream>
#include<iomanip>
#include "Fahrzeug.h"
#include "string"
#include"PKW.h"
#include "Fahrrad.h"
#include <vector>
#include <math.h>
using namespace std;
double dGlobaleZeit = 0.0;


inline bool bEqual(double x, double y)
{
	return (fabs(x - y) < 1e-6);
}
void VHead()
{
	cout << setprecision(2) << fixed
		<< resetiosflags(ios::left) << setiosflags(ios::left) << setw(2) << "ID" << " "
		<< setw(12) << "Name" << " "
		<< setw(8) << "Max Kmh" << " "
		<< setw(10) << "GesamtStrecke" << " "
		<< setw(8) << "Kmh" << " " 
		<< endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}





void VAufgabe_1()
{
	Fahrzeug f1("pkw",10);
	Fahrzeug f2;

	string sName ;
	cout << "die Name ist ";
	cin >> sName;
	cout << sName;
	Fahrzeug *f3 = new Fahrzeug(sName, 100);
	Fahrzeug *f4 = new Fahrzeug();
	
	VHead();
	f1.vAusgabe();
	f2.vAusgabe();

	f3->vAusgabe();
	f4->vAusgabe();

	delete f3;
	delete f4;

	Fahrzeug fahr2s("fahr2s", 60);
	VHead();
	while (dGlobaleZeit < 5)
	{
		dGlobaleZeit = dGlobaleZeit + 0.2;
		fahr2s.vAbfertigung();
		fahr2s.vAusgabe();
		cout << "dGlobaleZeit" << dGlobaleZeit;
	}
	int i;
	cin >> i;
	
}


void vAufgabe1Deb()
{
	Fahrzeug* pFahrzeuge[4];

	pFahrzeuge[0] = new Fahrzeug("Car 1", 50);
	pFahrzeuge[1] = new Fahrzeug("Car 2", 80);
	pFahrzeuge[2] = new Fahrzeug("Car 3", 25);
	pFahrzeuge[3] = new Fahrzeug("Car 4", 45);

	VHead();
	for (int i = 0; i < 4; i++)
	{
		pFahrzeuge[i]->vAusgabe();
		cout << endl;
	}
	int k;
	cin  >> k;

	//pFahrzeuge[2] = 0; 

	//Fahrzeug::vAus();
	//for (int i = 0; i < 4; i++)
	//{
		//pFahrzeuge[i]->vAusgabe();
		//cout << endl;
		//delete pFahrzeuge[i];
	//}

}


void VAufgabe_2()
{
	int iNumPKW = 0;
	int iNumFahrrad = 0;

	cout << "How many car you need? " << endl;
	cin >> iNumPKW;
	cout << "How many motor you need?" << endl;
	cin >> iNumFahrrad;

	vector<Fahrzeug*> vecFahrzeuge; //vector of cars

	for (int i = 1; i <= iNumPKW; i++) //pushing the cars into the vector with dynamic initialization
	{
		PKW *pkwTemp = new PKW("Car " + to_string(i), 60, 5);
		vecFahrzeuge.push_back(pkwTemp);
	}
	for (int i = 1; i <= iNumFahrrad; i++) //pushing the motors into the vector with dynamic initialization
	{
		Fahrrad *frdTemp = new Fahrrad("Motor " + to_string(i), 24);
		vecFahrzeuge.push_back(frdTemp);
	}

	double dInterval;
	cout << "What is the time interval of the driving step? ";
	cin >> dInterval;
	cout << endl;

	bool bGetankt = false;
	Fahrzeug::vAus();
	

	//driving with specified time interval
	for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += dInterval)
	{
		for (auto it = vecFahrzeuge.begin(); it != vecFahrzeuge.end(); it++) //iterator for the vector
		{
			if (((bEqual(dGlobaleZeit, 3.0)) || dGlobaleZeit > 3.0) && !bGetankt)
			{
				for (auto it2 = vecFahrzeuge.begin(); it2 != vecFahrzeuge.end(); it2++)
				{
					(*it2)->dTanken();
				}
				bGetankt = true;
			}

			(*it)->vAbfertigung();
			(*it)->vAusgabe();
		}

		cout << endl;
		
	}
	int l;
	cin >> l;
	//dynamic delete of the array
	for (auto it = vecFahrzeuge.begin(); it != vecFahrzeuge.end(); it++)
	{
		delete *it;
	}
	

}
int main()
{
	VAufgabe_1();
	cout << endl << endl << "***Aufgabe 1 is done*** " << endl << endl << endl << endl;
	vAufgabe1Deb();
	cout << endl << endl << "***Aufgabe 1b is done*** " << endl << endl << endl << endl;
	VAufgabe_2();
	cout << endl << endl << "***Aufgabe 2 is done*** " << endl << endl << endl << endl;
	return 0;
}