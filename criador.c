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
	printf("Nome da Fazenda: %s\n", fazenda->nome);
	//printf("Valor da fazenda: %.2f\n", fazenda->valor_fazenda);
	printf("Cidade: %s\n", fazenda->localizacao.cidade);
	printf("Estado: %c%c\n", fazenda->localizacao.estado[0], fazenda->localizacao.estado[1]);
	printf("Logradouro: %s\n", fazenda->localizacao.logradouro);
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

	//printf("\n--------Criador--------\n");

	while(aux){
		printf("-----------------------------------------\n");
		printf("Id do criador: %d\nNome: %s\n", aux->id_criador, aux->nome);
		mostrarFazenda(aux->fazendas);
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
Criador *removerCriador(Criador *criadores){
	Criador *aux = buscarCriador(criadores);
	Criador *aux2;
	if(temFazenda(aux->fazendas) != 0){
		printf("Nao eh possivel excluir esse criador.\n");
	} else{
		if(!aux->ant && !aux->prox){
			printf("Criador Removido.\n");
			return NULL;
		} else if(!aux->prox){
			aux2 = aux;
			aux->ant->prox = NULL;
			free(aux2);
		} else if(!aux->ant){
			aux2 = aux;
			aux = aux->prox;
			free(aux2);
		}
		printf("Criador Removido.\n");

	}

	return criadores;
	
}


/*float calcularPatrimonio(Criador *criador){
	float patrimonio = 0.0;


}*/

/*
if(!aux->ant){
			aux->prox->ant = NULL;
			aux->prox = NULL;
		} else if(!aux->prox){
			aux->ant->prox = NULL;
		} else{
			aux->ant->prox = aux->prox;
			aux->prox->ant = aux->ant;
		}
*/