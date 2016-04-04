#ifndef INTEGRATEUR_H
#define INTEGRATEUR_H

#include <vector>
#include <cmath>
#include "Vecteur.h"

class Boule;

class Integrateur {
	
	public:
		virtual void integre(Boule& B, double dt) = 0;
	
};

#endif
