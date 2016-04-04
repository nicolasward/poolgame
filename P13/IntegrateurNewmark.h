#ifndef INTEGRATEUREULER_H
#define INTEGRATEUREULER_H

#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "Boule.h"
#include "Integrateur.h"

class IntegrateurNewmark : public Integrateur {
	
	public:
		void integre(Boule& B, double dt) override;
	
};

#endif
