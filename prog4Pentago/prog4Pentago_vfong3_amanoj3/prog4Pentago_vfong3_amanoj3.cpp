//	Author: Victor Fong & Aswin Manoj
//	Assignment : #3, Pentago
//	TA : Nianzu Ma, Tues 4PM
//	Feb 19, 2017



//include libraries
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define ROWS 3
#define COLUMNS 3


//Function will display net-id's and other info
void displayInfo(void) {    //function Displays general information of program

	printf("Author: Victor Fong & Aswin Manoj \n");
	printf("Assignment : #3, Pentago \n");
	printf("TA : Nianzu Ma, Tues 4PM \n");
	printf("Feb 19, 2017 \n");
	printf("\n");

	return;
}


//function will display instrunctions
void displayInstructions(void) {    //function displays instructions of program

	printf("Play the two-player game of Pentago. Be the first to get 5 in a ROWS. \n");
	printf("\n");
	printf("Pentago is played on a 6 by 6 board, divided into four 3 by 3    \n");
	printf("quadrants.  There are two players, X and O, who alternate turns. \n");
	printf("The goal of each player is to get five of their pieces in a ROWS, \n");
	printf("either horizontally, vertically, or diagonally.                   \n");
	printf("\n");
	printf("Players take turns placing one of their pieces into an empty     \n");
	printf("space anywhere on the board, then choosing one of the four       \n");
	printf("board quadrants to rotate 90 degrees left or right.              \n");
	printf("\n");
	printf("If both players get five in a ROWS at the same time, or the       \n");
	printf("last move is played with no five in a ROWS, the game is a tie.    \n");
	printf("If a player makes five a ROWS by placing a piece, there is no need \n");
	printf("to rotate a quadrant and the player wins immediately.            \n");
	printf("\n");
	printf("Play online at:  https://perfect-pentago.net                     \n");
	printf("Purchase at:     www.mindtwisterusa.com                          \n");
	printf("\n");
	printf("For each move provide four inputs:                               \n");
	printf("ROWS (A-F), COLUMNS (1-6), Quadrant (1-4), Rotation Direction (L or R) \n");
	printf("\n");
	printf("For instance input of B32R places the next piece at B3 and then  \n");
	printf("would rotate quadrant 3 (lower-left) to the right (clockwise).   \n");
	printf("\n");
	printf("At any point enter 'x' to exit the program.                      ");

	return;
}


//function initializes the selected quadrant
void initializeQuadrant(char variable, char quadrant[ROWS][COLUMNS]) {

	int i = 0;
	int j = 0;

	for (i; i < 3; i++) {

		for (j; j < 3; j++) {

			quadrant[i][j] = variable;

		}

		j = 0;

	}
	return;
}


//displays board
void displayBoard(char quadrant1[3][3], char quadrant2[3][3], char quadrant3[3][3], char quadrant4[3][3]) {		//function displays the pegboard and it's subsequent positions.


	printf("\n\n   	       1   1 2 3 4 5 6   2\n");
	printf("                   -----------\n");
	printf("               A:  %c %c %c %c %c %c  :A       \n", quadrant1[0][0], quadrant1[0][1], quadrant1[0][2], quadrant2[0][0], quadrant2[0][1], quadrant2[0][2]);
	printf("               B:  %c %c %c %c %c %c  :B       \n", quadrant1[1][0], quadrant1[1][1], quadrant1[1][2], quadrant2[1][0], quadrant2[1][1], quadrant2[1][2]);
	printf("               C:  %c %c %c %c %c %c  :C       \n", quadrant1[2][0], quadrant1[2][1], quadrant1[2][2], quadrant2[2][0], quadrant2[2][1], quadrant2[2][2]);
	printf("               D:  %c %c %c %c %c %c  :D       \n", quadrant3[0][0], quadrant3[0][1], quadrant3[0][2], quadrant4[0][0], quadrant4[0][1], quadrant4[0][2]);
	printf("               E:  %c %c %c %c %c %c  :E       \n", quadrant3[1][0], quadrant3[1][1], quadrant3[1][2], quadrant4[1][0], quadrant4[1][1], quadrant4[1][2]);
	printf("               F:  %c %c %c %c %c %c  :F       \n", quadrant3[2][0], quadrant3[2][1], quadrant3[2][2], quadrant4[2][0], quadrant4[2][1], quadrant4[2][2]);
	printf("                   -----------\n");
	printf("	       3   1 2 3 4 5 6   4\n\n");


	return;
}


//prompts user for a move
void promptforMove(int turnCounter) {		//function displays a single print statement to prompt the user for a move.

	(turnCounter % 2 == 0) ? printf("Enter row, column, quadrant, direction for X: ")			//if turncounter is even then prompt for X
		: printf("Enter row, column, quadrant, direction for O: ");			//else prompt for O

	return;
}


//gets a character from user using scanf
char getChar(void) {	//function acquires input of a character as prompted by other functions.

	char input = ' ';
	scanf(" %c", &input);

	return input;
}


//checks input for an x or X that will later quit program
int checkForX(char input) {	//function that takes character variable and checks for for 'x' or 'X'. if true than the function will return an integer of 1 to main(), which will then break away from the loop.

	int XCheck = -1;

	if (input == 'X' || input == 'x') {
		XCheck = 1;
	}
	return XCheck;
}


//scans for the move that a player moves, 4 seperate char checks
void scanForMoveOrX(char *row, int *column, int *quadrant, char *direction) {
	int twoMidInts = 0;
	int exitLoopStatus = -1;

	*row = getChar();

	//check for X and react accordingly
	exitLoopStatus = checkForX(*row);
	if (exitLoopStatus == 1) {
		printf(".  . .Thanks for playing!. .  .");
		exit(2);
	}

	*column = getChar() - '0';
	*quadrant = getChar() - '0';

	*direction = getChar();
	return;
}


//corrects a lowercase character into a capital character for ease of use
char correctUpper(char input) {		//function changes any of the possible lower-case iterations inputted by user into a capital letter for ease of use.

	if (input >= 97 && input <= 122) {

		input -= 32;
	}

	return input;
}


//makes a move
void makeMove(char quadrant1[3][3], char quadrant2[3][3], char quadrant3[3][3], char quadrant4[3][3], int fixedRowInput, int fixedColumnInput, int moveCounter) {

	char symbol = ' ';

	if (moveCounter % 2 == 0) {
		symbol = 'X';
	}
	else {
		symbol = 'O';
	}

	//-------------------------------------------------------------------------------------------

	if ((fixedRowInput >= 0 && fixedRowInput <= 2) && (fixedColumnInput >= 0 && fixedColumnInput <= 2)) {
		quadrant1[fixedRowInput][fixedColumnInput] = symbol;
	}
	else if ((fixedRowInput >= 0 && fixedRowInput <= 2) && (fixedColumnInput >= 3 && fixedColumnInput <= 5)) {
		fixedColumnInput %= 3;
		quadrant2[fixedRowInput][fixedColumnInput] = symbol;
	}
	else if ((fixedRowInput >= 3 && fixedRowInput <= 5) && (fixedColumnInput >= 0 && fixedColumnInput <= 2)) {
		fixedRowInput %= 3;
		quadrant3[fixedRowInput][fixedColumnInput] = symbol;
	}
	else if ((fixedRowInput >= 3 && fixedRowInput <= 5) && (fixedColumnInput >= 3 && fixedColumnInput <= 5)) {
		fixedRowInput %= 3;
		fixedColumnInput %= 3;
		quadrant4[fixedRowInput][fixedColumnInput] = symbol;
	}
	return;
}


//rotates selected quadrant
void makeRotation(char quadrant[3][3], char direction, int errStatus[5]) {

	if (direction != 'R' && direction != 'L') {
	return;
	}

	else if (direction == 'R') {
		for (int i = 0; i < 3 / 2; i++) {
			for (int j = 0; j < 3 - i - 1; j++) {
				char tmp = quadrant[i][j];
				quadrant[i][j] = quadrant[3 - j - 1][i];
				quadrant[3 - j - 1][i] = quadrant[3 - i - 1][3 - j - 1];
				quadrant[3 - i - 1][3 - j - 1] = quadrant[j][3 - i - 1];
				quadrant[j][3 - i - 1] = tmp;
			}
		}
	}
	else if (direction == 'L') {
		for (int i = 0; i < 3 / 2; i++) {
			for (int j = 0; j < 3 - i - 1; j++) {
				char tmp = quadrant[i][j];
				quadrant[i][j] = quadrant[j][3 - i - 1];
				quadrant[j][3 - i - 1] = quadrant[3 - i - 1][3 - j - 1];
				quadrant[3 - i - 1][3 - j - 1] = quadrant[3 - j - 1][i];
				quadrant[3 - j - 1][i] = tmp;
			}
		}
	}
	return;
}


//sets up the rotation to be used by make rotation
void setUpAndMakeRotation(char quadrant1[3][3], char quadrant2[3][3], char quadrant3[3][3], char quadrant4[3][3], char quadrantInput, char turnDirectionInput, int errStatus[5]) {
	
	switch (quadrantInput) {

	case 1:
		if (turnDirectionInput == 'R') {
			makeRotation(quadrant1, 'R', errStatus);
		}
		else {
			makeRotation(quadrant1, 'L', errStatus);
		}
		break;

	case 2:
		if (turnDirectionInput == 'R') {
			makeRotation(quadrant2, 'R', errStatus);
		}
		else {
			makeRotation(quadrant2, 'L', errStatus);
		}
		break;

	case 3:
		if (turnDirectionInput == 'R') {
			makeRotation(quadrant3, 'R', errStatus);
		}
		else {
			makeRotation(quadrant3, 'L', errStatus);
		}
		break;

	case 4:
		if (turnDirectionInput == 'R') {
			makeRotation(quadrant4, 'R', errStatus);
		}
		else {
			makeRotation(quadrant4, 'L', errStatus);
		}
		break;

	default:
		break;
	}

	return;
}

//checks char range for possible inputs and returns error code
int charRangeCheck(char rowInput, int errStatus[5]) {			//errorChecker: checks if input is a character between 'A' and 'F'. if is is not then it will change errCode, which is returned to main() to check for errors

	if ((rowInput >= 65 && rowInput <= 70) || rowInput == 88) {
		errStatus[0] = -1;
	}
	else {
		printf("\n*** Invalid move row.  Please retry.\n\n");
		errStatus[0] = 1;
	}

	return errStatus[0];
}


//checks int range for possible inputs and returns error code
int intRangeCheck(int columnInput, int errStatus[5]) {			//errorChecker: checks if input is a character between 'A' and 'F'. if is is not then it will change errCode, which is returned to main() to check for errors

	if (columnInput >= 1 && columnInput <= 6){
		errStatus[1] = -1;
	}
	else {
		printf("\n*** Invalid move column.  Please retry.\n\n");
		errStatus[1] = 1;
	}

	return errStatus[1];
}

//checks in destination point is empty
int emptySpaceCheck(char quadrant1[3][3], char quadrant2[3][3], char quadrant3[3][3], char quadrant4[3][3], int fixedRowInput, int fixedColumnInput, int errStatus[5]) {

	char pieceGot = ' ';

	if ((fixedRowInput >= 0 && fixedRowInput <= 2) && (fixedColumnInput >= 0 && fixedColumnInput <= 2)) {
		pieceGot = quadrant1[fixedRowInput][fixedColumnInput];
	}
	else if ((fixedRowInput >= 0 && fixedRowInput <= 2) && (fixedColumnInput >= 3 && fixedColumnInput <= 5)) {
		fixedColumnInput %= 3;
		pieceGot = quadrant2[fixedRowInput][fixedColumnInput];
	}
	else if ((fixedRowInput >= 3 && fixedRowInput <= 5) && (fixedColumnInput >= 0 && fixedColumnInput <= 2)) {
		fixedRowInput %= 3;
		pieceGot = quadrant3[fixedRowInput][fixedColumnInput];
	}
	else if ((fixedRowInput >= 3 && fixedRowInput <= 5) && (fixedColumnInput >= 3 && fixedColumnInput <= 5)) {
		fixedRowInput %= 3;
		fixedColumnInput %= 3;
		pieceGot = quadrant4[fixedRowInput][fixedColumnInput];
	}

	if (pieceGot != '.') {
		printf("\n*** That board location is already taken.  Please retry.\n\n");
		errStatus[2] = 1;
	}
	return errStatus[2];
}


//self explanatory
int quadrantValidityCheck(int quadrantInput, int errStatus[5]) {

	if (quadrantInput >= 1 && quadrantInput <= 4) {
		errStatus[3] = -1;
	}
	else {
		printf("\n*** Selected quadrant is invalid.  Please retry.\n\n");
		errStatus[3] = 1;
	}

	return errStatus[3];
}


//self explanatory
int quadrantDirectionValidityCheck(char turnDirectionInput, int errStatus[5]) {

	if (turnDirectionInput == 'R' || turnDirectionInput == 'L') {
		errStatus[4] = -1;
	}
	else {
		printf("\n*** Quadrant rotation direction is invalid.  Please retry.\n\n");
		errStatus[4] = 1;
	}

	return errStatus[4];

}

//self explanatory
int seeIfSomeoneWonOrTied(char quadrant1[3][3], char quadrant2[3][3], char quadrant3[3][3], char quadrant4[3][3]) {

	int winStatus = -1;
	int i = 0;
	int XWon = 0;
	int OWon = 0;

	//player wins by horizontal pair of 5
	for (i = 0; i < 6; i++) {

		if ((quadrant1[i][0] == 'X' && quadrant1[i][1] == 'X' && quadrant1[i][2] == 'X' && quadrant2[i][0] == 'X' && quadrant2[i][1] == 'X') ||
			(quadrant2[i][0] == 'X' && quadrant2[i][1] == 'X' && quadrant2[i][2] == 'X' && quadrant1[i][0] == 'X' && quadrant1[i][1] == 'X') ||
			(quadrant3[i][0] == 'X' && quadrant3[i][1] == 'X' && quadrant3[i][2] == 'X' && quadrant4[i][0] == 'X' && quadrant4[i][1] == 'X') ||
			(quadrant4[i][0] == 'X' && quadrant4[i][1] == 'X' && quadrant4[i][2] == 'X' && quadrant3[i][0] == 'X' && quadrant3[i][1] == 'X')) {
			XWon = 1;
		}
		else if ((quadrant1[i][0] == 'O' && quadrant1[i][1] == 'O' && quadrant1[i][2] == 'O' && quadrant2[i][0] == 'O' && quadrant2[i][1] == 'O') ||
			(quadrant2[i][0] == 'O' && quadrant2[i][1] == 'O' && quadrant2[i][2] == 'O' && quadrant1[i][0] == 'O' && quadrant1[i][1] == 'O') ||
			(quadrant3[i][0] == 'O' && quadrant3[i][1] == 'O' && quadrant3[i][2] == 'O' && quadrant4[i][0] == 'O' && quadrant4[i][1] == 'O') ||
			(quadrant4[i][0] == 'O' && quadrant4[i][1] == 'O' && quadrant4[i][2] == 'O' && quadrant3[i][0] == 'O' && quadrant3[i][1] == 'O')) {
			OWon = 1;
		}
		//player wins by horizontal pair of 5
		else if ((quadrant1[0][i] == 'X' && quadrant1[1][0] == 'X' && quadrant1[2][i] == 'X' && quadrant3[0][i] == 'X' && quadrant3[1][i] == 'X') ||
			(quadrant3[0][i] == 'X' && quadrant3[1][i] == 'X' && quadrant3[2][i] == 'X' && quadrant1[0][i] == 'X' && quadrant1[1][i] == 'X') ||
			(quadrant2[0][i] == 'X' && quadrant2[1][i] == 'X' && quadrant2[2][i] == 'X' && quadrant4[0][i] == 'X' && quadrant4[1][i] == 'X') ||
			(quadrant4[0][i] == 'X' && quadrant4[1][i] == 'X' && quadrant4[2][i] == 'X' && quadrant2[0][i] == 'X' && quadrant2[1][i] == 'X')) {

			XWon = 1;
		}
		else if ((quadrant1[0][i] == 'O' && quadrant1[1][i] == 'O' && quadrant1[2][i] == 'O' && quadrant3[0][i] == 'O' && quadrant3[1][i] == 'O') ||
			(quadrant3[0][i] == 'O' && quadrant3[1][i] == 'O' && quadrant3[2][i] == 'O' && quadrant1[0][i] == 'O' && quadrant1[1][i] == 'O') ||
			(quadrant2[0][i] == 'O' && quadrant2[1][i] == 'O' && quadrant2[2][i] == 'O' && quadrant4[0][i] == 'O' && quadrant4[1][i] == 'O') ||
			(quadrant4[0][i] == 'O' && quadrant4[1][i] == 'O' && quadrant4[2][i] == 'O' && quadrant2[0][i] == 'O' && quadrant2[1][i] == 'O')) {
			OWon = 1;
		}
	}

	if (XWon == 1 && OWon == 1) {
		printf("Players tied!!!");
		winStatus = 2;
	}
	else if (XWon == 1 && OWon != 1){

		printf("\nX has won the game!");
}
	else if (XWon != 1 && OWon == 1){

		printf("\nO has won the game!");
}

	return winStatus;
}


int main(void) {	//main program

//initialize variables	
	int i = 0;
	int j = 0;
	int moveCounter = 0;
	int endGameConditionMet = 0;
	int checkForWinner;

	char quadrant1[ROWS][COLUMNS];
	char quadrant2[ROWS][COLUMNS];
	char quadrant3[ROWS][COLUMNS];
	char quadrant4[ROWS][COLUMNS];

	char tempChar = ' ';
	char input;

	char rowInput = ' ';
	int columnInput = 0;
	int quadrantInput = 0;
	char turnDirectionInput = ' ';

	int exitLoopStatus = 0;
	int errStatus[5];
	int continueStatus = 0;

//call functions and make calculations. see function definitions above for more information!
	displayInfo();
	displayInstructions();

	initializeQuadrant('.', quadrant1);
	initializeQuadrant('.', quadrant2);
	initializeQuadrant('.', quadrant3);
	initializeQuadrant('.', quadrant4);
	endGameConditionMet = -1;

	displayBoard(quadrant1, quadrant2, quadrant3, quadrant4);

	do {
	
		for (i = 0; i < 5; i++) {
		errStatus[i] = -1;
		}

		continueStatus = -1;

	//ask for and get inputs for entire move to be made.
		promptforMove(moveCounter);
		scanForMoveOrX(&rowInput, &columnInput, &quadrantInput, &turnDirectionInput);

	//make corrections to inputs to work with arrays
		rowInput = correctUpper(rowInput);
		turnDirectionInput = correctUpper(turnDirectionInput);


		int fixedColumnInput = (columnInput - 1);
		int fixedRowInput = (rowInput - 65);

		errStatus[0] = charRangeCheck(rowInput, errStatus);
		if (errStatus[0] == 1) {
			continue;
		}
		
		errStatus[1] = intRangeCheck(columnInput, errStatus);
		if (errStatus[1] == 1) {
			continue;
		}

		errStatus[2] = emptySpaceCheck(quadrant1, quadrant2, quadrant3, quadrant4, fixedRowInput, fixedColumnInput, errStatus);
		if (errStatus[2] == 1) {
			continue;
		}

		errStatus[3] = quadrantValidityCheck(quadrantInput, errStatus);
		if (errStatus[3] == 1) {
			continue;
		}

		errStatus[4] = quadrantDirectionValidityCheck(turnDirectionInput, errStatus);
		if (errStatus[4] == 1) {
			continue;
		}

	//make the actual move and rotation necessary to be reflected on board
		makeMove(quadrant1, quadrant2, quadrant3, quadrant4, fixedRowInput, fixedColumnInput, moveCounter);
		setUpAndMakeRotation(quadrant1, quadrant2, quadrant3, quadrant4, quadrantInput, turnDirectionInput, errStatus);
	
		moveCounter++;

		endGameConditionMet = seeIfSomeoneWonOrTied( quadrant1, quadrant2, quadrant3, quadrant4);			//does not work for diagonal checks... sorry...

	// reflect changes
		displayBoard(quadrant1, quadrant2, quadrant3, quadrant4);
		
		continueStatus = -1;
	} while (endGameConditionMet == -1);

	return 0;
}