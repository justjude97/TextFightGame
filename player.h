#pragma once

#include <iostream>
#include <string>
#include <vector>

#define TVector std::vector
using FString = std::string;

//enum class for view to interact with note::i don't know if i should include this in the player
//	header as it doesn't have any effect except with the view

enum class InvStat
{
	Invalid,
	OK,
	Not_Found,
	ERROR
};

class player
{

public:
	player();

	//resets inventory once game is over
	void reset();
	//the player should be able to access their inventory
	TVector<FString> getInventory() const;
	
	//add items to their inventory
	void addValidItem(FString); //TODO create item class and replace as argument

	//remove items from their inventory
	InvStat removeItem(FString);

private:
	TVector<FString> inventory; //TODO make richer template value

};
