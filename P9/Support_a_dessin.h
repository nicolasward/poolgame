#ifndef SUPPORT_A_DESSIN_H
#define SUPPORT_A_DESSIN_H

class Systeme;
class Boule;

class Support_a_dessin {
public:
	virtual ~Support_a_dessin() {}

	//virtual void dessine(Dessinable const&) =0;
	 virtual void dessine(Boule const&) =0;
	 //virtual void dessine(Objet const& a_dessiner) = 0;
	 virtual void dessine(Systeme const& a_dessiner) = 0;

};

#endif
