#include "Family.h"

Family::Family()
{
	Begin();
	Struction();

}


Family::~Family()
{
}


void Family::Begin()
{
	cout << "**               ���׹���ϵͳ                  **" << endl;
	cout << "=================================================" << endl;
	cout << "**             ��ѡ��Ҫִ�еĲ�����            **" << endl;
	cout << "**             A --- ���Ƽ���                  **" << endl;
	cout << "**             B --- ��Ӽ�ͥ��Ա              **" << endl;
	cout << "**             C --- ��ɢ�ֲ���ͥ              **" << endl;
	cout << "**             D --- ���ļ�ͥ��Ա����          **" << endl;
	cout << "**             E --- �˳�����                  **" << endl;

	string name;
	cout << "���Ƚ���һ�����ף�" << endl;
	cout << "���������ȵ�������";
	cin >> name;
	Member*tree = new Member(name);
	forest.push_back(tree);
	cout << "�˼��׵������ǣ�" << name << endl << endl;
}

void Family::Struction()
{
	char order;

	while (true)
	{
		cout << "��ѡ��Ҫִ�еĲ�����";
		cin >> order;

		if (order == 'A')
		{
			string name;
			cout << "������Ҫ������ͥ���˵�������";
			cin >> name;
			Member* father = find(name);
			bool flagnew = 0;
			if (father == nullptr)
			{
				flagnew = 1;
				father = new Member(name);
			}
			int number;
			cout << "������" << name << "�Ķ�Ů������";
			cin >> number;
			cout << "����������P0�Ķ�Ů��������";
			for (int i = 0; i < number; i++)
			{
				string childname;
				cin >> childname;
				Member* child = new Member(childname);
				father->appendChild(child);
			}
			if (flagnew == 1)forest.push_back(father);
			cout << name << "�ĵ�һ�������ǣ�";
			Member*ptr = father->child;
			while (ptr!=nullptr)
			{
				cout << ptr->name << " ";
				ptr = ptr->neighbor;
			}
			cout << endl << endl;
		}
		else if (order == 'B')
		{

		}
		else if (order == 'C')
		{

		}
		else if (order == 'D')
		{

		}
		else if (order == 'E')
		{
			break;
		}
		else
		{
			cout << "�Ҳ�����ִ�еĲ��������������롣" << endl << endl;
		}
	}
}

Member* Family::find(string name)
{
	vector<Member*>::iterator iter = forest.begin();
	while (iter != forest.end())
	{
		//����ͷ
		if ((*iter)->name == name)
		{
			return *iter;
		}
		//������Ů
		else
		{
			Member* ptr = (*iter)->child;
			while (ptr != nullptr)
			{
				//�����Լ�
				if (ptr->name == name)return ptr;
				//�����ھ�
				else
				{
					                                                                                                 
				}
			}
		}
		iter++;
	}
	return nullptr;
}