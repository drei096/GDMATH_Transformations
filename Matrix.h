#include<iostream>
using namespace std;
class Matrix
{
private:
	float matrix[4][4]; //4x4 size para kasya sa 3d
public:
	Matrix(float input[4][4])
	{
		int i,j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (j == 3 && i == 3)
					matrix[i][j] = 1;
				else if (j == 3 || i == 3)
					matrix[i][j] = 0;
				else
					matrix[i][j] = input[i][j];
			}
		}
	}
	Matrix get3DIdentity()
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (i == j)
					matrix[i][j] = 1;
				else
					matrix[i][j] = 0;
			}
		}
		return matrix;
	}
	void displayMatrix()
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
	void setIndexVal(int x, int y, int val)
	{
		matrix[x][y] = val;
	}
	Matrix getMatrix()
	{
		return matrix;
	}
	/*
	Vector getMatrixRow(int rowIndex)
	{
		int x, y, z;
		x = matrix[rowIndex][0];
		y = matrix[rowIndex][1];
		z = matrix[rowIndex][2];
		Vector row(x, y, z);
		row.forceZero(rowIndex);
		return row;
	}
	*/
};
