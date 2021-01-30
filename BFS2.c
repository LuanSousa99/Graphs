#include <stdio.h>
#include <stdlib.h>
#include "BFS2.h"

int main(){
	GRAPH* G;
	G = alocaGrafo(4);
	
	addEdge(&G,0,1);
	addEdge(&G,0,2);
	addEdge(&G,1,3);
	addEdge(&G,2,3);
	
	PrintList(G);
	BFS(G,2);
	return 0;
}	

int BFS(GRAPH* G,int starter){
	FILA* F = CreateQueue();
	G->visitados[starter] = 1;
	enqueue(F,starter);

	while(!IsEmpty(F)){
		PrintFila(F);
		int x = dequeue(F);
		printf("Nó %d visitado\n",x);

		NODE* temp = G->edge[x];

		search(G,temp,F);
	}	
}	

int search(GRAPH* G,NODE* N,FILA* F){
	if(N != NULL){
		int x = N->item;

		if(G->visitados[x] == 0){
			enqueue(F,x);
			G->visitados[x] = 1;
		}	

		search(G,N->next,F);
	}	
}	

int PrintFila(FILA* F){
	if(IsEmpty(F)){
		return -1;
	}	

	else{
		printf("fila: ");
		for(int i = F->inicio; i <= F->fim; i++){
			printf("->%d",F->queue[i]);
		}	
		printf("\n");
	}	
}	

int dequeue(FILA* F){
	if(IsEmpty(F)){
		return -1;
	}	

	int x = F->queue[F->inicio];
	F->inicio++;

	if(F->inicio > F->fim){
		printf("Fila resetada!!!\n");
		F->inicio = F->fim = -1;
	}	

	return x;
}	

int enqueue(FILA* F,int valor){
	if(F->fim == SIZE-1){
		printf("A fila já está cheia!!!\n\n");
		return -1;
	}	

	if(F->inicio == -1)
		F->inicio = 0;

	F->fim++;
	F->queue[F->fim] = valor;
	return valor;
}	

int IsEmpty(FILA* F){
	if(F->fim == -1){
		printf("Fila vazia!\n");
		return 1;
	}	

	return 0;
}	

void PrintList(GRAPH* G){
	for(int i = 0; i < G->V; i++){
		printf("Lista %d: ",i);
		PrintNode(G->edge[i]);
		printf("\n");
	}	

	printf("\n\n");
}	

void PrintNode(NODE* N){
	if(N != NULL){
		PrintNode(N->next);
		printf("->%d",N->item);
	}	
}	

int addEdge(GRAPH** G,int src,int dest){
	NODE* new = NewNode(dest);
	new->next = (*G)->edge[src];
	(*G)->edge[src] = new;

	new = NewNode(src);
	new->next = (*G)->edge[dest];
	(*G)->edge[dest] = new;

	return 1;
}	

GRAPH* alocaGrafo(int vertex){
	GRAPH* new;
	new = (GRAPH* ) malloc(sizeof(GRAPH));
	new->V = vertex;

	new->visitados = (int* ) malloc(vertex * sizeof(int));
	new->edge = (NODE** ) malloc(vertex * sizeof(NODE*));

	for(int i = 0; i < vertex; i++){
		new->visitados[i] = 0;
		new->edge[i] = NULL;
	}	

	return new;
}	

NODE* NewNode(int n){
	NODE* new;
	new = (NODE* ) malloc(sizeof(NODE));
	new->item = n;
	new->next = NULL;

	return new;
}	

FILA* CreateQueue(){
	FILA* new;
	new = (FILA* ) malloc(sizeof(FILA));
	new->inicio = -1;
	new->fim = -1;

	return new;
}	
