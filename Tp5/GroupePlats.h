#pragma once
#include "Composant.h"
#include <string>
#include <vector>
using namespace std;

class GroupePlats : public Composant {
private:
	vector <Composant*> listeComposant;
	bool choix = false;
public:
	GroupePlats();
	GroupePlats(string text);
	GroupePlats(string text, float prix);
	void addComposant(Composant& test);
	void setChoice(bool valeur);
	void Affiche() override;
	void exportHTML(string& text) override;
};