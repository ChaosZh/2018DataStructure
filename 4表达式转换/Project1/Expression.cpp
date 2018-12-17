#include "Expression.h"

Expression::Expression()
{
	Input();
	Build();
	cout << Digit[0];
}

void Expression::Input()
{
	Symbol.push_back(symbol('{'));

	cout << "��������ʽ��";
	int i = 0;
	while (true)
	{
		char temp = getchar();

		//�ж��ǲ�������
		if (temp <= '9' && temp >= '0')
		{
			//Ĭ�����ֲ������
			char digit[20] = {};
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
			Symbol.push_back(x);
		}
		//�ж��ǲ�������
		else if (temp == '{' || temp == '[' || temp == '(')
		{
			symbol x = temp;
			Symbol.push_back(x);
		}
		else if (temp == '}' || temp == ']' || temp == ')')
		{
			symbol x = temp;
			Symbol.push_back(x);
		}

		//�ж��ǲ��ǿ�
		if(temp=='\n')
		{
			//�������
			Symbol.push_back(symbol('}'));
			break;
		}
	}
}

bool Expression::Build()
{
	auto SymbolIterPre = Symbol.begin();
	auto SymbolIter = ++Symbol.begin();
	auto SymbolIterNext = ++(++Symbol.begin());
	auto DigitIter = Digit.begin();
	bool digitFlag = 1;
	
	while (true)
	{
		//��Ӧ��ǰ��Ԫ�������ǰһ������/����
		if (*SymbolIter != '('&&
			*SymbolIter != '['&&
			*SymbolIter != '{'&&
			*SymbolIter != '}'&&
			*SymbolIter != ']'&&
			*SymbolIter != ')')
		{
			if (digitFlag)
			{
				digitFlag = 0;
			}
			else
			{
				DigitIter++;
			}
		}

		//�����ǰָ�����������ȼ����
		if (*SymbolIter > *SymbolIterNext)
		{
			//���߶�����������ͬһ����,continue
			if ((SymbolIter->value == 1 && SymbolIterNext->value == 1) || (SymbolIter->value == 0 && SymbolIterNext->value == 0))
			{
				SymbolIterPre++;
				SymbolIter++;
				SymbolIterNext++;
				continue;
			}
			//���������������������������,��ʼ��Լ
			else
			{
				//����������
				if ((SymbolIter->value + SymbolIterNext->value) == 1)
				{
					cout << "come in";
				}
				else
				//���߶��������/һ�������һ������
				{
					string newDigit = "";
					auto DigitIterNext = DigitIter;
					DigitIterNext++;
					newDigit = *DigitIter + SymbolIter->_symbol + *DigitIterNext;
					//�滻ԭDigit
					*DigitIter = newDigit;
					Digit.erase(DigitIterNext);
					//ɾ��Symbol
					Symbol.erase(SymbolIter);
					SymbolIter = SymbolIterPre;
					SymbolIter++;
					SymbolIterNext++;
				}
			}
		}
		//��������ȼ�������,�����һ�������
		else
		{
			SymbolIterPre++;
			SymbolIter++;
			SymbolIterNext++;
			continue;
		}

		if (Digit.size() == 1)
		{
			break;
		}
	}
	return true;
}


////other constructions
//float transIntoDigit(char d[])
//{
//	float result = 0;
//	int length = sizeof(d) / sizeof(char);
//	int i = 0;
//	while (d[i] != '.'&&i < length)
//	{
//		result = result * 10 + d[i];
//		i++;
//	}
//	if (d[i] == '.')
//	{
//		int _i = 1;
//		while (i+_i < length)
//		{
//			result = result + d[i + _i] / (10 * _i);
//			_i++;
//		}
//	}
//	return result;
//}