// al.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Test.h"
#include <windows.h>
int _tmain(int argc, _TCHAR* argv[])
{
	FuncMain::Instance()->RunTests();

	Sleep(1000000);	
	return 0;
}

