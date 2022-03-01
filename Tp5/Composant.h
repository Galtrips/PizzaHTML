#pragma once
#include <string>
using namespace std;

class Composant {
protected:
	string name;
	float price = 0.0;
public:
	Composant();
	Composant(string text);
	Composant(string text, float price);

	string getName() {
		return name;
	}
	float getPrice() {
		return price;
	}

	virtual void Affiche();
	virtual void exportHTML(string& text) {  ; }
};