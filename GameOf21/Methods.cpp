#include "pch.h" // Imports all data from the default pch.h file
#include "My_Class.h" // imports all data held in the My_Class.h file
#include <iostream> // Imports the default console calls for input and output

using namespace std; // uses the default namespace from <iosteam> so we don't need the std:: before "cout" or "cin"
using namespace methods; // uses our namespace defined in the My_Class.h header file

void my_Class::mainMenu() // initializes out mainMenu() method from the My_Class.h header file
{
	cout << "Game of 21" << endl; // prints to the console the title of the game
	cout << "\nMain Menu" << endl; // prints to the console that the user is in the main menu
	 
	cout << "\n1) Start Game \n2) Instructions \n3) Quit" << endl; // prints to the console the 3 operations the user can choose from
	
	cin >> menuChoice; // gives the user the oppurtunity to enter a choice of 1 - 3 and assigns menuChoice to that number 

	switch (menuChoice) // this switch statement handles the 3 choices 
	{
		case 1: // if the user chose option 1
		{
			startGame(); // calls the startGame() method
		}
			break;
		case 2: // if the user chose option 2
		{
			instructions(); // calls the instructions() method
		}
			break; 
		case 3: // if the user chose option 3
		{
			quitGame(); // calls the quitGame() method
		}
			break;
		default: // if the user hasn't entered a valid option
		{
			cout << "Please choose a valid option" << endl; // prints to the console asking the user to choose a valid option listed
			cin >> menuChoice; // get the users input again and assign it to menuChoice
		}
			break;
	}
}

void my_Class::startGame() // initializes the startGame() method from the My_Class.h header file
{
	numberOfSticks = 21; // initializes the numberOfSticks as 21
	playersTurn(); // calls the playersTurn() method
}

void my_Class::playersTurn() // initializes the playersTurn() method from the My_Class.h header file
{
	numOfTurns++; // increases the numOfTurns by 1 everytime this method is called

	cout << "Please choose a number of sticks to remove between 1-3" << endl; // prints to the console asking the player to choose a number of sticks to remove between 1 and 3

	cin >> playerChoice; // gets the users choice and assigns it to the int playerChoice

	while (playerChoice < 0 || playerChoice > 3) // this loop runs if the player has chosen an number lower than 0 or greater than 3
	{
		cout << "Invalid number, please choose again" << endl; // prints to the console telling the player that the amount of sticks they chose to remove is invalid
		cin >> playerChoice; // gets the users choice and assigns it to the int playerChoice
	}

	numberOfSticks -= playerChoice; // removes how many sticks the player chose from the current amount of sticks left

	aisTurn(); // calls the aisTurn() method
	cout << "Sticks left: " << numberOfSticks << endl; // prints to the console how many sticks are left

	if (numberOfSticks == 0) // if the numberOfSticks is equal to 0 once the player has made their choice
	{
		playerWon(); // calls the playerWon() method
	}
}

void my_Class::aisTurn() // calls the aisTurn() method from the My_Class.h header file
{
	if (numberOfSticks > 3) // if the numberOfSticks left are greater than 3
	{
		randNum = rand() % 3 + 1; // generates a new random number from 1 - 3 using the rand() method and assigns randNum to that randomly generated number

		cout << "\nThe Computer Has Taken: " << randNum << "\n" << endl; // prints to the console how many sticks the AI has taken based on the random number
		numberOfSticks -= randNum; // takes away the randNum from the numberOfSticks left
		cout << "Sticks left: " << numberOfSticks << "\n" << endl; // prints to the console how many sticks are left after the AI's turn
		playersTurn(); // calls the playersTurn() method
	}
	else if (numberOfSticks <= 3) // if the numberOfSticks left is less than or equal to 3
	{
		randNum = numberOfSticks; // sets the randNum int to the numberOfSticks left
		numberOfSticks -= randNum; // takes how many sticks are left from the numberOfSticks left

		cout << "\nThe Computer Has Taken: " << randNum <<  "\n" << endl; // prints to the console how many sticks the computer has taken f

		computerWon(); // calls the computerWon() method
	}
}
 
void my_Class::playerWon() // initializes the playerWon() method from the My_Class.h header file
{
	cout << "\nYou won the game" << "\nYou took: " << numOfTurns << " turns" << endl; // prins to the console that the player has won the game and tells them how many turns they took
	mainMenu(); // calls the mainMenu() method
}
 
void my_Class::computerWon() // initializes the computerWon() method from the My_Class.h header file
{
	cout << "Computer has won the game" << endl; // prints to the console that the computer AI has won the game
	mainMenu(); // calls the mainMenu() method
}

void my_Class::instructions() // initializes the instructions() methods from the My_Class.h header file
{
	cout << "\nYour goal is to be the one who takes the last remaining sticks \n" << endl; // prints to the console that the users goal is to be the last to remove the remaining 3 or less sticks
	mainMenu(); // calls the mainMenu() method
}

int my_Class::quitGame() // initializes the quitGame() method from the My_Class.h header file
{
	cout << "Exiting Game...." << endl; // prints to the console telling the player they are exiting the game
	exit(0); // calls the exit function passing in code 0
}