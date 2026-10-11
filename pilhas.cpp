#include <stdio.h>
#include <stdlib.h>

struct No{
    int dado;
    struct No*prox;
};

struct No*topo = NULL;

void push(int nr);
void imprimir();
void pop();

int main(){
    int n, opcao;
    do {
        printf("\n\nStack Menu\n1.Empilhar \n2.Desempilhar\n3.Imprimir\n0.Sair\n");
        printf("Escolha uma opcao (0-3): ");
        scanf("%d", &opcao);
        
        switch (opcao){
            case 1:
                printf("\nEntre com um valor para ser empilhado: ");
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
              imprimir();
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!");
        }
    }while(opcao!=0);

    return 0;
}

void push(int nr){
    struct No*novo=(struct No*)malloc(sizeof(struct No));
    
    if(novo==NULL){
        printf("Erro na memoria!\n");
        return;
    }
  
  novo->dado=nr;
  novo->prox=topo;
  topo=novo;
}
  void pop()
  {
  	printf("\n============================");
  	printf("\n=======desempilhando=======");

  	if(topo==NULL){
  		printf("\nEstá vazio.");
  		
	  }
	  else{
	  	struct No*temp;
	  	temp=topo;
	  	topo=topo->prox;
	  	printf("\nDesempilhado: %d", temp->dado);
	    free(temp);
	  }
	  printf("\n=============================");
  }
  void imprimir(){
  	struct No*temp;
  	temp=topo;
  	printf("\n============================");
  	printf("\n=======IMPRIMIR PILHA=======");
  	while(temp!=NULL){
  		printf("\n%d", temp->dado);
  		temp=temp->prox;
	  }
  }