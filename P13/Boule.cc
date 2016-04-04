#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "Boule.h"
#include <cmath>
#include "Integrateur.h"
#include "IntegrateurNewmark.h"
using namespace std;

const double pi = 3.14159265358979323846264338327950288419716939937510; // 50 premieres decimales de pi

/*---------------------------------------------------------------------------*/

// accesseurs

double Boule:: volume() const { return (4.0/3.0)*pi*pow(rayon,3); }
double Boule:: getmasse() const { return masse; }
double Boule:: getrayon() const { return rayon; }
double Boule:: getcoef() const { return coeff_frt; }
double Boule:: getresti() const { return restitution; }
double Boule:: getroul() const { return frt_roul; }
double Boule:: getglis() const { return frt_glis; }
Vecteur Boule:: getForce() const { return force; }

/*---------------------------------------------------------------------------*/

// constructeurs

Boule::Boule(double r=0, double m=0, double frt=0, double rest=0, double roul=0, double glis=0)
	: 	rayon(r),
		masse(m),
		coeff_frt(frt),
		restitution(rest),
		frt_roul(roul),
		frt_glis(glis)
	
	{ Vecteur nul(6);
	  force = poids();
	  etat = nul;
	  derivee_temp = nul; }
	  
Boule::Boule(double r, double m, double frt, double rest, double roul, double glis, Vecteur force, Vecteur etat, Vecteur derivee)
	:	rayon(r),
		masse(m),
		coeff_frt(frt),
		restitution(rest),
		frt_roul(roul),
		frt_glis(glis), 
		force(force),
		etat(etat),
		derivee_temp(derivee) {}
		
/*---------------------------------------------------------------------------*/

// modificateurs

void Boule::setRoul(double const& a) { frt_roul = a; }
void Boule::setGlis(double const& a) { frt_glis = a; }
Vecteur Boule::getEtat() const { return etat; }
void Boule::setEtat(Vecteur const& a) { etat = a; }
Vecteur Boule::getDerivee() const { return derivee_temp; }
void Boule::setDerivee(Vecteur const& a) { derivee_temp = a; }
void Boule::setForce(Vecteur const& F) { force = F; }

/*---------------------------------------------------------------------------*/

// surcharge externe d'operateurs

ostream& operator<<(ostream& sortie, const Boule& b) {
	
	sortie << "Masse : " << b.getmasse() << endl
		   << "Rayon : " << b.getrayon() << endl
		   << "Masse volumique : " << b.masse_volumique()  << endl
		   << "Position : "  << "(" << b.getEtat().getV()[0] << ", " << b.getEtat().getV()[1] << ", " << b.getEtat().getV()[2] << ")" << endl
		   << "Vitesse : " << "(" << b.getDerivee().getV()[0] << ", " << b.getDerivee().getV()[1] << ", " << b.getDerivee().getV()[2] << ")" << endl 
		   << "Angles : " << "(" << b.getEtat().getV()[3] << ", " << b.getEtat().getV()[4] << ", " << b.getEtat().getV()[5] << ")" << endl
		   << "Vitesse angulaire : " << "(" << b.getDerivee().getV()[3] << ", " << b.getDerivee().getV()[4] << ", " << b.getDerivee().getV()[5] << ")" << endl 
		   << "Force : " << b.getForce() << endl
		   << "Coefficient de restitution : " << b.getresti() << endl
		   << "Coefficient de frottement : " << b.getcoef() << endl
		   << "Coefficient de frottement (roulement) : " << b.getroul() << endl
		   << "Coefficient de frottement (glissement) : " << b.getglis() << endl
		   << endl;
		   
	return sortie;
		   
}

/*---------------------------------------------------------------------------*/

// autres methodes

double Boule::masse_volumique() const {
		
	if (volume()==0) return 0;
	else return masse/volume();
	
}

double Boule::calcul_masse(double const& masse_volumique) const { return masse_volumique*pow(rayon,3)*(4*pi)/3; }
void Boule::ajoute_force(Vecteur df) { force = force + df; }
Vecteur Boule::poids() { return Vecteur(0, 0, -9.81)*masse; }

Vecteur Boule::evolution() const {
		
		Vecteur retour;
		
		retour.augmente(force.getV()[0]/masse);
		retour.augmente(force.getV()[1]/masse);
		retour.augmente(force.getV()[2]/masse);
		retour.augmente(0);
		retour.augmente(0);
		retour.augmente(0);
		
		return retour;

}
