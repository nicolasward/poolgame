#include "Dessinable.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& sortie, Dessinable const& D) {
	
	D.affiche(sortie);
	return sortie;
	
}
