#ifndef OBJET_H
#define OBJET_H

#include "Dessinable.h"
#include "Support_a_dessin.h"

class Objet : public Dessinable {
public:
	Objet(Support_a_dessin* vue)
	: Dessinable(vue), angle(0.0)
	{}
	virtual ~Objet() {}
	virtual void dessine() override
	{support->dessine(*this);}
	
	void evolue(double dt) {
		constexpr double omega(100.0);
		angle += omega*dt;
	}
	//accesseur
	double infos() const {return angle;}
private:
	double angle;
};

#endif
