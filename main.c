#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "criador.c"
#include "fazenda.h"

int menu(){
    printf("\n---------------------------------------------\n");
    printf("1 - Cadastrar Criador\t2 - Cadastrar Fazenda\n");
    printf("3 - Cadastrar Animal\t4 - Mostrar Criador\n");
    printf("\nEscolha uma opcao: ");
    int op; scanf("%d", &op);

    return op;
}

int main() {

    Criador *c, *cad_fazenda, *cad_animal;
    cad_animal = NULL;
    int r = 1;

    while(r != 0){
        r = menu();
        switch (r){
            case 1:
                c = criarListaDuplaCriadores();
                c = cadastrarCriador(c);
                break;
            case 2:
                cad_fazenda = buscarCriador(c);
                cad_fazenda->fazendas = criarListaEncadeadaCircularFazendas();
                cad_fazenda->fazendas = cadastrarFazenda(cad_fazenda->fazendas);
                break;
            case 3:
                cad_animal = buscarFazenda(c->fazendas);
                
                break;
            default:
                break;
        }
    }

    // c = criarListaDuplaCriadores();

    // c = cadastrarCriador(c);
    // c->fazendas = criarListaEncadeadaCircularFazendas();
    // c->fazendas = cadastrarFazenda(c->fazendas);

    // c->fazendas->rebanho = criaListaEncadeadaSimplesAnimais();
    // c->fazendas->rebanho = cadastrarAnimal(c->fazendas->rebanho);
    //c = cadastrarCriador(c);
    // c = cadastrarCriador(c);
    // c = cadastrarCriador(c);

    mostrarCriadores(c);
    mostrarTudo(c);
    //printf("%d\n",temFazenda(c->fazendas));
    // Criador *teste;

    // printf(".......\n");
    // teste = criarListaDuplaCriadores();

    // printf(".......\n");
    // teste->fazendas = criarListaEncadeadaCircularFazendas();
    // printf(".......\n");
    // // teste->fazendas = NULL;
    // printf("%d\n",temFazenda(teste->fazendas));
    

    return 0;
}