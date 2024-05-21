/**
 * -----------------------------------------------------
 * Testing for undirected non-weighted Graph
 * -----------------------------------------------------
 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "graph.h"

void test_vertex();
void test_edge();
void test_basic_graph();
void test_vertex_graph();
void test_edge_graph();
//void test_remove_vertex();

int main() {
	setbuf(stdout, NULL);
	test_vertex();
	test_edge();
	test_basic_graph();
	test_vertex_graph();
	test_edge_graph();
//	test_remove_vertex();
	return 0;
}

void test_vertex() {
	printf("------------------------------\n");
	printf("Start: Testing Vertex Struct:\n\n");

	char cities[4][20] = { "Toronto", "Ottawa", "Waterloo", "" };
	Vertex *v[4];

	int i;
	printf("Creating Vertices:\n");
	for (i = 0; i < 4; i++) {
		v[i] = create_vertex(i, cities[i]);
		print_vertex(v[i]);
		printf("\n");
	}

	printf("\n");
	printf("Testing is_equal_vertex:\n");
	print_vertex(v[0]);
	print_vertex(v[1]);
	printf(" Equal? %d\n", is_equal_vertex(v[0], v[1]));

	print_vertex(v[2]);
	print_vertex(v[2]);
	printf(" Equal? %d\n", is_equal_vertex(v[2], v[2]));

	print_vertex(v[2]);
	v[0]->num = v[2]->num;
	print_vertex(v[0]);
	printf(" Equal? %d\n", is_equal_vertex(v[2], v[0]));

	strcpy(v[2]->name, "Toronto");
	print_vertex(v[2]);
	v[0]->num = 0;
	print_vertex(v[0]);
	printf("Equal? %d\n", is_equal_vertex(v[2], v[0]));
	printf("\n");

	printf("destroy all vertices:\n");
	for (i = 0; i < 4; i++)
		destroy_vertex(&v[i]);
	printf("vertices were successfully destroyed\n\n");

	printf("End: Testing Vertex Struct\n");
	printf("------------------------------\n\n");
	return;
}

void test_edge() {
	printf("------------------------------\n");
	printf("Start: Testing Edge Struct:\n\n");

	char cities[4][20] = { "Toronto", "Ottawa", "Waterloo", "London" };
	Vertex *v[4];

	int i;
	printf("------------ start of test_edge() -------------\n");
	printf("List of Vertices:\n");
	for (i = 0; i < 4; i++) {
		v[i] = create_vertex(i, cities[i]);
		print_vertex(v[i]);
		printf(" ");
	}
	printf("\n\n");

	Edge *e[4];

	printf("Create edge between London and Waterloo:\n");
	e[0] = create_edge(v[2], v[3], 0, 0);
	print_edge(e[0]);
	printf("\n\n");

	printf("Create edge between Toronto and Waterloo:\n");
	e[1] = create_edge(v[0], v[3], 114, 0);
	print_edge(e[1]);
	printf("\n\n");

	printf("Create edge between Ottawa and Toronto:\n");
	e[2] = create_edge(v[1], v[0], 0, 1);
	print_edge(e[2]);
	printf("\n\n");

	printf("Create edge betwee Ottawa and London:\n");
	e[3] = create_edge(v[1], v[3], 450, 1);
	print_edge(e[3]);
	printf("\n\n");

	printf("Testing Equality:\n");
	print_edge(e[2]);
	print_edge(e[0]);
	printf(" Equal? %d\n", is_equal_edge(e[2], e[0]));

	print_edge(e[2]);
	print_edge(e[2]);
	printf(" Equal? %d\n", is_equal_edge(e[2], e[2]));
	printf("\n");

	printf("destroy edges:\n");
	for (i = 0; i < 4; i++)
		destroy_edge(&e[i]);
	printf("All edges successfully destroyed\n");

	printf("destroy vertices:\n");
	for (i = 0; i < 4; i++)
		destroy_vertex(&v[i]);
	printf("All vertices successfully destroyed\n\n");

	printf("End: Testing Edge Struct\n");
	printf("------------------------------\n\n");
	return;
}

void test_basic_graph() {
	printf("------------------------------\n");
	printf("Start: Testing Graph Basic Functions:\n\n");

	printf("Graph* g = create_graph();\n");
	Graph *g = create_graph(0, 0);
	printf("graph created successfully\n");
	printf("\n");

	printf("Invoke print_graph(g)\n");
	print_graph(g);
	printf("\n");

	printf("is_null? = %d\n", is_null_graph(g));
	printf("is_empty? = %d\n", is_empty_graph(g));
	printf("\n");

	printf("vertex count = %d\n", g->vertex_count);
	printf("edge count = %d\n", g->edge_count);
	printf("\n");

	destroy_graph(&g);
	printf("graph destroyed successfully\n");
	printf("\n");

	printf("End: Testing Graph Basic functions\n");
	printf("------------------------------\n\n");
	return;
}

void test_vertex_graph() {
	printf("------------------------------\n");
	printf("Start: Testing Graph with vertices:\n\n");

	printf("Creating an empty graph\n");
	Graph *g = create_graph(0, 0);
	print_graph(g);
	printf("\n");

	Vertex v[15];
	char temp[5];
	int i;
	for (i = 0; i < 11; i++) {
		sprintf(temp, "V%d", i);
		v[i] = *create_vertex(i, temp);
		printf("Adding Vertex:");
		print_vertex(&v[i]);
		printf("\n");
		printf("add_vertex_graph successful? = %d\n",
				add_vertex_graph(g, &v[i]));
		print_graph(g);
		printf("\n");
	}

	printf("Adding a duplicate Vertex:");
	print_vertex(&v[--i]);
	printf("\n");
	printf("add_vertex_graph successful? = %d\n", add_vertex_graph(g, &v[i]));
	print_graph(g);
	printf("\n");

	destroy_graph(&g);
	printf("Graph destroyed successfully\n\n");

	printf("End: Testing Graph with vertices\n");
	printf("------------------------------\n\n");
	return;
}

void test_edge_graph() {
	printf("------------------------------\n");
	printf("Start: Testing Graph with Edges:\n\n");

	printf("Creating a graph with 8 vertices\n");
	Graph *g = create_graph(1, 0);

	Vertex *v0 = create_vertex(0, "V0");
	Vertex *v1 = create_vertex(1, "V1");
	Vertex *v2 = create_vertex(2, "V2");
	Vertex *v3 = create_vertex(3, "V3");
	Vertex *v4 = create_vertex(4, "V4");
	Vertex *v5 = create_vertex(5, "V5");
	Vertex *v6 = create_vertex(6, "V6");
	Vertex *v7 = create_vertex(7, "V7");

	add_vertex_graph(g, v0);
	add_vertex_graph(g, v1);
	add_vertex_graph(g, v2);
	add_vertex_graph(g, v3);
	add_vertex_graph(g, v4);
	add_vertex_graph(g, v5);
	add_vertex_graph(g, v6);
	add_vertex_graph(g, v7);

	print_graph(g);
	printf("\n");

	Edge *e[12];

	printf("Adding an edge between V0 and V1\n");
	e[0] = create_edge(v0, v1, 5, 0);
	add_edge_graph(g, e[0]);
	print_graph(g);
	printf("\n");

	printf("is_null? = %d\n", is_null_graph(g));
	printf("is_empty? = %d\n", is_empty_graph(g));
	printf("\n");

	printf("Adding an edge between V4 and V5\n");
	e[1] = create_edge(v4, v5, 5, 0);
	add_edge_graph(g, e[1]);
	print_graph(g);
	printf("\n");

	printf("Adding an edge between V1 and V4\n");
	e[2] = create_edge(v1, v4, 5, 0);
	add_edge_graph(g, e[2]);
	print_graph(g);
	printf("\n");

	printf("Adding an edge between V0 and V4\n");
	e[3] = create_edge(v0, v4, 5, 0);
	add_edge_graph(g, e[3]);
	print_graph(g);
	printf("\n");

	printf("Adding an edge between V1 and V5\n");
	e[4] = create_edge(v1, v5, 5, 0);
	add_edge_graph(g, e[4]);
	print_graph(g);
	printf("\n");

	printf("Adding an edge between V3 and V4\n");
	e[5] = create_edge(v3, v4, 5, 0);
	add_edge_graph(g, e[5]);
	print_graph(g);
	printf("\n");

	printf("Adding an edge between V2 and V6\n");
	e[6] = create_edge(v2, v6, 5, 0);
	add_edge_graph(g, e[6]);
	print_graph(g);
	printf("\n");

	printf("Adding an edge between V2 and V6 (a duplicate)\n");
	e[6] = create_edge(v2, v6, 5, 0);
	add_edge_graph(g, e[6]);
	print_graph(g);
	printf("\n");

	printf("Adding an edge between V6 and V2 (reverse order of vertices)\n");
	e[7] = create_edge(v6, v2, 5, 0);
	add_edge_graph(g, e[7]);
	print_graph(g);
	printf("\n");

	printf("Adding an edge between V3 and V6 (a directed edge)\n");
	e[7] = create_edge(v3, v6, 5, 0);
	add_edge_graph(g, e[7]);
	print_graph(g);
	printf("\n");

	printf("Adding an edge between V3 and V6 (a non-weighted edge)\n");
	e[7] = create_edge(v3, v6, 0, 0);
	add_edge_graph(g, e[7]);
	print_graph(g);
	printf("\n");

	printf("Adding four more edges\n");
	e[8] = create_edge(v7, v6, 5, 0);
	add_edge_graph(g, e[8]);
	e[9] = create_edge(v2, v7, 5, 0);
	add_edge_graph(g, e[9]);
	e[10] = create_edge(v0, v7, 5, 0);
	add_edge_graph(g, e[10]);
	e[11] = create_edge(v4, v6, 5, 0);
	add_edge_graph(g, e[11]);
	print_graph(g);
	printf("\n");

	printf("Removing edge between V4 and V6\n");
	remove_edge_graph(g, e[11]);
	print_graph(g);
	printf("\n");

	printf("Removing edge between V4 and V6 (again)\n");
	remove_edge_graph(g, e[11]);
	print_graph(g);
	printf("\n");

	printf("Removing a middle edge (V2-V6)\n");
	remove_edge_graph(g, e[6]);
	print_graph(g);
	printf("\n");

	printf("Removing first edge (V0-V1)\n");
	remove_edge_graph(g, e[0]);
	print_graph(g);
	printf("\n");

	destroy_graph(&g);
	printf("Graph destroyed successfully\n\n");

	printf("End: Testing Graph with edges\n");
	printf("------------------------------\n\n");
	return;
}

//void test_remove_vertex() {
//	printf("------------------------------\n");
//	printf("Start: Testing remove_vertex_graph:\n\n");
//
//	printf("Creating a graph with 8 vertices\n");
//	Graph *g = create_graph(1, 0);
//
//	Vertex *v[8];
//	char temp[5];
//
//	int i;
//	for (i = 0; i < 8; i++) {
//		sprintf(temp, "V%d", i);
//		v[i] = create_vertex(i, temp);
//		add_vertex_graph(g, v[i]);
//	}
//	print_graph(g);
//	printf("\n");
//
//	printf("Adding 12 edges:\n");
//	Edge *e[12];
//	e[0] = create_edge(v[0], v[1], 0, 0);
//	add_edge_graph(g, e[0]);
//
//	e[1] = create_edge(v[4], v[5], 0, 0);
//	add_edge_graph(g, e[1]);
//
//	e[2] = create_edge(v[1], v[4], 0, 0);
//	add_edge_graph(g, e[2]);
//
//	e[3] = create_edge(v[0], v[4], 0, 0);
//	add_edge_graph(g, e[3]);
//
//	e[4] = create_edge(v[1], v[5], 0, 0);
//	add_edge_graph(g, e[4]);
//
//	e[5] = create_edge(v[3], v[4], 0, 0);
//	add_edge_graph(g, e[5]);
//
//	e[6] = create_edge(v[2], v[6], 0, 0);
//	add_edge_graph(g, e[6]);
//
//	e[7] = create_edge(v[6], v[4], 0, 0);
//	add_edge_graph(g, e[7]);
//
//	e[8] = create_edge(v[3], v[6], 5, 0);
//	add_edge_graph(g, e[8]);
//
//	e[9] = create_edge(v[2], v[7], 5, 0);
//	add_edge_graph(g, e[9]);
//
//	e[10] = create_edge(v[0], v[7], 5, 0);
//	add_edge_graph(g, e[10]);
//
//	e[11] = create_edge(v[4], v[7], 5, 0);
//	add_edge_graph(g, e[11]);
//
//	print_graph(g);
//	printf("\n");
//
//	printf("remove V3:\n");
//	remove_vertex_graph(g, v[3]);
//	print_graph(g);
//	printf("\n");
//
//	printf("remove V2:\n");
//	remove_vertex_graph(g, v[2]);
//	print_graph(g);
//	printf("\n");
//
//	printf("remove V0:\n");
//	remove_vertex_graph(g, v[0]);
//	print_graph(g);
//	printf("\n");
//
//	printf("remove V4:\n");
//	remove_vertex_graph(g, v[4]);
//	print_graph(g);
//	printf("\n");
//
//	printf("remove V7:\n");
//	v[7]->num = 3;
//	remove_vertex_graph(g, v[7]);
//	print_graph(g);
//	printf("\n");
//
//	printf("remove V1:\n");
//	remove_vertex_graph(g, v[1]);
//	print_graph(g);
//	printf("\n");
//
//	printf("remove V6:\n");
//	v[6]->num = 1;
//	remove_vertex_graph(g, v[6]);
//	print_graph(g);
//	printf("\n");
//
//	printf("remove V5:\n");
//	v[5]->num = 0;
//	remove_vertex_graph(g, v[5]);
//	print_graph(g);
//	printf("\n");
//
//	printf("Destroy vertices\n");
//	for (i = 0; i < 8; i++)
//		destroy_vertex(&v[i]);
//	printf("Destroy edges\n");
//	for (i = 0; i < 12; i++)
//		destroy_edge(&e[i]);
//
//	destroy_graph(&g);
//	printf("Graph destroyed successfully\n\n");
//
//	printf("End: Testing remove_vertex_graph\n");
//	printf("------------------------------\n\n");
//	return;
//}
