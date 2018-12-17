#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#define SIZE 7
using namespace std;

struct point
{
	int row;
	int col;
	point* pre;
	point(int a, int b)
	{
		row = a;
		col = b;
	}
	point(int a, int b, point* _pre)
	{
		row = a;
		col = b;
		pre = _pre;
	}
};

class maze
{
public:
	maze();
	~maze();
private:
	//maze situation
	char table[SIZE][SIZE];
	char solution[SIZE][SIZE];
	char block[SIZE][SIZE];
	

	//stack
	stack<point> detect;
	stack<point> detected;
	stack<point> path;

	//direction
	int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};

	//funtion
	bool findSolution();
	bool findPath(point p);
	void printSolution();
	void print()
	{
		cout << "��\\��\t��1��\t��2��\t��3��\t��4��\t��5��\t��6��\t��7��" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << "��" << i + 1 << "��" << '\t';
			for (int j = 0; j < SIZE; j++)
			{
				cout << table[i][j] << '\t';
			}
			cout << endl;
		}
	}

};