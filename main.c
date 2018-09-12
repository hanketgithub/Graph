//
//  main.c
//  Graph
//
//  Created by Hank Lee on 2018/9/12.
//  Copyright © 2018 Hank Lee. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>

#include "graph.h"

int main(int argc, const char * argv[]) {
    graph_t graph = { 0 };
    
    read_graph(&graph, false);
    print_graph(&graph);
    
    //bfs(&grpah);
    
    return 0;
}
