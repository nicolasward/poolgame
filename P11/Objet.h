#ifndef OBJET_H
#define OBJET_H

#include "Integrateur.h"
#include "Dessinable.h"
#include "Support_a_dessin.h"

class Objet : public Dessinable {
	
public:
	Objet(Support_a_dessin* vue)
	: Dessinable(vue)
	{}
	virtual ~Objet() {}
	virtual void dessine() = 0;

	virtual Vecteur distance(Boule const& B) const = 0;
	virtual double t_collision(Boule& B, double const& t, double const& dt, Integrateur* integrateur) const = 0;
	virtual void collision(Boule& B) = 0;
	
};

#endif
