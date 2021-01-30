#define SIZE 40

struct fila{
	int queue[SIZE];
	int inicio;
	int fim;

};	

struct node{
	int item;
	struct node *next;	

};	

struct graph{
	int V;
	int *visitados;
	struct node **edge;

};	

typedef struct fila FILA;
typedef struct node NODE;
typedef struct graph GRAPH;

GRAPH* alocaGrafo(int vertex);
NODE* NewNode(int n);
FILA* CreateQueue();
int addEdge(GRAPH** G,int src,int dest);
void PrintList(GRAPH* G);
void PrintNode(NODE* N);
int IsEmpty(FILA* F);
int enqueue(FILA* F,int valor);
int dequeue(FILA* F);
int PrintFila(FILA* F);
int BFS(GRAPH* G,int starter);
int search(GRAPH* G,NODE* N,FILA* F);

