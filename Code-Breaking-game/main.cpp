#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
	// Intro message
	std::cout << "You are a secret agent breaking into a level " << Difficulty << " secure server room...";
	std::cout << "\nEnter the correct code to continue..." << std::endl;
}

bool PlayGame(int Difficulty) {

	PrintIntroduction(Difficulty);
	
	// Initialize variables for solution
	int CodeA = rand() % Difficulty + Difficulty;
	int CodeB = rand() % Difficulty + Difficulty;
	int CodeC = rand() % Difficulty + Difficulty;
	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	std::cout << "There are three numbers in the code";
	std::cout << "\nThe numbers add up to " << CodeSum;
	std::cout << "\nThe numbers multiplied together equal " << CodeProduct;

	// Initialize variables for player's guess
	int GuessA, GuessB, GuessC;

	std::cout << "\nPlease enter the three numbers of the code, with a space between each, hit enter when ready \n";

	std::cin >> GuessA;
	std::cin >> GuessB;
	std::cin >> GuessC;

	std::cout << "\nYou entered : " << GuessA << GuessB << GuessC;

	const int GuessSum = GuessA + GuessB + GuessC;
	const int GuessProduct = GuessA * GuessB * GuessC;

	// Compare the player's guess to the solution
	if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
		std::cout << "\nYou successfully break into the server room \n";
		std::cout << "\n *************************************************** \n";
		std::cout << "\n You ascend to the next level... \n";
		std::cout << "\n *************************************************** \n \n";
		return true;
	}
	else {
		std::cout << "\nYou were incorrect, try again \n \n";
		return false;
	}

}

int main()
{
	srand(time(NULL)); // Create a new random sequence based on time of day
	int LevelDifficulty = 1;
	const int MaxLevel = 5;
	while(LevelDifficulty <= MaxLevel) // Loop the game until all the levels are completed
		{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // Clear any errors
		std::cin.ignore(); // Discard the buffer

		if(bLevelComplete) 
		{
			++LevelDifficulty;
		}

		}
	std::cout << "\n \n \n Congratulations agent, you have successfully completeted the game! :) \n \n \n ";
	return 0;
}