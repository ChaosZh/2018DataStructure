#include "ExamSystem.h"

using namespace std;

int menu();
Member create();
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
	ExamSystem system;
	
	//initial the system
	int number;
	cout << "�����뽨��������Ϣϵͳ��\n"
		<< "�����뿼������:";
	cin >> number;
	cout << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����䣬���������\n";
	for (int i = 0; i < number; i++)
	{
		Member newNode = create();
		system.Insert(newNode);
	}

	//construction
	bool flag = 1;
	while (flag)
	{
		int Construction = menu();
		switch (Construction)
		{
		case(CANCEL):
			flag = 0;
			break;
		case(INSERT):
			int pos;
			cout << "��������Ҫ����Ŀ�����λ�ã�";
			cin >> pos;
			cout << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����䣬���������\n";
			system.Insert(create());
			break;
		case(DELETE):
			int candidate_number;
			cout << "������Ҫɾ���Ŀ����Ŀ��ţ�";
			cin >> candidate_number;
			system.Delete(candidate_number);
			break;
		case(SEARCH):
			int candidate_number2;
			cout << "������Ҫ���ҵĿ����Ŀ��ţ�";
			cin >> candidate_number2;
			cout << "����\t����\t�Ա�\t����\t�������\t\n";
			system.print_stu_ifo(system.Find(candidate_number2));
			break;
		case(CALCULATE):
			system.print_all();
			break;
		case(MODIFY):
			int candidate_number3;
			cout << "������Ҫ�޸ĵĿ����Ŀ��ţ�";
			cin >> candidate_number3;
			cout << "����������Ҫ�޸ĵĿ����Ŀ��ţ��������Ա����䣬���������\n";
			Member* newNode = &create();
			system.Modify(candidate_number3, newNode);
			break;
		}
	}

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

Member create()
{
	int number;
	string name;
	string sex;
	int age;
	string occupation;

	cin >> number >> name >> sex >> age >> occupation;

	Member newNode = Member(number, name, sex, age, occupation);

	return newNode;
}