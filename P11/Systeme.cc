#include <iostream>
#include <vector>
#include <cmath>
#include "Systeme.h"
using namespace std;

// Collections d'objets

void Systeme::ajoute_boule(Boule* B) { boules.push_back(B); }

void Systeme::ajoute_objet(Objet* O) { objets.push_back(O); }

/*---------------------------------------------------------------------------*/

void Systeme :: dessine()
{
	for (auto const& element : objets) {
		element->dessine();
	}

	for (auto const& element : boules) {
		element->dessine();
	}
}

/*---------------------------------------------------------------------------*/

// Evolution de notre Systeme

void Systeme::evolue(double dt) {	// methode evolue 

	Vecteur Derivee(6);
	Vecteur nul(6);

	for(auto element : boules) { //parcourt toutes les boules du systeme
		
		Derivee = (*element).getDerivee();	//recupere le vecteur derivee des boules
		
		// on arrete toutes les boules dont l'energie cinetique est inferieure a 10^-4
		if(Derivee.norme() < pow(10, -4)) (*element).setDerivee(nul);
		
	}
	
	double temps_collision = 0.0;
	double temps_effectue = 0.0;
	double temps_restant = dt; 
	double temps_detecte = 2*dt;
	int o = -1; // indice pour collection d'objets
	int b = -1; // indice pour collection de boules
	bool test(false); // indiquera le type de collision


	while(temps_effectue < dt) {

		temps_detecte = 2*temps_restant; //pour etre sur qu'on est dans le bon intervalle de temps

		for(size_t i(0); i < objets.size(); ++i) {	 // on parcourt les objets du systeme

			for(size_t j(0); j < boules.size(); ++j) {	// on parcourt les boules du systeme
				
				temps_collision = (*objets[i]).t_collision(*boules[j], temps_restant, temps_restant, I); // on recupere le temps de collision entre
																										 // la boule et l'objet immobile 
				if((temps_collision < temps_detecte) and (temps_collision > 0)) { // si il y a collision
					temps_detecte = temps_collision;
					o = i;
					b = j;
					test = true;	// indique que c'est une collision entre une boule et un objet immobile
				}
			}
		}

		for(size_t i(0); i < boules.size(); ++i) {	// on parcourt les boules du systeme

			for(size_t j(i+1); j < boules.size(); ++j) {  // on parcourt les boules du systeme
				temps_collision = (*(boules[i])).t_collision(*boules[j], temps_restant, temps_restant, I); // on recupere le temps de collision
																										   // entre deux boules
				if((temps_collision < temps_detecte) and (temps_collision  >0)) { // si il y a collision
					temps_detecte = temps_collision;
					o = i;
					b = j;	
				}	// test reste a false (indique que c'est une collision entre deux boules)
			}
		}

		if((o != (-1)) and (temps_detecte > 0.001)) { //si il y a collision

			for(auto element : boules) (*I).integre(*element, temps_detecte);

			if(test == true) (*objets[o]).collision(*(boules[b])); //effectue collision entre la boule et l'objet

			else { //test==false
				cout << "Collision :" << endl << endl;
				(*boules[o]).affiche(cout);	//affiche la premiere boule de la collision
				(*boules[b]).affiche(cout);	//puis affiche la seconde
				(*boules[o]).collision(*(boules[b])); //et enfin actualise avec la methode collision

				cout << "Apres collision :" << endl << endl;
				(*boules[o]).affiche(cout);	//affiche la premiere boule apres collision
				(*boules[b]).affiche(cout);	//puis la seconde apres collision
			}
			temps_restant -= temps_detecte;
			temps_effectue += temps_detecte;

		} else {	//si il n'y a pas de collision

			for(auto element : boules) (*I).integre(*element, temps_restant);	//integration "classique"
			temps_effectue = dt;
		}
	}

}

/*---------------------------------------------------------------------------*/

// Destructeur : on libere la memoire allouee

Systeme :: ~Systeme ()
{
	I = nullptr;

	for(auto& element : objets)
		element = nullptr;

	for(auto& element : boules)
		element = nullptr;
}

/*---------------------------------------------------------------------------*/

// Affichage

ostream& Systeme::affiche(ostream& sortie) const {
	
	cout << "Tapis : " << endl << endl;
	cout << T;
	
	cout << endl << endl << "Parois : "  << endl << endl;
	cout << "Paroi 1 :" << endl << P1 << endl;
	cout << "Paroi 2 :" << endl << P2 << endl;
	cout << "Paroi 3 :" << endl << P3 << endl;
	cout << "Paroi 4 :" << endl << P4 << endl;
	
	cout << "Affichage des boules du systeme : " << endl << endl;
	
	for (auto const& element : boules) (*element).affiche(sortie);
	
	cout << "Affichage des objets immobiles du systeme : " << endl << endl;
	
	for (auto const& element : objets) (*element).affiche(sortie);
	
	return sortie;
}

/*---------------------------------------------------------------------------*/

// Surcharge externe de l'operateur "<<"

ostream& operator<<(ostream& sortie, Systeme const& S) {
	
	S.affiche(sortie);
	return sortie;
}
