#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>



int main() {

	std::string subject, name;
	std::string question[5], answerA[5], answerB[5], answerC[5], answerD[5], correct[5], userAnswer, line;
	int score = 0;
	int lineNumber = 1;
	int questionNumber = 0;
	

	std::fstream file;
	file.open("Quiz.txt", std::ios::in);

	if (file.good() == false) {
		std::cout << "File doesn't exist!";
		exit(0);
	}

	while (getline(file, line))
	{
		switch (lineNumber) {
		case 1:
			subject = line;
			break;
		case 2:
			name = line;
			break;
		case 3:
			question[questionNumber] = line;
			break;
		case 4:
			answerA[questionNumber] = line;
			break;
		case 5:
			answerB[questionNumber] = line;
			break;
		case 6:
			answerC[questionNumber] = line;
			break;
		case 7:
			answerD[questionNumber] = line;
			break;
		case 8:
			correct[questionNumber] = line;
			break;
		}
		if (lineNumber == 8) { lineNumber = 2; questionNumber++; }
		lineNumber++;
	}

	file.close();

	for (int i = 0; i <= 4; i++) {
		std::cout << std::endl << question[i] << std::endl;
		std::cout << "A. "<< answerA[i] << std::endl;
		std::cout << "B. " << answerB[i] << std::endl;
		std::cout << "C. " << answerC[i] << std::endl;
		std::cout << "D. " << answerD[i] << std::endl;

		std::cout << "Your answer is: ";
		std::cin >> userAnswer;

		transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);

		if (userAnswer == correct[i]) {
			std::cout << "Good! You get a point!" << std::endl;
			score++;
		}
		else {
			std::cout << "Wrong! You don't get a point! Correct answer is " << correct[i] << std::endl;
		}

	}
	std::cout << "This is the end of quiz, you have got " << score << " points";
	system("pause>0");
}