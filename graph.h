#include <stdio.h>
#include <stdlib.h>

#define HEAD -1
#define UNTOUCHED -2
#define VISITED 0xCAFEBABE

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
