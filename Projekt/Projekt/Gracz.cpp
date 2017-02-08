#include "Gracz.h"



Gracz::Gracz()
{
}

Gracz::Gracz(int x, int y) :Postac(x, y)
{
	Attk = 0;
	Defense = 50;
	DamageMin = 1;
	DamageMax = 2;
	Crit = 5;
	CritMulti = 2;
	MaxHP = 20;
	HP = 20;
	Regen = 3;
	CurrentRegen = 3;
}

Gracz::~Gracz()
{
}

void Gracz::Tick(int maxx, int maxy, Pole *** Tabela)
{
	if (CurrentRegen == 0)
	{
		if (HP < MaxHP)
		{
			HP++;
		}
		CurrentRegen = Regen;
	}
	else
	{
		CurrentRegen--;
	}
}

void Gracz::Interact()
{
	std::cout << std::endl << "Gracz trafiony" << std::endl;
}

char Gracz::GetType()
{
	return '@';
}

void Gracz::Display()
{
	std::cout << '@';
}

void Gracz::Move(Pole*** Tabela, Position cel)
{
		Pole * temp = Below;
		Below = Tabela[cel.x][cel.y];
		Tabela[cel.x][cel.y] = Tabela[Pos.x][Pos.y];
		Tabela[Pos.x][Pos.y] = temp;
		Pos = cel;
}

bool Gracz::TakeDamage(int DMG)
{
	HP -= DMG;
	std::cout << std::endl << "New HP " << HP << "Damage Taken " << DMG << std::endl;
	if (HP < 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool Gracz::Attack(Postac * P)
{
	int Roll = rand() % 100;
	if (EquipedWeapon == NULL)
	{
		if ((Attk + Roll) > P->GetAC())
		{
			int Damage = rand() % (DamageMax - DamageMin) + DamageMin;
			if (Roll > 100 - Crit)
			{
				P->TakeDamage(Damage*CritMulti);
			}
			else
			{
				P->TakeDamage(Damage);
			}
			return true;
		}
		return false;
	}
	else
	{
		if ((Attk + Roll+ EquipedWeapon->Attack) > P->GetAC())
		{
			int Damage = rand() % (EquipedWeapon->MaxDamage - EquipedWeapon->MinDamage) + EquipedWeapon->MinDamage;
			if (Roll > 100 - EquipedWeapon->Crit)
			{
				P->TakeDamage(Damage*EquipedWeapon->CritMulti);
			}
			else
			{
				P->TakeDamage(Damage);
			}
			return true;
		}
		return false;
	}
}

int Gracz::GetAC()
{
	if (EquipedArmor != NULL)
	{
		return Defense+(EquipedArmor->GetDef()*5);
	}
	else
	{
		return Defense;
	}
}

bool Gracz::Alive()
{
	if (HP > 0)
	{
		return true;
	}
	return false;
}

Item * Gracz::Equip(Item* toeq)
{
	Item* Temp=NULL;
	if ((toeq->GetType() == 'O') || (toeq->GetType() == 'T'))
	{
		Temp = EquipedWeapon;
		EquipedWeapon = dynamic_cast<Weapon*>(toeq);
	}
	else
	{
		Temp = EquipedArmor;
		EquipedArmor = dynamic_cast<Armor*>(toeq);
	}
	return Temp;
}
