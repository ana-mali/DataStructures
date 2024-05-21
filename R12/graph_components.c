/**
 * ------------------------------------------
 * Graph Components (Undirected, Non-weighted)
 * ------------------------------------------
 */
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>
# include "graph_components.h"

//------------------- Vertex -----------------------
/**
 * --------------------------------------------------------------
 * Parameters: 	n- a vertex number (int)
 * 				s- a vertex label/name (char*)
 * Returns: 	A vertex pointer (Vertex*)
 * Description:	Creates a vertex using the given number and name
 * 				Uses dynamic memory allocation to create a vertex pointer
 * 				Then sets the vertex number (num) and label (name) to the given parameters
 * --------------------------------------------------------------
 */
Vertex* create_vertex(int n, char *s) {
	Vertex *v = (Vertex*) malloc(sizeof(Vertex));
	v->num = n;
	if (strcmp(s, "") == 0)
		sprintf(v->name, "V%d", n);
	else
		strcpy(v->name, s);

	return v;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	A vertex pointer (Vertex*)
 * Returns: 	none
 * Description:	prints a given vertex as: (<num>,<name>)
 * Asserts:		vertex pointer is not null
 * ------------------------------------------------------------
 */
void print_vertex(Vertex *v) {
	assert(v);
	printf("(%d,%s)", v->num, v->name);
	return;
}

/**
 * -----------------------------------------------------
 * Parameters: 	A vertex double pointer (Vertex**)
 * Returns: 	none
 * Description:	destroys a vertex
 * 				1- sets vertex number to 0
 * 				2- sets vertex name to an empty string
 * 				3- deallocates vertex pointer and set it to NULL
 * Asserts:		*v and **v are not null
 * ------------------------------------------------------
 */
void destroy_vertex(Vertex **v) {
	assert(v && *v);
	(*v)->num = 0;
	strcpy((*v)->name, "");
	free(*v);
	*v = NULL;
	return;
}

/**
 * --------------------------------------------------------------------
 * Parameters: 	First vertex (Vertex*)
 * 				Second vertex (Vertex*)
 * Returns: 	True/False
 * Description:	checks if two vertices are equal
 * 				Equality is established if both vertex names are equal, ignores vertex numbers
 * 				returns True (1) if equal, and False (0) if unequal
 * Asserts:		v1 and v2 pointers are not null
 * ---------------------------------------------------------------------
 */
int is_equal_vertex(Vertex *v1, Vertex *v2) {
	assert(v1 && v2);
	return (strcmp(v1->name, v2->name) != 0);
}

//--------------------- Edge -----------------------------
/**
 * -----------------------------------------------------------------
 * Parameters: 	v1 - A source vertex (Vertex*)
 * 				v2 - A destination vertex (Vertex*)
 * 				w - edge weight
 * 				d - direction
 * Returns: 	An edge pointer (Edge*)
 * Description:	Creates an edge using given parameters
 * 				1- allocates memory to an edge pointer
 * 				2- sets the two vertices, weight and directed flag to given parameters.
 * 				3- This implementation does not allow loops (an edge to from a vertex to itself)
 * 					if v1 is the same as v2 --> print error and return NULL
 * 				4- Sets weight and directed to 0, ignores given values
 * 				asserts given two vertices are not NULL
 * ------------------------------------------------------------------
 */
Edge* create_edge(Vertex *v1, Vertex *v2, int w, int d) {
	assert(v1 && v2);
	Edge *e = (Edge*) malloc(sizeof(Edge));
	if (is_equal_vertex(v1, v2) == 0) {
		printf("Error(create_edge): loops are not supported\n");
		return NULL;
	}
	e->v1 = v1;
	e->v2 = v2;
	e->weight = 0;
	e->directed = 0;

	return e;
}

/**
 * --------------------------------------------------------------------
 * Parameters: 	An edge double pointer (Edge**)
 * Returns: 	none
 * Description:	destroys an edge
 * 				Deallocates the edge pointer
 * 				Note: since the vertices may be shared by other edges -->
 * 				the function should not destroy the vertices
 * Asserts 		**e and *e are not null
 * --------------------------------------------------------------------
 */
void destroy_edge(Edge **e) {
	assert(e && *e);
	(*e)->v1 = NULL;
	(*e)->v2 = NULL;
	free(*e);
	*e = NULL;
	return;
}

/**
 * -----------------------------------------------------------
 * Parameters: 	An edge pointer (Edge*)
 * Returns: 	none
 * Description:	prints an edge
 * 				format: "[<v1>-----<v2>]"
 * Asserts:		edge pointer is not null
 * -----------------------------------------------------------
 */
void print_edge(Edge *e) {
	assert(e);
	printf("[");
	print_vertex(e->v1);
	printf("-----");
	print_vertex(e->v2);
	printf("]");
	return;
}

/**
 * ---------------------------------------------------------------------------
 * Parameters: 	e1 - First edge (Edge*)
 * 				e2 - Second edge (Edge*)
 * Returns: 	True/False
 * Description:	checks if two edges are equal
 * 				Equality is established if the four components of the edges match (v1,v2,w,d)
 * 				returns True (1) if equal, and False (0) if unequal
 * 				Note: v1--v2 is equal to v2--v1
 * Asserts:		e1 and e2 pointers are not null
 * ----------------------------------------------------------------------------
 */
int is_equal_edge(Edge *e1, Edge *e2) {
	assert(e1 && e2);
	if (e1->weight != e2->weight)
		return False;
	if (e1->directed != e2->directed)
		return False;
	if (is_equal_vertex(e1->v1, e2->v2) && is_equal_vertex(e1->v2, e2->v2))
		return True;
	if (is_equal_vertex(e1->v2, e2->v1) == 0
			&& is_equal_vertex(e1->v1, e2->v2) == 0)
		return True;
	return False;
	return 0;
}
