#include <iostream>
using namespace std;
int main()
{
	int cboard[8][8] = {  };
	int hori[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int vert[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int count = 1;
	int currentRow = 0;
	int currentColumn = 0;
	int moveNumber = 0;
	int repeat = 1;
	while (repeat == 1) {
		repeat = 0;
		for (moveNumber = 0; moveNumber < 8; moveNumber++)
		{
			if ((currentRow + vert[moveNumber] >= 0 && currentRow + vert[moveNumber] <= 7) && (currentColumn + hori[moveNumber] >= 0 && currentColumn + hori[moveNumber] <= 7))
			{
				if (cboard[currentRow + vert[moveNumber]][currentColumn + hori[moveNumber]] == 0)
				{
					repeat = 1;
					count += 1;
					currentRow += vert[moveNumber];
					currentColumn += hori[moveNumber];
					cboard[currentRow][currentColumn] = count;
				}
			}
		}

	}
		for (int column = 0; column < 8; column++) {
			for (int row = 0; row < 8; row++)
			{
				cout << cboard[row][column];
				cout << "\t";
			}
			cout << endl;
		}
	}