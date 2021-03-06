// OptimizationMethods2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stack>
#include <stdint.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
	ofstream myfile("ss.txt");
	const int vertices = 10;
	int ind, depart = 0;

	int graphMap[vertices][vertices] = {
		{0, 4, 5, -1, -1, -1, -1, -1, -1, -1},
		{-1, 0, -1, 2, -1, 4, -1, -1, -1, -1},
		{-1, -1, 0, -1, 1, -1, -1, -1, -1, -1},
		{-1, -1, -1, 0, -1, -1, -1, 9, -1, -1},
		{-1, -1, -1, -1, 0, -1, -1, 8, 4, -1},
		{-1, -1, -1, -1, -1, 0, 5, 7, -1, -1},
		{-1, -1, -1, -1, -1, -1, 0, -1, -1, 9},
		{-1, -1, -1, -1, -1, -1, -1, 0, -1, 5},
		{-1, -1, -1, -1, -1, -1, -1, -1, 0, 1},
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, 0}
	};

	int route[vertices];
	int optimalValue[vertices];

	for (int i = 0; i < vertices - 1; ++i)
	{
		optimalValue[i] = -1;
	}
		optimalValue[vertices - 1] = 0;
		queue <int> path;
		ind = vertices - 1;

		myfile << "something something : " << endl;

		while (ind != depart)
		{
			for (int i = 0; i < vertices; ++i)
			{
				if ((graphMap[i][ind] > -1) && (i != ind))
				{
					if (optimalValue[i] == -1)
					{
						path.push(i);
					}
					if ((optimalValue[i] == -1) || (optimalValue[ind] + graphMap[i][ind] < optimalValue[i]))
					{
						optimalValue[i] = optimalValue[ind] + graphMap[i][ind];
						route[i] = ind;
						myfile << i + 1 << " -> " << ind + 1 << ": " << optimalValue[i] << endl;
					}
					else
					{
						myfile << "NOT OPTIMAL" << i + 1 << " -> " << ind + 1 << ": "
							<< optimalValue[ind] + graphMap[i][ind] << endl;
					}
				}
			}

				ind = path.front();
				path.pop();
		}

		myfile << "Optimal path value is " << optimalValue[depart] << endl;
		myfile << "Path : " << (ind = depart) + 1;
		while (ind != vertices - 1)
		{
			ind = route[ind];
			myfile << " -> " << ind + 1;
		}
		myfile << endl;
		myfile.close();
	system("pause");
    return 0;
}

