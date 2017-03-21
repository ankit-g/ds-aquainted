
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <iostream>

using namespace std;

class DlistNode
{
	int data;
	DlistNode *next;
	DlistNode *prev;
	DlistNode *head;
	DlistNode *tail;
public:
	DlistNode();
	~DlistNode();
	void append(int data);
	void print_list(void);		
	void print_rev(void);		
};
