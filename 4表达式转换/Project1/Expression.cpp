#include "Expression.h"

Expression::Expression()
{
	Input();
}

bool Expression::Input()
{
	stack<symbol> Symbol;
	vector<string> Digit;
	Symbol.push(symbol('('));

	cout << "��������ʽ��";
	int i = 0;
	while (true)
	{
		char temp = getchar();

		//�ж��ǲ�������
		if (temp <= '9' && temp >= '0')
		{
			//Ĭ�����ֲ������
			char digit[20];
			int i = 0;
			while (temp <= '9' && temp >= '0' || temp == '.')
			{
				digit[i] = temp;
				i++;
				temp = getchar();
			}
			//���ַ�����ת������
			//transIntoDigit(digit);
			//��string���������
			Digit.push_back(digit);
		}
		//�ж��ǲ����������
		//����else if���ж��Ƿ�Ϊ���ֵ�ʱ������һ��char
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
		{
			symbol x = temp;
			Symbol.push(x);
		}
		//�ж��ǲ�������
		else if (temp == '{' || temp == '[' || temp == '(')
		{
			symbol x = temp;
			Symbol.push(x);
		}
		else if (temp == '}' || temp == ']' || temp == ')')
		{
			Symbol.pop();
		}
		//�ж��ǲ��ǿ�
		else if(temp=='\n')
		{
			//�������
			break;
		}
	}
}

//other constructions
float transIntoDigit(char d[])
{
	float result = 0;
	int length = sizeof(d) / sizeof(char);
	int i = 0;
	while (d[i] != '.'&&i < length)
	{
		result = result * 10 + d[i];
		i++;
	}
	if (d[i] == '.')
	{
		int _i = 1;
		while (i+_i < length)
		{
			result = result + d[i + _i] / (10 * _i);
			_i++;
		}
	}
	return result;
}