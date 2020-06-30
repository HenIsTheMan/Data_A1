#pragma once
#include "CEntity.h"

class CMonster: public CEntity{
	public:
		CMonster();
		void attack(CEntity*);
};