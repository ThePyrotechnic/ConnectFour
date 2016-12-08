#include <iostream>
using namespace std;

void printBoard(char board[6][7]);
bool tryPos(int selection, char board[6][7], bool player1);
bool checkTie(char board[6][7]);
bool checkWin(char board[6][7], bool player1);
bool checkDiagonal(char piece, int row, int col, char board[6][7]);
bool checkHorizontal(char piece, int row, int col, char board[6][7]);
bool checkVertical(char piece, int row, int col, char board[6][7]);
void endGame();
void playGame();

int main()
{
	playGame();

	system("pause");
}

void playGame()
{
	bool win = false, player1 = true;
	int selection;

	char board[6][7];
	for (int a = 0; a < 6; a++)
		for (int b = 0; b < 7; b++)
			board[a][b] = ' ';

	printBoard(board);

	cout << "Welcome to Command-Line Connect Four!" << endl
		<< "Player 1, select a row (1 - 7):" << endl;

	while (true)
	{
		cin >> selection;
		if (tryPos(selection, board, player1))
		{
			if (checkWin(board, player1))
			{
				printBoard(board);
				if (player1) cout << "Player 1 ";
				else cout << "Player 2 ";
				cout << "wins!";
				endGame();
			}
			if (checkTie(board))
			{
				cout << "The game is a tie!" << endl;
				break;
			}
			printBoard(board);
			player1 = !player1;

			if (player1) cout << "Player 1, ";
			else cout << "Player 2, ";
			cout << "Select a row (1 - 7):" << endl;
		}
		else
		{
			cout << "that column is full, try another (1 - 7): " << endl;
		}
	}
	endGame();
}

bool tryPos(int selection, char board[6][7], bool player1) 
{
	for (int a = 6; a >= 0; a--) 
	{
		if (board[a][selection - 1] == ' ')
			if (player1) 
			{
				board[a][selection - 1] = 'X';
				//cout << "Placed at row " << a << " col " << selection - 1 << endl; //Debugging
				return true;
			}
			else 
			{
				board[a][selection - 1] = 'O';
				//cout << "Placed at row " << a << " col " << selection - 1 << endl; //Debugging
				return true;
			}
	}
}

void printBoard(char board[6][7]) 
{
	for (int a = 0; a < 6; a++)
	{
		for (int b = 0; b < 7; b++)
			cout << '|' << board[a][b];

		cout << '|' << endl;
	}
	cout << " 1 2 3 4 5 6 7" << endl;
}

bool checkTie(char board[6][7])
{
	for (int a = 0; a < 6; a++)
		for (int b = 0; b < 7; b++)
			if (board[a][b] == ' ') 
				return false;
	return true;
}

bool checkWin(char board[6][7], bool player1)
{
	char piece;
	if (player1) piece = 'X';
	else piece = 'O';
	for (int a = 0; a < 6; a++)
		for (int b = 0; b < 7; b++)
		{
			if (checkDiagonal(piece, a, b, board)) return true;
			if (checkHorizontal(piece, a, b, board)) return true;
			if (checkVertical(piece, a, b, board)) return true;
		}
	return false;
}

bool checkDiagonal(char piece, int row, int col, char board[6][7])
{
	bool result = false;
	int count = 0;
	for (int a = row + 1, b = col + 1; a < 6 && b < 7 && count < 4; a++, b++)
	{
		if (board[a][b] == piece) count++;
		else break;
	}
	if (count == 4) 
		result = true;
	else if (row <= 2 && col > 2)
	{
		count = 0;
		for (int a = row + 1, b = col - 1; a < 6 && b >= 0 && count < 4; a++, b--)
		{
			if (board[a][b] == piece) count++;
			else break;
		}
		if (count == 4) result = true;
	}
	return result;
}
bool checkHorizontal(char piece, int row, int col, char board[6][7])
{
	return false;
}
bool checkVertical(char piece, int row, int col, char board[6][7])
{
	return false;
}

void endGame()
{
	char choice;
	cout << "Play again? (Y or N):" << endl;
	cin >> choice;
	if (toupper(choice) == 'Y')
		playGame();
	else 
		exit(1);
}