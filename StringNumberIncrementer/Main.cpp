#include <fstream>
#include <iostream>
#include <string>

int main()
{
	//--------Variable Declarations--------
	std::ifstream ReadFile;
	std::string userInput;
	std::string fullString;
	std::string subString;
	std::string fileLocation;
	bool exitFlag = true;

	//Main program loop
	while (exitFlag)
	{
		std::cout << "NOTE: At any of the following prompts enter only 'q' to quit program." << std::endl << std::endl;

		//Request file location from user
		std::cout << "Please enter the location of file." << std::endl;
		std::cin >> fileLocation;
		if (fileLocation == "q") break;

		//Request the full string in the file to be located and used for incrementing numbers
		std::cout << "Please enter the string that in which the number contained inside will be incremented" << std::endl;
		std::cin >> fullString;
		if (fullString == "q") break;

		//Request the substring of fullString that is the number to be incremented
		std::cout << "Enter the part of the string that contains the numbers to be incremented" << std::endl;
		std::cin >> subString;
		if (subString == "q") break;

		if ()
	}

	return 0;