#pragma once
#include "Postac.h"
#include "Weapon.h"
#include "Armor.h"
class Gracz :
	public Postac
{
protected:
	Weapon* EquipedWeapon;
	Armor* EquipedArmor;
	int Regen;
	int CurrentRegen;
public:
	Gracz();
	Gracz(int x, int y);
	~Gracz();
	void Tick(int maxx, int maxy, Pole *** Tabela);
	void Interact();
	virtual char GetType();
	void Display();
	void Move(Pole *** Tabela, Position cel);
	bool TakeDamage(int DMG);
	bool Attack(Postac* P);
	int GetAC();
	bool Alive();
	Item* Equip(Item* toeq);
};

