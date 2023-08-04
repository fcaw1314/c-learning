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
			_capacity = _size == 0 ? 3 : _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//拷贝构造s3(s2)
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
		
		//扩容
		void reverse(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		//扩容+初始化
		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				//删除数据，保留前n个
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n > _capacity)
				{
					reverse(n);
				}
				size_t i = _size;
				while (i < n)
				{
					_str[i++] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		void push_back(char ch)
		{
			if (_size + 1 > _capacity)
			{
				reverse(_capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
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

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size + 1 > _capacity)
			{
				reverse(2 * _capacity);
			}
			size_t end = _size + 1;
			while (pos < end)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = ch;
			_size++;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			
			if (_size + len > _capacity)
			{
				reverse(_size + len);
			}
			
			//挪动数据
			size_t end = _size + len;
			while ( end > pos +len-1 )
			{
				_str[end] = _str[end-len];
					end--;
			}
			//拷贝插入 
			strncpy(_str + pos, str, len);
			_size += len;
		}

		void erase(size_t pos, size_t len = npos)
		{
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			//0123456789
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= pos;
			}
		}
		size_t find(char ch, size_t pos = npos)
		{
			assert(pos < _size);

			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = npos)
		{
			assert(pos < _size);

			char* p = strstr(_str, str);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				return p - str;
			}
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		void clean()
		{
			_str[0] = '\0';
			_size = 0;
		}


	private:
		char* _str;
		size_t _capacity;
		size_t _size;

		static const size_t npos;
	};

	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& str)
	{
		for (auto ch : str)
		{
			out << ch;
		}

		return out;
	}

	istream& operator>>(istream& in, string& str)
	{
		str.clean();

		char ch = in.get();
		char buff[128]; //避免因频繁扩容导致效率过低
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[127] = '\0';
				str += buff;
				i = 0;
			}
			ch = in.get();
		}

		if (i != 0)
		{
			buff[i] = '\0';
			str += buff;
		}

		return in;
	}

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
	void test_string6()
	{
		string s1("hhh ");
		cout << s1.c_str() << endl;
		s1.resize(10, 'x');
		cout << s1.c_str() << endl;
		s1.resize(100, 'y');
		cout << s1.c_str() << endl;
	}
	void test_string7()
	{
		string s1("123456789");
		cout << s1.c_str() << endl;

		s1.insert(2, "wwww");
		cout << s1.c_str() << endl;

		s1.insert(0, "ss");
		cout << s1.c_str() << endl;

	}
	void test_string8()
	{
		string s1("123456789");
		cout << s1.c_str() << endl;

		s1.erase(4, 2);
		cout << s1.c_str() << endl;

	}

	void test_string9()
	{
		string s1;
		cin >> s1;
		cout << s1 << endl;
	}
}