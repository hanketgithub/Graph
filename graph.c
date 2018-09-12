//
//  graph.c
//  Graph
//
//  Created by Hank Lee on 2018/9/12.
//  Copyright © 2018 Hank Lee. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

void init_graph(graph_t *g, bool directed)
{
    for (int i = 0; i < MAXV; i++)
    {
        g->edges[i] = NULL;
    }
    
    g->n_vertex = 0;
    g->n_edges = 0;
    g->directed = false;
}

void print_graph(graph_t *g)
{
    for (int i = 0; i < g->n_vertex; i++)
    {
        edgenode_t *v = g->edges[i];
        while (v)
        {
            printf("[%d-%d]", i, v->y);
            v = v->next;
        }
        printf("\n");
    }
}

void insert_edge(graph_t *g, int x, int y, bool directed)
{
    edgenode_t *p = calloc(1, sizeof(edgenode_t));
    
    p->y = y;
    p->weight = 0;
    
    // insert to list head
    p->next = g->edges[x];
    g->edges[x] = p;
    
    if (!directed)
    {
        insert_edge(g, y, x, true);
    }
    else
    {
        g->n_edges++;
    }
}

void read_graph(graph_t *g, bool directed)
{
    int m;      // number of edges
    int x, y;   // edge (x,y)
    
    init_graph(g, directed);
    
    scanf("%d,%d", &(g->n_vertex), &m);
    
    for (int i = 0; i < m; i++)
    {
        scanf("%d,%d", &x, &y);
        insert_edge(g, x, y, directed);
    }
}

