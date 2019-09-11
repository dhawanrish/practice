#include<iostream>
using namespace std;

template<typename T>
class sp
{
	T a;
public:
	sp()
	{
		a = (T)0;

	}
	sp(T p)
	{
		a = p;
	}
	sp(const sp &obj)
	{
		a=(obj.a);
	}
	~sp()
	{	}

	friend ostream &operator <<(ostream &output, const sp &obj)
	{
		output << (obj.a) << endl;
		return output;
	}
	friend istream &operator >>(istream &input, sp &obj)
	{
		input >> (obj.a);
		return input;
	}
	void operator=(const sp &obj)
	{
		a = (obj.a);
	}
	sp operator+(const sp &obj)
	{
		sp obj2;
		obj2.a = this->a + (obj.a);
		return obj2;
	}


};
int main()
{
	sp<int> b(5);
	sp<int> c(10); //calls copy constructor
	sp<int> d;

	d = c+b;
	cout << "At b: " << b;
	cout << "At c: " << c;
	cout << "At d: " << d;
	return 0;
}
