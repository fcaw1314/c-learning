#include"Date.h"

void TextDate1()
{
	Date d1(2023,5,17);
	d1.Print();
	Date d2(2023, 5, 17);
	cout << (d1 == d2) << endl;
}

void TextDate2()
{
	Date d1(2023, 5, 17);
	d1.Print();

	d1 -= 100;
	d1.Print();
	Date d2(2023, 5, 17);
	d2 += -100;
	d2.Print();
}

void TextDate3()
{
	Date d1(2023, 5, 17);
	d1.Print();
	Date d2(2002, 5, 8);
	d2.Print();
	cout << d1 - d2 << endl;
}
int main()	
{
	TextDate3();
	return 0;
}