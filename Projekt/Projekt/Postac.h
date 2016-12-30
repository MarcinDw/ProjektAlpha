#pragma once
#include "Pole.h"
class Postac :
	public Pole
{
protected:
	int Attk;
	int Defense;
	int HP;
	int MaxHP;
	int DamageMin;
	int DamageMax;
	int Crit;
	int CritMulti;
public:
	Postac();
	~Postac();
	virtual bool GetMoveBlock();
	virtual bool GetVisionBlock();
	virtual void Interact();
	virtual void Tick();
	virtual bool TakeDamage(int DMG);
	virtual bool Attack(Postac P);
	virtual Pole* Deathrattle(Pole* Pol);
};

