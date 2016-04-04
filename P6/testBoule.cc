#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "Boule.h"
#include "Integrateur.h"
#include "IntegrateurEuler.h"
using namespace std;

int main() {
	
	cout << "--- TEST BOULES ET INTEGRATEUR D'EULER ---" << endl << endl;
	
	IntegrateurEuler Charlie;
	
	Boule B(0.02625, 0.127, 0.2, 0.99, 0, 0);
	
	Vecteur force(0, 0, -1.24587);
	
	vector<double> tab1 = {0, 0, 1, 0, 0, 0};
	vector<double> tab2 = {1, 0, 2, 0, 0, 0};
	
	Vecteur V(tab1);
	Vecteur W(tab2);
	
	B.setEtat(V);
	B.setDerivee(W);
	
	cout << "Situation de depart : " << endl << endl;
	cout << B << endl;
		
	cout << "============================================" << endl << endl << endl;
	cout << "Integration avec dt = 0.01 : " << endl << endl;
	
	Charlie.integre(B, 0.01);
	cout << B << endl << endl;
	
	cout << "============================================" << endl << endl << endl;
	cout << "Deuxieme integration avec dt = 0.01 : " << endl << endl;
	
	Charlie.integre(B, 0.01);
	cout << B << endl << endl;
	
		
	return 0;

}
