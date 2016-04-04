#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "Boule.h"
#include "Integrateur.h"
#include "IntegrateurKutta.h"
using namespace std;

int main() {
	
	cout << "--- TEST INTEGRATEUR RUNGE-KUTTA ---" << endl << endl;
	
	IntegrateurKutta K;
	
	/*---------------------------------------------------------------------------*/
	
	// Initialisation d'une Boule 
	
	Boule B(0.02625, 0.127, 0.2, 0.99, 0, 0);
	
	vector<double> tab1 = {0, 0, 1, 0, 0, 0};	//valeurs du vecteur etat
	vector<double> tab2 = {1, 0, 2, 0, 0, 0};	//valeurs du vecteur derivee
	
	// On met les valeurs precedentes dans des vecteurs
	
	Vecteur V(tab1);
	Vecteur W(tab2);
	
	// Puis on initialise la boule avec ces vecteurs
	
	B.setEtat(V);
	B.setDerivee(W);
	
	/*---------------------------------------------------------------------------*/
	
	// test de l'integrateur de Runge-Kutta avec deux integrations
	
	cout << "Situation de depart : " << endl << endl;
	cout << B << endl;
		
	cout << "============================================" << endl << endl << endl;
	cout << "Integration de Runge-Kutta avec dt = 0.01 : " << endl << endl;
	
	K.integre(B, 0.01);
	cout << B << endl << endl;
	
	cout << "============================================" << endl << endl << endl;
	cout << "Deuxieme integration de Runge-Kutta avec dt = 0.01 : " << endl << endl;
	
	K.integre(B, 0.01);
	cout << B << endl << endl;
	
		
	return 0;

}
