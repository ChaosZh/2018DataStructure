#pragma once

#include<iostream>
#include<vector>
using namespace std;

class Wood
{
public:
	Wood();
	~Wood();

	//����
	void firstSort();
	//����
	void calculate();
	//�����½ڵ�
	void insert(int i);

private:
	int n;
	int money = 0;
	vector<int> node;
};

