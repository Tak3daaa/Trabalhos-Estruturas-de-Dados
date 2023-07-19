#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "criador.h"
#include "fazenda.h"
#include "fazenda.c"
#include "animal.h"
#include "animal.c"
// #include "fazenda.c"

struct criador
{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;// Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; // esse valor deve ser constantemente modificado para que o valor esteja atualizado
	struct criador *prox, *ant; // lista dupla encadeada, nao é necessário ser circular
};

// int id = 0;

Criador *criarListaDuplaCriadores(){
	return NULL;
}

Criador *cadastrarCriador(Criador *criadores){
	Criador *c;

	c = (Criador*)malloc(sizeof(Criador));
	printf("Id do criador: ");
	scanf("%d", &c->id_criador);
	fflush(stdin);
	printf("Nome do criador: ");
	scanf("%s[^\n]", c->nome);
	fflush(stdin);
	c->ant = NULL;
	if(!criadores){
		c->prox = NULL;
	} else{
		c->prox = criadores;
		criadores->ant = c;
	}

	return c;
}

int size(Criador *c){
	Criador *aux;
	int count = 0;

	aux = c;
	while(aux){
		count++;
		aux = aux->prox;
	}

	return count;
}

Criador *buscarCriador(Criador *criadores){
	Criador *aux = criadores;
	int id;
	printf("Informe o id do criador: ");
	scanf("%d", &id);

	while(aux){
		if(id == aux->id_criador){
			printf("Criador encontrado.\n");
			return aux;
		}

		aux = aux->prox;
	}

	printf("Criador nao encontrado.\n");
	return NULL;
}

int tem(Criador *criador){
	if(criador->fazendas){
		return 1;
	}

	return 0;
}

void mostrarCriadores(Criador *criadores){
	Criador *aux = criadores;
	//printf("Id\tNome\tTem Fazenda\tId fazenda\n");
	printf("\nCriador\n");
	//printf("Id\tNome\n");
	while(aux){
		printf("%d\t%s\t", aux->id_criador, aux->nome);
		//printf("%d\t%s\n", aux->id_criador, aux->nome);
		//printf("%d\t\t%d\n", temFazenda(aux->fazendas), aux->fazendas->id_fazenda);
		aux = aux->prox;
	}
	printf("\n");
}

void mostrarTudo(Criador *criador){
	Criador *aux = criador;
	mostrarCriadores(aux);
	mostrarAnimalStatus(aux->fazendas->rebanho);
}

// https://wiki.python.org.br/ExerciciosClasses
