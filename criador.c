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

Criador *criarListaDuplaCriadores(){
	return NULL;
}

Criador *cadastrarCriador(Criador *criadores){
	Criador *c;

	c = (Criador*)malloc(sizeof(Criador));
	c->fazendas = criarListaEncadeadaCircularFazendas();
	printf("Id do criador: ");
	scanf("%d", &c->id_criador);
	fflush(stdin);
	printf("Nome do criador: ");
	scanf("%[^\n]", c->nome);
	fflush(stdin);
	c->ant = NULL;
	c->prox = criadores;

	if(!criadores){
		c->prox = NULL;
	} else{
		c->prox = criadores;
		criadores->ant = c;
	}

	return c;
}

void mostrarFazenda(Fazenda *fazenda){
	if(fazenda){
		printf("Nome da Fazenda: %s\n", fazenda->nome);
		//printf("Valor da fazenda: %.2f\n", fazenda->valor_fazenda);
		printf("Cidade: %s\n", fazenda->localizacao.cidade);
		printf("Estado: %c%c\n", fazenda->localizacao.estado[0], fazenda->localizacao.estado[1]);
		printf("Logradouro: %s\n", fazenda->localizacao.logradouro);
	} else{
		printf("Nao tem nehuma fazenda cadastrada.\n");
	}
	
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

int temFazenda(Fazenda *fazenda){
	if(fazenda){
		return 1;
	}

	return 0;
}

void mostrarCriadores(Criador *criadores){
	Criador *aux = criadores;

	while(aux){
		printf("-----------------------------------------\n");
		printf("Id do criador: %d\nNome: %s\n", aux->id_criador, aux->nome);
		printf("Patrimonio: %.2f\n", aux->patrimonio);
		//printf("------------Fazendas-----------\n");
		mostrarFazenda(aux->fazendas);
		//printf("------------Animais-----------\n");
		mostrarTodosAnimais(aux->fazendas);
		aux = aux->prox;
	}
	printf("\n");
}

void mostrarTudo(Criador *criador){
	Criador *aux = criador;
	mostrarCriadores(aux);
	mostrarAnimal(aux->fazendas->rebanho);
}

// https://wiki.python.org.br/ExerciciosClasses
Criador *removerCriador(Criador *criadores){
	Criador *aux = buscarCriador(criadores);
	Criador *aux2;
	if(temFazenda(aux->fazendas) != 0){
		printf("Nao eh possivel excluir esse criador.\n");
	} else{
		if(!aux){
			printf("Criador Removido.\n");
			free(aux);
			return NULL;
		} else{
			if(!aux->ant && !aux->prox){
				free(aux);
				return NULL;
			} else if(!aux->ant){
				aux2 = aux;
				aux = aux->prox;
				aux->ant = NULL;
				free(aux2);
			} else if(!aux->prox){
				aux2 = aux->ant;
				aux2->prox = NULL;
				free(aux);
			}
		}

		printf("Criador Removido.\n");

	}

	return criadores;
	
}


void calcularPatrimonio(Criador *criador){
	float quantArroba;

	quantArroba = contArroba(criador->fazendas);

	criador->patrimonio = quantArroba * 235.0;

}

/*
if (remover_animal == NULL)
	{
		return fazenda->rebanho;
	}
	if (anterior == NULL)
	{
		fazenda->rebanho = remover_animal->prox;
	}else
	{
		anterior->prox = remover_animal->prox;
	}
	free(remover_animal);
*/