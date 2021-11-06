#include <iostream> 
#include"Myclass.h"
using namespace std; 
int main()
{
	char c;
	Myclass* pObject = new Myclass();
	pObject->vPrint();
	delete pObject; 
	cin >> c; 
		cout << "hello world " << endl ; 
	cin >> c; 
	return 0;
}