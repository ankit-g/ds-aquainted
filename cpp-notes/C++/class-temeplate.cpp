/* The class template is defined same way you define a tempelate for a
 *	function:
 *		template <typename/class name, typename/class name2, ....>
 *		where name is the new template used in the class.
 *
 *	Lets try to implement a list/stack class with a template as data.
 *
 *	Each time now the class Stack is mentioned or accessed we'll have to mention the
 *	class operates on a template data type in a "<>" triangular bracket. 
 *
 *	However stupid one might think this. This Looks damn ugly for sure.
 *
 *	Non working example 
 */
#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
	T data;
	Stack *next;
public:
	Stack(T);
	void push(T);
	T pop(void);	
};

template <typename T>
Stack<T>::Stack(T new_data)
{
	data = new_data;
	next = NULL;
}

template <typename T>

void Stack<T>::push(T new_data)
{
	Stack<T> *new_node = new Stack(new_data);
	next = this;
	while (next->next)
	next = next->next;
	next = new_node;
}

template <typename T>
T Stack<T>::pop(void)
{
	T ret_data;
	Stack *crawler = this;
	
	if (!crawler) {
		return (int)-1;
	} else if (!crawler->next) {
		goto give_data;
	} 
	

	while (crawler->next->next)
		crawler = crawler->next;

	ret_data = crawler->next->data;
	delete crawler->next;
	return ret_data;

give_data:
	ret_data = crawler->data;
	delete crawler;

	return ret_data;
}

int main(void)
{
	Stack<int> *fine = new Stack<int>(-1);

	fine->push(5);
	fine->push(6);
	fine->push(7);
	fine->push(8);

	cout << fine->pop() << endl;
	cout << fine->pop() << endl;
	cout << fine->pop() << endl;
	cout << fine->pop() << endl;
	return 0;
}
