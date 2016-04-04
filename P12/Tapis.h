#ifndef TAPIS_H
#define TAPIS_H

#include <vector>
#include <cmath>
#include "Parois.h"

class Tapis : public Paroi {
	
	public:
	
		// constructeurs
		Tapis(double const& L, double const& l);
		Tapis(Vecteur const& n, double const& L, double const& l, Vecteur const& O, double const& c, double r, Support_a_dessin* S);
		
		// methodes propres a tout Objet
		Vecteur distance(Boule const& B) const;
		double t_collision(Boule& B, double const& t, double const& dt, Integrateur* I) const;
		void collision(Boule& B);		
		void dessine();	
		
		// Pour savoir si notre paroi est conventionnelle
		void conventionnel() const;
		
		// Methode definie dans P11
		void reaction(Boule& B);
		
		// affichage d'un Tapis
		std::ostream& affiche (std::ostream& sortie) const;
		
		// modificateurs
		void setRoul(double const& r);
		void setGlis(double const& g);
	
	private: // attributs
		double frt_roul = 0.0;
		double frt_glis = 0.0;
	
};

#endif
