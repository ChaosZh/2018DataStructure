#include "Wood.h"



Wood::Wood()
{
	cout << "ľͷ��Ҫ����ɼ��飿��";
	cin >> n;
	cout << "����ÿ��ľͷ�ĳ��ȣ��ո���ָ����س����������룩��" << endl;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		node.push_back(temp);
	}
	firstSort();
	calculate();

	cout << "��ľͷ���" << n << "�����С������" << money << "Ԫ��" << endl;
}

void Wood::calculate()
{
	while (true)
	{	
		auto a = node.begin();
		auto b = node.begin() + 1;
		if (b == node.end())break;

		int newNode = *a + *b;
		money += newNode;
		node.erase(node.begin());
		node.erase(node.begin());
		insert(newNode);

	}
}

void Wood::firstSort()
{
	int a = 0;
	for (a; a < node.size() - 1; a++)
	{
		for (auto point = node.begin(); point != node.end() - a - 1; point++)
		{
			auto point_after = point + 1;
			int temp;
			//��С��������
			if (*point > *point_after)
			{
				temp = *point_after;
				*point_after = *point;
				*point = temp;
			}
		}
	}

}

void Wood::insert(int i)
{
	auto a = node.begin();
	while (true)
	{
		if (a == node.end())
		{
			node.insert(a, i);
			break;
		}
		else if (*a > i)
		{
			node.insert(a,i);
			break;
		}
		else
		{
			a++;
		}
	}
}

Wood::~Wood()
{
}
