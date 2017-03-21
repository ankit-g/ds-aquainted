#include "dlist.h"

int main(void)
{
	DlistNode *list = new DlistNode();

	list->append(5);
	list->append(4);
	list->append(3);
	list->append(2);
	list->append(1);

	list->print_list();
	cout << endl;
	list->print_rev();

	return 0;
}
