#ifndef SYSTEME_H
#define SYSTEME_H

#include "Dessinable.h"
#include "Support_a_dessin.h"

class Systeme : public Dessinable {
	
	public:
		virtual void dessine() override
		{support->dessine(*this);}
		
		void ajoute_boule(Boule*);
		void ajoute_objet(Objet*);
	
	private:
		std::vector<Boule*> boules;
		std::vector<Objet*> objets;
};

#endif
