 //Pilha Com Alocação Dinamica
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define clear() system("clear || cls");

typedef struct NodoAux{
	int dado;
	struct NodoAux *ant;
}Nodo;

typedef struct {
    Nodo *topo;
    int tamanho;
} Pilha;

void LimpaEntrada(){
    #ifdef WIN32
      fflush(stdin);
    #else
      __fpurge(stdin);
    #endif
}

void Pausar(){
    printf("Pressione qualquer tecla para continuar...");
    LimpaEntrada();
    getchar();
}

Pilha *create(){
    Pilha *p;
    p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

void insere(Pilha *p, int valor) {
	Nodo *novo;
	novo = (Nodo *) malloc(sizeof(Nodo));
	novo->dado = valor;

    novo->ant = p->topo;
	p->topo = novo; 
	
	p->tamanho++;
	printf("\nElemento inserido com sucesso\n");
}

void exibir_Pilha(Pilha *p) {
	Nodo *aux;

	if(p->topo==NULL) {
		printf("\nERRO: Pilha vazia\n");
		return;
	}

	aux=p->topo;
    printf("\nPilha: ");
	while(aux!=NULL) {
		printf(" %d |", aux->dado);
		aux = aux->ant;
	}
    printf("\n");
}

void remover(Pilha *p) {
	Nodo *aux;

	if(p->topo==NULL) {
		printf("\nERRO: Pilha vazia\n");
		return;
	}
	aux = p->topo;
    p->topo = NULL;
    if (aux->ant != NULL)
 	  p->topo = aux->ant;
	p->tamanho--;
	printf("\nvalor dado: %d.\n\nElemento removido com sucesso\n", aux->dado);
    free(aux);
}

int menu() {
    int *result;
    result = (int *) malloc(sizeof(int));
    clear();
	printf("\n===============================| MENU - Pilha Linux |===============================");
	printf("\n1- Inserir elemento");
	printf("\n2- Remover elemento");
	printf("\n3- Exibir Pilha");
	printf("\n------------------------------------------------------------------------------------");
	printf("\nEsc- Sair");
    printf("\n====================================================================================");
	printf("\n\n");
    bool *controle;
    controle = (bool *) malloc(sizeof(bool *));
    do{
        *controle = false;
        printf("Escolha uma Opcao: ");
        *result = getc(stdin);
        switch (*result)
        {
            case 49:
            case 50:  
            case 51:
            case 27:  
                break;
        
             default:
                    printf("\nOpcao Invalida!\n");
                    *controle = true;
                break;
        }
    }while(*controle == true);
    return *result;
}

int main() {
    Pilha *p;
    p = create();
	int *opcao;
    opcao = (int *) malloc(sizeof(int));
    int *valor;
    valor = (int *) malloc(sizeof(int));
	int *controleMain;
    controleMain = (int *) malloc(sizeof(int));
	do { 
        *controleMain = 1;
        *opcao = menu();
		switch(*opcao) {
			case 49:
				printf("\nDigite o valor a ser inserido ");
				scanf("%d", valor);
				insere(p, *valor);
                Pausar();
				break;
			case 50:
				remover(p);
                Pausar();
				break;
			case 51:
				exibir_Pilha(p);
                Pausar();
				break;
			case 27:
				printf("\n\nAte logo !!");
                printf("\nAluno: Luis Antonio Gambatti Junior");
                printf(" | IFSP - Campus Catanduva - 2022 | CT3010864\n");
				*controleMain = false;
                Pausar();
                printf("\n\n");
				break;
		}
	}
	while(*controleMain == 1);
    free(valor);
    free(p);
    free(opcao);
    free(controleMain);
    return 0;
}