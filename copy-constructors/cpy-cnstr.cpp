// Copy Constructor
// shallow copy
// In shallow copy the data is from the class object passed to the default constructor is copied
// to the object bit by bit. so if the source object's destructor deallocates one of the member pointer it has
// then the copy object wont be able to access it.

/*	the solution: <currently commented>
 *	The solution to this problem is deep copy. Hurrayyyy !!!
 *	In case of deep copy we can use refence to allocate and have seperate space for pointers
 *	and voila the problem disappears.
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

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

int main(void)
{
	MyClass *t_obj = new MyClass();
	cout << t_obj->ptr->a << endl;
	{
		MyClass My_obj(*t_obj);
		cout << My_obj.ptr->a << endl;
	}
	
	cout << t_obj->ptr->a << endl;

	return EXIT_SUCCESS;
}
