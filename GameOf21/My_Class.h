#pragma once // this ensures the current source code is only added once in every compilation

namespace methods // creates a new namespace that we can import
{
	class my_Class // creates a new class to hold our methods and variables
	{
		public: // gives all the methods specified below a public modifier
			void mainMenu(); // creates a new mainMenu method 
			void startGame(); // creates a new startGame method
			void instructions(); // creates a new instructions method
			void playersTurn(); // creates a new playersTurn method
			void aisTurn(); // creates a new aisTurn method
			void computerWon(); // creates a new computerWon method
			void playerWon(); // creates a new playerWon method
			int quitGame(); // creates a new quitGame method

		public: // gives all the variables specified the public modifier
			int playerChoice{ 0 }; // creates a new int called playerChoice and assigns it the value of 0 using direct initialization
			int randNum{ 0 }; // creates a new int called randNum and assigns it the value of 0 using direct initialization
			int menuChoice{ 0 }; // creates a new int called menuChoice and assigns it the value of 0 using direct initialization
			int numberOfSticks{ 0 }; // creates a new int called numberOfSticks and assigns it the value of 0 using direct initialization
			int numOfTurns{ 0 }; // creates a new int called numbOfTurns and assigns it the value 0f 0 using direct initialization
	};
}
