#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "fazenda.h"

struct criador
{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;// Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; // esse valor deve ser constantemente modificado para que o valor esteja atualizado	
	struct criador *prox, *ant; // lista dupla encadeada, nao é necessário ser circular
};

int id = 0;

Criador *criarListaDuplaCriadores(){
	/*Criador *c;

	c = (Criador*)malloc(sizeof(Criador));

	c->ant = NULL;
	c->prox = NULL;*/

	return NULL;
}

Criador *cadastrarCriador(Criador *criadores){
	Criador *c;

	c = (Criador*)malloc(sizeof(Criador));

	c->id_criador = ++id;
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

int buscarCriador(Criador *criadores){
	Criador *aux = criadores;
	int id = 3, rep = 0;

	while(aux){
		if(id == aux->id_criador){
			return rep;
		}

		aux = aux->prox;
		rep++;
	}

	return -1;
}


