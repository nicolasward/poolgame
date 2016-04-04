#include <iostream>
#include <vector>
#include <cmath>
#include "Tapis.h"
using namespace std;

Tapis::Tapis(double const& L, double const& l)
: Paroi(L, l) {}

Tapis::Tapis(Vecteur const& n, double const& L, double const& l, Vecteur const& O, double const& c, double r, Support_a_dessin* S)
: Paroi(n, L, l, O, c, r, S) 
{ 
	if(n*Vecteur(0, 0, 1) != 0) conditions = false; // vecteur normal perpendiculaire a l'axe z
}

void Tapis::conventionnel() const { 
	
	if(conditions) cout << "Tapis OK." << endl;
	else cout << "Tapis non-conventionnel." << endl;
	
}

void Tapis::setRoul(double const& r) { frt_roul = r; }
void Tapis::setGlis(double const& g) { frt_glis = g; }

Vecteur Tapis::distance(Boule const& B) const { return Vecteur(3); }

double Tapis::t_collision(Boule& B, double const& t, double const& dt, Integrateur* I) const 
{ 	
	return Paroi::t_collision(B, t, dt, I); 
}

void Tapis::collision(Boule& B) { 
	
	Vecteur v = B.getVitesse();
	vector<double> tab = v.getV();
	double verticale = tab[2];
	
	if(fabs(verticale) < 0.1) {
		
		B.setVerticale_vitesse(0.0);
		B.setVerticale_force(0.0);
		
	} else { Paroi::collision(B); }
	
	
}

void Tapis::reaction(Boule& B) {
	
	Vecteur v = B.getVitesse();
	vector<double> tab = v.getV();
	double verticale = tab[2];
	
	Vecteur oppose(0, 0, B.getmasse());
	
	if((fabs(verticale) <= pow(10, -6)) and (fabs(distance(B).norme()) <= pow(10, -3))) {
		
		B.setRoul(frt_roul*B.getcoef()); // modifie le coefficient de roulement de la boule
		B.setGlis(frt_glis*B.getcoef()); // modifie le coefficient de glissement de la boule
		B.ajoute_force(oppose); // ajoute une force de reaction verticale s'opposant au poids de la boule
		B.setAltitude(B.getrayon()); // remet l'altitude de la boule egale a son rayon (pose la boule sur le sol)
		
	} else {
		
		B.setRoul(0);
		B.setGlis(0);
		
	}
		
}

void Tapis::dessine() { support -> dessine(*this); }

ostream& Tapis::affiche(ostream& sortie) const { 

	Paroi::affiche(sortie);
	sortie << "Coefficient de roulement : " << frt_roul << endl;
	sortie << "Coefficient de glissement : " << frt_glis << endl;

	return sortie; 
}
