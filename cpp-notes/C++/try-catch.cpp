#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Xterm
{
	public:
	static unsigned int rem;
	Xterm();	
};

Xterm::Xterm()
{}

int main(void)
{
	int i = 1;
	try {
	string str = "tommorrow never dies";
		if (0==i)
		throw 56;
		else
		throw str;
	} catch (int x) {
		cout << "int x " << x << endl;
	} catch (string str) {
		cout << "the world is not enough " << str << endl;
	}

	Xterm::rem = 0;
	return EXIT_SUCCESS;
}
