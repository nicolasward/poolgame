#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <cmath>

class Vecteur {
	
	private:
		std::vector<double> V;
				
		// operations avec signe (avec surcharge)
		Vecteur soustraction(Vecteur const& autre) const;
		Vecteur oppose() const;
		Vecteur mult(double const& d) const;
		Vecteur prod_vect(Vecteur const& autre) const;
		double prod_scal(Vecteur const& autre) const;
		bool compare(Vecteur const& U) const;
		void virgule(int const& n) const;
		
	public:
	
		// getter et setter
		void setV(std::vector<double> const& U);
		std::vector<double> getV() const;
		double dimension() const;
		
		// surcharge d'operateurs
		Vecteur operator-() const;
		double operator%(Vecteur autre) const;
		Vecteur operator^(Vecteur autre) const;
		Vecteur operator*(double d) const;
		double operator*(Vecteur const& autre) const;
		bool operator==(Vecteur const& U) const; 
		Vecteur& operator+=(Vecteur const& autre);
		Vecteur& operator-=(Vecteur const& autre);
		
		// constructeurs
		Vecteur();
		Vecteur(int n);
		Vecteur(Vecteur const& autre);
		Vecteur(double const& x, double const& y, double const& z);
		Vecteur(std::vector<double> const& liste);
		
		// operations sans signe (sans surcharge)
		double norme() const;
		double norme_carre() const;
		
		// autres methodes
		void augmente(double const& d);
		void diminue();
		void efface(); 
		std::ostream& affiche(std::ostream& sortie) const;
		
};

// operateurs externes

std::ostream& operator<<(std::ostream& sortie, Vecteur const& V); // affichage
const Vecteur operator+(Vecteur const& V1, Vecteur const& V2);
const Vecteur operator-(Vecteur const& V1, Vecteur const& V2);

#endif
