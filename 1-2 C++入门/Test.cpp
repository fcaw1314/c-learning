#include<iostream>
#include <assert.h>
using namespace std;

//int main()
//{
//	int a = 0;
//	int& b = a;
//	int& c = b;
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//
//	int x = 10;
//	c = x;
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//
//	return 0;
//}

//////////////////////////////////////////////////////////////
// 1��������
// ����Ͳ���
// �βεĸı䣬Ӱ��ʵ��
//void swap(int* p1, int* p2)
//{
//
//}
//
//void swap(int& r1, int& r2)
//{
//
//}
//
//// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
////BTNode* BinaryTreeCreate(char* a, int* pi)  // c
////BTNode* BinaryTreeCreate(char* a, int& ri) // cpp
////{}
//
//typedef struct SeqList
//{
//	int* a;
//	int size;
//	int capaicty;
//}SL;
//
//void SLPushBack(SL& sl, int x);
//
//typedef struct Node
//{
//	struct Node* next;
//	int val;
//}Node, *PNode;
//
////typedef struct Node* PNode;
////void SLTPushBack(Node** pphead, int x);  // C
//
////void SLTPushBack(Node*& phead, int x);  // CPP
//void SLTPushBack(PNode& phead, int x);
//
//int main()
//{
//	int a = 0, b = 1;
//	swap(&a, &b);
//	swap(a, b);
//
//	char* ptr = "ABD##E#H##CF##G##";
//	int i = 0;
//	//BinaryTreeCreate(ptr, i);
//
//	Node* plist = NULL;
//	//SLTPushBack(&plist, 1);
//	SLTPushBack(plist, 1);
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////
// 2��������ֵ

//int& Count()
//{
//	static int n = 0;
//	n++;
//
//	return n;
//}

//#define N 10
//typedef struct Array
//{
//	int a[N];
//	int size;
//}AY;
//
//// ���÷���
//// 1�����ٿ���
//// 2�������߿����޸ķ��ض���
//int& PosAt(AY& ay, int i)
//{
//	assert(i < N);
//
//	return ay.a[i];
//}
//
//int main()
//{
//	int ret = Count();
//
//	AY ay;
//	for (int i = 0; i < N; ++i)
//	{
//		PosAt(ay, i) = i*10;
//	}
//
//	for (int i = 0; i < N; ++i)
//	{
//		cout << PosAt(ay, i) << " ";
//	}
//	cout << endl;
//	
//
//	return 0;
//}

//#define N 10
//struct Array
//{
//	int& at(int i)
//	{
//		assert(i < N);
//		return a[i];
//	}
//
//	int& operator[](int i)
//	{
//		assert(i < N);
//		return a[i];
//	}
//
//	int a[N];
//	int size;
//};
//

// 16:16����
//// a[i] *(a+i)
//int main()
//{
//	Array ay;
//
//	for (int i = 0; i < N; ++i)
//	{
//		//ay.at(i) = 0;
//		//ay.operator[](i) = 0;
//		ay[i] = 0;
//	}
//
//	for (int i = 0; i < N; ++i)
//	{
//		//cout << ay.at(i) << " ";
//		cout << ay[i] << " ";
//	}
//	cout << endl;
//
//
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int ret = Add(1, 2);
//	//Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	cout << "Add(1, 2) is :" << ret << endl;
//
//	return 0;
//}

#include <time.h>
struct A { int a[10000]; };
//void TestFunc1(A a){}
//
//void TestFunc2(A& a){}
//
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}

//A a;
//
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2(){ return a; }
//
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	TestReturnByRefOrValue();
//
//	return 0;
//}

int Count()
{
	int n = 0;
	n++;

	return n;
}

//int main()
//{
//	int a = 1;
//	int& b = a;
//
//	// ָ������ã���ֵ/��ʼ�� Ȩ�޿�����С�����ǲ��ܷŴ�
//
//	// Ȩ�޷Ŵ�
//	/*const int c = 2;
//	int& d = c;
//
//	const int* p1 = NULL;
//	int* p2 = p1;*/
//
//	// Ȩ�ޱ���
//	const int c = 2;
//	const int& d = c;
//
//	const int* p1 = NULL;
//	const int* p2 = p1;
//
//	// Ȩ����С
//	int x = 1;
//	const int& y = x;
//
//	int* p3 = NULL;
//	const int* p4 = p3;
//
//	// 
//	//const int m = 1;
//	//int n = m;
//
//	const int& ret = Count();
//
//	int i = 10;
//
//	cout << (double)i << endl;
//
//	double dd = i;
//
//	const double& rd = i;
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//
//	int& ra = a;
//	ra = 20;
//
//	int* pa = &a;
//	*pa = 20;
//
//	return 0;
//}

// C++�Ƽ�
// const��enum����곣��
// inlineȥ����꺯��

// ��ȱ�㣺
// 1�����ܵ���
// 2��û�����Ͱ�ȫ�ļ��
// 3����Щ�����·ǳ�����,���׳�������������

// Ҫ��ʵ��ADD�꺯��
//#define ADD(int x, int y) return x+y;
//#define ADD(x, y) x+y;
//#define ADD(x, y) (x+y)
//#define ADD(x, y) (x)+(y)
//#define ADD(x, y) ((x)+(y));

//#define ADD(x, y) ((x)+(y))
////#define ADD(x, y) (x + y)
////#define ADD(x, y) (x)+(y)
////#define ADD(x, y) x+y
//
//
//int main()
//{
//	ADD(1, 2) * 3; // ((1)+(2))*3;
//
//	int a = 1, b = 2;
//	ADD(a | b, a & b); // ((a | b) + (a & b));;
//
//	return 0;
//}

inline int Add(int x, int y)
{
	int z = x + y;
	z = x + y;
	z += x + y;
	//z = x + y;
	//z = x + y;
	//z = x * y;
	//z = x + y;
	//z += x + y;
	//z -= x + y;
	//z += x + y;
	//z += x * y;
	//z -= x / y;
	//z += x + y;
	//z += x + y;

	return z;
}

int main()
{
	int ret = Add(1, 2);
	cout << ret << endl;

	return 0;
}