#include <stdio.h>
#include <stdlib.h>
#include "exe8.h"

int main(){
	struct graph* G = AlocaGrafo(Q);
	
	addEdge(&G,0,1);
	addEdge(&G,1,2);
	addEdge(&G,2,3);
	addEdge(&G,3,4);
	addEdge(&G,4,5);
	addEdge(&G,5,6);
	addEdge(&G,6,7);
	addEdge(&G,7,8);
	addEdge(&G,8,9);
	addEdge(&G,9,0);
	
	PrintList(G);
	DFS(G,9,3);
	return 0;
}	

int DFS(struct graph* G,int src,int dest){
	if(G->visitados[src] == 1)
		return -1;
	
	if(src == dest){
		printf("Destino %d encontrado!!!\n\n",dest);
		return 1;
	}	
	
	G->visitados[src] = 1;
	
	printf("Nó %d visitado.\n",src);

	int x = ContaNo(G->edge[src],0);
	int diferenca[x];

	
	ContaDistancia(G->edge[src],diferenca,dest);
	int menor = diferenca[0];
	int y = 0,i = 0;

	for(i = 0; i < x; i++){
		if(menor >= diferenca[i]){
			menor = diferenca[i];
			y = i;
		}	
	}	

	struct node* temp = G->edge[src];

	for(i = 0; i < y; i++)
		temp = temp->prox;
	DFS(G,temp->n,dest);

}	

int ContaDistancia(struct node* N,int diferenca[],int dest){
	int x = 0;

	while(N != NULL){
		int y = 0;
		int temp = N->n;
		
		if(N->n > dest){

			while(temp != dest){
				temp--;
				y++;
			}	
	
			diferenca[x] = y;
		}

		else{
			if(temp == dest)
				diferenca[x] = 0;

			else{

				while(temp != dest){
					temp++;
					y++;
				}

				diferenca[x] = y;
			}			
		}	
		N = N->prox;
		x++;
	}	
}	

int ContaNo(struct node* N,int n){
	if(N == NULL)
		return n;
	
	else{
		int x = ContaNo(N->prox,n+1);
		return x;
	}	
}	

int PrintList(struct graph* G){
	for(int i = 0; i < G->qtd; i++){
		printf("Lista %d: ",i);
		PrintNode(G->edge[i]);
		printf("\n");
	}	

	printf("\n\n");
}	

int PrintNode(struct node* N){
	if(N != NULL){
		PrintNode(N->prox);
		printf("->%d",N->n);
	}	
}	

int addEdge(struct graph** G,int src,int dest){
	struct node* new = NewNode(dest);
	new->prox = (*G)->edge[src];
	(*G)->edge[src] = new;

	new = NewNode(src);
	new->prox = (*G)->edge[dest];
	(*G)->edge[dest] = new;

	return 1;
}	

struct node* NewNode(int n){
	struct node* new = (struct node* ) calloc(1,sizeof(struct node));
	new->n = n;

	new->prox = NULL;

	return new;
}	

struct graph* AlocaGrafo(int n){
	struct graph* G;

	G = (struct graph* ) calloc(1,sizeof(struct graph));
	
	G->qtd = Q;
	
	G->visitados = (int* ) calloc(Q,sizeof(int));
	G->edge = (struct node** ) calloc(Q,sizeof * G->edge);

	for(int i = 0; i < Q; i++){
		G->edge[i] = NULL;
		G->visitados[i] = 0;

	}

	return G;
	

}	
