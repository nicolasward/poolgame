#ifndef DESSINABLE_H
#define DESSINABLE_H

#include <iostream>

class Support_a_dessin;

class Dessinable {
public:
	Dessinable(Support_a_dessin* support)
	: support(support)
	{}
	virtual ~Dessinable() {}
	virtual std::ostream& affiche (std::ostream& sortie) const = 0;

protected:
	Support_a_dessin* support;
};

std::ostream& operator<< (std::ostream&, Dessinable const&);

#endif
