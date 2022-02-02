/*
* @fichier: Pouvoir.cpp
* @auteurs:
* @date:
* @description: La classe Pouvoir correspond aux differents attaques
*/

#include "Pouvoir.h"

// TODO: constructeur avec liste d'initialisation 
Pouvoir::Pouvoir(): nom_(""), nombreDeDegat_(0), manaNecessaire_(0) {
	// code
}

// TODO: constructeur par parametre avec liste d'initialisation
Pouvoir::Pouvoir(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int manaNecessaire) : Pouvoir()  {
	// code 
}

// TODO: destructeur
Pouvoir::~Pouvoir() {
	// code
	nom_.clear();
	//???

}

// TODO: Getters
unsigned int Pouvoir::obtenirManaNecessaire() const {
	// code
	return manaNecessaire_;
}

std::string Pouvoir::obtenirNom() const {
	// code
	return nom_;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const {
	// code
	return nombreDeDegat_;
}

// TODO: Setters
void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat) {
	// code
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::modifierManaNecessarie(unsigned int manaNecessaire) {
	// code
	manaNecessaire_ = manaNecessaire;
}

void Pouvoir::modifierNom(const std::string& nom) {
	// code
	nom_ = nom;
}

// TODO: Affichage du pouvoir
// ex: Blaze necessite 5 mana et inflige 10 degats
void Pouvoir::description() const {
	// code
	cout << nom_ << " necessite " << manaNecessaire_ << " mana et inflige " << nombreDeDegat_ << " degats" << endl;

}
