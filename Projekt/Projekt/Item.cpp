#include "Item.h"



std::string Item::GetName()
{
	return Nazwa;
}

char Item::GetType()
{
	return Type;
}

Item::Item()
{
}


Item::~Item()
{
}

std::ostream & operator<<(std::ostream & os, Item & A)
{
	os << "An Error Happened this should not be here";
		return os;
}
