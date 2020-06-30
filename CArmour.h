#pragma once
#include "CEquipment.h"

class CArmour: public CEquipment{
	public:
		CArmour(string);
		static int getEqIndex();
	private:
		static int EqIndex;
};