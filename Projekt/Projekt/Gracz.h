#pragma once
#include "Postac.h"
#include "Weapon.h"
class Gracz :
	public Postac
{
protected:
	Weapon* EquipedWeapon;
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
	Item* Equip(Item* toeq);
};

