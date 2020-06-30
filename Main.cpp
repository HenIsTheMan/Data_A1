#include <conio.h>
#include <string>
#include <time.h>
#include <windows.h>
#include "CArmour.h"
#include "CEntity.h"
#include "CEquipment.h"
#include "CHero.h"
#include "CMonster.h"
#include "CWeapon.h"

void HideConsoleCursor(){
	HANDLE StdHandle = GetStdHandle(DWORD(-11));
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(StdHandle, &cursorInfo);
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(StdHandle, &cursorInfo);
}

void heroText(CEntity *Ptr[], string start){
	printf("%sHero: %s, %s, %i (H), %i + %i (AttackPt), %i + %i (DefencePt)\n", start.c_str(), static_cast<CHero*>(Ptr[0])->getArmour()->getName().c_str(),
		(static_cast<CHero*>(Ptr[0])->getWeapon() == NULL ? "NIL" : static_cast<CHero*>(Ptr[0])->getWeapon()->getName().c_str()), Ptr[0]->getHealth(), Ptr[0]->getAttackPt(),
		(static_cast<CHero*>(Ptr[0])->getWeapon() == NULL ? 0 : static_cast<CHero*>(Ptr[0])->getWeapon()->getAddPt()), Ptr[0]->getDefencePt(), static_cast<CHero*>(Ptr[0])->getArmour()->getAddPt());
}

void monsterText(CEntity *Ptr[], string start){
	printf("%sMonster: %i (H), %i (AttackPt), %i (DefencePt)\n", start.c_str(), Ptr[1]->getHealth(), Ptr[1]->getAttackPt(), Ptr[1]->getDefencePt());
}

int main(){
	srand(unsigned int(time(NULL)));
	HideConsoleCursor();
	int turn = 1;
	CEntity *Ptr[2]{new CHero, new CMonster};
	while(1){
		printf("***My 1st RPG Game: Turn %d***\n", turn);
		heroText(Ptr, "");
		monsterText(Ptr, "");
		if(rand() % 2){
			bool eq = rand() % 2;
			(eq ? static_cast<CHero*>(Ptr[0])->setNewArmour() : static_cast<CHero*>(Ptr[0])->setNewWeapon());
			cout << "Event: Found new " << (eq ? "Armour A" + to_string(static_cast<CHero*>(Ptr[0])->getArmour()->getEqIndex()): "Weapon W" + to_string(static_cast<CHero*>(Ptr[0])->getWeapon()->getEqIndex())) << endl;
			heroText(Ptr,"");
		} else{
			cout << "Event: Encountered THE Monster\n";
			Ptr[0]->attack(Ptr[1]);
			monsterText(Ptr, "/Hero attacked/ ");
			if(Ptr[1]->getHealth() == 0){
				cout << "\nYou Win!\n";
				break;
			}
			Ptr[1]->attack(Ptr[0]);
			heroText(Ptr, "/Monster attacked/ ");
			if(Ptr[0]->getHealth() == 0){
				cout << "\nYou Lose...\n";
				break;
			}
			Ptr[1]->improve();
			monsterText(Ptr, "/Monster improved/ ");
		}
		++turn;
		cout << "\n***Press any key to start next turn***\n" << (_getch() ? "\n\n" : "");
	}
	delete Ptr[0];
	delete Ptr[1];
	_CrtDumpMemoryLeaks();
	return 0;
}