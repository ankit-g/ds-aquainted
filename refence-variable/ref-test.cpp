#include <iostream>
using namespace std;

#define STRNG_LEN 256

char buff[STRNG_LEN];

void print(int a)
{
	cout << a << endl;
}

void print(char *str)
{
	cout << str << endl;
}


void print(double a, int u = 0)
{
	cout << u << " ";
	cout << a << endl;
}

struct point
{
	int value;
	char *strng;
};

int& ret_ref(void)
{
	static int x = 0;
	
	cout << x << endl;

	return x;
}

int main(void)
{
	int *arr = new int[10];

	for (int i=0; i < 10; i++)
		ret_ref()++;

	print(1);
	print(0.1234);
	print(0.1234, 34);
	print((char *)"hello world");


	delete [] arr;

	return 0;
}
