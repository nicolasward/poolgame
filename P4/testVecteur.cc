#include <iostream>
#include <cmath>
#include "Vecteur.h"
using namespace std;

int main()
{
	Vecteur V1(0);
	Vecteur V2(0);
	Vecteur V3(0);
	
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

	if(V1 == V2) { 
		cout << "Les vecteurs 1 et 2 sont egaux. " << endl; 
		} else { cout << "Les vecteurs 1 et 2 ne sont pas egaux." 
					  << endl; };
					  
	cout << endl;
		
	// test de la fonction "affiche"
	
	cout << "Voici votre vecteur 3: "; 
	cout<<V3; 
	cout << endl;
	cout << endl;
	
	// test des fonctions "addition" et "soustraction" pour des vecteurs de meme dimension

	Vecteur Q(0);

	cout << "vecteur 1 + vecteur 2 = ";
	Q = V1 + V2;
	cout<<V3;
	cout << endl;
	cout << endl;
	cout << "vecteur 1 - vecteur 2 = ";
	Q = V1 - V2;
	cout<<Q;
	cout << endl;
	cout << endl;
		 
	// test des fonctions "addition" et "soustraction" pour des vecteurs de dimensions differentes
	
	V1.augmente(3);
	cout << "Ajout d'une dimension. Voici le nouveau vecteur 1: ";
	cout<<V1;
	cout << endl;
	cout << endl;
	cout << "vecteur 1 + vecteur 2 = ";
	Q = V1 + V2;
	cout<<Q;
	cout << endl;
	cout << endl;
	cout << "vecteur 1 - vecteur 2 = ";
	Q = V1 - V2;
	cout<<Q;
	cout << endl;
	cout << endl;
	V1.diminue();
	
	// test de la fonction "oppose"
	
	Q = --V3;
	cout << "L'oppose du vecteur 3 est: ";
	cout<<Q;
	cout << endl;
	cout << endl;
	
	// test de la fonction "mult" (multiplication par un scalaire)
	
	Q = V2*5;
	cout << "5 * vecteur 2 = ";
	cout<<Q;
	cout << endl;
	cout << endl;
	
	// test de la fonction "prod_scal"
	
	cout << endl;
	cout << "Produit scalaire V1.V3 = "
		 << V1 % V3
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
	cout<<( V1 ^ V2 );
	cout<<endl;
	cout<<endl;
	
	// test des constructeurs
	
		// constructeur de copie
		
		Vecteur Nouveau(V3);
		cout << "Creation d'un vecteur 'Nouveau'. " << endl;
		cout << "Copie de V3 dans Nouveau." << endl;
		cout << "Voici le vecteur Nouveau: ";
		cout<<Nouveau;
		cout << endl;
		cout << endl;
				
		// constructeur coordonnees cartesiennes
		
		Vecteur Nouveau2(10, 10, 10);
		cout << "Creation d'un vecteur 'Nouveau2'. " << endl;
		cout << "Initialisation a 10, 10, 10." << endl;
		cout << "Voici le vecteur Nouveau2: ";
		cout<<Nouveau2;
		cout << endl;
		cout << endl;
		
		/* initialisation a 0
		
		Vecteur Nouveau3;
		cout << "Creation d'un vecteur 'Nouveau3'. " << endl;
		cout << "Initialisation au vecteur nul." << endl;
		cout << "Voici le vecteur Nouveau3: ";
		Nouveau3.affiche();
		cout << endl; 											*/
		
		// initialisation avec liste
		
		vector<double> liste;
		int dim;
		cout << "Initialisation avec liste."
			 << endl
			 << "Creation d'un nouveau vecteur."
			 << endl
			 << "Combien de dimensions souhaitez-vous pour ce nouveau vecteur? ";
		cin >> dim;
		
		for(int i(1); i<=dim; ++i) {
			int k(0);
			cout << "Coordonnee "
				 << i
				 <<  ": ";
			cin >> k;
			liste.push_back(k);
		}
		
		cout << endl;
		Vecteur Nouveau3(liste);
		cout << "Voici votre vecteur: ";
		cout<<Nouveau3;
		cout << endl;
	
	return 0;
}
