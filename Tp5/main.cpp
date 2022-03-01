#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include "Plat.h"
#include "GroupePlats.h"
using namespace std;

void TemplateHTML(string& text) {
	ifstream entrer("PizzTemplate.html", ios::in);
	if(!entrer) {
		cout << "Probleme d'ouverture !" << endl;
	}
	else {
		char Ligne[500];
		while (!entrer.eof()) {
			entrer.getline(Ligne, 500);
			text += Ligne;
			text += "\n";
		}
	}
	entrer.close();
}

void remplaceBalise(string Balise, string& templateWebsite, string code) {
	size_t found = templateWebsite.find(Balise);
	if (found != string::npos) {
		templateWebsite.replace(templateWebsite.find(Balise), Balise.length(), code);
	}
}

int nombreDieses(string text) {
	int i = 0;
	while (text[i] != '#') {
		i++;
	}
	return i;
}

void genereSiteWeb(const string& codeFinal) {
	ofstream sortie("SiteFinal.html", ios::trunc);
	if (!sortie) {
		cout << "Probleme d'ouverture";
	}
	else {
		sortie << codeFinal;
	}
	sortie.close();
}

int main(void) {

	GroupePlats menu("Mon Menu Gourmand ", 25);
	GroupePlats entrer("Entrees");
	GroupePlats plats("Plats");
	GroupePlats desserts("Desserts");
	Plat p1("LE LIEU JAUNE EN GRAVLAX, MELON, CONCOMBRE ET CORIANDRE.");
	Plat p2("LE TARTARE DE BOEUF, RADIS, OSEILLE ET CREME FUMEE");
	Plat p3("LES ENCORNETS, COURGE, YUZU VERT ET BEURRE A L'ENCRE");
	Plat p4("LE SUPREME DE PINTADE, CELERI, CEPES ET SAUCE VIN JAUNE");
	Plat p5("COMME UN MONT BLANC, GANACHE VANILLE, MARRON ET MERINGUE");
	Plat p6("LA FIGUE, EN SORBET, PATE A CHOUX ET SESAME NOIR.");

	menu.addComposant(entrer);
	menu.addComposant(plats);
	menu.addComposant(desserts);
	entrer.addComposant(p1);
	entrer.addComposant(p2);
	entrer.setChoice(true);
	plats.addComposant(p3);
	plats.addComposant(p4);
	plats.setChoice(true);
	desserts.addComposant(p5);
	desserts.addComposant(p6);
	desserts.setChoice(true);


	string code;
	menu.exportHTML(code);

	string templateCode;
	TemplateHTML(templateCode);
	remplaceBalise("$$Menu$$", templateCode, code);
	genereSiteWeb(templateCode);

	return EXIT_SUCCESS;
}