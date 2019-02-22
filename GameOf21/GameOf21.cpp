#include "pch.h" // Imports all data from the default pch.h file
#include "My_Class.h" // imports all data held in the My_Class.h file
#include <cstdlib> // Imports the calls for generating random numbers and other functions
#include <stdio.h>
#include <time.h>

using namespace methods; // allows us to import classes specified in the My_Class.h file

my_Class mc; // creates a nnew reference to the class in the methods.h file

int main() // Main Method
{
	srand(time(NULL)); // this seeds the pseudo random number generator by default the seed for rand() is 1, using time(NULL) uses the computers clock to change the random number since the computers clock in s
	mc.mainMenu(); // calls the mainMenu() method from the class My_Class.h file
}