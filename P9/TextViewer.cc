#include <iostream>
#include "TextViewer.h"
#include "Boule.h"
#include "Systeme.h"
using namespace std;


void TextViewer::dessine(Boule const& D)
{
	D.affiche(sortie);
}

void TextViewer::dessine(Systeme const& D)
{
    D.affiche(sortie);
}

// void TextViewer::dessine(Boule const& B) {
// 	sortie << B << endl;
//}
