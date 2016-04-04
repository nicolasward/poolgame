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
	void efface();
	void augmente(double d);
	void diminue();
	std::ostream& affiche(std::ostream& flux) const; 
	bool operator==(Vecteur U); 
	Vecteur operator+(Vecteur autre);
	Vecteur operator-(Vecteur autre);
	Vecteur operator--();
	Vecteur operator*(double d);
	double operator%(Vecteur autre);
	Vecteur operator^(Vecteur autre);
	double norme() const;
	double norme_carre() const;
	Vecteur(int dim);
	Vecteur(const Vecteur& autre);
	Vecteur(double x, double y, double z);
	Vecteur(std::vector<double> liste);
};
	std::ostream& operator<<(std::ostream& flux, Vecteur const& V);

#endif
