#pragma once
#include "CEquipment.h"

class CWeapon: public CEquipment{
	public:
		CWeapon(string);
		static int getEqIndex();
	private:
		static int EqIndex;
};