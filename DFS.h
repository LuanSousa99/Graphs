#define Q 10

struct node{
	int n;

	struct node* prox;

};		

struct graph{
	int qtd;
	int* visitados;

	struct node** edge;
};	

struct graph* AlocaGrafo(int n);
struct node* NewNode(int n);
int addEdge(struct graph** G,int src,int dest);
int PrintList(struct graph* G);
int PrintNode(struct node* N);
int DFS(struct graph* G,int src,int dest);
int ContaNo(struct node* N,int n);
int ContaDistancia(struct node* N,int diferenca[],int dest);
