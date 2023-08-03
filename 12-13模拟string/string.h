#pragma once
#include<assert.h>

namespace yxb
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
		/*string()
			:_str(new char[1])
			, _size(0)
			,_capacity(0)
		{
			_str[0] = '\0';
		}*/

		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//øΩ±¥ππ‘Ïs3(s2)
		string(const string& s)
			:_size(s._size)
			,_capacity(s._capacity)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
		}

		//s1 = s3   s1 = s1
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp,s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0; 
		}

		const char* c_str()
		{
			return _str;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}

		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		bool operator>(const string& s)const
		{
			return strcmp(_str, s._str) > 0;
		}
		bool operator==(const string& s)const
		{
			return strcmp(_str, s._str) == 0;
		}
		bool operator>=(const string& s)const
		{
			return (*this == s || *this > s);
		}
		bool operator<(const string& s)const
		{
			return !(*this >= s);
		}
		bool operator<=(const string& s)const
		{
			return !(*this > s);
		}
		bool operator!=(const string& s)const
		{
			return !(*this == s);
		}
		
		//¿©»›
		void reverse(size_t n)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}

		void push_back(char ch)
		{
			if (_size + 1 > _capacity)
			{
				reverse(_capacity * 2);
			}
			_str[_size] = ch;
			_size++;
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reverse(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};

	void test_string1()
	{	
		string s1;
		string s2("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		s2[0]++;
		cout << s2.c_str() << endl;

	}
	void test_string2()
	{
		string s1;
		string s2("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		s1 = s2;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
	}
	void test_string3()
	{
		string s1;
		string s2("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		
		string::iterator it = s2.begin();
		while (it != s2.end())
		{
			cout << *it << endl;
			++it;
		}
	}
	void test_string4()
	{
		string s1;
		string s2("hello world");
		string s3("hello");

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << (s3 >= s2) << endl;
	}
	void test_string5()
	{
		string s1;
		string s2("hello world");
		s2.append("yyyyyy");
		cout << s2.c_str() << endl;
	}
} 