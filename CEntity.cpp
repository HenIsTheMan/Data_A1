#include "CEntity.h"
#include <algorithm>

CEntity::CEntity(int AP, int DP): Health(100), AttackPt(AP), DefencePt(DP){}
CEntity::~CEntity(){}

int CEntity::getHealth() const{
	return Health;
}

int CEntity::getAttackPt() const{
	return AttackPt;
}

int CEntity::getDefencePt() const{
	return DefencePt;
}

void CEntity::setHealth(int newHealth){
	Health = (newHealth > Health ? Health : (newHealth < 0 ? 0 : newHealth));
}

void CEntity::improve(){
	AttackPt += 2;
	DefencePt += 3;
}