#include "Test.h"

//©������
void LeakeyBucket()
{

}

//��������
void TokenBucket()
{

}
//��¡�����������������أ���ֹѹ����mysql
void BloomFilter()
{

}

class TESTX
{
public:
	TESTX()
	{
		Register();
	}


	void Register()
	{
		FuncMain::Instance()->AddMethod(LeakeyBucket);
		FuncMain::Instance()->AddMethod(TokenBucket);
		FuncMain::Instance()->AddMethod(BloomFilter);
	}
};

static TESTX a;