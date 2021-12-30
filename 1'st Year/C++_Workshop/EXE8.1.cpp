/************************
*	Roei Barak			*
*	318419611			*
*	Exe 8 Q 1			*
*						*
*						*
*************************/
#include <iostream>
#include "StackList.h"
#include "StackList.h"
#include<cmath>
using namespace std;
string infixToPostfix(string s)
{
	int i = 0;
	string str = "";
	StackList stk;
	char ch = s[i];
	while (ch != '\0')
	{
		if (ch == '(')
		{
			stk.push(s[i]);
		}
		else if (ch == ')')
		{
			char tmp = stk.pop();
			while (stk.isEmpty() == false && tmp != '(')
			{
				str += tmp ;
				str += " " ;
				if (stk.isEmpty())
				{
					break;
				}
				tmp = stk.pop();
			}
			/*if (!stk.isEmpty())
			{
				stk.pop();
			}*/

		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			if (ch == '+' || ch == '-')
			{
				char tmp = stk.pop();
				StackList temp;
				while (!stk.isEmpty() && tmp != '(')
				{
					char tmp = stk.pop();
					if (tmp == '*' || tmp == '/')
					{
						str += tmp + " ";
					}
					else
					{
						temp.push(tmp);
					}
				}
				while (!temp.isEmpty())
				{
					stk.push(temp.pop());
				}
				if (tmp == '(')
				{
					stk.push(tmp);
				}
			}
			stk.push(ch);
		}
		else if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
		{
			str += ch;
			if (s[i + 1] >= '0' && s[i + 1] <= '9')
			{
				char tmp = s[++i];
				while (tmp >= '0' && tmp <= '9')
				{
					str += tmp;
					tmp = s[++i];;
				}
				i--;
				str += " ";
			}
			else
			{
				str += + " ";
			}

		}
		i++;
		ch = s[i];
	}
	while (!stk.isEmpty())
	{
		str += stk.pop();
	}
	return str;
}
int calcPostfix(string postfix)
{
	StackList stk;
	int result = 0;
	int temp = 0;
	int counter = 0;
	int loper = 0;//Left operand
	int roper= 0;//Right operand
	for (int i = 0; i < postfix.length(); i++)
	{
		char ch = postfix[i];
		if ((ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9'))
		{

			if (postfix[i + 1] >= '0' && postfix[i + 1] <= '9')//if there a number wihte more than one digit
			{
				for (int k = i+1; k < postfix.length(); k++)
				{
					if (postfix[k] >= '0' && postfix[k] <= '9')
						counter++;
					else
						break;
				}
				for (int k = counter; k >= 0; k--)
				{
					temp += (postfix[i++] -'0') * pow(10, k);
				}
				stk.push(temp + '0');
				temp = 0;
				counter = 0;
			}
			else
			{
				stk.push(postfix[i]);
			}
			/*stk.push(ch);
			if (postfix[i + 1] >= '0' && postfix[i + 1] <= '9')
			{
				char tmp = postfix[++i];
				int counter = 0;
				while (tmp >= '0' && tmp <= '9')
				{
					stk.push(tmp);
					tmp = postfix[++i];
				}
				i--;
			}*/
		}
		switch (ch)
		{
		case '+': {
			roper = stk.pop() - '0';
			loper= stk.pop() - '0';
			result = loper + roper; 
			stk.push(result + '0');
			break;
		}
		case '-': {roper = stk.pop() - '0'; loper = stk.pop() - '0'; result = loper - roper; stk.push(result + '0'); break; }
		case '*': {roper = stk.pop() - '0';loper= stk.pop() - '0'; result = loper * roper; stk.push(result + '0'); break; }
		case '/': {
			roper = stk.pop() - '0';
			loper= stk.pop() - '0';
			result = loper / roper; 
			stk.push(result +'0');
			break; 
		}
		default:
			break;
		}
	}
	return (stk.pop() - '0');
}

int main()
{
	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << postfix << endl;
	cout << calcPostfix(postfix) << endl;
	return 0;
}
/*
enter an infix expression as a string
(5+3)*((20/10)+(8-6))
5 3 + 20 10 / 8 6 - + *
32
*/
