#pragma once
#include "iostream"
#include<string>
using namespace std; 

class Fahrzeug
{
public:
	Fahrzeug();
	~Fahrzeug();
private :
	string p_sName; 
	int p_iID,
		static int p_imaxID;

};

