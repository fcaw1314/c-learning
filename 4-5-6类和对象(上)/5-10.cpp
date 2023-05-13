#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1 ,int month = 1, int day =1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void print()
	{
		cout << _year << "Äê" << _month << "ÔÂ" << _day << "ÈÕ" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2023,5,13);
	d1.print();

	Date d2(d1);
	d2.print();

	return 0;
}