#include "graph.h"

void print_graph(struct graph *grph)
{
	int vertex;
	struct vertex *crawler;
	
	printf("grph->num_nodes = %d\n", grph->num_nodes);
	
	for (vertex = 0; vertex < grph->num_nodes; vertex++) {
		printf("\nvertex %d ", vertex);
		
		crawler = grph->array[vertex].next;
		
		while(crawler)
		{
			printf("--> %d ", crawler->dest);
			crawler = crawler->next;	
		}
	}	
}
