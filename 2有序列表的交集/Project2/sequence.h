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

	//validity()��ȷ����1 ���󷵻�0
	bool validity();
	//���1������2�������� �д���>=1
	bool numberValidity(T x);
	bool orderValidity(list<T> x);
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
	
	bool flag = 1;
	while (flag)
	{
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

		//����Ƿ���ȷ
		flag=1-validity();
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

	while (true)
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

template<typename T>
bool intersect<T>::validity()
{
	int validity = 0;
	validity += orderValidity(a);
	validity += orderValidity(b);
	//��ȷ
	if (validity == 0)
	{
		return 1;
	}
	//����
	else
	{
		cout << "�����������������롣" << endl << endl;
		return 0;
	}
}

template<typename T>
bool intersect<T>::numberValidity(T x)
{
	if (x <= 0)return 1;
	else return 0;
}

template<typename T>
bool intersect<T>::orderValidity(list<T> x)
{
	auto p1 = x.begin();
	auto p2 = p1++;
	while (p1!=x.end())
	{
		//numberValidity
		if (numberValidity(*p1))
		{
			return 1;
		}

		if (*p1 <= *p2)
		{
			p1++;
			p2++;
			continue;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}