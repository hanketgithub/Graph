//
//  queue.h
//  Graph
//
//  Created by Hank Lee on 2018/9/12.
//  Copyright © 2018 Hank Lee. All rights reserved.
//

#ifndef queue_h
#define queue_h

#define MAXV    100

typedef struct
{
    int data[MAXV];
    int r;
    int w;
} queue_t;

bool is_empty(queue_t *queue);

void enqueue(queue_t *queue, int v);

int dequeue(queue_t *queue);

#endif /* queue_h */
