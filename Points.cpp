#include "stdafx.h"
#include <iostream>
using namespace std;
void points(int currentX, int currentY, const char* direction)
{
	int length = strlen(direction);
	bool warp = false;
	for (int i = 0; i < length; i++)
	{
		if (direction[i] == '>' && !warp)
			currentX += 1;
		else if (direction[i] == '<' && !warp)
			currentX -= 1;
		else if (direction[i] == '^' && !warp)
			currentY -= 1;
		else if (direction[i] == 'v' && !warp)
			currentY += 1;
		else if (direction[i] == '~' && !warp)
			warp = true;
		else if (direction[i] == '~' && warp)
			warp = false;
		else if (direction[i] == '>' && warp)
			currentX -= 1;
		else if (direction[i] == '<' && warp)
			currentX += 1;
		else if (direction[i] == '^' && warp)
			currentY += 1;
		else if (direction[i] == 'v' && warp)
			currentY -= 1;
	}
	cout << "(" << currentX << ", " << currentY << ")" << endl;
}

int main()
{
	int strlen;
	cout << "How long is the string(direction)?";
	cin >> strlen;
	char* direction = new char[strlen];
	int x, y;
	cout << "Input current x" << endl;
	cin >> x;
	cout << "Input current y" << endl;
	cin >> y;
	cout << "Input the direction" << endl;
	cin >> direction;
	points(x, y, direction);
	return 0;
}
