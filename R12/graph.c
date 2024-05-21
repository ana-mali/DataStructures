/*
 * -------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student email: mali4700@mylaurier.ca
 * -------------------------
 */

/**
 * ------------------------------------------
 * Graph Implementation (Undirected, Non-weighted)
 * ------------------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include "graph.h"
void expand_graph(Graph *g);
/**
 * -----------------------------------------------------------------
 * Parameters: 	none
 * Returns: 	A graph pointer (Graph*)
 * Description:	Creates a null graph (no edges, no vertices)
 * 				1- Creates an empty adjacency matrix BLOCK x BLOCK
 * 				2- directed and weighted flags set to 0
 * 				3- Initialize vertex and edge count to 0
 * 				5- Sets all matrix elements to 0
 * -----------------------------------------------------------------
 */
Graph* create_graph(int w, int d) {
	Graph *g = (Graph*) malloc(sizeof(Graph));
	g->vertex_list = (Vertex*) malloc(sizeof(Vertex) * BLOCK);
	g->matrix = (int**) malloc(sizeof(int*) * BLOCK);
	int i, j;
	for (i = 0; i < BLOCK; i++)
		g->matrix[i] = (int*) malloc(sizeof(int) * BLOCK);
	for (i = 0; i < BLOCK; i++)
		for (j = 0; j < BLOCK; j++)
			g->matrix[i][j] = 0;

	g->vertex_count = 0;
	g->edge_count = 0;
	g->directed = 0;
	g->weighted = 0;
	return g;
}

/**
 * ----------------------------------------------------------------------
 * Parameters: 	A graph double pointer (Graph**)
 * Returns: 	none
 * Description:	destroys a graph through:
 * 				1- free memory allocated to the adjacency matrix, set pointer to NULL
 * 				2- free memory allocated to vertex list, set pointer to NULL
 * 				3- Reset edge and vertex count to 0
 * 				4- free memory allocated to graph, set pointer to NULL
 * Asserts:		Graph* and Graph** are not null
 * -----------------------------------------------------------------------
 */
void destroy_graph(Graph **g) {
	assert(g && *g);
	int num_of_blocks = (*g)->vertex_count / BLOCK + 1;
	int i;
	for (i = 0; i < num_of_blocks; i++) {
		free((*g)->matrix[i]);
		(*g)->matrix[i] = NULL;
	}
	free((*g)->matrix);
	(*g)->matrix = NULL;
	(*g)->vertex_count = 0;
	(*g)->edge_count = 0;
	free(*g);
	*g = NULL;
	return;
}

/**
 * --------------------------------------------------------------
 * Parameters: 	A graph pointer (Graph*)
 * Returns: 	True/False
 * Description:	Checks if a given graph is a null graph
 * 				A null graph is a graph with no vertices (which also means no edges)
 * 				return True if null graph and False otherwise
 * Asserts:		Graph pointer is not NULL
 * ---------------------------------------------------------------
 */
int is_null_graph(Graph *g) {
	assert(g);
	return (g->vertex_count == 0);
}

/**
 * -----------------------------------------------------------
 * Parameters: 	A graph pointer (Graph*)
 * Returns: 	True/False
 * Description:	Checks if a given graph is an empty graph
 * 				An empty graph is a graph with no edges
 * 				return True if empty graph and False otherwise
 * Asserts:		Graph pointer is not NULL
 * -----------------------------------------------------------
 */
int is_empty_graph(Graph *g) {
	assert(g);
	return (g->edge_count == 0);
}

/**
 * ------------------------------------------------------------------------
 * Parameters: 	A graph pointer (Graph*)
 * Returns: 	none
 * Description:	Prints the contents of a given graph
 * 				1- if null graph, prints: "<"null graph>\n", otherwise:
 * 				2- graph meta-data in the following format:
 * 					"(<representation>): #Vertices = <num>, #edges = <num>\n"
 * 				3- Prints adjacency matrix in tabular format
 * 				Asserts given graph is not NULL
 * 	Analysis:	Printing a graph is O(V^2)
 * 				because adjacency matrix has O(V^2) memory blocks
 * -------------------------------------------------------------------------
 */
void print_graph(Graph *g) {
	assert(g!=NULL);
	int i, j;
	printf("(Adjacency Matrix Representation): #Vertices = %d, #Edges = %d\n",
			g->vertex_count, g->edge_count);
	if (is_null_graph(g)) {
		printf("<null graph>\n");
		return;
	}

	printf("Vertices: ");
	for (i = 0; i < g->vertex_count; i++) {
		print_vertex(&g->vertex_list[i]);
		if ((i + 1) % BLOCK == 0 || i == g->vertex_count - 1)
			printf("\n");
		else
			printf(" , ");
	}

	if (g->vertex_count == 1)
		printf("%5s\n", "-");
	else
		for (i = 0; i < g->vertex_count; i++) {
			for (j = 0; j < g->vertex_count; j++) {
				if (g->matrix[i][j] == 0)
					printf("%5s ", "-");
				else
					printf("%5d ", g->matrix[i][j]);
			}
			printf("\n");
		}

	return;
}

/**
 * ---------------------------------------------------------------------------
 * Parameters: 	A graph pointer (Graph*)
 * 				A vertex pointer (Vertex*)
 * Returns: 	True/False
 * Description:	Checks if a given graph contains the given vertex
 * 				Check for vertex name, not number
 * Asserts:		Graph and vertex pointers are not NULL
 * Analysis:	O(1)
 * ----------------------------------------------------------------------------
 */
int has_vertex_graph(Graph *g, Vertex *v) {
	assert(g && v);
	if (is_null_graph(g))
		return False;
	if (v->num < g->vertex_count)
		return True;
	return False;
}

/**
 * ---------------------------------------------------------------------------
 * Parameters: 	A graph pointer (Graph*)
 * 				A vertex pointer (Vertex*)
 * Returns: 	success (True/False)
 * Description:	Adds a vertex to a graph
 * 				Performs the following:
 * 				1- if vertex already exist --> error, return False
 * 				2- Set the vertex num to a new sequential value
 * 				3- Reallocates to new size (multiple of blocks), if necessary
 * 				4- Adds vertex to the array
 * 				5- Increments vertex_count
 * 				Asserts given graph and vertex are not NULL pointers
 * Analysis:	?
 * ----------------------------------------------------------------------------
 */
int add_vertex_graph(Graph *g, Vertex *v) {
	assert(g && v);
	if (has_vertex_graph(g, v)) {
		printf("Error(add_vertex_graph): Vertex already exist\n");
		return False;
	}
	if (!is_null_graph(g) && (g->vertex_count % BLOCK == 0))
		expand_graph(g);

	v->num = g->vertex_count;
	g->vertex_count++;
	g->vertex_list[g->vertex_count - 1] = *v;
	return True;
}
void expand_graph(Graph *g) {
	assert(g);
	int i, j;
	int new_size = g->vertex_count + BLOCK;
	g->vertex_list = realloc(g->vertex_list, sizeof(Vertex) * new_size); //expand vertex list
	g->matrix = realloc(g->matrix, sizeof(int*) * new_size); //resize matrix
	//add columns to existing rows
	for (i = 0; i < g->vertex_count; i++)
		g->matrix[i] = realloc(g->matrix[i], sizeof(int) * new_size);
	for (i = 0; i < g->vertex_count; i++)
		for (j = g->vertex_count; j < new_size; j++)
			g->matrix[i][j] = 0;
	//create new rows
	for (i = g->vertex_count; i < new_size; i++)
		g->matrix[i] = (int*) malloc(sizeof(int) * new_size);
	for (i = g->vertex_count; i < new_size; i++)
		for (j = 0; j < new_size; j++)
			g->matrix[i][j] = 0;
	return;

}
/**
 * -------------------------------------------------------------------
 * Parameters: 	A graph pointer (Graph*)
 * 				An edge pointer (Edge*)
 * Returns: 	True/False
 * Description:	Checks if a given graph contains the given edge
 * 				Need to verify:
 * 				1- Graph is not empty/null
 * 				2- Graph contains both vertices of the given edge
 * 				3- Edge is undirected
 * 				In order to return True:
 * 				If weighted graph, matrix[v1][v2] should be equivalent to given weight
 * 				If non-weighted graph, matrix[v1][v2] should be 1
 * 				Asserts given graph and edge are not NULL pointers
 * Analysis:	?
 * -------------------------------------------------------------------
 */
int has_edge_graph(Graph *g, Edge *e) {
	assert(g && e);
	if (is_empty_graph(g))
		return False;
	if (e->v1->num >= g->vertex_count || e->v2->num >= g->vertex_count)
		return False;
	if (e->directed || e->weight)
		return False;
	if (g->matrix[e->v1->num][e->v2->num] == 1)
		return True;
	return False;
}

/**
 * ---------------------------------------------------------------------------------
 * Parameters: 	A graph pointer (Graph*)
 * 				An edge pointer (Edge*)
 * Returns: 	success (True/False)
 * Description:	Adds an edge to a graph
 * 				Performs the following:
 * 				1- if edge already exist --> error, return False
 * 				2- Checks for compatibility in terms of weight and directed
 * 					if incompatible --> error, return False
 * 				3- If any of the vertices does not exist in the graph --> add it
 * 				4- Adds edge to the matrix by:
 * 					setting the cell to 1 if non-weighted
 * 					setting the cell to the given edge weight if weighted
 * 				5- Increments the edge count
 * 				6- If undirected graph, ensure symmetry of matrix
 * Asserts:		Given graph and edge are not NULL pointers
 * Analysis:	O(1)
 * --------------------------------------------------------------------------------
 */
int add_edge_graph(Graph *g, Edge *e) {
	assert(g && e);
	if (has_edge_graph(g, e)) {
		printf("Error(add_edge_graph): edge already exists\n");
		return False;
	}
	if (e->directed || e->weight) {
		printf("Error(add_edge_graph): incompatible edge\n");
		return False;
	}
	if (!has_vertex_graph(g, e->v1))
		add_vertex_graph(g, e->v1);
	if (!has_vertex_graph(g, e->v2))
		add_vertex_graph(g, e->v2);

	g->matrix[e->v1->num][e->v2->num] = 1;
	g->matrix[e->v2->num][e->v1->num] = 1;
	g->edge_count++;
	return 0;
}

/**
 * ----------------------------------------------------------------
 * Parameters: 	A graph pointer (Graph*)
 * 				An edge pointer (Edge*)
 * Returns: 	success: (True/False)
 * Description:	removes a given edge from graph
 * 				1- if the edge does not exist --> error, return False
 * 				2- Set the corresponding matrix cell to 0
 * 					If undirected, maintain symmetry.
 * 				3- decrement the edge count
 * Asserts:		Graph and Edge are not NULL pointers
 * Analysis:	O(1)
 * ---------------------------------------------------------------
 */
int remove_edge_graph(Graph *g, Edge *e) {
	assert(g && e);
	if (is_empty_graph(g) || !has_edge_graph(g, e)) {
		printf("Error(remove_edge_graph): Edge does not exists\n");
		return False;
	}
	g->matrix[e->v1->num][e->v2->num] = 0;
	g->matrix[e->v2->num][e->v1->num] = 0;
	g->edge_count--;
	return True;
}

/*
 * -------------- Analysis Summary of Adjacency Matrix Representation ------------
 * Memory:        O(v^2)
 * hasVertex:     O(1)
 * addVertex:     O(1)
 * removeVertex:  O(1)
 * hasEdge:       O(1)
 * addEdge:       O(1)
 * removeEdge:    O(1)
 * -----------------------------------------------------------------------
 */
