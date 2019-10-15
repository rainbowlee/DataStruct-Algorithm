#include "Test.h"
#include "Sorting.h"

//重做，取消
void TestSort()
{

}

class TESTSort
{
public:
	TESTSort()
	{
		Register();
	}


	void Register()
	{
		FuncMain::Instance()->AddMethod(TestSort);
	}
};

static TESTSort a;