#include "Test.h"

//漏斗限流
void LeakeyBucket()
{

}

//令牌限流
void TokenBucket()
{

}
//布隆过滤器，对命中拦截，防止压力到mysql
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