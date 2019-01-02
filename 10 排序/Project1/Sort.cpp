#include "Sort.h"



Sort::Sort()
{
	instruct();

	int i;
	cout << "������Ҫ������������ĸ�����";
	cin >> i;
	datalist = Datalist(i);
	//datalist.showDatalist();	//debug

	bool flag = true;
	while (flag)
	{
		Datalist list;
		list = datalist;
		char Choice = choice();

		float timeBegin = clock();
		unsigned long long exchangeCount = 0;
		switch (Choice) 
		{
		case '1':	//bubbleSort
		{
			bubbleSort(list, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "ð����������ʱ�䣺\t" << duration << "ms" << endl;
			cout << "ð�����򽻻�������\t" << exchangeCount << endl;
			break;
		}
		case '2':	//selectSort
		{
			selectSort(list, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "ѡ����������ʱ�䣺\t" << duration << "ms" << endl;
			cout << "ѡ�����򽻻�������\t" << exchangeCount << endl;
			break;
		}
		case '3':	//insertionSort
		{
			insertionSort(list, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "ֱ�Ӳ�����������ʱ�䣺\t" << duration << "ms" << endl;
			cout << "ֱ�Ӳ������򽻻�������\t" << exchangeCount << endl;
			break;
		}
		case '4':	//shellSort
		{
			shellSort(list, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "ϣ����������ʱ�䣺\t" << duration << "ms" << endl;
			cout << "ϣ�����򽻻�������\t" << exchangeCount << endl;
			break;
		}
		case '5':	//quickSort
		{
			quickSort(list, 0, list.total - 1, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "������������ʱ�䣺\t" << duration << "ms" << endl;
			cout << "�������򽻻�������\t" << exchangeCount << endl;
			break;
		}
		case '6':	//heapSort
		{
			heapSort(list, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "����������ʱ�䣺\t" << duration << "ms" << endl;
			cout << "�����򽻻�������\t" << exchangeCount << endl;
			break;
		}
		case '7':	//mergeSort
		{
			mergeSort(list, exchangeCount);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "�鲢��������ʱ�䣺\t" << duration << "ms" << endl;
			cout << "�鲢���򽻻�������\t" << exchangeCount << endl;
			break;
		}
		case '8':	//radixSort
		{
			radixSort(list);
			float timeEnd = clock();
			float duration = timeEnd - timeBegin;
			cout << "������������ʱ�䣺\t" << duration << "ms" << endl;
			cout << "�������򽻻�������\t" << exchangeCount << endl;
			break;
		}
		case '9':
		{
			flag = false;
		}
		}

		//list.showDatalist();
		cout << endl;
		//datalist.showDatalist();
	}
}

Sort::~Sort()
{
}

void Sort::bubbleSort(Datalist& list, unsigned long long& t)
{
	for (int i = 0; i < list.total - 1; i++)
	{
		for (int j = 0; j < list.total - i - 1; j++)
		{
			if (list[j] > list[j + 1])
			{
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
				t+=3;
			}
		}
	}
}

void Sort::selectSort(Datalist& list, unsigned long long& t)
{
	for (int i = 0; i < list.total - 1; i++)
	{
		int min_index = i;
		for (int j = i; j < list.total; j++)
		{
			if (list[min_index] > list[j])
			{
				min_index = j;
				t++;
			}
		}
		int temp = list[i];
		list[i] = list[min_index];
		list[min_index] = temp;
		t+=3;
	}
}

void Sort::insertionSort(Datalist& list, unsigned long long& time)
{
	for (int t = 1; t < list.total; t++)
	{
		int temp = list[t];
		int i = t - 1;
		while (temp < list[i] && i>=0)
		{
			list[i + 1] = list[i];
			time++;
			i--;
		}
		list[i + 1] = temp;
		time++;
	}
}

void Sort::shellSort(Datalist& list, unsigned long long& time)
{
	int gap = 7;
	while (gap >= 1)
	{
		//gap==Nʱ�ļ��������ж��ź���
		int start = gap - 1;
		while (start >= 0)
		{
			for (int t = start + gap; t < list.total; t += gap)
			{
				int temp = list[t];
				int i = t - gap;
				while (temp < list[i] && i >= 0)
				{
					list[i + gap] = list[i];
					i -= gap;
					time++;
				}
				list[i + gap] = temp;
				time++;
			}
			start--;

			//debug
			//cout << "(gap,start)==" << gap << ',' << start << ": ";
			//list.showDatalist();
			//cout << endl;
		}
		if (gap == 1)
		{
			break;
		}
		gap /= 2;
	}
}

void Sort::quickSort(Datalist& list, int start, int end, unsigned long long& t)
{
	if (end <= start)
	{
		return;
	}
	else
	{
		int mid = start;
		for (int i = start; i <= end; i++)
		{
			if (list[i] < list[mid])
			{
				int temp = list[mid];
				list[mid] = list[i];
				list[i] = list[mid + 1];
				list[mid + 1] = temp;
				t += 3;
				mid++;
			}
		}
		quickSort(list, start, mid - 1, t);
		quickSort(list, mid + 1, end, t);
	}
}

/*heapSort*/

void Sort::heapSort(Datalist& list, unsigned long long& t)
{
	int i = 1;
	//�ҵ�������ڵ�
	while (i * 2 - 1 < list.total)
	{
		i *= 2;
	}
	i = i / 2 - 1;
	//��������
	while (i > -1)
	{
		heapAdjust(list, i, list.total, t);
		i--;
	}
	int size = list.total;
	//����
	while (size > 1)
	{
		swap(list[0], list[size - 1]);//list���һ�������
		size -= 1;
		heapAdjust(list, 0, size, t);
	}
}

void Sort::heapAdjust(Datalist& list, int i, int size, unsigned long long& t)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (right < size)
	{
		if (list[right] > list[i])
		{
			swap(list[i], list[right]);
			t++;
			heapAdjust(list, right, size, t);
		}
	}
	if (left < size)
	{
		if (list[left] > list[i])
		{
			swap(list[i], list[left]);
			t++;
			heapAdjust(list, left, size, t);
		}
	}
	return;
}


void Sort::mergeSort(Datalist& list, unsigned long long& t)
{
	int size = 1;
	while (size < list.total)//size
	{
		int first = 0;
		int second = 0 + size;
		while (first < list.total)//first second
		{
			//compare
			int a = first;
			int b = second;
			int* temp = new int[2 * size];
			int temp_i = 0;
			while (a < second&&b < second + size && b < list.total)//ab��Ϊ��
			{
				if (list[a] < list[b])
				{
					temp[temp_i] = list[a];
					temp_i++;
					a++;
					t++;
				}
				else
				{
					temp[temp_i] = list[b];
					temp_i++;
					b++;
					t++;
				}
			}
			while (a < second&&a < list.total)//a��Ϊ��
			{
				temp[temp_i] = list[a];
				temp_i++;
				a++;
			}
			while (b < second + size && b < list.total)//b��Ϊ��
			{
				temp[temp_i] = list[b];
				temp_i++;
				b++;
			}
			//copy
			int i = 0;
			int j = first;
			while (j < second + size && j < list.total)
			{
				list[j] = temp[i];
				i++;
				j++;
			}
			delete []temp;
			//next 2
			first += 2 * size;
			second += 2 * size;
		}
		size *= 2;
	}
}

/*radixSort*/

void Sort::radixSort(Datalist& list)
{
	int baseNum = findMaxBase(list);
	//listת��������first
	node* first = new node(list[0]);
	int i = 1;
	node* p = first;
	while (i <list.total)
	{
		p->next = new node(list[i]);
		p = p->next;
		i++;
	}
	//radixSort
	radixSort(first, baseNum);
	//����ת����list
	i = 0;
	p = first;
	while (p != nullptr && i < list.total)
	{
		list[i] = p->value;
		i++;
		p = p->next;
	}
}

int Sort::findMaxBase(Datalist& list)
{
	int max = 0;
	int i = 0;
	while (i < list.total)
	{
		if (max < list[i])
		{
			max = list[i];
		}
		i++;
	}
	
	int base = 10;
	while (max%base != max)
	{
		base *= 10;
	}
	base /= 10;
	return base;
}

void Sort::radixSort(node* &P, int baseNum)
{
	//���ݵ�ǰ��baseNum��������
	node* ptr = P;	//����ָ��
	node* bucket[10];
	for (int i = 0; i < 10; i++)
	{
		bucket[i] = new node(0);
	}

	while (ptr != nullptr)//�������� ���䵽bucket��
	{
		int key = (ptr->value / baseNum) % 10;
		node* p = bucket[key];
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new node(ptr->value);
		ptr = ptr->next;
	}

	//ɾ��ԭ����
	ptr = P;
	while (ptr != nullptr)
	{
		node* before = ptr;
		ptr = ptr->next;
		delete before;
	}

	//��10������ݹ�
	if (baseNum != 1)//�������λ
	{
		baseNum /= 10;
		for (int i = 0; i < 10; i++)
		{
			if (bucket[i]->next != nullptr)//��Ԫ�ص�Ͱ
			{
				radixSort(bucket[i]->next, baseNum);
			}
		}
	}

	//����Ͱ ���ظ�P
	node* start;
	node* end;
	bool find_start = 0;
	for (int i = 0; i < 10; i++)
	{
		node* ptr = bucket[i];
		if (ptr->next == nullptr)continue;//�ų�ǰ���ֵĿ�Ͱ
		else if(!find_start)
		{
			start = ptr->next;//��������Ŀ�ͷ
			find_start = 1;//ֻ����1��
		}
		else
		{
			end->next = ptr->next;
		}

		while (ptr->next != nullptr)//ptr�ҵ�Ͱ���һ��Ԫ��
		{
			ptr = ptr->next;
		}
		end = ptr;

		//i++;
		//while (i < 10 && bucket[i]->next == nullptr)//��һ����Ԫ�ص�Ͱ
		//{
		//	i += 1;
		//}
		//if (i < 10 && bucket[i]->next != nullptr)
		//{
		//	ptr->next = bucket[i]->next;
		//	i--;//����forѭ���е�++
		//}
	}
	
	//ɾ��Ͱ
	for (int i = 0; i < 10; i++)
	{
		delete bucket[i];
	}

	P = start;
}

/////////////////
/////*OTHER*/////
/////////////////
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
	cout << endl << "��ѡ�������㷨��\t";
	cin >> in;
	return in;
}