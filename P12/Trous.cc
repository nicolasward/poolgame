#include <iostream>
#include "TextViewer.h"
#include "Dessinable.h"
#include "IntegrateurEuler.h"
#include "Boule.h"
#include "Systeme.h"
#include "Trous.h"
using namespace std;

void Trou::byebye(Boule& B) const { B.supprime(); }

// methodes propres a tout Objet

Vecteur Trou::distance(Boule const& B) const {
	
	vector<double> stock = B.getPosition().getV();
	Vecteur projection(stock[0], stock[1], 0); // on projette la Boule sur la table
	
	return (projection-centre).norme(); // la distance correspond a l'ecart entre le centre du trou et la projection du centre de la Boule
	
}

double Trou::t_collision(Boule& B, double const& t, double const& dt, Integrateur* I) const { return 0.0; } // non-definie

void Trou::collision(Boule& B) {} // non-definie

int main() {
	
	
	
}
