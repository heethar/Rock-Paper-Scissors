#include <iostream>

//namespace
using namespace std;

//no constants

//enumerated data types
enum objectType { ROCK, PAPER, SCISSORS };

//function prototypes
void displayRules();
objectType retrievePlay(char selection);
bool validSelection(char selection);
void convertEnum(objectType object);
objectType winningObject(objectType play1, objectType play2);
void gameResults(objectType play1, objectType play2, int& winner);
void displayResults(int gCount, int wCount1, int wCount2);

//initialize main module
int main()
{
	//element 8:  executable code with inline comments
	//Step 1:  declare the variables
	int gameCount; //variable to store the number of 
				   //games played
	int winCount1; //variable to store the number of games 
				   //won by player 1
	int winCount2; //variable to store the number of games 
				   //won by player 2
	int gameWinner;
	char response;  //variable to get the user's response to 
					//play the game
	char selection1;
	char selection2;
	objectType play1;  //player1's selection
	objectType play2;  //player2's selection

					   //Initialize loop variables
	gameCount = 0;
	winCount1 = 0;
	winCount2 = 0;

	displayRules();   //display rules

	cout << "Enter Y/y to play the game: ";       //prompt user to play
	cin >> response;                              //get results
	cout << endl;

	while (response == 'Y' || response == 'y')   //while response is yes
	{
		cout << "Player 1 enter your choice: ";   //prompt player 1
		cin >> selection1;                        //get player 1 results
		cout << endl;

		cout << "Player 2 enter your choice: ";   //prompt player 2
		cin >> selection2;                        //get player 2 results
		cout << endl;

		//determine if both play selections are valid
		if (validSelection(selection1) && validSelection(selection2))
		{
			play1 = retrievePlay(selection1);
			play2 = retrievePlay(selection2);
			gameCount++;                          //increment total game count
			gameResults(play1, play2, gameWinner); //call function to determine winner

			if (gameWinner == 1)                  //Increment winner games win count
				winCount1++;
			else if (gameWinner == 2)
				winCount2++;
		}//end if

		cout << "Enter Y/y to play the game: ";   //promt user to play again
		cin >> response;                          //get player response
		cout << endl;
	}//end while

	 //ouput the game results
	displayResults(gameCount, winCount1, winCount2);

	//pause the window
	system("pause");

	//end the module
	return 0;
}//end the program

//define the functions:

 //Display Rules Function:  display some brief information about the game and the rules
void displayRules()
{
	using namespace std;

	cout << "Welcome to the game of ROCK, PAPER, SCISSORS!" << endl;
	cout << "This is a game for two players.  For each game, each player " << endl;
	cout << "selects one of the objects: " << endl;
	cout << " {ROCK, PAPER, or SCISSORS}.  " << endl;
	cout << " The rules for winning are: " << endl;
	cout << "      1.  If both players select the same object it is a tie." << endl;
	cout << "      2.  Rock breaks scissors: so player who selects wins." << endl;
	cout << "      3.  Paper covers rock; so player who selects wins." << endl;
	cout << "      4.  Scissors cut paper; so player so selects wins." << endl;
	cout << "Enter R or r for ROCK, P or p for PAPER, or S or s for SCISSORS. " << endl;
}

//because enumeration types cannot be read directly, this function 
//converst the entered choice (R,r,S,s,P,p) and returns the appropriate 
//object type.
objectType retrievePlay(char selection)
{
	using namespace std;
	//declare the local variable
	objectType object;

	//create switch statement to determine object type
	switch (selection)
	{
	case 'R':
	case 'r':
		object = ROCK;
		break;
	case 'P':
	case 'p':
		object = PAPER;
		break;
	case 'S':
	case 's':
		object = SCISSORS;
		break;
	}
	return object;
}

//This function checks whether a player's selection is valid.
//The only valid selections are: R,r, P,p, or S,s.
bool validSelection(char selection)
{
	using namespace std;

	switch (selection)
	{
	case 'R':
	case 'r':
	case 'P':
	case 'p':
	case 'S':
	case 's':
		return true;
	default:
		return false;

	}
}

//This function is called by the function gameResult to output the
//enumeration type values.
void convertEnum(objectType object)
{
	using namespace std;
	switch (object)
	{
	case ROCK:
		cout << "Rock";
		break;
	case PAPER:
		cout << "Paper";
		break;
	case SCISSORS:
		cout << "Scissors";
		break;
	}
}

//This function determines and returns the winning object.
objectType winningObject(objectType play1, objectType play2)
{
	using namespace std;
	if ((play1 == ROCK && play2 == SCISSORS) || (play2 == ROCK && play1 == SCISSORS))
		return ROCK;
	else if ((play1 == ROCK && play2 == PAPER) || (play2 == ROCK && play1 == PAPER))
		return PAPER;
	else
		return SCISSORS;
}

//This function outputs the players' choices and the winner of the game.
void gameResults(objectType play1, objectType play2, int& winner)
{
	using namespace std;
	//local variable
	objectType winnerObject;

	if (play1 == play2)
	{
		winner = 0;
		cout << "Both players selected ";
		convertEnum(play1);
		cout << ".  This game is a tie." << endl;
	}
	else
	{
		winnerObject = winningObject(play1, play2);

		//output each player's choice
		cout << "Player 1 selection:  ";
		convertEnum(play1);
		cout << " and Player 2 selection:  ";
		convertEnum(play2);
		cout << ".  ";

		//Decide the winner
		if (play1 == winnerObject)
			winner = 1;
		else if (play2 == winnerObject)
			winner = 2;

		//output the winner
		cout << "Player " << winner << " wins this game. " << endl;
	}
}
//After the game is over, this function displays the FINAL overall results
void displayResults(int gCount, int wCount1, int wCount2)
{
	using namespace std;
	cout << "The total number of games played:  " << gCount << endl;
	cout << "The number of plays won by player 1:  " << wCount1 << endl;
	cout << "The number of plays won by player 2:  " << wCount2 << endl;
}
