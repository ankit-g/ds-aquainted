// stack
#include <stdio.h>
#include <stdlib.h>

struct queue_node
{
	int data;
	struct queue_node *next;	
};

void enqueue(int data);
int dequeue(void);
