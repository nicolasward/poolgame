#include <iostream>
#include "TextViewer.h"
#include "Dessinable.h"
#include "IntegrateurEuler.h"
#include "Boule.h"
#include "Systeme.h"
using namespace std;

int main() {
	
	TextViewer text(cout);
	
	cout << "--- TEST SYSTEME ---" << endl << endl;
		
	Vecteur force(0, 0, -1.24587);
	
	cout << "Situation initiale: " << endl << endl;
		
	
	/*---------------------------------------------------------------------------*/
	
	// Initialisation de deux boules
	
	// Boule 1
	
	Boule B1(0.02625, 0.127, 0.2, 0.99, 0, 0, &text);
	
	vector<double> tab1 = {0, 0, 1, 0, 0, 0};	//valeurs du vecteur etat
	vector<double> tab2 = {1, 0, 2, 0, 0, 0};	//valeurs du vecteur derivee
	
	// On met les valeurs precedentes dans des vecteurs
	
	Vecteur V(tab1);
	Vecteur W(tab2);
	
	// Puis on initialise la boule avec ces vecteurs
	
	B1.setEtat(V);
	B1.setDerivee(W);
	B1.setForce(force);
	
	// Affichage de B1
	
	cout << "Boule 1 : " << endl;
	cout << B1 << endl;
	
	// Boule 2
	
	Boule B2(0.02625, 0.127, 0.2, 0.99, 0, 0, &text);
		
	vector<double> tab3 = {0.08, 0, 1.16, 0, 0, 0};	//valeurs du vecteur etat
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
		
	cout << "============================================" << endl << endl;	
	
	/*---------------------------------------------------------------------------*/
	
	// On definit un nouveau Systeme

	IntegrateurEuler I;
	IntegrateurEuler* p(&I);
	
	Systeme systeme(p);

	systeme.ajoute_boule(&B1);	//on ajoute la boule B1 au systeme
	systeme.ajoute_boule(&B2);	//on ajoute la boule B2 au systeme
	

	// On l'affiche "en mode texte" et on le fait evoluer

	double t(0.0);	//temps initialise au depart (0.0)
	double dt(0.01);	//pas de temps

	do {

		cout << "t = " << t << " :" << endl << endl;
		systeme.dessine();	//dessine les objets sur systeme
		cout << endl;
		systeme.evolue(dt);	  // effectue la methoe evolue sur tout le systeme
		t += dt;   // rajoute un pas de temps a t

	} while(t < 10*dt);	// permet de faire l'evolution sur 10 pas de temps et donc de couvrir P7

	cout << "t = " << t << " :" << endl << endl;
	systeme.dessine();
	
	
	return 0;

}
