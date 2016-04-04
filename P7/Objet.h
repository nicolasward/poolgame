#ifndef OBJET_H
#define OBJET_H

#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "IntegrateurEuler.h"

class Objet {
	
	public:
		virtual Vecteur distance(Boule const& B) const = 0;
		virtual double t_collision(Boule const& B, double const& t, double const& dt, IntegrateurEuler const& integrateur) const = 0;
		virtual void collision(Boule& B) = 0;
	
};

#endif
