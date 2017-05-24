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
}

TVector<FString> player::getInventory() const{ return inventory; }

void player::addValidItem(FString item)
{
	//std::cout << item << std::endl;
	inventory.push_back(item);
	
	/*
	if (inventory.empty())
		std::cout << " uh oh." << std::endl;
	*/
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


