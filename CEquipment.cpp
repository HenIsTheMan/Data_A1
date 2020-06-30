#include "CEquipment.h"

CEquipment::CEquipment(int eqIndex){
	AddPt = eqIndex * 5;
}

int CEquipment::getAddPt() const{
	return AddPt;
}

string CEquipment::getName() const{
	return name;
}

void CEquipment::setName(string name){
	this->name = name;
}