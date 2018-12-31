#include "Expression.h"

Expression::Expression()
{
	Input();
	Build();
	Digit[0].pop_back();
	cout << Digit[0];
}

void Expression::Input()
{
	cout << "��������ʽ��";
	int bracketValue = 0;
	char str[30] = {};
	
	char temp;
	str[0] = '(';
	int i = 1;
	while (temp=getchar())
	{
		if (temp == '\n')break;
		else if (temp == ' ')continue;
		else
		{
			str[i] = temp;
			i++;
		}
	}

	int x = 0;
	int length = sizeof(str) / sizeof(char);
	while (true)
	{
		//�ж��ǲ��ǿ�
		if (x==length)
		{
			//�������
			break;
		}
		//�ж��ǲ����������
		else if (str[x] == '+' || str[x] == '-' || str[x] == '*' || str[x] == '/')
		{
			char temp = str[x];
			symbol x = temp;
			x.value += bracketValue;
			Symbol.push_back(x);
		}
		//�ж��ǲ������ţ��ı����ȼ�
		else if (str[x] == '{' || str[x] == '[' || str[x] == '(')
		{
			Bracket.push_back(str[x]);
			bracketValue += 2;

			if (str[x + 1] == '-' || str[x + 1] == '+')//��������
			{
				//Ĭ�����ֲ������
				char digit[20] = {};
				x+=2;
				digit[0] = str[x + 1];
				digit[1] = str[x];
				int i = 2;
				while (str[x + 1] <= '9' && str[x + 1] >= '0' || str[x + 1] == '.')
				{
					x++;
					digit[i] = str[x];
					i++;
				}
				//���ַ�����ת������
				//transIntoDigit(digit);
				//��string���������
				digit[i] = ' ';
				Digit.push_back(digit);
			}
		}
		//�ж��ǲ�������
		else if (str[x] <= '9' && str[x] >= '0')
		{
			//Ĭ�����ֲ������
			char digit[20] = {};
			digit[0] = str[x];
			int i = 1;
			while (str[x+1] <= '9' && str[x+1] >= '0' || str[x+1] == '.')
			{
				x++;
				digit[i] = str[x];
				i++;
			}
			//���ַ�����ת������
			//transIntoDigit(digit);
			//��string���������
			digit[i] = ' ';
			Digit.push_back(digit);
		}
		else if (str[x] == '}' || str[x] == ']' || str[x] == ')')
		{
			Bracket.pop_back();
			bracketValue -= 2;
		}

		x++;
	}
}

bool Expression::Build()
{
	auto SymbolIter = Symbol.begin();
	auto DigitIter = Digit.begin();
	
	while (true)
	{
		if (Symbol.size() == 0)return true;
		if (Symbol.size()==1)
		{
			string newDigit = "";
			newDigit = *DigitIter + *(DigitIter + 1) + SymbolIter->_symbol + ' ';
			*DigitIter = newDigit;
			DigitIter = Digit.erase(DigitIter + 1);
			break;
		}
		//�����ǰָ�����������ȼ���ߣ���Լ
		///ָ�����һ�����������������ȼ��Ѿ��Ǵ�С�����ˣ�||��ǰ��������ȼ����ں���������
		else if (SymbolIter + 1 == Symbol.end() || *SymbolIter >= *(SymbolIter + 1))
		{
			//�滻ԭDigit
			string newDigit = "";
			newDigit = *DigitIter + *(DigitIter + 1) + SymbolIter->_symbol + ' ';
			*DigitIter = newDigit;
			Digit.erase(DigitIter+1);
			if(DigitIter!=Digit.begin())DigitIter--;
			//ɾ�������
			if (SymbolIter != Symbol.begin())
			{
				SymbolIter--;
				Symbol.erase(SymbolIter + 1);
			}
			else
			{
				SymbolIter = Symbol.erase(SymbolIter);
			}
		}
		else
		{
			//����
			SymbolIter++;
			DigitIter++;
		}
	}
	return true;
}