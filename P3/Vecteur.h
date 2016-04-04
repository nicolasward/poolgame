#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <cmath>

class Vecteur {
	private:
	std::vector<double> V;
	
	public:
	std::vector<double> getV(); 
	void setV(std::vector<double> U);
	void augmente(double d);
	void diminue();
	void affiche();
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

#endif
