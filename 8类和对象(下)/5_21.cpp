#include<iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// �������Ĺ��캯��
//class A
//{
//public:
//	explicit A(int a)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	//explicit A(int a1, int a2)
//	A(int a1, int a2)
//		:_a1(a1)
//		, _a2(a2)
//	{}
//
//	A(const A& aa)
//		:_a1(aa._a1)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a2;
//	int _a1;
//};

//int main()
//{
//	// ���������캯�� C++98
//	A aa1(1);  // ���캯��
//	//A aa2 = 1; // ��ʽ����ת��   ����+����+�Ż�->����
//	//const A& ref = 10;
//
//
//	// ��������캯�� C++11
//	A aa2(1, 1);
//	A aa3 = { 2, 2 };
//	const A &ref = { 2, 2 };
//
//	int i = 1;
//	double d = i; // ��ʽ����ת��
//
//	return 0;
//}
//using std::cout;
//using std::endl;
//
//// ʵ��һ���࣬��������д������˶��ٸ������
//int count = 0;
//
//class A
//{
//public:
//	A(int a = 0)
//	{
//		++count;
//	}
//
//	A(const A& aa)
//	{
//		++count;
//	}
//};
//
//void func(A a)
//{}
//
//int main()
//{
//	A aa1;
//	A aa2(aa1);
//	func(aa1);
//	A aa3 = 1;
//
//	count++;
//	count++;
//	count++;
//
//	cout << count << endl;
//
//	return 0;
//}

// ʵ��һ���࣬��������д������˶��ٸ������
//class A
//{
//public:
//	A(int a = 0)
//	{
//		++count;
//	}
//
//	A(const A& aa)
//	{
//		++count;
//	}
//
//	// ��̬��Ա���� -- û��thisָ��
//	static int GetCount()
//	{
//		// _a++; // ����ֱ�ӷ��ʷǾ�̬��Ա
//		return count;
//	}
//
//private:
//	// ������ĳ�������������ж�������������
//	static int count; // ����
//
//	int _a = 0;
//};
//
//int A::count = 0; // �����ʼ��

//void func()
//{
//	A aa1;
//	A aa2(aa1);
//	A aa3 = 1;
//
//	A aa4[10];
//}

//int main()
//{
//	func();
//
//	//cout << A::count << endl;
//	//cout << aa2.count << endl;
//	//cout << aa3.count << endl;
//	//A* ptr = nullptr;
//	//cout << ptr->count << endl;
//
//	//A aa;
//	//cout << aa.GetCount()-1 << endl;
//	cout << A::GetCount()<< endl;
//
//	return 0;
//}

//class Sum
//{
//public:
//	Sum()
//	{
//		_sum += _i;
//		++_i;
//	}
//
//	static int GetSum()
//	{
//		return _sum;
//	}
//private:
//	static int _i;
//	static int _sum;
//};
//
//int Sum::_i = 1;
//int Sum::_sum = 0;
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//Sum a[n];
//		Sum* ptr = new Sum[n];
//
//		return Sum::GetSum();
//	}
//
//	~Solution()
//	{
//		cout << "~Solution()" << endl;
//	}
//};
//
//A func()
//{
//	int n;
//	cin >> n;
//	int ret = Solution().Sum_Solution(n);
//
//	//A retA(ret);
//	//return retA;
//	return A(ret);
//}
//
//int main()
//{
//	/*Solution s;
//	cout << s.Sum_Solution(10) << endl;*/
//
//	cout << Solution().Sum_Solution(10) << endl;
//
//	//Solution s1();
//
//	// ����������������ֻ����һ��
//	Solution();
//	Sum();
//
//	return 0;
//}

//class A
//{
//private:
//	static int k;
//	int h = 1;
////public:
//	// �ڲ��� -- ��A�Ƕ�����ֻ����A����������
//	// B��������A����Ԫ
//	class B
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//	private:
//		int b = 2;
//	};
//};
//
//int A::k = 1;
//
//int main()
//{
//	A aa;
//	cout << sizeof(aa) << endl;
//
//	//A::B bb;
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//
//		return *this;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//void func1(A aa)
//{
//
//}
//
//void func2(const A& aa)
//{
//
//}
//
////int main()
////{
////	A aa1 = 1; // ����+�������� -�� �Ż�Ϊֱ�ӹ���
////	func1(aa1); // ���Ż�
////	func1(2); // ����+�������� -�� �Ż�Ϊֱ�ӹ���
////	func1(A(3)); // ����+�������� -�� �Ż�Ϊֱ�ӹ���
////
////	cout << "----------------------------------" << endl;
////
////	func2(aa1);  // ���Ż�
////	func2(2);    // ���Ż�
////	func2(A(3)); // ���Ż�
////
////
////	return 0;
////}
//
//A func3()
//{
//	A aa;
//	return aa; 
//}
//
//A func4()
//{
//	return A();
//}

// ���̽��C++����ģ��
//
//int main()
//{
//	func3();
//
//	A aa1 = func3(); // ��������+��������  -- �Ż�Ϊһ����������
//
//	cout << "****" << endl;
//	A aa2;
//	aa2 = func3();  // �����Ż�
//
//	cout << "---------------------------" << endl;
//	func4(); // ����+�������� -- �Ż�Ϊ����
//	A aa3 = func4(); // ����+��������+��������  -- �Ż�Ϊ����
//
//	return 0;
//}

//int main()
//{
//	int* p2 = (int*)calloc(4, sizeof (int));
//	int* p3 = (int*)realloc(p2, sizeof(int)* 100);
//
//	cout << p2 << endl;
//	cout << p3 << endl;
//
//	// ������Ҫfree(p2)��
//	//free(p2);
//	free(p3);
//
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}

	~A()
	{
		cout << "~A():" << this << endl;
	}

private:
	int _a;
};

struct ListNode
{
	int _val;
	ListNode* _next;

	ListNode(int val)
		:_val(val)
		, _next(nullptr)
	{}
};

//ListNode BuyListNode(int x)
//{
//	//...
//}

int main()
{
	int* pp1 = (int*)malloc(sizeof(int));
	int* p1 = new int;

	free(pp1);

	delete p1;

	int* pp2 = (int*)malloc(sizeof(int) * 10);
	int* p2 = new int[10];

	free(pp2);
	delete[] p2;

	A* pp3 = (A*)malloc(sizeof(A));
	free(pp3);

	A* p3 = new A(1);
	delete p3;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);


	return 0;
}