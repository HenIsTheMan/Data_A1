#pragma once
#include "CArmour.h"
#include "CWeapon.h"

class CEntity{
	public:
		CEntity(int, int);
		virtual ~CEntity();
		int getHealth() const, getAttackPt() const, getDefencePt() const;
		virtual void attack(CEntity*) = 0;
		void setHealth(int), improve();
	private:
		int Health, AttackPt, DefencePt;
};