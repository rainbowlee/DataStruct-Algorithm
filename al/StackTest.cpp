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

//表达式实现 四则运算 + - */ eg:a + b + c*d*f
void TestExpression()
{
	string str = "1+2+5*4";
	Stack stackOp;
	Stack stackNum;

	bool inputError = false;
	for(int i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if(c >= '0' && c <='9')
		{

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


}


//括号匹配 {}[]
void TestMath()
{

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
		FuncMain::Instance()->AddMethod(TestExpression);
		FuncMain::Instance()->AddMethod(TestMath);
		FuncMain::Instance()->AddMethod(TestDoRedoList);
	}
};

static TESTStack a;