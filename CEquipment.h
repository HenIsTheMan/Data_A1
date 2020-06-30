#pragma once
#include <iostream>
using namespace std;

class CEquipment{
	public:
		int getAddPt() const;
		string getName() const;
		void setName(string);
		CEquipment(int);
	private:
		int AddPt;
		string name;
};