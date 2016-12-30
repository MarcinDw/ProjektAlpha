#include "Postac.h"



Postac::Postac()
{
}

Postac::~Postac()
{
}

bool Postac::GetMoveBlock()
{
	return false;
}

bool Postac::GetVisionBlock()
{
	return false;
}

void Postac::Interact()
{
}

void Postac::Tick()
{
}

bool Postac::TakeDamage(int DMG)
{
	HP -= DMG;
	if (HP < 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool Postac::Attack(Postac P)
{
	int Roll = rand() % 100;
	if ((Attk + Roll) > P.Defense)
	{
		int Damage = rand() % (DamageMax - DamageMin) + DamageMin;
		if (Roll > Crit)
		{
			P.TakeDamage(Damage*CritMulti);
		}
		else
		{
			P.TakeDamage(Damage);
		}
		return true;
	}
	return false;
}

Pole * Postac::Deathrattle(Pole * Pol)
{
	return nullptr;
}