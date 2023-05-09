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
// 1、做参数
// 输出型参数
// 形参的改变，影响实参
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
//// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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
// 2、做返回值

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
//// 引用返回
//// 1、减少拷贝
//// 2、调用者可以修改返回对象
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

#define N 10
struct Array
{
	int& at(int i)
	{
		assert(i < N);
		return a[i];
	}

	int& operator[](int i)
	{
		assert(i < N);
		return a[i];
	}

	int a[N];
	int size;
};

//// a[i] *(a+i)
int main()
{
	Array ay;

	for (int i = 0; i < N; ++i)
	{
		//ay.at(i) = 0;
		//ay.operator[](i) = 0;
		ay[i] = 0;
	}

	for (int i = 0; i < N; ++i)
	{
		//cout << ay.at(i) << " ";
		cout << ay[i] << " ";
	}
	cout << endl;


	return 0;
}