#include <stdio.h>
#include <stdlib.h>
 
#include "fazenda.h"
#include "animal.h"
#include "criador.h"
// #include "animal.c"
//#include "criador.h"

struct endereco{
	char cidade[50], estado[2], logradouro[200];
};

int i = 0;

struct fazenda{
	int id_criador, id_fazenda;
	char nome[100];
	Endereco localizacao;
	float valor_fazenda;//lembrar de atualizar o valor sempre que houver alterações no rebanho
	Animal *rebanho; // ponteiro para uma lista (verificar no .h do animal que lista é)
	//ponteiro para permitir o apontamento para o proximo elemento da lista (deve ser circular)
	struct fazenda *prox;
};

Fazenda *criarListaEncadeadaCircularFazendas(){
	return NULL;
}

Fazenda *cadastrarFazenda(Fazenda *fazendas){
	Fazenda *novo = (Fazenda *) malloc(sizeof(Fazenda));
	Fazenda *aux = fazendas;

	novo->id_criador = ++i;
	
	printf("Informe o id da fazenda: ");
	fflush(stdin);
	scanf("%d", &novo->id_fazenda);
	printf("Insira o nome da fazenda: "); 
	scanf("%s[^\n]", novo->nome);
	fflush(stdin);
	printf("Insira a cidade: "); 
	scanf("%s[^\n]", novo->localizacao.cidade);
	fflush(stdin);
	printf("Insira o estado: "); 
	scanf("%s[^\n]", novo->localizacao.estado);
	fflush(stdin);
	printf("Insira o logradouro: "); 
	scanf("%s[^\n]", novo->localizacao.logradouro);
	fflush(stdin);
	novo->rebanho = criaListaEncadeadaSimplesAnimais();

	if(novo->rebanho) printf("Rebanho criado\n");

	if(fazendas == NULL){
		novo->prox = novo;
		return novo;
	}

	while(aux->prox != fazendas){
		aux = aux->prox;
	}

	aux->prox = novo;
	novo->prox = fazendas;

	return fazendas;
}

Fazenda *removerFazenda(Fazenda *fazendas, int id){
	Fazenda *aux = fazendas, *aux2;

	if(fazendas == NULL){
		printf("\nLista vazia\n");
		return fazendas;
	}

	if(!buscarFazenda(fazendas)){
		printf("\nFazenda nao cadastrada!\n");
		return fazendas;
	}

	if(aux->id_fazenda == id){

		if(aux->rebanho != NULL){
			printf("\nNao eh possivel remover fazenda com rebanho!\n");
			return fazendas;
		}

		if(aux->prox == aux){
			return NULL;
		}

		while(aux->prox != fazendas){
			aux = aux->prox;
		}

		aux->prox = fazendas;
		free(fazendas);

		return aux->prox;
	}

	while(aux->prox != fazendas && aux->prox->id_fazenda != id){
		aux = aux->prox;
	}

	if(aux->prox == fazendas){
		printf("\nFazenda nao cadastrada!\n");
		return fazendas;
	}

	if(aux->rebanho != NULL){
		printf("\nNao eh possivel remover fazenda com rebanho!\n");
		return fazendas;
	}
	

	aux2 = aux->prox;
	aux->prox = aux->prox->prox;
	free(aux2);

	return fazendas;

}

Fazenda *buscarFazenda(Fazenda *fazendas){
	Fazenda *aux = fazendas;
	int id;
	printf("Informe o id da fazenda que voce procura: \n");
	scanf("%d", &id);

	if(fazendas == NULL){
		printf("\nSem fazendas registradas!\n");
		return fazendas;
	}

	if(aux->id_fazenda == id){
		return aux;
	}

	while(aux->prox != fazendas && aux->prox->id_fazenda != id){
		aux = aux->prox;
	}

	return aux->prox == fazendas ? NULL : aux->prox;
}

Fazenda *getBuscar(Fazenda *fazendas, int id){

	Fazenda *aux = fazendas;

	if(fazendas == NULL){
		printf("\nSem fazendas registradas!\n");
		return fazendas;
	}

	if(aux->id_fazenda == id){
		return aux;
	}

	while(aux->prox != fazendas && aux->prox->id_fazenda != id){
		aux = aux->prox;
	}

	return aux->prox == fazendas ? NULL : aux->prox;
}

/*
void mostrarFazendas(Fazenda *fazendas){
	Fazenda *aux = fazendas;


}
*/
// int quantAnimaisSexo(Fazenda *fazenda, char sexo){

// }
