/***********************
 *Annie Hayes
 *ahayes5
 *Lab 3 2311-003
 **********************/
#include <stdio.h>

//snippet of code given in lab 3 PDF
int main(void) {
struct NODE{
	int a;
	struct NODE *b;
	struct NODE *c;
};

struct NODE 	nodes[5] = {
	{5,	nodes + 3, 	NULL},
	{15,	nodes + 4, 	nodes + 3},
	{22,	NULL,		nodes + 4},
	{12, 	nodes + 1, 	nodes},
	{18, 	nodes + 2, 	nodes + 1}
};

struct NODE  *np  = nodes + 2;
struct NODE  **npp = &nodes[1].b;

//print statements for values
//the illegal expressions are commented out
printf("\nnodes: \t\t\t%p", nodes);
//printf("\nnodes.a: \t\t\tILLEGAL");
printf("\nnodes[3].a: \t\t%d", nodes[3].a);
printf("\nnodes[3].c: \t\t%p", nodes[3].c);
printf("\nnodes[3].c->a: \t\t%d", nodes[3].c->a);
//printf("\n*nodes.a: \t\t\tILLEGAL");
printf("\n(*nodes).a: \t\t%d", (*nodes).a);
printf("\nnodes->a: \t\t%d", nodes->a);
printf("\nnodes[3].b->b: \t\t%p", nodes[3].b->b);
printf("\n&nodes: \t\t%p", &nodes);
printf("\n&nodes[3].a: \t\t%p", &nodes[3].a);
printf("\n&nodes[3].c: \t\t%p", &nodes[3].c);
printf("\n&nodes[3].c->a: \t%p", &nodes[3].c->a);
printf("\n&nodes->a: \t\t%p", &nodes->a);
printf("\nnp: \t\t\t%p", np);
printf("\nnp->a: \t\t\t%d", np->a);
printf("\nnp->c->c->a: \t\t%d",np->c->c->a);
printf("\nnpp: \t\t\t%p", npp);
//printf("\nnpp->a: \t\t\tILLEGAL");
printf("\n*npp: \t\t\t%p", *npp);
//printf("\n*npp->a: \t\t\tILLEGAL");
printf("\n(*npp)->a: \t\t%d",(*npp)->a);
printf("\n&np \t\t\t%p", &np);
printf("\n&np->a: \t\t%p", &np->a);
printf("\n&np->c->c->a: \t\t%p\n\n", &np->c->c->a);

}
