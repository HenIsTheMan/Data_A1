#include "CArmour.h"
#include <string>

int CArmour::EqIndex = 0;

CArmour::CArmour(string name): CEquipment(++EqIndex){
	EqIndex = stoi(name.substr(1));
	setName(name);
}

int CArmour::getEqIndex(){
	return EqIndex;
}