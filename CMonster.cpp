#include "CMonster.h"
#include "CHero.h"

CMonster::CMonster(): CEntity(20, 5){}

void CMonster::attack(CEntity *hero){
	hero->setHealth(hero->getHealth() + hero->getDefencePt() + static_cast<CHero*>(hero)->getArmour()->getAddPt() - getAttackPt());
}