#include <iostream>
#include "TextViewer.h"
#include "Dessinable.h"
#include "IntegrateurEuler.h"
#include "Boule.h"
#include "Systeme.h"
#include "Tapis.h"
using namespace std;

int main() {
	
	TextViewer T(cout);
	
	Vecteur force(0, 0, -1.24587);
	
	cout << endl << "Situation initiale: initialisation d'un Systeme" << endl << endl;
	
	// Boule 1
	
	Boule B1(0.02625, 0.127, 0.2, 0.99, 0, 0, &T);
	
	vector<double> tab1 = {0, 0, 1, 0, 0, 0};
	vector<double> tab2 = {1, 0, 2, 0, 0, 0};
	
	Vecteur V(tab1);
	Vecteur W(tab2);
	
	B1.setEtat(V);
	B1.setDerivee(W);
	B1.setForce(force);
	
	// Boule 2
	
	Boule B2(0.02625, 0.127, 0.2, 0.99, 0, 0, &T);
		
	vector<double> tab3 = {0.08, 0, 1.16, 0, 0, 0};
	vector<double> tab4 = {0, 0, 0, 0, 0, 0};
	
	Vecteur F(tab3);
	Vecteur M(tab4);
	
	B2.setEtat(F);
	B2.setDerivee(M);
	B2.setForce(force);
	
	IntegrateurEuler I;
	IntegrateurEuler* p(&I);
	
	// Initialisation d'un Systeme
	
	Systeme S(p, 3.569, 1.778);
	
	// Ajout de boules
	Boule* d(&B1);
	Boule* e(&B2);
	S.ajoute_boule(d);
	S.ajoute_boule(e);
	
	//Ajout d'autres objets (une paroi par exemple...meme si nous en avons deja 4)
	Paroi P(2, 3);
	Paroi* K(&P);
	S.ajoute_objet(K);
	
	// Affichage de ce Systeme
	
	cout << S; 
		
	return 0;
}
