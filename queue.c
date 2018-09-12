//
//  queue.c
//  Graph
//
//  Created by Hank Lee on 2018/9/12.
//  Copyright © 2018 Hank Lee. All rights reserved.
//

#include <stdbool.h>

#include "queue.h"

bool is_empty(queue_t *queue)
{
    if (queue->r == queue->w)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(queue_t *queue, int v)
{
    int w = queue->w;
    queue->data[w] = v;
    queue->w++;
}

int dequeue(queue_t *queue)
{
    int r = queue->r;
    int result = queue->data[r];
    queue->r++;
    return result;
}

