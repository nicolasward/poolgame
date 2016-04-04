#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "Boule.h"
#include <cmath>
#include "Integrateur.h"
#include "IntegrateurEuler.h"
#include "Support_a_dessin.h"
#include "Systeme.h"
#include "Dessinable.h"
using namespace std;


void Systeme::ajoute_boule(Boule* B) { boules.push_back(B); }
		
void Systeme::ajoute_objet(Objet* O) { objets.push_back(O); }
