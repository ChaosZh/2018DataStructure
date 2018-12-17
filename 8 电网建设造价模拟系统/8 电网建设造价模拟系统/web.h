#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

struct edge
{
	char self;
	char target;
	int l;
	bool used = 0;//ʹ�ù�==1/δʹ�ù�==0
	edge* bro = nullptr;

	//���캯��
	edge(char _self, char _target, int _l)
	{
		self = _self;
		target = _target;
		l = _l;
	}
};

struct point
{
	char name;
	edge* bro = nullptr;

	//���캯��
	point(char _name)
	{
		name = _name;
	}

	//�����������صı�
	void attach(edge e)
	{
		edge* pointer = bro;
		if (!pointer)
		{
			bro = &e;
			return;
		}
		while (true)
		{
			//bro��Ϊ�գ���ѭ��ֱ��broΪ�գ�����bro��ĩβ�����e������ѭ����
			if (pointer->bro)
			{
				pointer = pointer->bro;
			}
			else
			{
				pointer->bro = &e;
				return;
			}
		}
	}

};

//struct stick
//{
//	char a, b;
//	int length;
//
//	//���캯��
//	stick(char _a, char _b, int _length)
//	{
//		a = _a;
//		b = _b;
//		length = _length;
//	}
//};

class Web
{
public:
	Web();
	~Web();

	void construction();

	point* findPoint(char x);
	edge* findEdge(point* x, char anotherP);

	//������С������
	void buildTree(char start);

	//չʾ��С������
	void showTree();

private:
	int n;
	vector<point> Point;
	vector<point*> attachedPoint;
	
	//������
	vector<edge*> tree;
};

