#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
#include "string.h"


int main()
{
	try
	{
		yxb::test_string9();

	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	
	return 0;
}



