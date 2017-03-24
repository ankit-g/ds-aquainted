// Copy Constructor
// shallow copy
// In shallow copy the data is from the class object passed to the default constructor is copied
// to the object bit by bit. so if the source object's destructor deallocates one of the member pointer it has
// then the copy object wont be able to access it.

/*	the solution: <currently commented>
 *	The solution to this problem is deep copy. Hurrayyyy !!!
 *	In case of deep copy we can use refence to allocate and have seperate space for pointers
 *	and voila the problem disappears.
 *
 *	Topics:
 *
 *1	C vs C++				|	<done>
 *2	Reference Variables			|
 *3	Function Overloading			|
 *4	Default Argument			|
 *5	Inline Functions			|
 *6	new and delete				|
 *7	Class and Object			|
 *8	Static Members				|
 *9	‘this’ Pointer				|
 *10	Constructor and Destructor		|	<done> pointers can't be used in <deep> copy constructors. only use refence
 *11	Inheritance				|
 *12	Friend					|
 *13	Virtual Functions			|
 *14	Operator Overloading			|
 *15	Exception Handling			|
 *16	Templates				|
 *17	Namespaces				|	<done>
 *18	Standard Template Library (STL)		|
 *19	Misc					|
 *20	C++ vs Java				|
 *21	Puzzles					|
 *22	Output Questions			|
 *23	Quizzes on C++				|
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

struct MyApp
{
	int var_a;
	int var_b;
	struct MyApp &ref;
	MyApp() :ref(*this){}
};


struct Test
{
	int a;
	int b;
};

class MyClass
{
public:
	Test *ptr;

	MyClass() {
		ptr = new Test();
		ptr->a = 10;
		ptr->b = 20;
	};

	~MyClass() {
		delete ptr;
		ptr = NULL;
	}

	// Deep copy construct
#if 0
	MyClass(MyClass &orignal_obj)
	{
		ptr = new Test();
		ptr->a = orignal_obj.ptr->a;
		ptr->b = orignal_obj.ptr->b;
	}
#endif

	int var_a;
	int var_b; 
};

namespace kopal
{
	int cout = 77;
	namespace inner_kopal
	{
		int cout = 456;
	}
}

int cout = 99;

int main(void)
{
	const int ajr = 0;
	int cout = 111;
	int a = 99;
	int& b = a;

	MyApp mapp;

	mapp.var_a = 100;

	std::cout <<  mapp.var_a << endl;

	std::cout << b << endl;
	MyClass *t_obj = new MyClass();
	std::cout << t_obj->ptr->a << endl;
	{
		MyClass My_obj(*t_obj);
		std::cout << My_obj.ptr->a << endl;
	}
	
	std::cout << t_obj->ptr->a << endl;

	std::cout << kopal::cout << " " << cout << " " << ::cout << endl;

	std::cout << kopal::inner_kopal::cout << endl;

	return EXIT_SUCCESS;
}
