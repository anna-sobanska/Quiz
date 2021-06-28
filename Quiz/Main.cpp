#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


int main() {
	std::string name, surName;
	int mobileNumber{};

	/*std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Enter your surname: ";
	std::cin >> surName;
	std::cout << "Enter your mobile phone: ";
	std::cin >> mobileNumber;*/

	std::fstream file;
	file.open("card.txt", std::ios::in);

	if (file.good() == false) {
		std::cout << "File doesn't exist!";
		exit(0);
	}

	std::string line;
	int lineNumber=1;
	
	while (getline(file, line))
	{
		switch (lineNumber) {
		case 1:
			name = line;
			break;
		case 2:
			surName = line;
			break;
		case 3:
			mobileNumber = atoi(line.c_str());
			break;
		}
		lineNumber++;
	}

	file.close();

	std::cout << name << std::endl;
	std::cout << surName << std::endl;
	std::cout << mobileNumber << std::endl;

	system("pause>0");
}