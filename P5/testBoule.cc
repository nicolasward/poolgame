#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "Boule.h"
using namespace std;

int main() {
	
	cout << "AFFICHAGE DE TROIS BOULES" << endl << endl;

/*---------------------------------------------------------------------------*/
	
	// Initialisation de trois boules
	
	// Boule 1
	
	Boule B1(0.02625, 0.127, 0.2, 0.99, 0, 0);
	
	vector<double> tab1 = {-1, 0, 0.02625, 0, 0, 0};	// valeurs du vecteur etat
	vector<double> tab2 = {2, 0, 0, 0, 76.1905, 0};	// valeurs du vecteur derivee
	
	// On met les valeurs precedentes dans des vecteurs
	
	Vecteur V(tab1);
	Vecteur W(tab2);
	Vecteur force(0, 0, -1.24587);
	
	// Puis on initialise la boule avec ces vecteurs
	
	B1.setEtat(V);
	B1.setDerivee(W);
	B1.setForce(force);
	
	// Affichage de B1
	
	cout << "Boule 1 : " << endl;
	cout << B1 << endl;
	
	// Boule 2
	
	Boule B2(0.02625, 0.127, 0.2, 0.99, 0, 0);
		
	vector<double> tab3 = {0.5525, 0, 0.02625, 0, 0, 0};	//valeurs du vecteur etat
	vector<double> tab4 = {0, 0, 0, 0, 0, 0};	//valeurs du vecteur derivee
	
	// On met les valeurs precedentes dans des vecteurs
	
	Vecteur F(tab3);
	Vecteur M(tab4);
	
	// Puis on initialise la boule avec ces vecteurs
	
	B2.setEtat(F);
	B2.setDerivee(M);
	B2.setForce(force);
	
	// Affichage de B2
	
	cout << "Boule 2 : " << endl;
	cout << B2;
	
	// Boule 3
	
	Boule B3(0.02625, 0.127, 0.2, 0.99, 0, 0);
		
	vector<double> tab5 = {0.5, 0, 0.02625, 0, 0, 0};	//valeurs du vecteur etat
	vector<double> tab6 = {0, 0, 0, 0, 0, 0};	//valeurs du vecteur derivee
	
	// On met les valeurs precedentes dans des vecteurs
	
	Vecteur X(tab5);
	Vecteur Y(tab6);
	
	// Puis on initialise la boule avec ces vecteurs
	
	B3.setEtat(X);
	B3.setDerivee(Y);
	B3.setForce(force);
	
	// Affichage de B3
	
	cout << "Boule 3 : " << endl;
	cout << B3;
	
	return 0;
}
