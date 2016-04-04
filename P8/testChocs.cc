#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "Boule.h"
#include "Integrateur.h"
#include "IntegrateurEuler.h"
using namespace std;

// Meme fichier test que P7

int main() {
	
	cout << "--- TEST CHOCS ---" << endl << endl;
	cout << "SANS ROTATION" << endl << endl;
	
	IntegrateurEuler I;
	
	Vecteur force(0, 0, -1.24587);
	
	cout << "Situation initiale: " << endl << endl;
	
	// Boule 1
	
	Boule B1(0.02625, 0.127, 0.2, 0.99, 0, 0);
	
	vector<double> tab1 = {0, 0, 1, 0, 0, 0};
	vector<double> tab2 = {1, 0, 2, 0, 0, 0};
	
	Vecteur V(tab1);
	Vecteur W(tab2);
	
	B1.setEtat(V);
	B1.setDerivee(W);
	B1.setForce(force);
	
	cout << "Boule 1 : " << endl;
	cout << B1 << endl;
	
	// Boule 2
	
	Boule B2(0.02625, 0.127, 0.2, 0.99, 0, 0);
		
	vector<double> tab3 = {0.08, 0, 1.16, 0, 0, 0};
	vector<double> tab4 = {0, 0, 0, 0, 0, 0};
	
	Vecteur F(tab3);
	Vecteur M(tab4);
	
	B2.setEtat(F);
	B2.setDerivee(M);
	B2.setForce(force);
	
	cout << "Boule 2 : " << endl;
	cout << B2;
		
	cout << "============================================" << endl << endl;	
	
	cout << "Premieres positions obtenues: " << endl << endl;
	
	cout << B1.getPosition() << endl;
	cout << B2.getPosition() << endl << endl;
	
	double temps_collision(B2.t_collision(B1, 0.05, 0.01, I));
	
	while(temps_collision >= 0.01) {
	
	I.integre(B1, 0.01);
	I.integre(B2, 0.01);
	cout << B1.getPosition() << endl;	
	cout << B2.getPosition() << endl << endl;
	temps_collision = B2.t_collision(B1, 0.05, 0.01, I);
	
	}
	
	if(temps_collision < 675) { // changer de convention, mettre -1 au lieu de 675!
	
		cout << "Choc possible : tChoc = " << temps_collision << endl;
		cout << "Temps collision : " << temps_collision + 0.05 << endl;
		cout << endl;
	
	}
	
	I.integre(B1, temps_collision);	
	I.integre(B2, temps_collision);	
	
	cout << "============================================" << endl << endl;	
	
	cout << "COLLISION BOULE - BOULE" << endl << endl;
	cout << "Entre Boule 1 : " << endl << endl << B1 << endl;
	cout << "Et Boule 2 : " << endl << endl << B2;
	
	cout << "============================================" << endl << endl;	

	B1.collision(B2);
	
	cout << "RESULTAT (apres collision) :" << endl << endl;
	cout << "Boule 1 : " << endl << endl << B1 << endl;
	cout << "Boule 2 : " << endl << endl << B2 << endl;
	
	cout << "============================================" << endl << endl;	
		
	cout << "AVEC ROTATION" << endl << endl;
	
	// Boule 3
	
	Boule B3(0.02625, 0.127, 0.2, 0.99, 0, 0);
	
	B3.setEtat(V);
	B3.setDerivee(W);
	B3.setForce(force);
	
	// Boule 4
	
	Boule B4(0.02625, 0.127, 0.2, 0.99, 0, 0);
	
	B4.setEtat(F);
	B4.setDerivee(M);
	B4.setForce(force);
	
	vector<double> va = { 0, 5, 0 };
	B4.setVitesse_Angulaire(va);
	
	double temps_collision2(B3.t_collision(B4, 0.05, 0.01, I));
	
	while(temps_collision2 >= 0.01) {
	
	I.integre(B3, 0.01);
	I.integre(B4, 0.01);
	temps_collision2 = B3.t_collision(B4, 0.05, 0.01, I);
	
	}
	
	I.integre(B3, temps_collision2);	
	I.integre(B4, temps_collision2);
	
	cout << "COLLISION BOULE - BOULE" << endl << endl;
	cout << "Entre Boule 3 : " << endl << endl << B3 << endl;
	cout << "Et Boule 4 : " << endl << endl << B4;
	
	cout << "============================================" << endl << endl;	

	B3.collision(B4);
	
	cout << "RESULTAT (apres collision) :" << endl << endl;
	cout << "Boule 3 : " << endl << endl << B3 << endl;
	cout << "Boule 4 : " << endl << endl << B4 << endl;	
	
	

		
	return 0;

}
