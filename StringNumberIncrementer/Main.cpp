#include <fstream>
#include <iostream>
#include <string>

//Function Protoypes
std::string poTopoSubstring(std::string String, std::size_t first, std::size_t last);

int main()
{
	//--------Variable Declarations--------
	std::ifstream ReadFile;
	std::string userInput;
	std::string fullString;
	std::string subString;
	std::string tempString;
	std::string fileLocation;
	std::size_t position[4];
	std::size_t decimalPosition;
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
		std::cout << "Please enter the string in which the number contained inside will be incremented" << std::endl;
		std::cin >> fullString;
		if (fullString == "q") break;

		//Request the substring of fullString that is the number to be incremented
		std::cout << "Enter the part of the string that contains the number to be incremented" << std::endl;
		std::cin >> subString;
		if (subString == "q") break;

		//Checking for file validity
		ReadFile.open(fileLocation);
		if (!ReadFile.good())
		{
			//Request file location from user
			std::cout << "Please enter the location of file." << std::endl;
			std::cin >> fileLocation;
			if (fileLocation == "q") break;

			//Checking for file validity one last time
			ReadFile.open(fileLocation);
			if (!ReadFile.good())
			{
				std::cout << "Invalid File Location. Check file name or path again." << std::endl << "Press any key to exit" << std::endl;
				std::cin;
				break;
			}
		}

		//File processing Loop
		while (!ReadFile.eof())
		{
			std::getline(ReadFile, tempString);

			//Find the full string inputed but user
			if (tempString.find(fullString) != std::string::npos)
			{
				position[0] = tempString.find(fullString);
				position[1] = position[0] + fullString.size();

				tempString = poTopoSubstring(tempString, position[0], position[1]);

				//Find the substring containing the numbers to increment
				if (tempString.find(subString) != std::string::npos)
				{
					position[2] = tempString.find(subString);
					position[3] = position[2] + subString.size();

					tempString = poTopoSubstring(tempString, position[2], position[3]);

					//Will increment starting at the last position of the subString

				}
			}

		}
	}

	return 0;
}

std::string poTopoSubstring(std::string String, std::size_t first, std::size_t last)
{
	return String.substr(first, last - first);
}

