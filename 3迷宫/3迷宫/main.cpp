#include "maze.h"

int main()
{
	bool flag = 1;
	do
	{
		maze A;
		cout << "�Ƿ��������¸��Թ���(Y/N)��";
		char order;
		while (cin >> order)
		{
			if (order == 'N')
			{
				cout << "Bye!" << endl << endl;
				flag = 0;
				break;
			}
			else if (order == 'Y')
			{
				break;
			}
			else
			{
				cout << "����������������룺";
			}
		}

	} while (flag);
	
}