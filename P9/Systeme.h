#ifndef SYSTEME_H
#define SYSTEME_H

#include <iostream>
#include "Boule.h"
#include "Integrateur.h"

class Systeme {

	public:
		void ajoute_boule(Boule*);
		void ajoute_objet(Objet*);

		void dessine();

		void evolue(double dt);

		Systeme(Integrateur* inte)
		: I(inte) {}

		Systeme (const Systeme&) = delete ;

		~Systeme();

		std::ostream& affiche(std::ostream&) const;

	private:
		Integrateur* I;
		std::vector<Boule*> boules;	//collection heterogene d'objets mobiles
		std::vector<Objet*> objets;	//collection heterogene d'objets immobiles
};

#endif
