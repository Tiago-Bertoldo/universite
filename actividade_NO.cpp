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
ptr_no lista;
int op ;

//PROTOTIPAÇÂO

void menu_mostrar();
void menu_selecionar(int op);
void lista_inserir(ptr_no lista);
void lista_remove(ptr_no lista);
void lista_mostrar(ptr_no lista);
void lista_mostrar2(ptr_no lista);


//Main function
int main(){
	//INICIALIZANDO A MAQUINA DE NUMERO RANDOM.
	srand(time(NULL));
	op = 1;
	//Criando o primeiro no da lista
	lista = (ptr_no) malloc(sizeof(no));
	lista -> dado = 0;
	lista -> proximo = NULL;
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
	lista_mostrar(lista);
	printf("\n Escolha uma das opcões \n");
	printf("1 - Inserir no final da lista\n ");
	printf("2 - Remove um item da lista\n ");
	printf("0 - Sair \n");
}

//Executa a opção selecionada
void menu_selecionar(int op) {
	switch(op) {
		case 1 :
			lista_inserir(lista);
		break;
		case 2 : 
			lista_remove(lista);
		break;
	}
	
}

//inserir um elemento no final da lista;
void lista_inserir(ptr_no lista){

	while(lista -> proximo != NULL){
		lista = lista -> proximo;
	}
	lista -> proximo = (ptr_no) malloc(sizeof(no));
	lista = lista -> proximo;
	lista -> dado = rand() %100;
	lista -> proximo = NULL;
	}
	
//remove um elemento da lista
void lista_remove (ptr_no lista) {
	int dado ;
	ptr_no atual;
	atual = (ptr_no) malloc(sizeof(no));
	printf("\n escolha um dos itens : \n");
	scanf("%d" , &dado);
	while((lista -> dado != dado)){
		if (lista -> proximo == NULL) {
			break;
		}
		atual = lista;
		lista = lista -> proximo;
	}
	if(lista -> dado == dado) {
		atual -> proximo = lista -> proximo;
	}
	
}

//Desenha o conteudo da lista na tela
void lista_mostrar(ptr_no lista) {
	system("cls");
	while(1) {
		printf("%d to aqui" , lista -> dado);
		if(lista -> proximo == NULL){
			break;
		}
		lista = lista -> proximo;
	}
	
}

//DESENHA O CONTEUDO;
void lista_mostrar2(ptr_no lista) {
	system("cls");
	while(lista -> proximo != NULL)	{
		printf("%d" , lista -> dado);
		lista = lista -> proximo;
		}
		printf("%d to aqui" , lista -> dado);
	}


