#include <fstream>
#include <iostream>
#include <string>

//Function Protoypes
std::string poTopoSubstring(std::string String, std::size_t first, std::size_t last);

int main()
{
	//--------Variable Declarations--------
	std::fstream ReadFile;
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
			ReadFile.flush();
			std::getline(ReadFile, tempString);
			std::cout << "After getline = " << ReadFile.tellp() << std::endl;
			//Find the full string inputed but user
			if (tempString.find(fullString) != std::string::npos)
			{
				position[0] = tempString.find(fullString);
				position[1] = position[0] + fullString.size();

				//Find the substring containing the numbers to increment
				if (tempString.find(subString, position[0]) != std::string::npos)
				{
					position[2] = tempString.find(subString, position[0]);
					position[3] = position[2] + (subString.size() - 1);

					//Starting from right to left will increment all position of string
					for (int index = 0; index < subString.size(); index++)
					{
						switch (tempString.at(position[3]))
						{
						case '0':
							tempString.replace(position[3], 1, 1, '1');
							index = subString.size();
							break;
						case '1':
							tempString.replace(position[3], 1, 1, '2');
							index = subString.size();
							break;
						case '2':
							tempString.replace(position[3], 1, 1, '3');
							index = subString.size();
							break;
						case '3':
							tempString.replace(position[3], 1, 1, '4');
							index = subString.size();
							break;
						case '4':
							tempString.replace(position[3], 1, 1, '5');
							index = subString.size();
							break;
						case '5':
							tempString.replace(position[3], 1, 1, '6');
							index = subString.size();
							break;
						case '6':
							tempString.replace(position[3], 1, 1, '7');
							index = subString.size();
							break;
						case '7':
							tempString.replace(position[3], 1, 1, '8');
							index = subString.size();
							break;
						case '8':
							tempString.replace(position[3], 1, 1, '9');
							break;
						case '9':
							//Make sure there isn't another positon to the left
							if (position[2] - position[3] != 0)
							{
								tempString.replace(position[3], 1, 1, '0');
								position[3]--;
							}
							break;
						}
					}
					std::cout << "Before seek Change = " << ReadFile.tellp() << std::endl;
					ReadFile.seekp(ReadFile.tellp() - (std::streampos)(tempString.size() + 2));
					std::cout << "After seek Change = " << ReadFile.tellp() << std::endl;
					ReadFile << tempString;
					ReadFile.seekp(ReadFile.tellp() + (std::streampos)2);

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

