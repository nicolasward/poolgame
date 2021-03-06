#ifndef BOULE_H
#define BOULE_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "IntegrateurEuler.h"
#include "Objet.h"

// P9

class Boule : public Objet {

	private: // attributs
		double volume() const;
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
		double getmasse() const;
		double getrayon() const;
		double getcoef() const;
		double getresti() const;
		double getroul() const;
		double getglis() const;
		Vecteur getEtat() const;
		Vecteur getPosition() const;
		Vecteur getVitesse() const;
		Vecteur getForce() const;
		Vecteur getDerivee() const;
		Vecteur getVitesse_Angulaire() const;
		
		// modificateurs
		void setRoul(double const& a);
		void setGlis(double const& a);
		void setEtat(Vecteur const& a);
		void setDerivee(Vecteur const& a);
		void setVitesse(Vecteur const& A);
		void setVitesse_Angulaire(Vecteur const& A);
		void setForce(Vecteur const& F);
		void setAltitude(double const& a);
		void setVerticale_vitesse(double const& v);
		void setVerticale_force(double const& f);
		
		// constructeurs
		Boule(double r, double m, double frt, double rest, double roul, double glis, Support_a_dessin* vue);
		Boule(double r, double m, double frt, double rest, double roul, double glis, Vecteur force, Vecteur etat, Vecteur derivee, Support_a_dessin* vue);
		
		// autres méthodes
		Vecteur poids();
		double masse_volumique() const;
		double calcul_masse(double const& masse_volumique) const;
		void ajoute_force(Vecteur df);
		Vecteur evolution() const;
		void affiche() const;
		void supprime();

		// methodes de l'exercice P7 (chocs)
		Vecteur distance(Boule const& B) const;
		double t_collision(Boule& B2, double const& t, double const& dt, Integrateur* integrateur) const;
		void collision(Boule& B);

		virtual void dessine() override;
		virtual std::ostream& affiche(std::ostream& sortie) const;

};

#endif
