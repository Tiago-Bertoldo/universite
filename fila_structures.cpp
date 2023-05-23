#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//DEFINE A ESTRUTURA
struct no {
	int dado;
	struct no *proximo;
};


//DEFINE VARIAVEIS
typedef no *ptr_no; 
ptr_no fila;
int op ;

//PROTOTIPAÇÂO

void menu_mostrar();
void menu_selecionar(int op);
void fila_inserir(ptr_no fila);
void fila_remover(ptr_no fila);
void fila_mostrar(ptr_no fila);
void lista_mostrar2(ptr_no fila);


//Main function
int main(){
	//INICIALIZANDO A MAQUINA DE NUMERO RANDOM.
	srand(time(NULL));
	op = 1;
	//Criando o primeiro no da lista
	fila = (ptr_no) malloc(sizeof(no));
	fila -> dado = 0;
	fila -> proximo = NULL;
	//laço principal
	while(op != 0) {
		system("cls");
		menu_mostrar();
		scanf("%d" , &op);
		menu_selecionar(op);
	}
	system("Pause");
	return(0);
	
}


//MENU MOSTRAR

void menu_mostrar() {
	fila_mostrar(fila);
	printf("\n Escolha uma das opcões \n");
	printf("1 - Inserir no final da lista\n ");
	printf("2 - Remove um item da lista\n ");
	printf("0 - Sair \n");
}

//Executa a opção selecionada
void menu_selecionar(int op) {
	switch(op) {
		case 1 :
			fila_inserir(fila);
		break;
		case 2 : 
			fila_remover(fila);
		break;
	}
	
}

//inserir um elemento no final da lista;
void fila_inserir(ptr_no fila){

	while(fila -> proximo != NULL){
		fila = fila -> proximo;
	}
	fila -> proximo = (ptr_no) malloc(sizeof(no));
	fila = fila -> proximo;
	fila -> dado = rand() %100;
	fila -> proximo = NULL;
	}
	
//remove um elemento da lista
void fila_remover(ptr_no fila) {
	int dado ;
	ptr_no atual;
	atual = (ptr_no) malloc(sizeof(no));
	printf("\n escolha um dos itens : \n");
	scanf("%d" , &dado);
	while(fila -> dado != dado){
		if (fila -> proximo == NULL) {
			break;
		}
		atual = fila;
		fila = fila -> proximo;
	}
	if(fila -> dado == dado) {
		atual -> proximo = fila -> proximo;
	}
	
}

//Desenha o conteudo da lista na tela
void fila_mostrar(ptr_no fila) {
	system("cls");
	while(1) {
		printf("%d" , fila -> dado);
		if(fila -> proximo == NULL){
			break;
		}
		fila = fila -> proximo;
	}
	
}

//DESENHA O CONTEUDO;
void fila_mostrar2(ptr_no fila) {
	system("cls");
	while(fila -> proximo != NULL)	{
		printf("%d" , fila -> dado);
		fila = fila -> proximo;
		}
		printf("%d to aqui" , fila -> dado);
	}


