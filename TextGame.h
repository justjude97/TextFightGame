//will hold the most basic of game logic, including the GameOver variable
#pragma once

class textGame
{
public:
	textGame();

	bool isGameOver() const;

private:
	bool gameOver;
};
