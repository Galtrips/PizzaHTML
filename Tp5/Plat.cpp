#include "Plat.h"
#include "Composant.h"
#include <iostream>
#include <string>
using namespace std;

Plat::Plat() { ; }
Plat::Plat(const string text) : Composant(text) { ; }
void Plat::Affiche() {
	cout << "\t" << name << endl;
}

void Plat::exportHTML(string& text) {
	
	string nom = name;
	string exports = "<p>" + nom + "</p>\n";
	text += exports;
}