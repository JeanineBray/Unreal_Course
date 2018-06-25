/*
This is the console executable, that makes use of the FBullCow class.
This acts as the view in the MVC pattern, and is responsible for all
user interaction. For game logice see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;

//Prototypes for our functions
void PrintIntro();
void playGame();
FText GetGuess();
bool askToPlayAgain();

FBullCowGame BCGame;//Instantiate a new game

//Entry point for our application
int main() 
{	
	//Initializing our functions
	do
	{
		PrintIntro();
		playGame();

	} while (askToPlayAgain() == true);

	return 0;
}

void playGame()
{	
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//Loop for the predetermined number of turns for guessing
	//TODO change from FOR to WHILE loop once we have checked validity
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess(); //TODO check validity

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//Submit number of Bulls and Cows

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		std::cout << std::endl;
	}

	//TODO summarize game

	return;
}


//Introduction to the game
void PrintIntro() 
{
	constexpr int32 WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;

	return;
}

//Get a guess from the player
FText GetGuess() 
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << " Please enter a guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);


	return Guess;
}

bool askToPlayAgain()
{
	std::cout << "Would you like to play again? (y/n)" << std::endl;
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	if (Response[0] == ('y', 'Y'))
	{
		return true;
	}
	else
	{
		return false;
	}

	return 0;
}
