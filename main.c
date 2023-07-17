#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "criador.c"

int main() {

    Criador *c;

    c = criarListaDuplaCriadores();

    c = cadastrarCriador(c);
    //int s = size(c);
    //printf("%d\n", s);
    c = cadastrarCriador(c);
    //s = size(c);
    //printf("%d\n", s);
    c = cadastrarCriador(c);
    //s = size(c);
    //printf("%d\n", s);
    c = cadastrarCriador(c);
    //s = size(c);
    //printf("%d\n", s);
    //c = cadastrarCriadorII(c);
    // Criador *aux = c;
    /*Criador *v;

    while(aux){
        v = aux;
        printf("%d ", aux->id_criador);
        aux = aux->prox;
    }

    printf("\n\n");
    while(v){
        printf("%d ", v->id_criador);
        v = v->ant;
    }*/

    mostrarCriadores(c);

    //printf("\n\n\npos: %d\n\n\n", buscarCriador(c));

    ///printf("%d\n",temFazenda(c->fazendas));
    

    return 0;
}