#include "graph.h"
#include "queue.h"

void inline __add_edge(struct graph *grph, int src, int dest)
{
 //       add_dest(&grph->array[src].next, dest);
 		struct vertex *crawler = &grph->array[src];
 
 		if (!crawler->next)
 		{
 			crawler->next = malloc(sizeof(struct vertex));
 			crawler = crawler->next;
 			crawler->dest = dest;
 			crawler->next = NULL;
		} else {
			while (crawler->next)
				crawler = crawler->next;
			
			crawler->next = malloc(sizeof(struct vertex));
 			crawler = crawler->next;
 			crawler->dest = dest;
 			crawler->next = NULL;	
		}
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
        
        grph->num_nodes = num_nodes;

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

void print_graph(struct graph *grph);
void bfs_graph(struct graph *grph, int start);

int main(void)
{
	int i;
	        
        struct graph *Graph;

        Graph = init_graph(5);
        
        add_edge(Graph, 0, 1);
        add_edge(Graph, 0, 2);
        add_edge(Graph, 1, 2);
        add_edge(Graph, 2, 0);
        add_edge(Graph, 2, 3);
        add_edge(Graph, 3, 3);
        
		print_graph(Graph);
		
		bfs_graph(Graph, 2);
}
  
