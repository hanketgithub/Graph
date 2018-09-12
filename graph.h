//
//  graph.h
//  Graph
//
//  Created by Hank Lee on 2018/9/12.
//  Copyright © 2018 Hank Lee. All rights reserved.
//

#ifndef graph_h
#define graph_h

#define MAXV    100

typedef enum
{
    status_undiscovered,
    status_discovered,
    status_processed,
} status_e;

typedef struct edge_node
{
    int y;
    int weight;
    struct edge_node *next;
} edgenode_t;

typedef struct
{
    edgenode_t *edges[MAXV];
    int n_vertex;
    int n_edges;
    bool directed;
} graph_t;

#endif /* graph_h */
