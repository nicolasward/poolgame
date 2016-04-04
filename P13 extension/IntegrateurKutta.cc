#include <iostream>
#include <vector>
#include "Boule.h"
#include <cmath>
#include "Vecteur.h"
#include "Integrateur.h"
#include "IntegrateurKutta.h"
using namespace std;

class Boule;

void IntegrateurKutta::integre(Boule& B, double dt) {

		Boule B1(B), B2(B), B3(B);
		
		Vecteur k1(3), k2(3), k3(3), k4(3);
		Vecteur k1_prime(3), k2_prime(3), k3_prime(3), k4_prime(3);
		
		k1 = B.getDerivee();
		k1_prime = B.evolution();
		
		B1.setEtat(B.getEtat()+k1*(dt/2));
		B1.setDerivee(B.getDerivee()+k1_prime*(dt/2));
		
		k2 = B.getDerivee() + k1_prime*(dt/2);
		k2_prime = B1.evolution();
		
		B2.setEtat(B.getEtat()+k2*(dt/2));
		B2.setDerivee(B.getDerivee()+k2_prime*(dt/2));
		
		k3 = B.getDerivee() + k2_prime*(dt/2);
		k3_prime = B2.evolution();
		
		B3.setEtat(B.getEtat()+k3*dt);
		B3.setDerivee(B.getDerivee()+k3_prime*dt);
		
		k4 = B.getDerivee() + k3_prime*dt;
		k4_prime = B3.evolution();
		
		B.setEtat(B.getEtat() + (k1+k2*2+k3*2+k4)*(dt/6));
		B.setDerivee(B.getDerivee() + (k1_prime+k2_prime*2+k3_prime*2+k4_prime)*(dt/6));
		
}
