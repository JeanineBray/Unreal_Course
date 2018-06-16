#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//All values initialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
	public:
		FBullCowGame(); //Constructor

		int32 GetMaxTries() const;
		int32 GetCurrentTry() const;
		bool IsGameWon() const;
		
		bool CheckGuessValidity(FString); //TODO make a more rich return value
		void Reset(); //TODO make a more rich return value
		
		//count bulls and cows, and increases try # assuming valid guess
		FBullCowCount SubmitGuess(FString);

//Please try and ignore this and focus on the interface above
	private:
		//See constructor for initialisation
		int32 MyCurrentTry;
		int32 MyMaxTries;
		FString MyHiddenWord;
};