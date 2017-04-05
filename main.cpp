#include <iostream>
using namespace std;
int main()
{
	int size_of_array = 10;
	int left = 10%4;

	for (int i=0; i < (size_of_array-left); i+=4)
	{
		cout << i << " ";
		cout << i+1 << " ";
		cout << i+2 <<  " ";
		cout << i+3 <<  " ";
	
	}
	
	return 0;
}
