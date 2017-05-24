#pragma once
#include "player.h"

player::player()
{
	reset();
}

void player::reset()
{
	if (!inventory.empty())
	{
		inventory.clear();
	}
	else
	{
		inventory = TVector<FString>(0);
	}
}

TVector<FString> player::getInventory() const
{
	return inventory;
}

void player::addValidItem(FString item)
{
	inventory.push_back(item);
	return;
}

InvStat player::removeItem(FString item)
{
	//goes through inventory
	for (auto myItem = inventory.begin(); myItem != inventory.end(); myItem++)
	{
		//if the item was found removes it from inventory
		if (*myItem == item)
		{
			inventory.erase(myItem);
			
			//returns good if found
			return InvStat::OK;
		}
	}

	return InvStat::Not_Found;
}
