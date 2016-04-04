#include <iostream>
#include <vector>
#include "Vecteur.h"
#include <cmath>
using namespace std;

	vector<double> Vecteur:: getV() { return V; }
	void Vecteur:: setV(std::vector<double> U) { V = U; }
	void Vecteur:: augmente(double d) { V.push_back(d); }
	void Vecteur:: diminue() {V.pop_back();}
	ostream& Vecteur:: affiche(ostream& flux) const 
	{
		for(auto element: V) { 
			flux << element << " ";
		}
		return flux;
	}
	ostream& operator<<(ostream& flux, Vecteur const& V) 
	{
		return V.affiche(flux);
	}
	bool Vecteur:: operator==(Vecteur U) {
		bool resultat(true);
		bool provisoire(true);
		for(size_t i(0); i<V.size(); ++i) {
				if(V[i] != U.V[i]) { 
					provisoire = false; }
				}
		resultat = provisoire;
		return resultat;
	}
 
Vecteur Vecteur:: operator+(Vecteur autre) {
	
		Vecteur resultat(0);
		vector<double> resultat2;
		vector<double> stockage_autre(autre.getV());
		if(stockage_autre.size() != V.size()) {
			if(stockage_autre.size() < V.size()) {
				for(size_t i(0); i< stockage_autre.size(); ++i) {
					double P = V[i] + stockage_autre[i];
					resultat2.push_back(P); } 
			} else { 
				for(size_t i(0); i< V.size(); ++i) {
					double P = V[i] + stockage_autre[i];
					resultat2.push_back(P); } }			
		} else {
			for(size_t i(0); i< stockage_autre.size(); ++i) {
					double P = V[i] + stockage_autre[i];
					resultat2.push_back(P); }
				}
		
		resultat.setV(resultat2);
		return resultat;
}

Vecteur Vecteur:: operator-(Vecteur autre) {
	
	Vecteur resultat(0);
	vector<double> resultat2;
	vector<double> stockage_autre(autre.getV());
	if(stockage_autre.size() != V.size()) {
		if(stockage_autre.size() < V.size()) {
			for(size_t i(0); i< stockage_autre.size(); ++i) {
				double P = V[i] - stockage_autre[i];
				resultat2.push_back(P); } 
		} else { 
			for(size_t i(0); i< V.size(); ++i) {
				double P = V[i] - stockage_autre[i];
				resultat2.push_back(P); } }			
		} else {
			for(size_t i(0); i< stockage_autre.size(); ++i) {
				double P = V[i] - stockage_autre[i];
				resultat2.push_back(P); }
			}
		
	resultat.setV(resultat2);
	return resultat;
}

Vecteur Vecteur:: operator--() {
	
	Vecteur resultat(0);
	vector<double> resultat2;
				
		for(size_t i(0); i< V.size(); ++i) {
			double P = -V[i];
			resultat2.push_back(P); }
		
	resultat.setV(resultat2);
		
	return resultat; 
}
 
Vecteur Vecteur:: operator*(double d) {
	
	Vecteur resultat(0);
	vector<double> resultat2;
				
	for(size_t i(0); i< V.size(); ++i) {
		double P = d*V[i];
		resultat2.push_back(P); }
		
	resultat.setV(resultat2);
	
	return resultat;
}

double Vecteur:: operator%(Vecteur autre) {
	
	double resultat;
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

Vecteur Vecteur:: operator^(Vecteur autre) {
	Vecteur resultat(0);
	vector<double> resultat2;
	vector<double> stock = autre.getV();
	int k(stock.size()), l(V.size());
	if (k==3 && l==3) {
			resultat2.push_back(V[1]*stock[2]-V[2]*stock[1]);
			resultat2.push_back(V[2]*stock[0]-V[0]*stock[2]);
			resultat2.push_back(V[0]*stock[1]-V[1]*stock[0]);
	resultat.setV(resultat2);
	} else {
		cerr<<"Produit vectoriel impossible"<<endl;
	}
	return resultat;
}

double Vecteur:: norme() const { return sqrt(norme_carre()); }

double Vecteur:: norme_carre() const {
	
	double resultat(0.0);
	for (size_t i(0); i<V.size(); ++i) { resultat += V[i]*V[i]; }
	
	return resultat;
}

	void Vecteur :: efface() { 
		for(size_t i(0); i<V.size(); ++i) {
			V.pop_back();
			--i;
		}
	}

	Vecteur::Vecteur(int dim) {
		for(int i(1); i<=dim; ++i) {
			V[i] = 0;
		}
	}
	
	Vecteur::Vecteur(double x, double y, double z)
	{
	 augmente(x);
	 augmente(y);
	 augmente(z);
	}
	
	Vecteur::Vecteur(const Vecteur& autre) 
	{
		Vecteur autre2(0);
		autre2 = autre;
		vector<double> tableau;
		tableau = autre2.getV();
		for(size_t i(0); i<tableau.size(); ++i) {
		V.push_back(tableau[i]);
		}
	}
	
	Vecteur::Vecteur(vector<double> liste)
	{
		for(size_t i(0); i<liste.size(); ++i) {
			V.push_back(liste[i]);
		}
	}
