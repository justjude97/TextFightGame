/*
	name: TextFightGame //TODO come up with better name
	
	this is the view/controller for TextFight game. it will handle user inputs to update the model

*/
#include <iostream>
#include <string>
#include "player.h"

//enumeration class for specifying actions in parser
enum class action: bool
{
	AddItem,
	RemoveItem,
	Move,
	HelpRequest,
	Error
};

//ue4 object names
using int32 = int;
using FText = std::string;

void introduction();
void playGame();
void playerAction(FString input);

FText getPlayerCommand();
void printInventory();

//player object to complete the game
player myPlayer;

int main()
{
	//introduce the player to the game
	//loop while player wants to play the game
	while (true) //TODO add loop exit functionality, make do-while
	{
		//TODO ask for players name
		introduction();
		playGame();
	}
	
	//ask if play wants to start again
}

void introduction()
{
	const FText gameName = "TextFightGame";

	std::cout << "Welcome to the wonderful world of " << gameName << "!\n";
	std::cout << " The objective of this game is to explore the map and collect loot.\n";

}

void playGame()
{
	//secondary event loop

	FText input = "";
	for(int x = 0; x < 5; x++)
	{
		//describe surroundings to player
		//take player input
		input = getPlayerCommand();
		
		//describe action effect
		//TODO proccess player input
		playerAction(input);
	}
}

void playerAction(FString input)
{
	//parse input, return action enum
	//do action based on parse
}

FText getPlayerCommand() //TODO validate player command
{
	FText input;
	std::cout << "what will you do?" << std::endl;
	getline(std::cin, input);

	return input;
}

void printInventory()
{
	//TVector<FString> inv = myPlayer.getInventory();

	std::cout << "your inventory.\n";

	for (auto item : myPlayer.getInventory())
	{
		std::cout << item << std::endl;
	}
}
