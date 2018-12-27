#include "ExamSystem.h"

using namespace std;

int menu();
Member* create();
enum 
{
	CANCEL,		//ȡ������
	INSERT,		//����
	DELETE,		//ɾ��
	SEARCH,		//����
	MODIFY,		//�޸�
	CALCULATE	//ͳ��
};

int main()
{
	ExamSystem System;

	//initial the system
	int number;
	cout << "�����뽨��������Ϣϵͳ��\n"
		<< "�����뿼������:";
	cin >> number;
	cout << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����䣬���������\n";
	for (int i = 0; i < number; i++)
	{
		Member* newNode = create();
		System.Insert(newNode, i);
	}

	//construction
	bool flag = 1;
	while (flag)
	{
		int Construction = menu();
		switch (Construction)
		{
		case(CANCEL):
		{
			cout << "��лʹ�ñ�ϵͳ��";
			flag = 0;
			break;
		}
		case(INSERT):
		{
			int number;
			cout << "��������Ҫ����Ŀ�����λ�ã�";
			cin >> number;
			cout << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����䣬���������\n";
			Member* temp = create();
			System.Insert(temp, number - 1);
			break;
		}
		case(DELETE):
		{
			int candidate_number;
			cout << "������Ҫɾ���Ŀ����Ŀ��ţ�";
			cin >> candidate_number;
			System.Delete(candidate_number);
			break;
		}
		case(SEARCH):
		{
			int candidate_number;
			cout << "������Ҫ���ҵĿ����Ŀ��ţ�";
			cin >> candidate_number;
			cout << "����\t����\t�Ա�\t����\t�������\t\n";
			System.print_stu_ifo(System.Find(candidate_number));
			break;
		}
		case(CALCULATE):
		{
			System.print_all();
			break;
		}
		case(MODIFY):
		{
			int candidate_number3;
			cout << "������Ҫ�޸ĵĿ����Ŀ��ţ�";
			cin >> candidate_number3;
			cout << "����������Ҫ�޸ĵĿ����Ŀ��ţ��������Ա����䣬���������\n";
			Member* newNode = create();
			System.Modify(candidate_number3, newNode);
			break;
		}
		}
	}

	system("pause");
	return 0;
}

int menu()
{
	cout << "��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������\n";
	cout << "��ѡ����Ҫ���еĲ�����";
	int s;
	cin >> s;
	return s;
}

Member* create()
{
	int number;
	string name;
	string sex;
	int age;
	string occupation;

	cin >> number >> name >> sex >> age >> occupation;

	Member* newNode = new Member(number,name,sex,age,occupation);

	//��ʽ���
	bool isAccurate = 1;
	if (sex != "��"&&sex != "Ů")
	{
		isAccurate = 0;
		cout << "����ѧ���Ա���Ϣ�����ʽ����\n";
		cout << newNode->number << '\t'
			<< newNode->name << '\t'
			<< newNode->sex << '\t'
			<< newNode->age << '\t'
			<< newNode->occupation << '\n';
	}

	if (!isAccurate)return nullptr;
	else return newNode;
}