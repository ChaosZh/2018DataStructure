#include "ExamSystem.h"



ExamSystem::ExamSystem()
{
	first = new Member();
}

ExamSystem::~ExamSystem()
{
	Member* iter = first;
	while (iter->next)
	{
		Member* del = iter;
		iter = iter->next;
		delete del;
	}
	delete iter;

	return;
}

/*********/
/*��Ӳ���*/
/*********/
void ExamSystem::Insert(Member* newNode, int pos)
{
	//�����Ϣ������� newNodeΪ��
	if (!newNode)return;

	//�����Ŀ��Ų������ظ�
	//apointed position is out of range
	if (pos > total || pos < 0)
	{
		cout << "���󣡲��뿼����λ�ó�����Χ��";
		return;
	}

	//����
	///����ڵ�һ��Ԫ�ص�λ�ò���
	if (pos == 0)
	{
		newNode->next = first->next;
		first->next = newNode;
	}
	///��ĩβλ�ò���
	else if (pos == total)
	{
		Member* pre = find(pos - 1);
		pre->next = newNode;
	}
	///���м����
	else
	{
		Member* pre = find(pos - 1);
		newNode->next = pre->next;
		pre->next = newNode;
	}

	//change the total number
	total++;

	return;
}

/*********/
/*ɾ������*/
/*********/
void ExamSystem::Delete(int candidate_number)
{
	Member* preDel = find_pre_withNUMBER(candidate_number);
	Member* del = preDel->next;
	preDel->next = del->next;
	
	//CARVEAT!!!
	cout << "��ɾ���Ŀ�����Ϣ�ǣ�";
	print_stu_ifo(del);
	
	delete del;

	//change the total number
	total--;
	return;
}

void ExamSystem::Delete(string name)
{
	Member* preDel = find_pre_withNAME(name);
	Member* del = preDel->next;
	preDel->next = del->next;
	delete del;

	//change the total number
	total--;
	return;

}

/*********/
/*���Ҳ���*/
/*********/
Member* ExamSystem::Find(int candidate_number)
{
	//point to ZERO
	Member* iter = first;
	while (iter->next)
	{
		iter = iter->next;
		if (iter->number == candidate_number)
		{
			return iter;
		}
	}
	cout << "����δ�ҵ�ָ�����ŵĿ�����";
	return nullptr;
}

Member* ExamSystem::Find(string name)
{
	//point to ZERO
	Member* iter = first;
	while (iter->next)
	{
		iter = iter->next;
		if (iter->name == name)
		{
			return iter;
		}
	}
	cout << "����δ�ҵ�ָ�����ƵĿ�����";
	return nullptr;
}


/*********/
/*�޸Ĳ���*/
/*********/
void ExamSystem::Modify(int candidate_number, Member* newNode)
{
	Member* pre = find_pre_withNUMBER(candidate_number);
	Member* target = pre->next;
	pre->next = newNode;
	newNode->next = target->next;
	delete target;

	return;
}

/***********************/
/*���ָ��/ȫ��ѧ������Ϣ*/
/***********************/
void ExamSystem::print_stu_ifo(Member* p)
{
	cout << p->number << '\t'
		<< p->name << '\t'
		<< p->sex << '\t'
		<< p->age << '\t'
		<< p->occupation << '\n';
	return;
}

void ExamSystem::print_all()
{
	cout << "����\t����\t�Ա�\t����\t�������\t\n";
	
	Member* iter = first;
	while (iter->next)
	{
		iter = iter->next;
		print_stu_ifo(iter);
	}

	return;
}

/////////////////////////////////////////////////////////////
///////////////////////�ڲ����õĺ���/////////////////////////
/////////////////////////////////////////////////////////////



/******************/
/*�ҵ�ָ����ŵ�ѧ��*/
/******************/
Member* ExamSystem::find(int pos)
{
	//�ų�����Χ �����ų�������������total==0��
	if (pos >= total || pos < 0)
	{
		cout << "����ָ����ų�����Χ��";
		return nullptr;
	}
	
	//ָ���һ��Ԫ��
	Member* iter = first->next;
	int seq = 0;
	while (seq!=pos)
	{
		seq++;
		iter = iter->next;
	}
	return iter;
}


/***************************/
/*�ҵ�ָ������/ѧ�ŵ�ѧ����ǰһ����*/
/***************************/
Member* ExamSystem::find_pre_withNAME(string name)
{
	//point to ZERO
	Member* iter = first;
	Member* iter_pre;
	while (iter->next)
	{
		iter_pre = iter;
		iter = iter->next;
		if (iter->name == name)
		{
			return iter_pre;
		}
	}
	cout << "����δ�ҵ�ָ�����ƵĿ�����";
	return nullptr;
}

Member* ExamSystem::find_pre_withNUMBER(int number)
{
	//point to ZERO
	Member* iter = first;
	Member* iter_pre;
	while (iter->next)
	{
		iter_pre = iter;
		iter = iter->next;
		if (iter->number == number)
		{
			return iter_pre;
		}
	}
	cout << "����δ�ҵ�ָ�����ƵĿ�����";
	return nullptr;
}
