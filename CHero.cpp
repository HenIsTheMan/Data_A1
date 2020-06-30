#include "CHero.h"
#include <string>

CHero::CHero(): armour(new CArmour("A1")), weapon(NULL), CEntity(8, 3){}

CHero::~CHero(){
	delete armour;
	if(weapon != nullptr){
		delete weapon;
	}
}

CArmour* CHero::getArmour() const{
	return armour;
}

CWeapon* CHero::getWeapon() const{
	return weapon;
}

void CHero::attack(CEntity *mon){
	mon->setHealth(mon->getHealth() + mon->getDefencePt() - getAttackPt() - (getWeapon() == NULL ? 0 : getWeapon()->getAddPt()));
}

void CHero::setNewArmour(){
	delete armour;
	armour = new CArmour("A" + to_string(CArmour::getEqIndex() + 1));
}

void CHero::setNewWeapon(){
	if(weapon != nullptr){
		delete weapon;
	}
	weapon = new CWeapon("W" + to_string(CWeapon::getEqIndex() + 1));
}