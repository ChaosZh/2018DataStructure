#ifndef _MAZE_H_
#define _MAZE_H_

#include "maze.h"

maze::maze()
{
	cout << "����7*7���Թ���ͼ����������������ݵ��ļ�����";
	string fstr;
	cin >> fstr;
	ifstream in("../Test/"+fstr+".txt");
	if (in.is_open())
	{
		char temp;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (in >> temp)table[i][j] = block[i][j] = temp;
			}
		}
	}
	in.close();

	print();
	cout << "��ͼ������ϣ�Ĭ�����Ϊ(1,1)���յ�Ϊ(7,7)��" << endl << endl;

	if (findSolution())
	{
		printSolution();
	}
	else
	{
		cout << "���Թ��޽⡣" << endl << endl;
	}
}

maze::~maze()
{

}

bool maze::findSolution()
{
	return findPath(point(0, 0));
}

bool maze::findPath(point p)
{
	int x = p.row;
	int y = p.col;
	//��ǰλ������Ϊ�Ѽ���
	block[x][y] = '0';

	for (int t = 0; t < 4; t++)
	{
		int _x = x + dir[t][0];
		int _y = y + dir[t][1];

		if (!(0 <= _x && _x <= SIZE - 1 && 0 <= _y && _y <= SIZE - 1))continue;
		else if (table[_x][_y] == '0' || block[_x][_y] == '0')continue;
		else if (_x == SIZE - 1 && _y == SIZE - 1)
		{
			path.push(point(_x, _y));
			path.push(point(x, y));
			return true;
		}
		else if (findPath(point(_x, _y)))	//�ݹ�����findPath()
		{
			path.push(point(x, y));
			return true;
		}
	}
	return false;
}

void maze::printSolution()
{
	cout << "���ɽⷨ·�����£�" << endl;
	point p(-1,-1);
	do
	{
		p = path.top();
		path.pop();
		table[p.row][p.col] = 'X';
		cout << '(' << p.row << ',' << p.col << ')' << "--->";
	} while (p.row != SIZE-1 || p.col != SIZE-1);

	cout << "END" << endl << endl;


	print();
}

#endif