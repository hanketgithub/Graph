//
//  bfs.c
//  Graph
//
//  Created by Hank Lee on 2018/9/12.
//  Copyright © 2018 Hank Lee. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>

#include "graph.h"
#include "queue.h"
#include "bfs.h"

void process_vertex(int v)
{
    printf("processing vertex %d\n", v);
}

void process_vertex_late(int v)
{
    printf("processed vertex %d done\n", v);
}

status_e status[MAXV];

void bfs(graph_t *g, int start)
{
    queue_t q = { 0 };
    edgenode_t *p;
    
    status[start] = status_discovered;
    enqueue(&q, start);
    
    while (!is_empty(&q))
    {
        int v = dequeue(&q);
        process_vertex(v);
        status[v] = status_processed;
        p = g->edges[v];
        while (p)
        {
            if (status[p->y] == status_undiscovered)
            {
                status[p->y] = status_discovered;
                enqueue(&q, p->y);
                printf("Node %d is new!\n", p->y);
            }
            else if (status[p->y] == status_discovered)
            {
                printf("Node %d is waiting to be processed!\n", p->y);
            }
            else {
                printf("Node %d is visited!\n", p->y);
            }
            p = p->next;
        }
        process_vertex_late(v);
    }
}

