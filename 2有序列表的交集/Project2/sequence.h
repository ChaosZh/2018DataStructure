#pragma once

#include <iostream>
#include <list>
using namespace std;

template<typename T>
class intersect
{
public:
	intersect();
	~intersect();

	void findIntersection();
	void print();
private:
	list<T>a, b, c;
};





/******************************/
/******************************/
/*         Defination         */
/******************************/
/******************************/

template<typename T>
intersect<T>::intersect()
{
	int input;
	cout << "��������a�����ݣ��ո����������Ԫ�أ�����-1��������" << endl;

	while (cin >> input && input!=-1)
	{
		a.push_back(input);
	}
	cout << "��������b�����ݣ��ո����������Ԫ�أ����س�����������" << endl;
	while (cin >> input && input != -1)
	{
		b.push_back(input);
	}

	findIntersection();
	print();
}

template<typename T>
intersect<T>::~intersect()
{

}

template<typename T>
void intersect<T>::findIntersection()
{
	if (a.size() == 0 || b.size() == 0)return;
	auto iterA = a.begin();
	auto iterB = b.begin();

	//flag==0 continue
	//flag==1 running out of a
	//flag==2 running out of b
	int flag = 0;
	while (flag == 0)
	{
		int A = *iterA;
		int B = *iterB;

		if (A < B)iterA++;
		else if (A > B)iterB++;
		else if (A == B)
		{
			c.push_back(A);
			iterA++;
			iterB++;
		}
		
		//break conditions
		if (iterA == a.end() || iterB == b.end())
		{
			break;
		}
	}
}

template<typename T>
void intersect<T>::print()
{
	cout << endl << "�����еĽ���Ϊ��" << endl;
	auto iter = c.begin();
	if (c.size()==0)cout << "NULL";
	else
	{
		cout << *iter;
		iter++;
	}
	while (iter != c.end())
	{
		cout << ' ' << *iter;
		iter++;
	}
	cout << endl;
}