#pragma once
#include "CEntity.h"

class CHero: public CEntity{
	public:
		CHero();
		~CHero();
		CArmour *getArmour() const;
		CWeapon *getWeapon() const;
		void attack(CEntity*), setNewArmour(), setNewWeapon();
	private:
		CArmour *armour;
		CWeapon *weapon;
};