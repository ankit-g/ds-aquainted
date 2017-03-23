/*	Template can be used to build functions which handle multiple 
 *	types of data
 *	tempelate <class name>
 *	or 
 *	tempelate <typename N>
 *	now name is a generic type of data, which can now represent userdefined or
 *	intrinsic type of data and can be used in functions.
 *
 *	so here when the function print_whatever is called, c++ looks at the argument that is 
 *	an integer float or what ever and replaces that with the template variable.
 *	WHAT the HECK
 *
 *	when we need the function to work on two different data types we can use two template types.
 * */

#include <iostream>
#include <string.h>
using namespace std;

template <class bucky, class tucky>
bucky addCrap(bucky a, tucky b)
{
return a+b;
}

template <typename M>
void print_whatever(M of)
{
	cout << of << endl;
}

int main()
{
	int x=7, y=43,z;
	string s1, s2;

	z=addCrap(x,y);
	cout << z <<endl;

	z=addCrap(5.5, 5);
	cout << z <<endl;

	cout << addCrap(s1 = "Hello ", s2 = "World\n");
	print_whatever("Hello");
	print_whatever(6.6);
	print_whatever(6);
	print_whatever('c');
	print_whatever(s1);
	print_whatever(s2);
	
}
