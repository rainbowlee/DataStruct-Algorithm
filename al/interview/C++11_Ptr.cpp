#include <memory>
#include <iostream>
using namespace std;
#include "C++11_Ptr.h"
#include "../Test.h"

class Bad : public enable_shared_from_this<Bad>//非public不成
{
public:
	void fun()
	{
		shared_ptr<Bad> sp(shared_from_this());
		cout<<sp.use_count()<<endl;
	}
};


void Test1()
{
	cout << "Test_Ptr::Test1" << endl;
	shared_ptr<Bad> sp(make_shared<Bad>());
	sp->fun(); //输出为1
	cout << sp.use_count() << endl;
	weak_ptr<Bad> weakptr(sp);
	weak_ptr<Bad> weakptr2(weakptr);
	cout << sp.use_count() << endl;
	shared_ptr<Bad> sp2 = shared_ptr<Bad>(weakptr2);
	cout << sp.use_count() << endl;
}

void Test2()
{
	std::shared_ptr<int> sp(new int(10));
	std::weak_ptr<int> wp(sp);
	wp = sp;
	//printf("%d\n", wp.use_count()); // 1
	wp.reset();
	//printf("%d\n", wp); // 0

	// 检查 weak_ptr 内部对象的合法性.
	if (std::shared_ptr<int> sp = wp.lock())
	{
	}
}


class Test_Ptr
{
public:
	Test_Ptr()
	{
		Init();
	}

	void Init()
	{
		FuncMain::Instance()->AddMethod(Test1);
		FuncMain::Instance()->AddMethod(Test2);
	}
};




static Test_Ptr a;