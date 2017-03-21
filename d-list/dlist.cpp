#include "dlist.h"

DlistNode::DlistNode()
{
	head = (DlistNode *)malloc(sizeof(DlistNode));
	head->data = INT_MAX;
	head->next = NULL;
	head->prev = NULL;

	tail = head;
}

DlistNode::~DlistNode()
{
	DlistNode *crawler;
	DlistNode *del;

	crawler = head;
	while (crawler) {
		del = crawler;
		free(del);
		crawler = crawler->next;	
	}

	head = NULL;
		
}

void DlistNode::append(int data)
{
	DlistNode *new_node = (DlistNode *)malloc(sizeof(DlistNode));

	new_node->data = data;

	tail->next = new_node;
	new_node->prev = tail;

	tail = tail->next;

	tail->next = NULL;
}

void DlistNode::print_list(void)
{
	DlistNode *crawler;

	crawler = head->next;

	while (crawler) {
		cout << crawler->data << endl;
		crawler = crawler->next;	
	}
}

void DlistNode::print_rev(void)
{
	DlistNode *crawler;

	crawler = tail;

	while (crawler != head)
	{
		cout << crawler->data << endl;
		crawler = crawler->prev;		
	}
}
