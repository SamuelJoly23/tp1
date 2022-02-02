/*
* @fichier: Dresseur.cpp
* @auteurs:
* @date:
* @description: les dresseurs sont les etres capables d'attraper des creatures
*/

#include "Dresseur.h"

// TODO: constructeur avec liste d'initialisation
Dresseur::Dresseur(): nom_(""), nombreCreatures_(0), nombreCreaturesMax_(MAX_NOMBRE_CREATURES), creatures_(nullptr) {
	// code

	creatures_ = new Creature* [MAX_NOMBRE_CREATURES]; //Creation d'un tableau de pointeurs de taille MAX_NOMBRE_CREATURES dans l'attribut creatures_
	for (int i = 0; i < MAX_NOMBRE_CREATURES; i++) {
		creatures_[i] = nullptr;
	}
}

// TODO: constructeur par parametre avec liste d'initialisation
Dresseur::Dresseur(const std::string& nom) : Dresseur() { 
	// code 
	nom_ = nom;


	/*creatures_ = new Creature * [MAX_NOMBRE_CREATURES]; //Creation d'un tableau de pointeurs de taille MAX_NOMBRE_CREATURES dans l'attribut creatures_
	for (int i = 0; i < MAX_NOMBRE_CREATURES; i++) {
		creatures_[i] = nullptr;
	}*/
}

// TODO: destructeur
Dresseur::~Dresseur() {
	// code
	for (int i = 0; i < nombreCreatures_; i++) {
		delete creatures_[i];
		creatures_[i] = nullptr;
	}

	/*for (auto& Creature : creatures_*) {
		delete Creature;
		creatures_ = nullptr;
	}*/
	
	

}

// TODO: Getters
std::string Dresseur::obtenirNom() const {
	// code
	return nom_;
	return "";
}

unsigned int Dresseur::obtenirNombreCreatures() const {
	// code
	return nombreCreatures_;
	return 0;
}

Creature** Dresseur::obtenirCreatures() const {
	// code
	Creature* c = new Creature();
	Creature** p = &c;
	return p;
}

// TODO: Setters
void Dresseur::modifierNom(const std::string& nom) {
	// code	
	nom_ = nom;
}

void Dresseur::modifierCreature(Creature** creatures) { // A VERIFIER
	// code
	creatures_ = creatures;
}

// TODO: ajouter creature dans creatures_
// *verifier que la creature n'est pas deja presente
// *verifier que nb creature < nombreCreaturesMax_
//	->	sinon doubler la taille de creatures_
bool Dresseur::ajouterCreature(const Creature& creature) {
	// code
	bool creature_ajoutee = true;
	for (int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == creature.obtenirNom()) {
			creature_ajoutee = false;
		}
	}
	if (creature_ajoutee == true) {
		if (nombreCreatures_ >= nombreCreaturesMax_) {
			Creature** tabteamporaire = new Creature * [nombreCreaturesMax_ * 2];
			for (int j = 0; j < nombreCreatures_;j++) {
				tabteamporaire[j] = creatures_[j];
				delete[] creatures_;
				creatures_ = tabteamporaire;
				nombreCreaturesMax_ = nombreCreaturesMax_ * 2;
			}
			creatures_[nombreCreatures_] == &creature; //pourquoi & ??? 
			nombreCreatures_++;
		}
		return creature_ajoutee;
	}
}








// TODO: retire creature dans creatures_
bool Dresseur::retirerCreature(const std::string& nom) {
	// code
	bool creature_retiree = false;
	for (int i = 0; i < nombreCreatures_; i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			creatures_[i] == nullptr;
			creature_retiree = true;
		}
	}
	return creature_retiree;
}


// TODO: fonction d'affichage
void Dresseur::affichage() const {
	// afficher le nom et le nombre de creature
	// ex: Leon possede 1 creature(s)
	// boucler sur chaque creature et afficher ses informations
	for (int i = 0; i < nombreCreatures_; i++) {
		cout << nom_ << " possede " << nombreCreatures_ << " creature(s)" << endl;
		creatures_[i]->information();
	}
	
}
