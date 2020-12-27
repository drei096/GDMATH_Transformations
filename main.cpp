/*needed to be addressed:
* fix getMatrixRow at Matrix.h, it should return an array or vector na either 0 or 1 ang last elem
* becos of the homog coord. 
* 
* address natin muna yung matrix multiplication fxn tsaka tayo sa rotation
* pwede mo paglaruan yung test calls para makuha mo feel ng fxns
*/

#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<cctype>
#include"Matrix.h"
#include"Vector.h"
#include"Transformations.h"
using namespace std;

typedef struct point3D
{
	float x;
	float y;
	float z;
};

int main()
{
	int i,j,trans;
	char addchoice;
	vector <point3D> points;
	vector <float> readPoints;
	vector <int> transChoices;
	string indiv, filename, subs, ssubs;
	float conv;
	bool choice;
	Transformations transf;

	cout << "What file would you like to open? ";
	cin >> filename;
	filename = filename + ".txt";
	ifstream setOfPoints(filename);
	
	//read coordinates from file
	while(getline(setOfPoints, indiv))
	{
		stringstream ss(indiv);
		while (ss.good())
		{
			i = 0;
			getline(ss, subs, ','); //prints a new line after the comma
			while (!isdigit(subs[i]))
			{
				i++;
			}
			ssubs = subs.substr(i, '\n');
			conv = stof(ssubs);
			readPoints.push_back(conv);
		}
	}
	//end
	//assign read coordinates as point3d
	for (size_t i = 0; i < readPoints.size(); i+=3)
	{
		point3D pt;
		pt.x = readPoints[i];
		pt.y = readPoints[i + 1];
		pt.z = readPoints[i + 2];
		points.push_back(pt);
	}
	//end
	//generate vector matrix per point in points vector

	
	
	Vector p(points[0].x, points[0].y, points[0].z); //creates a 4x1 column matrix na nagcocontain ng x,y,z and homog coords
	Vector p2(points[1].x, points[1].y, points[1].z);
	p.displayVector();
	cout << endl;
	p2.displayVector();
	cout << endl;
	cout << "dot prod:" << transf.dotProd(p, p2) << endl;

	
	
	cout << endl << "What transformations would you like to do?" << endl;
	cout << "[1] Translate" << endl << "[2] Scale" << endl << "[3] Distort" << endl << "[4] Squeeze" << endl << "[5] Project" << endl << "[6] Rotate" << endl;
	choice = true;
	while (choice == true)
	{
		cout << endl << "Select your transformations:";
		cin >> trans;
		transChoices.push_back(trans);
		cout << "Do you want to add another? (y/n): ";
		cin >> addchoice;
		if (addchoice == 'y')
			choice = true;
		else
			choice = false;
	}
	

	transf.getScaleMatrix(2, 3, 2); // creates and displays a scale matrix that scales 2 in x, 3 in y, 2 in z
	transf.getTranslateMatrix(5, 3, 5); // creates and displays a trans matrix that moves 5 in x, 3 in y, 5 in z
	
	/*
	//perform transformations, return matrices
	for (i = 0; i < transChoices.size(); i++)
	{
		
	}
	//compose here after
	*/
	setOfPoints.close();
	return 0;
}