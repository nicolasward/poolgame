#ifndef BOULE_H
#define BOULE_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "Integrateur.h"
#include "IntegrateurKutta.h"

class Boule {
	
	private: //attributs
		double rayon;
		double masse;
		double coeff_frt;
		double restitution;
		double frt_roul;
		double frt_glis;
		Vecteur force;
		Vecteur etat;
		Vecteur derivee_temp;
	
	public:
		// accesseurs
		double volume() const;
		Vecteur poids();
		double getmasse() const;
		double getrayon() const;
		double getcoef() const;
		double getresti() const;
		double getroul() const;
		double getglis() const;
		Vecteur getForce() const;
		Boule(double r, double m, double frt, double rest, double roul, double glis);
		Boule(double r, double m, double frt, double rest, double roul, double glis, Vecteur force, Vecteur etat, Vecteur derivee);
		double masse_volumique() const;
		double calcul_masse(double const& masse_volumique) const;
		
		//modificateurs
		void setRoul(double const& a);
		void setGlis(double const& a);
		Vecteur getEtat() const;
		void setEtat(Vecteur const& a);
		Vecteur getDerivee() const;
		void setDerivee(Vecteur const& a);
		void ajoute_force(Vecteur df);
		Vecteur evolution() const;
		void setForce(Vecteur const& F);
		
		// autres methodes
		void affiche() const;
};
		
		std:: ostream& operator<<(std:: ostream& sortie,const Boule& B);
		
#endif
