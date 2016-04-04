#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "Boule.h"
#include <cmath>
#include "Integrateur.h"
#include "IntegrateurEuler.h"
#include "Support_a_dessin.h"
using namespace std;

const double pi = 3.14159265358979323846264338327950288419716939937510; // 50 premieres decimales de pi

/*---------------------------------------------------------------------------*/

// constructeurs

Boule::Boule(double r=0, double m=0, double frt=0, double rest=0, double roul=0, double glis=0, Support_a_dessin* vue)
	: 	Objet(vue),
		rayon(r),
		masse(m),
		coeff_frt(frt),
		restitution(rest),
		frt_roul(roul),
		frt_glis(glis)
	
	{ Vecteur nul(6);
	  force = poids();
	  etat = nul;
	  derivee_temp = nul; }
	  
Boule::Boule(double r, double m, double frt, double rest, double roul, double glis, Vecteur force, Vecteur etat, Vecteur derivee, Support_a_dessin* vue)
	:	Objet(vue),
		rayon(r),
		masse(m),
		coeff_frt(frt),
		restitution(rest),
		frt_roul(roul),
		frt_glis(glis), 
		force(force),
		etat(etat),
		derivee_temp(derivee)
		{}
		
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

// modificateurs

void Boule::setRoul(double const& a) { frt_roul = a; }
void Boule::setGlis(double const& a) { frt_glis = a; }
Vecteur Boule::getEtat() const { return etat; }
void Boule::setEtat(Vecteur const& a) { etat = a; }
Vecteur Boule::getDerivee() const { return derivee_temp; }
void Boule::setDerivee(Vecteur const& a) { derivee_temp = a; }
void Boule::setForce(Vecteur const& F) { force = F; }
Vecteur Boule::getPosition() const { 
	
	vector<double> tab(etat.getV());
	return Vecteur(tab[0], tab[1], tab[2]);
	
}
Vecteur Boule::getVitesse() const {
	
	vector<double> tab(derivee_temp.getV());
	return Vecteur(tab[0], tab[1], tab[2]);
	
}
void Boule::setVitesse(Vecteur const& A) {
	
	vector<double> tab(A.getV());
	derivee_temp.modifie(1, tab[0]);
	derivee_temp.modifie(2, tab[1]);
	derivee_temp.modifie(3, tab[2]);
	
}
Vecteur Boule::getVitesse_Angulaire() const {
	
	vector<double> tab;
	tab = derivee_temp.getV();
	return Vecteur(tab[3], tab[4], tab[5]);
	
}
void Boule::setVitesse_Angulaire(Vecteur const& A) {
	
	vector<double> tab(A.getV());
	derivee_temp.modifie(4, tab[3]);
	derivee_temp.modifie(5, tab[4]);
	derivee_temp.modifie(6, tab[5]);
	
}

/*---------------------------------------------------------------------------*/

// surcharge externe d'operateurs

ostream& operator<<(ostream& sortie, const Boule& b) {
	
	sortie << "Masse : " << b.getmasse() << endl
		   << "Rayon : " << b.getrayon() << endl
		   << "Masse volumique : " << b.masse_volumique()  << endl
		   << "Position : "  << "(" << b.getEtat().getV()[0] << ", " << b.getEtat().getV()[1] << ", " << b.getEtat().getV()[2] << ")" << endl
		   << "Angles : " << "(" << b.getEtat().getV()[3] << ", " << b.getEtat().getV()[4] << ", " << b.getEtat().getV()[5] << ")" << endl
		   << "Vitesse : " << "(" << b.getDerivee().getV()[0] << ", " << b.getDerivee().getV()[1] << ", " << b.getDerivee().getV()[2] << ")" << endl 
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

Vecteur Boule::distance(Boule const& B) const {
	
	Vecteur O;
	O.augmente(etat.getV()[0]);
	O.augmente(etat.getV()[1]);
	O.augmente(etat.getV()[2]);
	
	Vecteur x1;
	x1.augmente(B.getEtat().getV()[0]);
	x1.augmente(B.getEtat().getV()[1]);
	x1.augmente(B.getEtat().getV()[2]);
	
	
	return O + rayon * (x1 - O);
	
}

double quadratique(double const& A, double const& B, double const& C) {
	
	double resultat(0);
	double delta(B*B-4*A*C);
	
	if(delta < 0) resultat = 675;
	else if(delta == 0) {
		resultat = -B/(2*A);
		if(resultat<0 or resultat>1) resultat = 675;
	}
	else {
		double x1((-B-sqrt(delta))/(2*A)), x2((-B+sqrt(delta))/(2*A));
		if(x1<x2 or x1==x2) resultat = x1;
		else resultat = x2;
		if(resultat<0 or resultat>1) resultat = 675;
	}
	
	return resultat;
	
}

double Boule::t_collision(Boule& B2, double const& t, double const& dt, IntegrateurEuler const& integrateur) const {
	
	// double dts = 0.1;
	
	IntegrateurEuler I;
	
	// Boule 1 (integree dans la classe)
	
	Boule B1(*this);
	double R1(B1.getrayon());
	Vecteur x1(B1.getPosition());
	Vecteur v1(B1.getVitesse());
	
	// Boule 2 (entree en parametre de la methode)
	
	Boule B2_copie(B2);
	double R2(B2_copie.getrayon());
	Vecteur x2(B2_copie.getPosition());
	Vecteur v2(B2_copie.getVitesse());
	
	Vecteur nul(3);
	double tau(0.0);
	
	if(not(v1 == nul and v2 == nul)) {
	
		I.integre(B1, dt);
		I.integre(B2_copie, dt);
	
		Vecteur x1_prime(B1.getPosition());
		Vecteur x2_prime(B2_copie.getPosition());
		
		Vecteur a(x2 - x1);
		Vecteur b(x2_prime - x1_prime - a);
		double A(b.norme_carre());
		double B(2*(a*b));
		double C(a.norme_carre() - pow((R1+R2), 2));
	
		tau = quadratique(A, B, C);
		if(tau != 675) { tau *= dt; }
	
		return tau;
	
	} else if((v1 == nul) xor (v2 == nul)) {
		
		if(v1 == nul) {
			
			Vecteur D(B2_copie.distance(B1));
			I.integre(B2_copie, dt);
			Vecteur x2_prime(B2_copie.getPosition());
			Vecteur D_prime(B2_copie.distance(B1));
			
			if(D_prime.norme() < R2 or D*D_prime < 0) {
				
				Vecteur n((x2 - x1) * (1/(x2 - x1).norme()));
					
				tau = (R2 - n*D)/(n*D_prime - n*D);
				
			} else {
				
				tau = 675; 
				
			}
				
			return tau;
			
			
		} else {
				
				Vecteur D(B2_copie.distance(B1));
				I.integre(B1, dt);
				Vecteur x1_prime(B1.getPosition());
				Vecteur D_prime(B2_copie.distance(B1));
			
				if(D_prime.norme() < R1 or D*D_prime < 0) {
				
					Vecteur n((x1 - x2) * (1/(x1 - x2).norme()));
					
					tau = (R1 - n*D)/(n*D_prime - n*D);
					
				} else {
				
				tau = 675; 
				
				}
				
				return tau;
				 
		}
			
	} else {
			
			return 675;
			
	}
		

}

void Boule::collision(Boule& B2) {
	
	
	// Boule 1 (integrée dans la classe)
	
	double R1(rayon);
	Vecteur x1(getPosition());
	Vecteur v1(getVitesse());
	Vecteur w1(getVitesse_Angulaire());
	double m1(masse);
	
	// Boule 2 (entrée en paramètre de la méthode)
	
	double R2(B2.rayon);
	Vecteur x2(B2.getPosition());
	Vecteur v2(B2.getVitesse());
	Vecteur w2(B2.getVitesse_Angulaire());
	double m2(B2.masse);
	
	double alpha = restitution * B2.restitution; // bon
	double mu = coeff_frt * B2.coeff_frt; // bon
	double lambda = (1+alpha) * (m2/(m1+m2)); // bon
	Vecteur n = (x1 - x2) * (1/(x1 - x2).norme()); // bon
	
	Vecteur delta_v(3);
	Vecteur delta_w(3);
	Vecteur Vc(3);
	Vecteur nul(3);
	Vecteur Vc_norme(3);
	double v_etoile(0);
	
	if((x1-x2).norme() <= R1+R2) {
		
		// cout << "1" << endl;
	
		v_etoile = (v2 - v1) * n; // bon
		Vc = v1 - v2 + (n*v_etoile) + (n^((w1*R1) + (w2*R2))); // bon
		Vc_norme = Vc * (1/Vc.norme()); // bon
		
	
		if(((1+alpha)*7*mu*v_etoile) >= 2*Vc.norme()) {
			
			// cout << "1, 2" << endl;
			
			delta_v = n*(lambda*v_etoile) - Vc*(2*m2*(1/(7*(m1+m2))));
			delta_w = ((5*m2)/(7*R1*(m1+m2)))*(n^Vc);
			
			
		} else {
			
			// cout << "1, 3" << endl;
			
			delta_v = (n - mu*Vc_norme)*(lambda*v_etoile);
			delta_w = ((n)^(Vc_norme))*(5*mu*lambda*v_etoile)*(1/(2*R1));
			
		}
		
		v1 += delta_v;
		w1 += delta_w;
		v2 -= delta_v*(m1/m2);
		w2 += delta_w*((m1*R1)/(m2*R2));
		
	
	} else if((x1-x2).norme() <= R1) {
		
		// cout << "2" << endl;
		
		v_etoile = (nul - v1) * n;
		Vc = v1 + (n*v_etoile) + (n^(R1*w1));
	
		if((7*mu*(1+lambda)*v_etoile) >= 2*Vc.norme()) {
			
			// cout << "2, 1" << endl;
			
			delta_v = n*(lambda*v_etoile) - Vc*(2/7);
			delta_w = (n^Vc)*(5/(7*R1));
			
		} else {
			
			// cout << "2, 2" << endl;
			
			delta_v = (n - mu*(Vc*(1/(Vc.norme()))))*(lambda*v_etoile);
			delta_w = (n^(Vc*(1/Vc.norme())))*((5/(2*R1))*mu*lambda*v_etoile);
			
		}
		
		v1 += delta_v;
		w1 += delta_w;

		
	}
		setVitesse(v1);
		setVitesse_Angulaire(w1);
		B2.setVitesse(v2);
		B2.setVitesse_Angulaire(w2);
	
}
