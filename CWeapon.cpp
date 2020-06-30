#include "CWeapon.h"
#include <string>

int CWeapon::EqIndex = 0;

CWeapon::CWeapon(string name): CEquipment(++EqIndex){
	EqIndex = stoi(name.substr(1));
	setName(name);
}

int CWeapon::getEqIndex(){
	return EqIndex;
}