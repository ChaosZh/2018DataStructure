#include "Family.h"

Family::Family()
{
	Begin();
	Struction();

}

Family::~Family()
{
	deleteAll();
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
			if (father == nullptr)
			{
				father = new Member(name);
				forest.push_back(father);
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
			Member* child = findTree(childName);
			if (child == nullptr)child = new Member(childName);
			father->appendChild(child);
			cout << fatherName << "�ĵ�һ�������ǣ�";
			child = father->child;
			while (child != nullptr)
			{
				cout << child->name << ' ';
				child = child->neighbor;
			}
			cout << endl << endl << endl;
		}
		else if (order == 'C')
		{
			string fatherName;
			cout << "������Ҫ��ɢ��ͥ���˵�������";
			cin >> fatherName;
			cout << "Ҫ��ɢ��ͥ�����ǣ�" << fatherName << endl << endl;
			Member* father = find(fatherName);
			deleteMember(father);
		}
		else if (order == 'D')
		{
			string name;
			string nameAlter;
			cout << "������Ҫ�����������˵�Ŀǰ������";
			cin >> name;
			cout << "��������ĺ��������";
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
		iter++;
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
		iter++;
	}
	return nullptr;
}

Member* Family::findUpper(Member* member)
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
			if (ptr->child == member || ptr->neighbor == member)
			{
				return ptr;
			}
			//update stack
			if (ptr->child != nullptr)node.push(ptr->child);
			if (ptr->neighbor != nullptr)node.push(ptr->neighbor);
		}
		iter++;
	}
	return nullptr;
}

Member* Family::findTree(string name)
{
	vector<Member*>::iterator iter = forest.begin();
	while (iter != forest.end())
	{
		if ((*iter)->name == name)
		{
			Member* temp = *iter;
			forest.erase(iter);
			return temp;
		}
		iter++;
	}
	return nullptr;
}

void Family::deleteAll()
{
	vector<Member*>::iterator iter = forest.begin();
	while (iter != forest.end())
	{
		deleteMember(*iter);
		iter++;
	}
}

void Family::deleteMember(Member* member)
{
	Member*m = member;
	Member* upperNode = findUpper(member);
	if (upperNode != nullptr)
	{
		if (upperNode->child == member)upperNode->child = member->neighbor;
		else if (upperNode->neighbor == member)upperNode->neighbor = member->neighbor;
		member->neighbor = nullptr;
	}
	stack<Member*> node;
	node.push(m);
	while (node.size() != 0)
	{
		Member* ptr = node.top();
		node.pop();
		//judge ptr
		if (ptr->child != nullptr)
		{
			node.push(ptr->child);
		}
		if (ptr->neighbor != nullptr)
		{
			node.push(ptr->neighbor);
		}
		delete(ptr);
	}
}