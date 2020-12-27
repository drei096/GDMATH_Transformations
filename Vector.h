#include<iostream>
using namespace std;
class Vector
{
public:
	float vMatrix[4];
public:
	Vector(float x, float y, float z)
	{
		vMatrix[0] = x;
		vMatrix[1] = y;
		vMatrix[2] = z;
		vMatrix[3] = 1;
	}
	void forceZero(int rowIndex)
	{
		if (rowIndex <= 3)
			vMatrix[3] = 0;
		else
			vMatrix[3] = 1;
	}
	void displayVector()
	{
		int i;
		for (i = 0; i < 4; i++)
		{
			cout << vMatrix[i] << endl;
		}
	}
	
};

