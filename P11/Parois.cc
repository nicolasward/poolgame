#include <iostream>
#include <vector>
#include <cmath>
#include "Parois.h"
#include "TextViewer.h"
using namespace std;

// constructeurs

Paroi::Paroi(Vecteur const& n, double const& L, double const& l, Vecteur const& O, double const& c, double r, Support_a_dessin* S)
: Objet(S), normal(n), longueur(L, 0, 0), largeur(0, l, 0), origine(O), coeff_frt(c), restitution(r) {
	
	// verification des conditions de l'enonce:
	
	if((n.norme() != 1) or (n*longueur != 0) or (n*largeur != 0)) conditions = false; // vecteur normal unitaire et orthogonal a la paroi
	else if(largeur*longueur != 0) conditions = false; // vecteurs longueur et largeur orthogonaux	
	
}

Paroi::Paroi(double const& L, double const& l)
: Objet(new TextViewer(std::cout)) {
	
	origine = Vecteur(3);
	longueur = Vecteur(L/2, 0, 0);
	largeur = Vecteur(0, l/2, 0);
	normal = Vecteur(0, 0, 0.04); // pour que sa norme soit 0.2 (= hauteur de la paroi)
	conditions = true;


}

void Paroi::conventionnel() const { 
	
	if(conditions) cout << "Paroi conventionnelle." << endl;
	else cout << "Paroi non-conventionnelle." << endl;
	
}

void Paroi::setFrottement(double const& f) { coeff_frt = f; }
void Paroi::setRestitution(double const& r) { restitution = r; }
	

// distance

Vecteur Paroi::distance(Boule const& B) const {
	
	Vecteur x1 = B.getPosition(), x2(3);
	Vecteur xkL(3), xkl(3);
	Vecteur L(longueur), l(largeur), n(normal), O(origine);
	Vecteur eL = L * (1/(L.norme()));
	Vecteur el = (n) ^ (eL);
	
	x2 = x1 + ((O - x1) * n) * n;
	
	xkL = (x2 - O) * eL;
	xkl = (x2 - O) * el;
	
	if(xkL.norme() > L.norme()) x2 -= (xkL - L) * eL;
	else if(xkL.norme() < 0) x2 -= xkL * eL;
	
	if(xkl.norme() > l.norme()) x2 -= (xkl - l) * el;
	else if(xkl.norme() < 0) x2 -= xkl * el;
	
	return x2;
	
}


double Paroi::t_collision(Boule& B, double const& t, double const& dt, Integrateur* I) const { 	
	
	Boule B_copie = B;
	double R(B_copie.getrayon());
	Vecteur v(B_copie.getVitesse());
		
	Vecteur x(B_copie.getPosition()); // position avant integration
	Vecteur D(distance(B)); // distance avant integration
	(*I).integre(B_copie, dt);
	Vecteur D_prime(distance(B)); // distance apres integration
	Vecteur x_prime(B_copie.getPosition()); // position apres integration
	
	if(D_prime.norme() < R or D*D_prime < 0) return (R - normal*D)/(normal*D_prime - normal*D);
		
	else return -1;
	
}

void Paroi::collision(Boule& B) { 
	
	double R = B.getrayon();
	Vecteur x = B.getPosition();
	Vecteur v = B.getVitesse();
	Vecteur w = B.getVitesse_Angulaire();
	// double m = B.getmasse();
	
	double alpha = restitution * B.getresti();
	double mu = coeff_frt * B.getcoef(); 
	double lambda = 1 + alpha;
	Vecteur n = (origine - x) * (1/(origine - x).norme());
	
	Vecteur delta_v(3);
	Vecteur delta_w(3);
	Vecteur Vc(3);
	Vecteur Vc_norme(3);
	double v_etoile(0);
	
	if(distance(B).norme() <= R) {
		
		v_etoile = (-v) * n;
		Vc = v + (n*v_etoile) + (n^(R*w));
	
		if((7*mu*(1+lambda)*v_etoile) >= 2*Vc.norme()) {
						
			delta_v = n*(lambda*v_etoile) - Vc*(2/7);
			delta_w = (n^Vc)*(5/(7*R));
			
		} else {
						
			delta_v = (n - mu*(Vc*(1/(Vc.norme()))))*(lambda*v_etoile);
			delta_w = (n^(Vc*(1/Vc.norme())))*((5/(2*R))*mu*lambda*v_etoile);
			
		}
		
		v += delta_v;
		w += delta_w;

		
	}
	
		B.setVitesse(v);
		B.setVitesse_Angulaire(w);

}

void Paroi::dessine() { support -> dessine(*this); }

ostream& Paroi::affiche(ostream& sortie) const {
	sortie << "Vecteur normal : " << normal << endl;
	sortie << "Vecteur origine : " << origine << endl;
	sortie << "Vecteur longueur : " << longueur << endl;
	sortie << "Vecteur largeur : " << largeur << endl;
	sortie << "Coefficient de frottement : " << coeff_frt << endl;
	sortie << "Coefficient de restitution : " << restitution << endl;
	
	conventionnel();
	
	return sortie; 
}
