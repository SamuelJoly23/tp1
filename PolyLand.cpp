/*
* @fichier: PolyLand.h
* @auteurs:
* @date:
* @description: Polyland est la map de jeu que l'on va explorer, elle contient les differents elements de jeu
*/

#include "PolyLand.h"

// TODO: constructeur
PolyLand::PolyLand(): dresseurs_(nullptr), nombreDresseurs_(0), creatures_(nullptr), nombreCreatures_(0) {
	// code
	dresseurs_ = new Dresseur * [MAX_DRESSEURS]; 
	for (int i = 0; i < MAX_DRESSEURS; i++) {
		dresseurs_[i] = nullptr;
	}

	creatures_ = new Creature * [MAX_NOMBRE_CREATURES]; // tableau deja fait dans Dresseur.cpp?
	for (int i = 0; i < MAX_NOMBRE_CREATURES; i++) {
		creatures_[i] = nullptr;
	}

}

// TODO: destructeur
PolyLand::~PolyLand() {
	// code
}

// TODO: ajouter dresseur dans dresseurs_
// *verifier que nb dresseur < MAX_DRESSEURS
// *verifier que le dresseur n'est pas deja dans dresseurs_
// *si ajoute,  return true sion false
//	ex: Leon a bien �t� ajout� !
bool PolyLand::ajouterDresseur(Dresseur* dresseur) {
	// code
	bool dresseurAjoute = true;

	if (nombreDresseurs_ >= MAX_DRESSEURS) {
		dresseurAjoute = false;
	}
	for (int i = 0;i < nombreDresseurs_;i++) {
		if (dresseurs_[i]->obtenirNom() == dresseur->obtenirNom()) {
			dresseurAjoute = false;
		}
	}
	if (dresseurAjoute == true) {
		dresseurs_[nombreDresseurs_] == dresseur; // * a ajouter??
		nombreDresseurs_++;
	}
	return dresseurAjoute;
}

// TODO: ajouter creature dans creatures_
// *verifier que nb creature < MAX_CREATURES
// *si ajoute, return true sinon false
//	ex: Pikachu a bien �t� ajout� !
bool PolyLand::ajouterCreature(const Creature& creature) {
	// code
	bool creatureAjoutee = true;
	if (nombreCreatures_ >= MAX_CREATURES) {
		creatureAjoutee = false;
	}
	for (int i = 0;i < nombreCreatures_;i++) {
		if (creatures_[i]->obtenirNom() == creature.obtenirNom()) {
			creatureAjoutee = false;
		}
	}
	if (creatureAjoutee == true) {
		creatures_[nombreCreatures_] == &creature; // * a ajouter??
		nombreDresseurs_++;
	}

	return creatureAjoutee;
}

// TODO: retire dresseur dans dresseurs_
bool PolyLand::retirerDresseur(const std::string& nom) {
	// code
	bool dresseurRetire = false;
	for (int i = 0;i < nombreDresseurs_;i++) {
		if (dresseurs_[i]->obtenirNom() == nom) {
			dresseurs_[i] == nullptr;
			dresseurRetire = true;
		}
	}
	return dresseurRetire;
}

// TODO: retire creature dans creatures_
bool PolyLand::retirerCreature(const std::string& nom) {
	// code
	bool CreatureRetiree = false;
	for (int i = 0;i < nombreCreatures_;i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			creatures_[i] == nullptr;
			CreatureRetiree = true;
		}
	}
	return CreatureRetiree;
}

// TODO: generer un indice aleatoire et
// retourner le dresseur a cet indice
// *verifier le nb de dresseur
Dresseur* PolyLand::choisirDresseurAleatoire() {
	// code
	return nullptr;
}

// TODO: generer un indice aleatoire et
// retourner la creature a cet indice
// *verifier le nb de creature
Creature* PolyLand::choisirCreatureAleatoire() {
	// code
	return nullptr;
}

// TODO: rechercher un dresseur par nom
Dresseur* PolyLand::choisirDresseur(const string& nom) {
	// code
	for (int i = 0;i < nombreDresseurs_;i++) {
		if (dresseurs_[i]->obtenirNom() == nom) {
			return dresseurs_[i];
		}
	}
}

// TODO: rechercher une creature par nom
Creature* PolyLand::choisirCreature(const string& nom) {
	// code
	for (int i = 0;i < nombreCreatures_;i++) {
		if (creatures_[i]->obtenirNom() == nom) {
			return creatures_[i];
		}
	}
}

// TODO: ajouter une creature a un dresseur
bool PolyLand::attraperCreature(Dresseur* dresseur, const Creature& creature) {

	bool creatureAttraper = true; //la fonction ajouterCreature est de type bool. trouver comment utiliser bool
	for (int i = 0;i < nombreCreatures_;i++) { //nombreCreatures_ peut etre pas la bonne valeur a utiliser
		if (dresseur->obtenirCreatures()[i] == &creature) {
			creatureAttraper = false;
		}
	}
	if (creatureAttraper == true) {
		dresseur->ajouterCreature(creature);
	}
	return creatureAttraper;
}

// TODO: retirer une creature a un dresseur
bool PolyLand::relacherCreature(Dresseur* dresseur, const Creature& creature) {
	bool creature_Relachee = false;

	for (int i = 0;i < nombreCreatures_;i++) {
		if (dresseur->obtenirCreatures()[i] == &creature) {
			creature_Relachee = true;
			dresseur->retirerCreature(creature.obtenirNom());
		}
	}
	return creature_Relachee;
}

// TODO: completer le code d'affichage
void PolyLand::infoDresseur(const std::string& nom) const {
	// effectuer une recherche par nom du dresseur passe en parametre
	Dresseur* dresseur = nullptr;
	// code


	if (dresseur != nullptr) {
		cout << "\u001b[32;1mInformations sur le dresseur: \033[0m" << std::endl;
		// afficher le dresseur
		// code
	}
	else {
		// afficher que le dresseur est introuvable
		// code
	}
}
