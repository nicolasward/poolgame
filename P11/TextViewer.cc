#include <iostream>
#include "TextViewer.h"
#include "Boule.h"
#include "Systeme.h"
using namespace std;


void TextViewer::dessine(Boule const& B)
{
	B.affiche(sortie);
}

void TextViewer::dessine(Systeme const& S)
{
    S.affiche(sortie);
}

void TextViewer::dessine(Objet const& O)
{
	O.affiche(sortie);
}

// void TextViewer::dessine(Boule const& B) {
// 	sortie << B << endl;
//}
