#include <iostream>
#include <vector>
#include "Vecteur.h"
#include <cmath>
using namespace std;

	
// getter et setter

vector<double> Vecteur::getV() const { return V; } // getter
void Vecteur::setV(vector<double> const& U) { V = U; } // setter
double Vecteur::dimension() const { return V.size(); } // renvoie la dimension du vecteur
void Vecteur::modifie(int n, double d) { V[n-1] = d; } // modifie la n-ème coordonnée du vecteur et lui affecte la valeur d
	
	

/*---------------------------------------------------------------------------*/

// operations de la classe Vecteur

Vecteur Vecteur::soustraction(Vecteur const& autre) const {

	Vecteur resultat(*this);
	resultat -= autre;
	return resultat;
	
}

Vecteur Vecteur::oppose() const {
	
	double P(0);
	vector<double> resultat2;
				
		for(size_t i(0); i< V.size(); ++i) {
			P = -V[i];
			resultat2.push_back(P); }
		
	return Vecteur(resultat2);  

}

Vecteur Vecteur::mult(double const& d) const {
	
	double P(0);
	vector<double> resultat2;
				
	for(size_t i(0); i< V.size(); ++i) {
		P = d*V[i];
		resultat2.push_back(P); }
	
	return Vecteur(resultat2);
}

bool Vecteur::compare(Vecteur const& U) const {
	 
	bool resultat(true);
	if(V.size() != U.getV().size()) resultat = false;
	else {
		for(size_t i(0); i<V.size(); ++i) {
			if(V[i] != U.V[i]) { 
				resultat = false;
				break; }
		}
	}
	
	return resultat;

}

double Vecteur::prod_scal(Vecteur const& autre) const {
	
	double resultat(0);
	vector<double> stock = autre.getV();
	int k(stock.size()), l(V.size());
	if (k != l) {
		if (k < l) {
			for (int i(0); i<k; ++i) {
				resultat += stock[i]*V[i];
			}
		} else {
			for (int j(0); j<l; ++j) {
				resultat += stock[j]*V[j];
			}
		}
	} else {
		for (int n(0); n<k; ++n) { resultat += stock[n]*V[n]; }
	}
	
	return resultat;

}

Vecteur Vecteur::prod_vect(Vecteur const& autre) const {
	
	Vecteur resultat(0);
	vector<double> resultat2;
	vector<double> stock = autre.getV();
	int k(stock.size()), l(V.size());
	if (k==3 && l==3) {
		resultat2.push_back(V[1]*stock[2]-V[2]*stock[1]);
		resultat2.push_back(V[2]*stock[0]-V[0]*stock[2]);
		resultat2.push_back(V[0]*stock[1]-V[1]*stock[0]);
		resultat.setV(resultat2);
	} else { cerr << "Produit vectoriel impossible" << endl; }
	
	return resultat;
}

double Vecteur::norme_carre() const {
	
	double resultat(0.0);
	for (size_t i(0); i<V.size(); ++i) resultat += V[i]*V[i]; 
	
	return resultat;
}

double Vecteur::norme() const { return sqrt(norme_carre()); }

/*---------------------------------------------------------------------------*/

// constructeurs

Vecteur::Vecteur() {} // constructeur vide, pour pouvoir etre libre de creer un vecteur et le remplir plus tard (setV)
Vecteur::Vecteur(double const& x, double const& y, double const& z) { V.push_back(x); V.push_back(y); V.push_back(z); } // coordonnees cartesiennes
Vecteur::Vecteur(Vecteur const& autre) { for(int i(0); i<autre.dimension(); ++i) V.push_back(autre.V[i]); } // constructeur de copie
Vecteur::Vecteur(vector<double> const& liste) { V = liste; } // constructeur par tableau
Vecteur::Vecteur(int n) { for(int i(1); i<=n; ++i) V.push_back(0); } // initialise les n premieres dimensions a 0

/*---------------------------------------------------------------------------*/

const Vecteur plongement(Vecteur const& vecteur, int const& n) { // but: completer vecteur avec des 0 pour qu'il ait n dimensions
	
	vector<double> tab;
	tab = vecteur.getV();
	Vecteur resultat;
	
	if(vecteur.dimension()<n) { 
		
		for(int i(vecteur.dimension()); i<n; ++i) { tab.push_back(0); }
		resultat = tab; 
		
	}
	
	else { resultat = vecteur; }
	
	return resultat;

}

// surcharge d'operateurs

ostream& operator<<(ostream& sortie, Vecteur const& V) { return V.affiche(sortie); } // affichage
bool Vecteur::operator==(Vecteur const& U) const { return compare(U); } // comparaison

Vecteur& Vecteur::operator+=(Vecteur const& autre) { // +=
	
	Vecteur stockage;
	
	if(dimension() == autre.dimension()) for(int i(0); i<dimension(); ++i) { V[i] += autre.V[i]; }
	
	else if(dimension() < autre.dimension()) {
		stockage = plongement(*this, autre.dimension()); // rajoute des 0 a *this
		
		vector<double> tableau(autre.dimension(), 0);
		for(size_t i(0); i<tableau.size(); ++i) tableau[i] = stockage.V[i] + autre.V[i];
		V = tableau;
		
	} else {
		
		stockage = plongement(autre, dimension()); // rajoute des 0 a autre
		for(int i(0); i<dimension(); ++i) V[i] += stockage.V[i];
		
	}
	
	return *this;
	
}

Vecteur& Vecteur::operator-=(Vecteur const& autre) { // -=
	
	Vecteur stockage;
	
	if(dimension() == autre.dimension()) for(int i(0); i<dimension(); ++i) { V[i] -= autre.V[i]; }
	
	else if(dimension() < autre.dimension()) {
		stockage = plongement(*this, autre.dimension()); // rajoute des 0 a *this
		
		vector<double> tableau(autre.dimension(), 0);
		for(size_t i(0); i<tableau.size(); ++i) tableau[i] = stockage.V[i] - autre.V[i];
		V = tableau;
		
	} else {
		
		stockage = plongement(autre, dimension()); // rajoute des 0 a autre
		for(int i(0); i<dimension(); ++i) V[i] -= stockage.V[i];
		
	}
	
	return *this; 
	
}

const Vecteur operator+(Vecteur const& V1, Vecteur const& V2) {
	
	Vecteur V3;
	V3 = V1;
	V3 += V2;
	return V3;
		
}

const Vecteur operator-(Vecteur const& V1, Vecteur const& V2) {
	
	Vecteur V3;
	V3 = V1;
	V3 -= V2;
	return V3;

}

Vecteur Vecteur::operator-() const { return oppose(); } // oppose
Vecteur Vecteur::operator*(double d) const { return mult(d); } // multiplication scalaire V*n
double Vecteur::operator*(Vecteur const& autre) const { return prod_scal(autre); } // produit scalaire
Vecteur Vecteur::operator^(Vecteur autre) const { return prod_vect(autre); } // produit vectoriel
Vecteur operator*(double d, Vecteur const& V) { // multiplication scalaire n*V (externe)
	
	vector<double> stockage(V.getV());
	vector<double> tableau;
	size_t taille(V.getV().size());
	for(size_t i(0); i<taille; ++i) tableau.push_back(d*stockage[i]);
	Vecteur resultat(tableau);
	
	return resultat;

}

/*---------------------------------------------------------------------------*/

// autres methodes

void Vecteur::augmente(double const& d) { V.push_back(d); } // ajoute une dimension
void Vecteur::diminue() {V.pop_back();} // enleve une dimension
void Vecteur::efface() { V.clear(); } // vide le vecteur
void Vecteur::virgule(int const& n) const { if(n>=2) cout << ", "; } // affichage de la virgule
ostream& Vecteur::affiche(ostream& sortie) const { // affichage
	
	int i(V.size());
	sortie << "(";
	for(auto element: V) {
		sortie << element;
		virgule(i);
		--i;
	}
	sortie << ")";
	return sortie;
	
}
