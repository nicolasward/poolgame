#include <iostream>
#include <vector>
#include "Boule.h"
#include <cmath>
#include "Vecteur.h"
#include "Integrateur.h"
#include "IntegrateurEuler.h"
using namespace std;

class Boule;

void IntegrateurEuler::integre(Boule& B, double dt) {
		
		B.setDerivee(B.getDerivee() + B.evolution()*dt);
		B.setEtat(B.getEtat() + B.getDerivee()*dt);
		
}
