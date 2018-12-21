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
			cout << "����������" << name << "�Ķ�Ů��������";
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
			string fatherName;
			cout << "������Ҫ��ӵĶ��ӣ���Ů�������˵�������";
			cin >> fatherName;
			Member* father = find(fatherName);
			string childName;
			cout << "������" << fatherName << "����ӵĶ��ӣ���Ů������������";
			cin >> childName;
			Member* child = new Member(childName);
			father->appendChild(child);
			cout << fatherName << "�ĵ�һ�������ǣ�";
			child = father->child;
			while (child != nullptr)
			{
				cout << child->name;
				child = child->neighbor;
			}
			cout << endl << endl << endl;
		}
		else if (order == 'C')
		{
			string fatherName;
			cout << "������Ҫ��ɢ��ͥ���˵�������";
			cin >> fatherName;
			cout << "Ҫ��ɢ��ͥ�����ǣ�" << fatherName << endl;
			Member* fatherUpper = findUpper(fatherName);
			if (fatherUpper->child->name == fatherName)
			{
				deleteMember(fatherUpper->child);
				fatherUpper->child == nullptr;
			}
			else if (fatherUpper->neighbor->name == fatherName)
			{
				deleteMember(fatherUpper->neighbor);
				fatherUpper->neighbor == nullptr;
			}

		}
		else if (order == 'D')
		{
			string name;
			string nameAlter;
			cout << "������Ҫ�����������˵�Ŀǰ������";
			cin >> name;
			cin >> nameAlter;
			find(name)->name = nameAlter;
			cout << name << "�Ѹ���Ϊ" << nameAlter << endl << endl;
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
		stack<Member*> node;
		node.push(*iter);
		while (node.size() != 0)
		{
			Member* ptr = node.top();
			node.pop();
			//judge ptr
			if (ptr->name == name)
			{
				return ptr;
			}
			//update stack
			if (ptr->child != nullptr)node.push(ptr->child);
			if (ptr->neighbor != nullptr)node.push(ptr->neighbor);
		}
	}
	return nullptr;
}

Member* Family::findUpper(string name)
{
	vector<Member*>::iterator iter = forest.begin();
	while (iter != forest.end())
	{
		stack<Member*> node;
		node.push(*iter);
		while (node.size() != 0)
		{
			Member* ptr = node.top();
			node.pop();
			//judge ptr
			if (ptr->child->name == name || ptr->neighbor->name == name)
			{
				return ptr;
			}
			//update stack
			if (ptr->child != nullptr)node.push(ptr->child);
			if (ptr->neighbor != nullptr)node.push(ptr->neighbor);
		}
	}
	return nullptr;
}

void Family::deleteMember(Member* m)
{
	//Member*iter = m;
	//stack<Member*> node;
	//node.push(iter);
	//while (node.size() != 0)
	//{
	//	Member* ptr = node.top();
	//	//judge ptr
	//	if (ptr->child == nullptr && ptr->neighbor == nullptr)
	//	{
	//		delete ptr;
	//	}
	//	else
	//	{
	//		//update stack
	//		if (ptr->child != nullptr)node.push(ptr->child);
	//		if (ptr->neighbor != nullptr)node.push(ptr->neighbor);
	//	}
	//}
}