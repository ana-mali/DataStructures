/*
 * ---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */

#ifndef GRAPH_H_
#define GRAPH_H_
# include "graph_components.h"
# define BLOCK 5
# define True 1
# define False 0

typedef struct {
	int **matrix; //adjacency matrix
	Vertex *vertex_list;
	int vertex_count;
	int edge_count;
	int directed;
	int weighted;
} Graph;

Graph* create_graph(int w, int d);
void destroy_graph(Graph **g);
void print_graph(Graph *g);
int is_null(Graph *g);
int is_empty_graph(Graph *g);
int add_vertex_graph(Graph *g, Vertex *v);
int has_vertex_graph(Graph *g, Vertex *v);
int remove_vertex_graph(Graph *g, Vertex *v);
int add_edge_graph(Graph *g, Edge *e);
int has_edge_graph(Graph *g, Edge *e);
int remove_edge_graph(Graph *g, Edge *e);

#endif /* GRAPH_H_ */
