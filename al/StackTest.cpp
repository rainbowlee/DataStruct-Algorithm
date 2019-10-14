#include "Stack.h"
#include "Test.h"
#include <iostream>

void TestStack()
{
	Stack stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);

	std::cout << stack.ToString() << std::endl;
	stack.Pop();
	std::cout << stack.ToString() << std::endl;
	stack.Pop();
	std::cout << stack.ToString() << std::endl;
	stack.Pop();
	std::cout << stack.ToString() << std::endl;

	stack.Pop();
	std::cout << stack.ToString() << std::endl;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	std::cout << stack.ToString() << std::endl;
}


int Expression(string str)
{
	Stack stackOp;
	Stack stackNum;

	bool inputError = false;
	for(int i = 0; i < str.size(); i++)
	{
		char c = str[i];
		std::cout << c <<endl;
		if(c >= '0' && c <='9')
		{
			int count = stackOp.Count();
			if(count > 0)
			{
				int value;
				stackOp.Top(value);
				char op = static_cast<char>(value);
				if( c == '+')
				{

				}
				else if( c == '-')
				{

				}
				else if( c == '*')
				{

				}
				else if( c == '/')
				{


				}
			}
		}
		else if( c == '+' || c == '-' || c == '*' || c == '/' )
		{

		}
		else
		{
			inputError = true;
			std::cout << "input error \r\n";
			break;
		}
	}

	return 0;
}

//表达式实现 四则运算 + - */ eg:a + b + c*d*f
void TestExpression1()
{
	string str = "1+2+5*4";
	int result = Expression(str);

	std::cout << "TestExpression1 " << result << endl ;
}

void TestExpression2()
{
	string str = "4/5+1+2+5*4";
	int result = Expression(str);

	std::cout << "TestExpression2 " << result << endl ;
}

static bool Macth(string str)
{
	Stack stack;

	bool inputerror = false;
	for(int i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if( c == '[' || c == '{' )
		{
			stack.Push(c);
		} 
		else if(c == ']' || c == '}')
		{
			if(stack.Count() <= 0)
				return false;
			int value;
			stack.Top(value);
			char ccmp = static_cast<char>(value);
			if(c== ']' && ccmp == '[')
			{
				stack.Pop();
			}
			else if(c== '}' && ccmp == '{' )
			{
				stack.Pop();
			}
			else
			{
				return false;
			}
		}
		else
		{
			inputerror = true;
			break;
		}
		
	}

	return stack.Count() == 0;
}

//括号匹配 {}[]
void TestMath1()
{
	string str = "{[{[[]]}]}";
	bool matched = Macth(str);
	if(matched)
		std::cout << "TestMath1 matched " << endl;
	else
		std::cout << "TestMath1 match error" << endl;
}


void TestMath2()
{
	string str = "{[}]";
	bool matched = Macth(str);
	if(matched)
		std::cout << "TestMath1 matched " << endl;
	else
		std::cout << "TestMath1 match error" << endl;
}


//重做，取消
void TestDoRedoList()
{

}

class TESTStack
{
public:
	TESTStack()
	{
		Register();
	}


	void Register()
	{
		FuncMain::Instance()->AddMethod(TestStack);
		FuncMain::Instance()->AddMethod(TestExpression1);
		FuncMain::Instance()->AddMethod(TestExpression2);
		FuncMain::Instance()->AddMethod(TestMath1);
		FuncMain::Instance()->AddMethod(TestMath2);
		FuncMain::Instance()->AddMethod(TestDoRedoList);
	}
};

static TESTStack a;