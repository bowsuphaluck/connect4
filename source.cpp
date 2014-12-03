#include <iostream>
using namespace std;

void init(int grid[6][7])
{
	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<7; j++)
		{
			grid[i][j] = 0;
		}
	}
}
void display(int grid[6][7])
{
	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<7; j++)
		{
			if (grid[i][j] == 0)
			{
				cout << " ";
			}
			else if (grid[i][j] == 1)
			{
				cout << 'X';
			}
			else
			{
				cout << 'O';
			}
			if (j<7)
			{
				cout << " |";
			}
		}
		cout << endl;
		if (i<6){
			cout << "--+--+--+--+--+--+--+" << endl;
		}
	}
}

void checkJ(int grid[6][7])
{
	for (int j = 0; j<7; j++)
	{
		if (grid[6][j] == 0)
		{
			j = j;
		}
		else if (grid[5][j] == 0)
		{
			j = j;
		}
		else if (grid[4][j] == 0)
		{
			j = j;
		}
		else if (grid[3][j] == 0)
		{
			j = j;
		}
		else if (grid[2][j] == 0)
		{
			j = j;
		}
		else if (grid[1][j] == 0)
		{
			j = j;
		}
		else if (grid[0][j] == 0)
		{
			j = j;
		}
	
	}
}

void comp(int grid[6][7], int player) 
{
	cout << "Computer\n" ;
	checkJ(grid);
	for (int i = 0; i<6; i++)
	for (int j = 0; j<7; j++)
	{ 
		if(grid[i][j] == 1)
		{
			if(grid[i][j] == 1 && grid[i][j + 1] != 1 && grid[i][j - 1] != 1)
			{
				grid[i - 1][j] = 2;
			}
			//แนวนอน 
			if (grid[i][j] == 1 && (grid[i][j + 1] == 1 || grid[i][j - 1] == 1))
			{
				if(grid[i][6] == 1 && grid[i][j - 1] == 0)
				{
					grid[i][j - 1] = 2;
				}
				else if(grid[i][j + 1] == 1 && grid[i][j + 2] == NULL)
				{
					grid[i][j + 2] = 2;
					break;
				}
				else if(grid[i][j - 1] == 1 && grid[i][j - 2] == NULL)
				{
					grid[i][j - 2] = 2;
					break;
				}
			}
			//แนวตั้ง
			if (grid[i][j] == 1 && grid[i - 1][j] == 1)
			{
				grid[i - 2][j] = 2;
			}
		}
		
	}
	for (int i = 5; i >= 0; i--)
	for (int j = 0; j <= 5; j++)
	{
		//แนวทแยง
		if (grid[i][j] == 1 && grid[i - 1][j + 1] == 1 && grid[i - 2][j + 2] == 1 )
		{
			grid[i - 3][j + 3] = 2;
		}
		if (grid[i][j] == 1 && grid[i - 1][j - 1] == 1 && grid[i - 2][j - 2] == 1 )
		{
			grid[i - 3][j - 3] = 2;
		}
	}
}

void turn(int grid[6][7], int player)
{
	if(player == 1)
	{ 
		cout << "Please choose number 0-6 \n" ;
		int x;
		cin >> x;
		if (x>=0 && x<7)
		{
			if (grid[6][x] == 0)
			{
				grid[6][x] = player;
			}
			else if (grid[5][x] == 0)
			{
				grid[5][x] = player;
			}
			else if (grid[4][x] == 0)
			{
				grid[4][x] = player;
			}
			else if (grid[3][x] == 0)
			{
				grid[3][x] = player;
			}
			else if (grid[2][x] == 0)
			{
				grid[2][x] = player;
			}
			else if (grid[1][x] == 0)
			{
				grid[1][x] = player;
			}
			else if (grid[0][x] == 0)
			{
				grid[0][x] = player;
			}
			else
			{
				cout << "Pick an empty cell! - MISS A GO!";
			}
		}
		else
		{
			cout << "That's not in the grid - MISS A GO!";
		}
	}
	else
	{
		comp(grid,player);
	}
}
int winlose(int grid[6][7], int player)
{
	for (int i = 0; i<6; i++)
	for (int j = 0; j<7; j++)
	{    //แนวนอน
		if (grid[i][j] == 1 && grid[i + 1][j] == 1 && grid[i + 2][j] == 1 && grid[i + 3][j] == 1)
		{
			cout << "You win!!!" << endl;
		}
		if (grid[i][j] == 2 && grid[i + 1][j] == 2 && grid[i + 2][j] == 2 && grid[i + 3][j] == 2)
		{
			cout << "You lose!!!" << endl;
		}
		//แนวตั้ง
		if (grid[i][j] == 1 && grid[i][j + 1] == 1 && grid[i][j + 2] == 1 && grid[i][j + 3] == 1)
		{
			cout << "You win!!!" << endl;
		}
		if (grid[i][j] == 2 && grid[i][j + 1] == 2 && grid[i][j + 2] == 2 && grid[i][j + 3] == 2)
		{
			cout << "You lose!!!" << endl;
		}
	}
	for (int i = 5; i >= 0; i--)
	for (int j = 0; j <= 5; j++)
	{
		//แนวทแยง
		if (grid[i][j] == 1 && grid[i - 1][j + 1] == 1 && grid[i - 2][j + 2] == 1 && grid[i - 3][j + 3] == 1)
		{
			cout << "You win!!!" << endl;
		}
		if (grid[i][j] == 2 && grid[i - 1][j + 1] == 2 && grid[i - 2][j + 2] == 1 && grid[i - 3][j + 3] == 1)
		{
			cout << "You lose!!!" << endl;
		}

		if (grid[i][j] == 1 && grid[i - 1][j - 1] == 1 && grid[i - 2][j - 2] == 1 && grid[i - 3][j - 3] == 1)
		{
			cout << "You win!!!" << endl;
		}
		if (grid[i][j] == 2 && grid[i - 1][j - 1] == 2 && grid[i - 2][j - 2] == 2 && grid[i - 3][j - 3] == 2)
		{
			cout << "You lose!!!" << endl;
		}
	}

	return 0;

}

void main()
{
	int grid[6][7];
	init(grid);

	int player = 1;
	for (int i = 0; i<100; i++)
	{
		display(grid);
		turn(grid, player);
		winlose(grid, player);
		if (player == 1)
		{
			player = 2;
		}
		else
		{
			player = 1;
		}
	}

}
