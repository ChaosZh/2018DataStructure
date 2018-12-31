#include "web.h"



Web::Web()
{
	construction();
}


Web::~Web()
{
}

void Web::construction()
{
	char input;
	bool flag = 1;
	
	while (flag)
	{
		cout << endl << "��ѡ�������";
		cin >> input;

		switch (input)
		{
			//���붥����Ϣ
			case'A':
				cout << "�����붥��ĸ�����";
				cin >> n;
				cout << "�������������������ƣ�" << endl;
				char _name;
				for (int i = 0; i < n; i++)
				{
					cin >> _name;
					Point.push_back(_name);
				}
				break;

			//���붥��ıߵ���Ϣ
			case'B':
				cout << "���붥��ͱߵ���Ϣ����Ҫ��ֹ���룬����? ? 0" << endl;
				while (true)
				{
					char a, b;
					int l;
					cout << "�������������㼰�ߣ�";
					cin >> a >> b >> l;
					
					if (a == '?'&&b == '?'&&l == 0)
					{
						cout << "�ߵ���Ϣ������ɡ�" << endl;
						break;
					}
					else
					{
						point* A = findPoint(a);
						A->attach(edge(a, b, l));
						point* B = findPoint(b);
						B->attach(edge(b, a, l));
					}
				}
				break;

			//������ʼ���㲢����Prim��С������
			case'C':
				cout << "��������ʼ���㣺";
				char start;
				cin >> start;
				buildTree(start);
				cout << "����Prim��С��������" << endl;
				break;
			//��ʾ��С������
			case'D':
				showTree();
				break;
			//�˳�����
			case'E':
				flag = 0;
				break;
		}
	}
}

point* Web::findPoint(char x)
{
	auto i = Point.begin();
	for (i; i != Point.end(); i++)
	{
		if (i->name == x)
		{
			point* RETURN = &(*i);
			return RETURN;
		}
	}
	assert("WRONG!������findPoint()������һ����ָ�룡");
	return nullptr;
}

edge* Web::findEdge(point* x, char anotherP)
{
	edge* e = x->bro;
	while (e)
	{
		if (e->target == anotherP)
		{
			return e;
		}
		else
		{
			e = e->bro;
		}
	}

	assert("WRONG!������findEdge()������һ����ָ�룡");
	return nullptr;
}

void Web::buildTree(char start)
{
	point* x = findPoint(start);
	attachedPoint.push_back(x);

	while (attachedPoint.size() < n)
	{
		//���attachedPoint�����ҳ�Ŀǰ����̱�
		//����̱������ӵĵ��ټ���attachedPoint����������������Ϣ¼�뵽Tree
		auto i = attachedPoint.begin();
		edge* minEdge = (*i)->bro;
		
		//�ҳ�attached����̱�
		for (i; i != attachedPoint.end(); i++)
		{

			edge* rival = (*i)->bro;
			while (rival != nullptr)
			{
				//�����ı�-1ʹ�ù�2��·-�������һ�����ǲ���attachPoint�������ж�
				if (isAttachedPoint(rival->target))continue;
				//���minEdge
				if (rival->l < minEdge->l)
				{
					minEdge = rival;
				}
				//����ĳ�������һ���ߣ�
				rival = rival->bro;
			}
		}

		//attachedPoint��ʹ�ù��ıߡ�����������
		point* newPoint = findPoint(minEdge->target);
		attachedPoint.push_back(newPoint);

		//minEdge->used = 1;
		//findEdge(newPoint, minEdge->self)->used = 1;
		tree.push_back(minEdge);
	}
}

bool Web::isAttachedPoint(char name)
{
	auto i = attachedPoint.begin();
	while (i != attachedPoint.end())
	{
		if ((*i)->name == name)
		{
			return true;
		}
		i++;
	}
	return false;
}

void Web::showTree()
{
	cout << "��С�������Ķ��㼰��Ϊ��" << endl;
	auto x = tree.begin();
	for (x; x != tree.end(); x++)
	{
		cout << (*x)->self <<"-<"<< (*x)->l <<">->"<< (*x)->target;
		cout << '\t';
	}
	cout << endl;
}