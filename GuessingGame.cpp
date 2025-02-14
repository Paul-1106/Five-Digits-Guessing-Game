#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <string>
#include <typeinfo>

int globalScore = 0;

// The main menu of the page.
void menuPage() {
	std::cout << "########################" << std::endl;
	std::cout << "# NUMBER GUESSING GAME #" << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "# 1. Start the Game    #" << std::endl;
	std::cout << "# 2. Your Score        #" << std::endl;
	std::cout << "# 3. Instructions      #" << std::endl;
	std::cout << "# 4. Exit              #" << std::endl;
	std::cout << "########################" << std::endl;

}

// The guessing number game function.
void randomNumber(int score) {

	int guessOne;
	int guessTwo;
	int guessThree;
	int guessFour;
	int guessFive;

	int randNum1 = std::rand() % 9 + 1;
	int randNum2 = std::rand() % 9 + 1;
	int randNum3 = std::rand() % 9 + 1;
	int randNum4 = std::rand() % 9 + 1;
	int randNum5 = std::rand() % 9 + 1;

	char oneCorrection = ' ';
	char twoCorrection = ' ';
	char threeCorrection = ' ';
	char fourCorrection = ' ';
	char fiveCorrection = ' ';

	std::cout << "Try to guess all five digits from 1-9 (Press enter to move on to the next digit). \nGood luck!" << std::endl;

	do {
		std::cout << "Enter your five digits here: " << std::endl;
		std::cin >> guessOne;
		
		if (guessOne == randNum1) { // Guessing the number right
			oneCorrection = 'O';
			std::cin >> guessTwo;
		}
		else if (guessOne != randNum1 && guessOne >= 1 && guessOne <= 9) { // Guessing the random number wrong
			oneCorrection = 'X';
			score--;
			std::cin >> guessTwo;
		}
		else if (guessOne != randNum1 && guessOne >= 10 && guessOne <= 0) {
			oneCorrection = '?';
			score--;
			std::cin >> guessTwo;
		}
		else { // Prevent from outputting an unecessary infinite loop
			oneCorrection = '?';
			score--;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin >> guessTwo;
		}

		if (guessTwo == randNum2) {
			twoCorrection = 'O';
			std::cin >> guessThree;
		}
		else if (guessTwo != randNum2 && guessTwo >= 1 && guessTwo <= 9) {
			twoCorrection = 'X';
			score--;
			std::cin >> guessThree;
		}
		else if (guessTwo != randNum2 && guessTwo >= 10 && guessTwo <= 0){
			twoCorrection = '?';
			score--;
			std::cin >> guessThree;
		}
		else {
			twoCorrection = '?';
			score--;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin >> guessThree;
		}

		if (guessThree == randNum3) {
			threeCorrection = 'O';
			std::cin >> guessFour;
		}
		else if(guessThree != randNum3 && guessThree >= 1 && guessThree <= 9){
			threeCorrection = 'X';
			score--;
			std::cin >> guessFour;
		}
		else if (guessThree != randNum3 && guessThree >= 10 && guessThree <= 0){
			threeCorrection = '?';
			score--;
			std::cin >> guessFour;
		}
		else {
			threeCorrection = '?';
			score--;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin >> guessFour;
		}

		if (guessFour == randNum4) {
			fourCorrection = 'O';
			std::cin >> guessFive;
		}
		else if (guessFour != randNum4 && guessFour >= 1 && guessFour <= 9) {
			fourCorrection = 'X';
			score--;
			std::cin >> guessFive;
		}
		else if (guessFour != randNum4 && guessFour >= 10 && guessFour <= 0){
			fourCorrection = '?';
			score--;
			std::cin >> guessFive;
		}
		else {
			fourCorrection = '?';
			score--;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin >> guessFive;
		}

		if (guessFive == randNum5) {
			fiveCorrection = 'O';
		}
		else if (guessFive != randNum5 && guessFive >= 1 && guessFive <= 9){
			fiveCorrection = 'X';
			score--;
		}
		else if (guessFive != randNum5 && guessFive >= 10 && guessFive <= 0){
			fiveCorrection = '?';
			score--;
		}
		else {
			fiveCorrection = '?';
			score--;
			std::cin.clear();
			std::cin.ignore(0, '\n');
		}

		std::cout << "First digit guess:  " << oneCorrection << std::endl;
		std::cout << "Second digit guess: " << twoCorrection << std::endl;
		std::cout << "Third digit guess:  " << threeCorrection << std::endl;
		std::cout << "Fourth digit guess: " << fourCorrection << std::endl;
		std::cout << "Fifth digit guess:  " << fiveCorrection << std::endl;

		// Will stop from an unecessary infinite loop
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (guessOne != randNum1 || guessTwo != randNum2 || guessThree != randNum3 || guessFour != randNum4 || guessFive != randNum5);

	std::cout << "You have finally guessed all five digits!" << std::endl;
	score += 15;
	globalScore += score;
	std::cout << "Your score is: " << score << std::endl;
	std::cout << "Your grand total score: " << globalScore << std::endl;
	std::cout << "########################################" << std::endl;
	std::cout << "1. Keep on playing" << std::endl;
	std::cout << "2. Your total score" << std::endl;
	std::cout << "3. Instructions" << std::endl;
	std::cout << "4. Exit" << std::endl;
	std::cout << "########################################" << std::endl;

}

// Will track your score when you are finished
void userScore() {

	std::cout << "Your current score is: " << globalScore << " point(s)." << std::endl;
}

// The instructions of the page
void instructionPage() {
	std::cout << "INSTRUCTIONS:" << std::endl;
	std::cout << "Try to guess all five digits of the numbers right." << std::endl;
	std::cout << "* 'X' = Incorrect" << std::endl;
	std::cout << "* 'O' = Correct" << std::endl << std::endl;
	std::cout << "* 5 digits off = -5 points" << std::endl;
	std::cout << "* 4 digits off = -4 points" << std::endl;
	std::cout << "* 3 digits off = -3 points" << std::endl;
	std::cout << "* 2 digits off = -2 points" << std::endl;
	std::cout << "* 1 digits off = -1 points" << std::endl;
	std::cout << "* All correct digits = +15 points" << std::endl;
}



int main() {

	menuPage();
	std::cout << "Select numbers from 1 to 4" << std::endl;
	int option;
	int score = 0;

	do {
		
		std::cin >> option;

		switch (option) {

			case 1:
				randomNumber(score);
				break;
			case 2:
				userScore();
				break;
			case 3:
				instructionPage();
				break;
			case 4:
				std::cout << "Thanks for playing!" << std::endl;
				break;
			default:

				// Will stop from an unecessary infinite loop
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (option != 4);

	return 0;
	
}