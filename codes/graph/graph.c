#include <stdio.h>
#include <stdlib.h>

#define HEAD -1

struct vertex
{
	int dest;
	struct vertex *next;
};

struct graph
{
	int num_nodes;
	struct vertex *array;
};

void add_dest(struct vertex **crawler, int dest)
{
	if (*crawler) {
		while((*crawler)->next)
			*crawler = (*crawler)->next;

		(*crawler)->next = malloc(sizeof(struct vertex));
		
		*crawler = (*crawler)->next;
		(*crawler)->dest = dest;
		(*crawler)->next = NULL;
	}

	*crawler = malloc(sizeof(struct vertex));
	(*crawler)->dest = dest;
	(*crawler)->next = NULL;			
}

void inline __add_edge(struct graph *grph, int src, int dest)
{
	add_dest(&grph->array[src].next, dest);	
}

void inline add_edge(struct graph *grph, int src, int dest)
{
	__add_edge(grph, src, dest);	
	__add_edge(grph, dest, src);	
}

struct graph *init_graph(int num_nodes)
{
	struct graph *grph;
	int vertex;
	
	grph = malloc(sizeof(struct graph));
	
	if (!grph) {
		perror("malloc :");
		exit(0);
	}

	grph->array = malloc(sizeof(struct vertex)*num_nodes);
	if (!grph->array) {
		perror("malloc :");
		exit(0);
	}

	for (vertex = 0; vertex < num_nodes ; vertex++) {
		grph->array[vertex].next = NULL;
		grph->array[vertex].dest = HEAD;
	}

	return grph;
}


int main(void)
{
	struct graph *Graph;

	
	Graph = init_graph(5);

	add_edge(Graph, 0, 1);
	add_edge(Graph, 1, 2);
	add_edge(Graph, 2, 3);
	add_edge(Graph, 3, 4);
	add_edge(Graph, 4, 0);


	return 0;
}	
