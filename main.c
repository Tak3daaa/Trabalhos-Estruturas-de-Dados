#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "criador.c"
#include "fazenda.h"

int main() {

    Criador *c;

    c = criarListaDuplaCriadores();

    c = cadastrarCriador(c);
    // c = cadastrarCriador(c);
    // c = cadastrarCriador(c);
    // c = cadastrarCriador(c);

    mostrarCriadores(c);
    mostrarTudo(c);
    printf("%d\n",temFazenda(c->fazendas));
    Criador *teste;

    teste = criarListaDuplaCriadores();

    teste->fazendas = criarListaEncadeadaCircularFazendas();
    printf("%d\n",temFazenda(teste->fazendas));
    

    return 0;
}