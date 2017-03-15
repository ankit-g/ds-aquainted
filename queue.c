#include "queue.h"

static struct queue_node *head = NULL;


void enqueue(int data)
{
	struct queue_node *crawler;
	if (!head) {
		head = malloc(sizeof(struct queue_node));
		if (!head) {
			printf("FUCK OFF\n");
			exit(0);		
		}
		
		head->data = data;
		head->next = NULL;
	} else {
		crawler = head;
		
		while (crawler->next)
			crawler = crawler->next;
		
		crawler->next = malloc(sizeof(struct queue_node));	
		crawler = crawler->next;
		crawler->data = data;
		crawler->next = NULL;		
	}
}

int dequeue(void)
{
	int data;
	struct queue_node *tmp;
	
	if(!head) return -1;
	
	tmp = head;
	data = tmp->data;
	head = head->next;

	free(tmp);
	
	return data;
}
