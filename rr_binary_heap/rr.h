#ifndef _RR_
#define _RR_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"
#include "graph.h"
                                        // Instruction misses - cache misses TODO


typedef struct list{
    vertex * vtx;
    struct list * next;
} list;

typedef struct head_list
{
    list * first;
    list * last;
} head_list;

/************************************************************************************************
*************************************************************************************************
****************************** ALGORITMOS DE RAMALINGAM E REPS *******************************
*************************************************************************************************
************************************************************************************************/
void rr_recalculate_shortest_path(vertex *graph, heap *queue);
void rr_add_edge(vertex *graph, int tail, int head, int cost, heap * queue);
void rr_remove_edge(vertex *graph,  int tail, int head, heap * queue);
head_list *rr_mark_affected(vertex *graph, edge *edge_marked);
void rr_estimate_new_pi(vertex *graph, head_list *affected_list, heap *queue);
edge * find_edge_pred(vertex * head, int key);
edge * find_edge_adj(vertex * tail, int key);
edge ** find_pointer_edge_pred(vertex *head, edge *edge_ref);
edge ** find_pointer_edge_adj(vertex *tail, edge *edge_ref);

void rr_print_sssp(vertex * graph); // TODO


/************************************************************************************************
*************************************************************************************************
****************************** ALGORITMOS DE MANIPULAÇÃO DE LISTA *******************************
*************************************************************************************************
************************************************************************************************/

head_list * list_vtx_new();

list * list_vtx_insert(head_list * h_list, vertex * v_list);

vertex * list_vtx_remove(head_list * h_list);


#endif
