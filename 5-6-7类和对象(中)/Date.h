#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	//构造函数
	Date(int year = 1900, int month = 1, int day = 1);
	//获取某月天数
	int GetMonthDay(int year, int month);
	//打印
	void Print();

	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);

	Date& operator+=(int day);
	Date operator+(int day);
	
	// d1 - 100 日期 - 天数
	Date operator-(int day);
	Date& operator-=(int day);

	// d1 - d2; 日期 - 日期
	int operator-(const Date& d);

	//++d1
	Date& operator++();
	// d1++
    // int参数 仅仅是为了占位，跟前置重载区分
	Date operator++(int);
	
	// --d1 -> d1.operator--()
	Date& operator--();

	// d1-- -> d1.operator--(1)
	Date operator--(int);

private:
	int _year;
	int _month;
	int _day;
};



