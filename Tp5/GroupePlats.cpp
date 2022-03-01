#include "GroupePlats.h"
#include "Composant.h"
#include <iostream>
#include <string>
using namespace std;

GroupePlats::GroupePlats() { ; }
GroupePlats::GroupePlats(string text) : Composant(text) { ; }
GroupePlats::GroupePlats(string text, float prix) : Composant(text, prix) { ; }

void GroupePlats::addComposant(Composant& c1) {
	listeComposant.push_back(&c1);
}

void GroupePlats::setChoice(bool valeur) {
	choix = valeur;
}

void GroupePlats::exportHTML(string& text) {
	string nom = name;
	if (price != NULL) {
		nom += (string)" ";
		nom += to_string(int(price));
		nom += "€";
	}
	string exports = "<h1>" + nom + "</h1>\n";
	text += exports;
	int j = 1;
	for (Composant* i : listeComposant) {
		text += "  ";
		i->exportHTML(text);
		if (choix == true && j != listeComposant.size()) {
			text += "<p>ou</p>";
		}
		j++;
	}
}

void GroupePlats::Affiche() {
	Composant::Affiche();
	int j = 1;
	for (Composant* i : listeComposant) {
		cout << "\t";
		i->Affiche();
		if (choix == true && j != listeComposant.size()) {
			cout << "\t\tou" << endl;
		}
		j++;
	}
}