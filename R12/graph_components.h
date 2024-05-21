/*
 * ---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */

#ifndef GRAPH_COMPONENTS_H_
#define GRAPH_COMPONENTS_H_

# define True 1
# define False 0

typedef struct {
	int num;
	char name[20];
} Vertex;

Vertex* create_vertex(int num, char *name);
void print_vertex(Vertex *v);
void destroy_vertex(Vertex **v);
int is_equal_vertex(Vertex *v1, Vertex *v2);

typedef struct {
	Vertex *v1;
	Vertex *v2;
	int weight;
	int directed;
} Edge;
Edge* create_edge(Vertex *v1, Vertex *v2, int w, int d);
void print_edge(Edge *e);
void destroy_edge(Edge **e);
int is_equal_edge(Edge *e1, Edge *e2);

#endif /* GRAPH_COMPONENTS_H_ */
