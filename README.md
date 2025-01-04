# 1stSem-Projects

**TIC TAC TOE** 

#include <iostream>
using namespace std;

void Welcome();
void InitializeBoard(char board[3][3]);
void DisplayBoard(char board[3][3]);
bool ValidMove(char board[3][3], int row, int cols);
bool SpaceChecker(char board[3][3]);
void MakeMove(char board[3][3], int row, int cols, char player_move);
void ComputerMove(char board[3][3]);
void TurnManager(int& turn);
bool Winner(char board[3][3], char player_move);
void FancyWelcome();
void Player1Win();
void Player2Win();
void ComputerWin();

int main()
{
	int choice;
	cout << "enter (1) for multiplayer and (2) for player VS computer :  " << endl;
	cin >> choice;

	if (choice == 1)
	{
		char board[3][3];
		char User = 'X';
		char computer = 'O';
		bool end = false;
		int playerTurn = 0;
		char user_choice;

		while (true)
		{
			FancyWelcome();
			InitializeBoard(board);
			end = false;
			while (!end)
			{
				DisplayBoard(board);

				if (playerTurn == 0)
				{
					int row;
					int cols;
					cout << "player 1 enter your desired row(0-2) " << endl;
					cin >> row;
					cout << "player 1 enter your column(0-2)" << endl;
					cin >> cols;
					while (!ValidMove(board, row, cols))
					{
						cout << "yout move is invalid " << endl;
						cout << "enter rows and column again (0-2): " << endl;
						cin >> row;
						cin >> cols;
					}
					MakeMove(board, row, cols, User);

				}
				else
				{
					int row2;
					int col2;
					cout << "player 2 enter desired row(0-2) " << endl;
					cin >> row2;
					cout << "player 2 enter desired column(0-2)" << endl;
					cin >> col2;

					while (!ValidMove(board, row2, col2))
					{
						cout << "your move is invalid " << endl;
						cout << "enter rows and cols again (0-2)" << endl;
						cin >> row2;
						cin >> col2;
					}
					MakeMove(board, row2, col2, computer);
				}
				if (Winner(board, User))
				{
					DisplayBoard(board);
					cout << "Player 1 Wins !!!" << endl;
					Player1Win();
					end = true;
				}
				else if (Winner(board, computer))
				{
					cout << "Player 2 wins!!" << endl;
					Player2Win();
					end = true;
				}
				else if (SpaceChecker(board))
				{
					DisplayBoard(board);
					cout << "Its a tie." << endl;
					end = true;
				}

				if (!end)
				{
					TurnManager(playerTurn);
				}

			}

			cout << "Do you want to play again ?" << endl;
			cin >> user_choice;

			if (user_choice != 'y' && user_choice != 'Y')
			{
				cout << "Exiting.." << endl;
				return 0;

			}

		}

		return 0;
	}
	else if (choice == 2)
	{
		char board[3][3];
		char User = 'X';
		char computer = 'O';
		bool end = false;
		int playerTurn = 0;
		char user_choice;

		while (true)
		{
			FancyWelcome();
			InitializeBoard(board);
			end = false;
			while (!end)
			{
				DisplayBoard(board);

				if (playerTurn == 0)
				{
					int row;
					int cols;
					cout << "enter your desired row(0-2) " << endl;
					cin >> row;
					cout << "enter your column(0-2)" << endl;
					cin >> cols;
					while (!ValidMove(board, row, cols))
					{
						cout << "yout move is invalid " << endl;
						cout << "enter rows and column again (0-2): " << endl;
						cin >> row;
						cin >> cols;
					}
					MakeMove(board, row, cols, User);

				}
				else
				{
					ComputerMove(board);
				}
				if (Winner(board, User))
				{
					DisplayBoard(board);
					cout << "You won !!!" << endl;
					Player1Win();
					end = true;
				}
				else if (Winner(board, computer))
				{
					cout << "Computer wins!!" << endl;
					ComputerWin();
					end = true;
				}
				else if (SpaceChecker(board))
				{
					DisplayBoard(board);
					cout << "Its a tie." << endl;
					end = true;
				}

				if (!end)
				{
					TurnManager(playerTurn);
				}

			}

			cout << "Do you want to play again ?" << endl;
			cin >> user_choice;

			if (user_choice != 'y' && user_choice != 'Y')
			{
				cout << "Exiting.." << endl;
				return 0;

			}

		}

		return 0;
	}

	return 0;
}
void Welcome()
{
	cout << "----------  -------  -------     --------  -------   -------     -------  ------   ------" << endl;
	cout << "    |          |     |               |     |     |   |               |   |      | |      " << endl;
	cout << "    |          |     |               |     |-----|   |               |   |      | |------" << endl;
	cout << "    |          |     |               |     |     |   |               |   |      | |      " << endl;
	cout << "    |       -------  -------         |     |     |   -------         |    ------   ------" << endl;

	cout << endl;
	cout << endl;

}
void InitializeBoard(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[3][3])
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j];
			if (j < 2)
			{
				cout << " | ";
			}

		}
		cout << endl;
		if (i < 2)
		{
			cout << "---------" << endl;
		}
	}
	cout << endl;
}
bool ValidMove(char board[3][3], int row, int cols)
{
	if (row < 0 || row>2 || cols < 0 || cols>2)
	{
		return false;
	}
	if (board[row][cols] != ' ')
	{

		cout << "This spot is alreadt taken. Plase choose a valid spot." << endl;
		return false;
	}

	return true;
}
void MakeMove(char board[3][3], int row, int cols, char player_move)
{
	board[row][cols] = player_move;
}
void ComputerMove(char board[3][3])
{

	cout << "Computer is taking it's turn " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = 'O';
				return;
			}
		}
	}
}
bool SpaceChecker(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}
void TurnManager(int& turn)
{
	if (turn == 0)
	{
		turn = 1;
	}
	else
	{
		turn = 0;
	}
}
bool Winner(char board[3][3], char player_move)
{
	//to check rows victory:
	int rows = 3;
	int cols = 3;
	int ct = 0;
	int max_ct = 3;
	for (int i = 0; i < rows; i++)
	{
		int ct = 0;
		for (int j = 0; j < cols; j++)
		{
			if (board[i][j] == player_move)
			{
				ct++;
			}
		}
		if (ct == max_ct)
		{
			return true;
		}
	}

	//to check cols:

	for (int i = 0; i < rows; i++)
	{
		ct = 0;
		for (int j = 0; j < cols; j++)
		{
			if (board[j][i] == player_move)
			{
				ct++;
			}
		}
		if (ct == max_ct)
		{
			return true;
		}
	}

	//to check main diagnoal :
	ct = 0;
	for (int k = 0; k < rows; k++)
	{
		if (board[k][k] == player_move)
		{
			ct++;
		}
	}
	if (ct == max_ct)
	{
		return true;
	}
	ct = 0;

	//for second diagnol : 

	for (int i = 0; i < rows; i++)
	{
		if (board[i][rows - i - 1] == player_move)
		{
			ct++;
		}
	}
	if (ct == max_ct)
	{
		return true;
	}


	return false;
}
void FancyWelcome()
{
	cout << " -----            -----             -----            " << endl;
	cout << "|     |          |     |           |     |           " << endl;
	cout << " -   - (_)        -   -             -   -            " << endl;
	cout << "  | |   -  ___     | | ____  ___     | | ___   ___   " << endl;
	cout << "  | |  | |/  _|    | |/    |/   |    | |/   \\ / _ \\  " << endl;
	cout << "  | |  | |  (_     | | (_) |  (_     | | ()  |  __/  " << endl;
	cout << "  \\_/  |_|\____|    \\_/\__,_ |\___ |    \\_/\___/ \\ ___   " << endl;


}
void Player1Win()
{
	cout << "-----           ____          ____  _____       |     |     |                 " << endl;
	cout <<"|     |  |      |    | (    / |     |     |     |     |     | | |    |   ---- " << endl;
	cout <<"|_____|  |      |    |  (  /  |     |_____|     |     |  |  | | |    |  |     " << endl;
	cout <<"|        |      |----|    |   |---- |*          |     |  |  | | |    |   ---  " << endl;
	cout <<"|         ----- |    |    |   |____ |  *        |      _/  _  | |    |  ___ | " << endl;

}
void Player2Win()
{
	cout << " -----           ____          ____  _____    ----   |     |                 " << endl;
	cout << "|     |  |      |    |  \   / |     |     |        |  |     | | |\   |   ---- " << endl;
	cout << "|_____|  |      |    |   \ /  |     |_____|     ___|  |  |  | | | \  |  |     " << endl;
	cout << "|        |      |----|    |   |---- |\         |      |  |  | | |  \ |   ---  " << endl;
	cout << "|         ----- |    |    |   |____ |  \        ____   _/ \_  | |   \|  ___ | " << endl;

}
void ComputerWin()
{
	cout << "----                        |      |            " << endl;
	cout <<"|      ----  |\  /|  ----    |      | | |\   |  ---  " << endl;
	cout <<"|     |    | | \/ | |    |   |  /\  | | | \  | |  "  << endl;
	cout <<"|     |    | |    | |---     | /  \ | | |  \ |  --- " << endl;
	cout <<" ____  ____  |    | |        |/    \| | |   \|  ___| " << endl;
}
