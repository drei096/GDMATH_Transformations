#include<iostream>
using namespace std;
class Transformations
{
public:
	Matrix getTranslateMatrix(float x, float y, float z)
	{
		int i, j;
		float mat[4][4];
		Matrix iden3d(mat);
		iden3d.get3DIdentity();
		iden3d.displayMatrix(); //display

		iden3d.setIndexVal(0, 3, x);
		iden3d.setIndexVal(1, 3, y);
		iden3d.setIndexVal(2, 3, z);
		iden3d.displayMatrix(); //display
		return iden3d;
	}
	Matrix getScaleMatrix(float sx, float sy, float sz)
	{
		int i, j;
		float mat[4][4];
		Matrix iden3d(mat);
		iden3d.get3DIdentity();
		iden3d.displayMatrix(); //display

		iden3d.setIndexVal(0, 0, sx);
		iden3d.setIndexVal(1, 1, sy);
		iden3d.setIndexVal(2, 2, sz);
		iden3d.displayMatrix(); //display
		return iden3d;
	}
	float dotProd(Vector v1, Vector v2)
	{
		float sum = 0;
		int i;
		for (i = 0; i < 4; i++)
		{
			sum = sum + (v1.vMatrix[i] * v2.vMatrix[i]);
		}
		return sum;
	}
	//focus muna tayo siguro sa matrix multip na fxn
	Matrix getRotateMatrix(float theta, char dir) //c counterclockwise, l clockwise
	{
		int i, j;
		float mat[4][4];
		// WIP WAG MUNA TO HAHAHA
	}

};

