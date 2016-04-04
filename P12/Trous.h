#ifndef TROUS_H
#define TROUS_H

#include <vector>
#include <cmath>
#include "Tapis.h"

class Trou : public Objet {
	
	public:
		// constructeur
		Trou(Vecteur const& c, double const& r, Support_a_dessin* S)
		: Objet(S), centre(c), rayon(r) {}
		
		// methode pour faire disparaitre une boule lors d'une "collision" avec un trou
		void byebye(Boule& B) const;
		
		// methodes propres a tout Objet
		Vecteur distance(Boule const& B) const;
		double t_collision(Boule& B, double const& t, double const& dt, Integrateur* I) const;
		void collision(Boule& B);
		
	private: // attributs
		Vecteur centre = Vecteur(3);
		double rayon = 1.0;
		
		
};

#endif
