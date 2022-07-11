#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define NIL -1

struct edge
{
    int u;
    int v;
    int weight;
    struct edge *link;
} *head = NULL;

void make_tree(struct edge tree[]);
void insert_pque(int i, int j, int wt);
struct edge *del_pque();
int isEmpty_pque();
void create_graph();

int n; /*Total number of vertices in the graph */

int main()
{
    int i;
    struct edge tree[MAX]; /* Will contain the edges of spanning tree */
    int wt_tree = 0;       /* Weight of the spanning tree */

    create_graph();

    make_tree(tree);

    printf("\nEdges to be included in minimum spanning tree are :\n");
    printf("\nOrig->Dest-->Weight\n");
    for (i = 1; i < n; i++)
    {
        printf("\n%d->", tree[i].u);
        printf("%d-->", tree[i].v);
        printf("%d\n", tree[i].weight);
        wt_tree += tree[i].weight;
    }
    printf("\nWeight of this minimum spanning tree is : %d\n", wt_tree);

    return 0;
}

void make_tree(struct edge tree[])
{
    struct edge *tmp;
    int v1, v2, root_v1, root_v2;
    int father[MAX];  /*Holds father of each vertex */
    int i, count = 0; /* Denotes number of edges included in the tree */

    for (i = 0; i < n; i++)
        father[i] = NIL;

    /*Loop till queue becomes empty or
    till n-1 edges have been inserted in the tree*/
    while (!isEmpty_pque() && count < n - 1)
    {
        tmp = del_pque();
        v1 = tmp->u;
        v2 = tmp->v;

        while (v1 != NIL)
        {
            root_v1 = v1;
            v1 = father[v1];
        }
        while (v2 != NIL)
        {
            root_v2 = v2;
            v2 = father[v2];
        }

        if (root_v1 != root_v2) /*Insert the edge (v1, v2)*/
        {
            count++;
            tree[count].u = tmp->u;
            tree[count].v = tmp->v;
            tree[count].weight = tmp->weight;
            father[root_v2] = root_v1;
        }
    }

    if (count < n - 1)
    {
        printf("\nGraph is not connected, no spanning tree possible\n");
        exit(1);
    }
}

/*Inserting edges in the linked priority queue */
void insert_pque(int i, int j, int wt)
{
    struct edge *tmp, *q;

    tmp = (struct edge *)malloc(sizeof(struct edge));
    tmp->u = i;
    tmp->v = j;
    tmp->weight = wt;

    /*Queue is empty or edge to be added has weight less than first edge*/
    if (head == NULL || tmp->weight < head->weight) // That is insert at head/begining
    {
        tmp->link = head;
        head = tmp;
    }
    else // This can be add at end or add if cond is matched
    {
        q = head;
        while (q->link != NULL && q->link->weight <= tmp->weight)
            q = q->link;
        tmp->link = q->link;
        q->link = tmp;
        if (q->link == NULL) /*Edge to be added at the end*/
            tmp->link = NULL;
    }
}

/*Deleting an edge from the linked priority queue*/
struct edge *del_pque()
{
    struct edge *tmp;
    tmp = head;
    head = head->link;
    return tmp;
}

int isEmpty_pque()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

void create_graph()
{
    int i, wt, max_edges, origin, destin;

    printf("\nEnter number of vertices : ");
    scanf("%d", &n);
    max_edges = n * (n - 1) / 2;

    for (i = 1; i <= max_edges; i++)
    {
        printf("\nEnter edge %d(-1 -1 to quit): ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == -1) && (destin == -1))
            break;
        printf("\nEnter weight for this edge : ");
        scanf("%d", &wt);
        if (origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            printf("\nInvalid edge!\n");
            i--;
        }
        else
            insert_pque(origin, destin, wt);
    }
}
