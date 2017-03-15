#include "graph.h"
#include "queue.h"

void bfs_graph(struct graph *grph, int start)
{
	int vertex = 0;
	int dst;
	int *vrtx_vstd;
	struct vertex *crawler;
	
	printf("\n BFS \n");
	
	vrtx_vstd = malloc(sizeof(int)*grph->num_nodes);
	
	 for (vertex = 0; vertex < grph->num_nodes; vertex++) {
	 	vrtx_vstd[vertex] = UNTOUCHED;
	 }
	 
	vertex = start;
	
	enqueue(vertex);
		 	
	while (-1 != (dst = dequeue())) {
	 	// Mark it as visited
	 	if (UNTOUCHED == vrtx_vstd[dst]) {
			printf("%d ", dst);
			vrtx_vstd[dst] = VISITED;
			// goto all its connected nodes and enqueue them if not visited.
			crawler = grph->array[dst].next;
			while (crawler) {
				if (!(VISITED == vrtx_vstd[crawler->dest])){
						enqueue(crawler->dest);
				}
				crawler = crawler->next;
			}
		}
	 }
	 
	 free(vrtx_vstd);
}
