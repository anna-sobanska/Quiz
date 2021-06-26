#include <iostream>
#include <fstream>
#include <string>


int main() {
	std::string name, surName;
	int mobileNumber;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Enter your surname: ";
	std::cin >> surName;
	std::cout << "Enter your mobile phone: ";
	std::cin >> mobileNumber;

	std::fstream file;
	file.open("card.txt", std::ios::out | std::ios::app);

	file << name << std::endl;
	file << surName << std::endl;
	file << mobileNumber << std::endl;

	file.close();

	system("pause>0");
}