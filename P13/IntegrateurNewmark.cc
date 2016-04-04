#include <iostream>
#include <vector>
#include "Boule.h"
#include <cmath>
#include "Vecteur.h"
#include "Integrateur.h"
#include "IntegrateurNewmark.h"
using namespace std;

class Boule;

void IntegrateurNewmark::integre(Boule& B, double dt) {

		
		Boule B1(B);
			
		Vecteur omega(B1.getEtat());
		Vecteur omegapoint_ancien(B1.getDerivee());
		
		Vecteur X_prime(B1.evolution());
		Vecteur X;
		Vecteur Sigma;
		
		do {
		Sigma = omega;
		X = B1.evolution();
		omegapoint_ancien = B.getDerivee();
		B.setDerivee(B.getDerivee() + (X + X_prime)*(dt/2));
		B.setEtat(B.getEtat() + omegapoint_ancien*dt + (X*0.5 + X_prime)*((dt*dt)/3));
		} while((B.getEtat() - Sigma).norme() >= 0.1);
		
		
}
