#pragma once
#include "Composant.h"
#include <string>
using namespace std;

class Plat : public Composant {
public:
	Plat();
	Plat(string text);

	string getName() {
		return name;
	}
	float getPrice() {
		return price;
	}
	void Affiche() override;
	void exportHTML(string& text) override;
};