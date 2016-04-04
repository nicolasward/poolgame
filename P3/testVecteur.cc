#include <iostream>
#include <cmath>
#include "vecteur.h"
using namespace std;

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
