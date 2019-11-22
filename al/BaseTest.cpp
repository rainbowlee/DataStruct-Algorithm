#include <iostream>
#include <vector>
using namespace std;

enum class TypeEnum
{
	TypeEnum1,
	TypeEnum2,
};

class TESTBase
{
public:
	TESTBase()
	{
		Register();
	}


	void Register()
	{
		Test();
	}

	void Test()
	{
		{
			//vector<int> ints = {2,3,4};
			//vector<string> strs = {"1111","2222","3333"};
			//for(auto& str : strs)
			//{

			//}
		}


		{
			string a = "123";

			cout << sizeof(a) << endl;
			// test1  
			char str[] = "world";
			cout << sizeof(str) << ": ";

			char *p = str;

			cout << sizeof(p) << ": ";

			char i = 10;

			cout << sizeof(i) << ": ";

			void *pp = malloc(10);

			cout << sizeof(pp) << endl;

		}

		TypeEnum tType = TypeEnum::TypeEnum2;
		if(TypeEnum::TypeEnum1 == tType)
		{

		}

		char *str = "vermeer";    
		const char *pstr = str; 
		//*str = 'test';//能赋值， 但是不可以改变产量
		//*pstr = "test2"; complie error
		cout << "The address of pstr is: " << pstr << endl;  

		int a = 1;
		cout << a++ << endl;//1
		a = 1;
		cout << ++a << endl;//2

		int b(11), c = 30;

		//cout << (true?1:"1") << endl; //三元操作符 必须同类型
	}
};

static TESTBase a;