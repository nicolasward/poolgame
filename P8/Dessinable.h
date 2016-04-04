#ifndef DESSINABLE_H
#define DESSINABLE_H

class Support_a_dessin;

class Dessinable {
public:
	Dessinable(Support_a_dessin* support)
	: support(support)
	{}
	virtual ~Dessinable() {}
	virtual void dessine() = 0;
protected:
	Support_a_dessin* support;
};

#endif
