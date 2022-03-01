#include "Composant.h"
#include <iostream>
#include <string>
using namespace std;

Composant::Composant(){ ; }
Composant::Composant(string text) {
	name = text;
	price = NULL;
}
Composant::Composant(string text, float prix) {
	name = text;
	price = prix;
}

void Composant::Affiche() {
	cout << name ;
	if (price != NULL) {
		cout << " " << price;
	}
	cout << endl;
}