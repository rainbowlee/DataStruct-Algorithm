#include "Test.h"
#include "Sorting.h"

//������ȡ��
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