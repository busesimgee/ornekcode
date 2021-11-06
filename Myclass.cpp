#include "Myclass.h"
#include <iostream>
using namespace std;


Myclass::Myclass()
{
	cout << "konstruktor " << endl; 
}


Myclass::~Myclass()
{
	cout << "destruktor" << endl;
}


// Ausgabe der klasse Myclass
void Myclass::vPrint()
{
	// TODO: Fügen Sie hier Ihren Implementierungscode ein..
	cout << "hello world " << endl;
}
