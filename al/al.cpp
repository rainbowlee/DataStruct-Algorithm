// al.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Test.h"
#include <windows.h>
int _tmain(int argc, _TCHAR* argv[])
{
	FuncMain::Instance()->RunTests();


	int i1 = 0, i2 = 0, i3 = 0;
	auto b = i1 == i2 == i3;

	Sleep(1000000);	
	return 0;
}

