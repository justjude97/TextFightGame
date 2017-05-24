/*
	name: TextFightGame //TODO come up with better name
	
	this is the view/controller for TextFight game. it will handle user inputs to update the model

*/
#include <iostream>
#include <string>
#include <sstream>

#include "player.h"
#include "control.h"

//enumeration class for specifying actions in parser
enum class action: bool
{
	Invalid,
	AddItem,
	RemoveItem,
	Move,
	HelpRequest,
	BadRequest,
	Error
};

//ue4 object names
using int32 = int;
using FText = std::string;

void introduction();
void playGame();
//this function parses player input then performs an action based on that input
void playerAction(action intent, FString input);
//parses player input and returns an action enumeration
action interpretAction(FString input);

FText getPlayerCommand();
void printInventory();

//player object to complete the game
player myPlayer;

int main()
{
	//introduce the player to the game
	//outermost loop, when gameOver will ask the player to play again
	do //TODO add loop exit functionality, make do-while
	{
		//TODO ask for players name
		introduction();
		playGame();

	} while (true);
	
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
	do
	{

		action myAction = action::Invalid;
		do
		{

			//describe surroundings to player
			//take player input
			input = getPlayerCommand();

			//buffer used as temporary storage to hold the command and target
			FString buffer;
			//parse input, return action enum
			std::stringstream ss;
			ss << input;
			ss >> buffer;

			myAction = interpretAction(buffer);

			if (myAction != action::BadRequest)
			{
				ss >> buffer;
				//TODO validate target
				//std::cout << buffer << std::endl;
				playerAction(myAction, buffer);
			}
			else
			{
				std::cout << "im sorry, i didn't understand you.\nenter \"help\" for details.\n";
			}

		} while (myAction == action::BadRequest); //loops through until a valid action is inputted

		//describe action effect
		printInventory();
		

	} while (true);

}

void playerAction(action intent, FString input)
{
	//TODO add error message if input targer was not valid
	switch (intent)
	{
	case action::Move:
		//TODO implement move command
		break;
	case action::HelpRequest:
		//TODO implement help text function
		break;
	case action::AddItem:
		//TODO provide interaction with map objects and player object
		myPlayer.addValidItem(input);
		break;
		//remember to add break statement -.-
	case action::RemoveItem:
		myPlayer.removeItem(input);
		
		break;
		

	}
	
}

//takes an input and returns an action enum based on what is contained in enum
action interpretAction(FString input)
{
	if (input == "move")
	{
		return action::Move;
	}
	else if (input == "pickup")
	{
		return action::AddItem;
	}
	else if (input == "drop")
	{
		return action::RemoveItem;
	}
	else if (input == "help")
	{
		return action::HelpRequest;
	}
	else
	{
		return action::BadRequest;
	}

	return action::Error; //incase things get really fucked up

	
}

FText getPlayerCommand() //TODO validate player command
{
	FText input;
	std::cout << "what will you do?" << std::endl;
	getline(std::cin, input);

	return input;
}

//TODO fox
void printInventory()
{
	TVector<FString> inv = myPlayer.getInventory();
	
	if (!inv.empty())
	{
		std::cout << "your inventory.\n";
		for (auto item : inv)
		{
			std::cout << item << std::endl;
		}
	}
	else
	{
		std::cout << "your inventory is empty!\n";
	}
	
}
