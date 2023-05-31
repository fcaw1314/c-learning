#include <iostream>
using namespace std;

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

//template <class T>
//void Swap(T& left, T& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//template <class S,class Y>
//Y Add(const S& a, const Y& b)
//{
//	return a + b;
//}
//int main()
//{
//	int left = 525;
//    double right = 2023;
//	cout << left << ',' << right << endl;
//	
//	cout << Add(left, right) << endl;
//
//	return 0;
//}

#include <iostream>
using namespace std;
//闰年
int leap_year[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//平年
int nonleap_year[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool is_leap_year(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int main() {
    int count, year, month, day, increment;
    scanf_s("%d", &count);
    while (cin >> year >> month >> day >> increment) {
        // 注意 while 处理多个 case
        while (increment > 0) {
            if (is_leap_year(year)) {
                for (int i = month; increment >= leap_year[i - 1] && i < 12; i++) {
                    increment -= leap_year[i - 1];
                    month++;
                }
            }
            else {
                for (int i = month; increment >= nonleap_year[i - 1] && i < 12; i++)
                {
                    month++;
                    increment -= nonleap_year[i - 1];
                }
            }
            if (month == 12 && increment + day > 31) {
                month = 1;
                year++;
                increment -= 31;
            }
            else if (month < 12 && increment + day < 62 && increment + day > 31) {
                if (is_leap_year(year)) {
                    if (month <= 12 && increment + day >= leap_year[month - 1]) {
                        day = increment + day - leap_year[month - 1];
                        month++;
                        break;
                    }
                }
                else {
                    if (month <= 12 && increment + day > nonleap_year[month - 1]) {
                        day = increment + day - nonleap_year[month - 1];
                        month++;
                        break;
                    }
                }
            }
            else {
                day += increment;
                break;
            }

        }
        printf("%04d-%02d-%02d\n", year, month, day);
    }

}