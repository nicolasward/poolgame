#ifndef TEXTVIEWER_H
#define TEXTVIEWER_H

#include "Dessinable.h"
#include "Support_a_dessin.h"

class TextViewer : public Support_a_dessin {

	public:

		TextViewer(std::ostream& s)
		: sortie(s) {}

		virtual ~TextViewer() {}

		virtual void dessine(const Boule&) override;
		virtual void dessine(const Systeme&) override;
		virtual void dessine(Objet const& a_dessiner);

	private:

		std::ostream& sortie;
};

#endif
