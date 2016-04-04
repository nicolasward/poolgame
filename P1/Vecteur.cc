#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Vecteur {
	private:
	vector<double> V;
	
public:
	vector<double> getV() { return V; }
	void setV(vector<double> U) { V = U; }
	void augmente(double d) { V.push_back(d); }
	void diminue() {V.pop_back();}
	void affiche() { for(auto element: V) { cout << element << " "; } }
	bool compare(Vecteur U) const; 
	Vecteur addition(Vecteur autre) const; 
	Vecteur soustraction(Vecteur autre) const;
	Vecteur oppose() const;
	Vecteur mult(double d) const; 
	double prod_scal(Vecteur autre) const;
	Vecteur prod_vect(Vecteur) const;
	double norme() const;
	double norme_carre() const;
};

int main()
{
	Vecteur V1;
	Vecteur V2;
	Vecteur V3;
	
	int n(0);
	double c(0);
	
	cout << "Avec combien de dimensions souhaitez-vous travailler ? ";
	cin >> n;
	cout << endl;
	
	cout << "Saisie des coordonnees du vecteur 1 " << endl;
	
	// test de la fonction "augmente"
	
	for(int i(1); i<=n; ++i) {
		c = 0;
		cout << "Coordonnee " << i << ": ";
		cin >> c;
		V1.augmente(c); } 
		
	cout << endl;
	cout << "Saisie des coordonnees du vecteur 2 " << endl;
	
	for(int i(1); i<=n; ++i) {
		c = 0;
		cout << "Coordonnee " << i << ": ";
		cin >> c;
		V2.augmente(c); }
	
	cout << endl;	
	cout << "Saisie des coordonnees du vecteur 3 " << endl;
	
	for(int i(1); i<=n; ++i) {
		c = 0;
		cout << "Coordonnee " << i << ": ";
		cin >> c;
		V3.augmente(c); }
		
		cout << endl;

	// test de la fonction "compare"

	if(V1.compare(V2)) { 
		cout << "Les vecteurs 1 et 2 sont egaux. " << endl; 
		} else { cout << "Les vecteurs 1 et 2 ne sont pas egaux." 
					  << endl; };
					  
	cout << endl;
		
	// test de la fonction "affiche"
	
	cout << "Voici votre vecteur 3: "; 
	V3.affiche(); 
	cout << endl;
	cout << endl;
	
	// test des fonctions "addition" et "soustraction" pour des vecteurs de meme dimension

	Vecteur Q;

	cout << "vecteur 1 + vecteur 2 = ";
	Q = V1.addition(V2);
	Q.affiche(); 
	cout << endl;
	cout << endl;
	cout << "vecteur 1 - vecteur 2 = ";
	Q = V1.soustraction(V2);
	Q.affiche();
	cout << endl;
	cout << endl;
		 
	// test des fonctions "addition" et "soustraction" pour des vecteurs de dimensions differentes
	
	V1.augmente(3);
	cout << "Ajout d'une dimension. Voici le nouveau vecteur 1: ";
	V1.affiche();
	cout << endl;
	cout << endl;
	cout << "vecteur 1 + vecteur 2 = ";
	Q = V1.addition(V2);
	Q.affiche();
	cout << endl;
	cout << endl;
	cout << "vecteur 1 - vecteur 2 = ";
	Q = V1.soustraction(V2);
	Q.affiche();
	cout << endl;
	cout << endl;
	V1.diminue();
	
	// test de la fonction "oppose"
	
	Q = V3.oppose();
	cout << "L'oppose du vecteur 3 est: ";
	Q.affiche();
	cout << endl;
	cout << endl;
	
	// test de la fonction "mult" (multiplication par un scalaire)
	
	Q = V2.mult(5);
	cout << "5 * vecteur 2 = ";
	Q.affiche();
	cout << endl;
	cout << endl;
	
	// test de la fonction "prod_scal"
	
	cout << endl;
	cout << "Produit scalaire V1.V3 = "
		 << V1.prod_scal(V3)
		 << endl
		 << endl;
		 
	// test des fonctions "norme" et "norme_carre"
	
	cout << "Norme du vecteur 2 = "
		 << V2.norme()
		 << endl
		 << endl;
		 
	cout << "Norme au carre du vecteur 2 = "
		 << V2.norme_carre()
		 << endl
		 << endl;
		 
	// test de la fonction "produit vectoriel"
	
	cout<<"Produit vectoriel de V1 et de V2 = ";
	V1.prod_vect(V2).affiche();
	
	
	
	return 0;
}

bool Vecteur:: compare(Vecteur U) const {
	 
		bool resultat(true);
		bool provisoire(true);
		for(size_t i(0); i<V.size(); ++i) {
				if(V[i] != U.V[i]) { 
					provisoire = false; }
				}
		resultat = provisoire;
		return resultat;
}

Vecteur Vecteur:: addition(Vecteur autre) const {
	
		Vecteur resultat;
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

Vecteur Vecteur:: soustraction(Vecteur autre) const {
	
	Vecteur resultat;
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

Vecteur Vecteur:: oppose() const {
	
	Vecteur resultat;
	vector<double> resultat2;
				
		for(size_t i(0); i< V.size(); ++i) {
			double P = -V[i];
			resultat2.push_back(P); }
		
	resultat.setV(resultat2);
		
	return resultat; 
}

Vecteur Vecteur:: mult(double d) const {
	
	Vecteur resultat;
	vector<double> resultat2;
				
	for(size_t i(0); i< V.size(); ++i) {
		double P = d*V[i];
		resultat2.push_back(P); }
		
	resultat.setV(resultat2);
	
	return resultat;
}

double Vecteur :: prod_scal(Vecteur autre) const {
	
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

Vecteur Vecteur:: prod_vect(Vecteur autre) const {
	
	Vecteur resultat;
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
