#include "bank.h"



bank::bank()
{
	cout << "�������ҵ���������";
	cin >> n;
	cout << "�������ҵ��Ķ��У�";
	
	//����AB���ڵĶ���
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp % 2 == 1)
		{
			A.push_back(temp);
		}
		else
		{
			B.push_back(temp);
		}
	}
	cout << "�������������" << endl;

	cout << "����ҵ���˳��Ϊ��";
	//�������ҵ��˳��
	auto iterA = A.begin();
	auto iterB = B.begin();
	//��AB�����ж���Ϊ��
	int flag = 0;//1A 2B
	while (true)
	{
		if (iterA == A.end())
		{
			if (iterB == B.end())
			{
				flag = 0;
				break;
			}
			else
			{
				flag = 2;
				break;
			}
		}
		if (iterB == B.end())
		{
			flag = 1;
			break;
		}
		cout << *iterA << ' ';
		iterA++;
		if (iterA == A.end())
		{
			flag = 2;
			break;
		}
		cout << *iterA << ' ';
		cout << *iterB << ' ';

		iterA++;
		iterB++;
	}
	if (flag == 1)
	{
		while (*iterA != A.back())
		{
			cout << *iterA << ' ';
			iterA++;
		}
		cout << *iterA;
	}
	else if (flag == 2)
	{
		while (*iterB != B.back())
		{
			cout << *iterB << ' ';
			iterB++;
		}
		cout << *iterB;
	}
	cout << endl;
}


bank::~bank()
{
}
