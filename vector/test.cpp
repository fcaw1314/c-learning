#include <iostream>
#include <vector>
using namespace std;

void test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> copy(v);
	for (auto c : copy)
	{
		cout << c << " ";
	}
	cout << endl;
}
void test_vector2()
{
	vector<int> w(10, 1);
	for (auto x : w)
	{
		cout << x << " ";
	}
	cout << endl;

	vector<int> v2(w.begin(), w.end());
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	//ÀàÐÍ×ª»»
	string s1("Hello world");
	vector<int> v3(s1.begin(), s1.end());
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test_vector2();
	return 0;
}