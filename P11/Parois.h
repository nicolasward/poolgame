#ifndef PAROIS_H
#define PAROIS_H
#include <vector>
#include <cmath>
#include "Boule.h"
#include "TextViewer.h"

class Paroi : public Objet {
	
	public:
		// constructeurs
		Paroi(double const& L, double const& l);
		Paroi(Vecteur const& n, double const& L, double const& l, Vecteur const& O, double const& c, double r, Support_a_dessin* S);		Vecteur distance(Boule const& B) const;
		
		// methodes propres a tout Objet
		double t_collision(Boule& B, double const& t, double const& dt, Integrateur* I) const;
		void collision(Boule& B);
		void dessine();
		
		void conventionnel() const; // pour verifier si une paroi est conventionnelle

		// affichage
		virtual std::ostream& affiche (std::ostream& sortie) const;
		
		// modificateurs
		void setFrottement(double const& f);
		void setRestitution(double const& r);
	
	protected: // attributs (les valeurs par defaut donnent une paroi qui respecte les donnees de l'enonce)
		Vecteur normal = Vecteur(0, 0, 1);
		Vecteur longueur = Vecteur(1, 0, 0);
		Vecteur largeur = Vecteur(0, 1, 0);
		Vecteur origine = Vecteur(3);
		double coeff_frt = 0.0;
		double restitution = 0.0;
		bool conditions = true; // indique si les conditions qui caracterisent une paroi sont bien respectees
	
	
};


#endif
