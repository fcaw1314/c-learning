#include"Date.h"

int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);
	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400)) == 0)
	{
		return 29;
	}
	else
	{
		return monthArray[month];
	}
}

Date::Date(int year, int month, int day)
{
	if (month > 0 && month < 13
		&& (day > 0 && day <= GetMonthDay(year, month)))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "输入格式错误" << endl;
	}
}

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

bool Date:: operator == (const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

bool Date::operator<(const Date& d)
{
	return _year < d._year
		|| (_year == d._year && _month < d._month)
		|| (_year == d._year && _month == d._month && _day < d._day);
}

bool Date::operator<=(const Date& d)
{
	return *this <= d || *this == d;
}

bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
		return *this;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += -day;
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

// d1 - 100 日期 - 天数
Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// d1++
Date Date::operator++(int)
{
	Date tmp(*this);

	*this += 1;

	return tmp;
}

// --d1 -> d1.operator--()
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// d1-- -> d1.operator--(1)
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

// d1 - d2; 日期 - 日期
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	while ( *this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}