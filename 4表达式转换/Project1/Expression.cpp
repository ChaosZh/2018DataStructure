#include "Expression.h"

Expression::Expression()
{
	Input();
	Build();
	cout << Digit[0];
}

void Expression::Input()
{
	cout << "��������ʽ��";
	int bracketValue = 0;
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
			digit[i]=' ';
			Digit.push_back(digit);
		}

		//�ж��ǲ����������
		//����else if���ж��Ƿ�Ϊ���ֵ�ʱ������һ��char
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
		{
			symbol x = temp;
			x.value += bracketValue;
			Symbol.push_back(x);
		}
		//�ж��ǲ������ţ��ı����ȼ�
		else if (temp == '{' || temp == '[' || temp == '(')
		{
			Bracket.push_back(temp);
			bracketValue += 2;
		}
		else if (temp == '}' || temp == ']' || temp == ')')
		{
			Bracket.pop_back();
			bracketValue -= 2;
		}
		//�ж��ǲ��ǿ�
		else if(temp=='\n')
		{
			//�������
			break;
		}
	}
}

bool Expression::Build()
{
	auto SymbolIter = Symbol.begin();
	auto DigitIter = Digit.begin();
	
	while (true)
	{
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