#include "Sort.h"



Sort::Sort()
{
	instruct();

	int i;
	cout << "������Ҫ������������ĸ�����";
	cin >> i;
	datalist = Datalist(i);
	datalist.showDatalist();	//debug

	bool flag = true;
	while (flag)
	{
		char Choice = choice();
		switch (Choice) 
		{
		case '1':	//bubble
		{
			
			break;
		}
		case '2':	//
		{

		}
		case '3':	//insertionSort
		{
			Datalist* p= &insertionSort(datalist);
			cout << endl << "Address=" << p << " RETURN " << endl;

			p->showDatalist();
			cout << endl;
			datalist.showDatalist();
			break;
		}
		case '4':
		{

		}
		case '5':
		{

		}
		case '6':
		{

		}
		case '7':
		{

		}
		case '8':
		{

		}
		case '9':
		{
			flag = false;
		}
		}
	}
}


Sort::~Sort()
{
}

Datalist Sort::bubbleSort(const Datalist& List)
{
	Datalist list;
	list = List;

	return list;
}

Datalist Sort::insertionSort(const Datalist& List)
{
	Datalist list = List;
	for (int t = 1; t < list.total; t++)
	{
		int temp = list[t];
		int i = t - 1;
		while (temp < list[i] && i >= 0)
		{
			list[i + 1] = list[i];
			i--;
		}
		list[i + 1] = temp;
	}
	return list;
}

void Sort::instruct()
{
	cout << "**            �����㷨�Ƚ�              **" << endl;
	cout << "==========================================" << endl;
	cout << "**            1 --- ð������            **" << endl;
	cout << "**            2 --- ѡ������            **" << endl;
	cout << "**            3 --- ֱ�Ӳ�������        **" << endl;
	cout << "**            4 --- ϣ������            **" << endl;
	cout << "**            5 --- ��������            **" << endl;
	cout << "**            6 --- ������              **" << endl;
	cout << "**            7 --- �鲢����            **" << endl;
	cout << "**            8 --- ��������            **" << endl;
	cout << "**            9 --- �˳�����            **" << endl << endl;
}

char Sort::choice()
{
	char in;
	cout << endl << "��ѡ�������㷨��";
	cin >> in;
	return in;
}