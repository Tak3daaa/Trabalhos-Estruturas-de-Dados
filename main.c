#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "criador.c"
#include "fazenda.h"

int menu(){
    printf("\n---------------------------------------------\n");
    printf("1 - Cadastrar Criador\t2 - Cadastrar Fazenda\n");
    printf("3 - Cadastrar Animal\t4 - Mostrar Criador\n");
    printf("5 - Remover Criador\t6 - Remover Fazenda\n");
    printf("7 - Remover Animal\t\n");
    printf("\nEscolha uma opcao: ");
    int op;
    scanf("%d", &op);

    return op;
}

int main() {

    Criador *c, *cad_fazenda;
    c = criarListaDuplaCriadores();
    int r = 1;

    while(r != 0){
        r = menu();
        switch (r){
            case 1:
                c = cadastrarCriador(c);
                break;
            case 2:
                cad_fazenda = buscarCriador(c);
                //cad_fazenda->fazendas = criarListaEncadeadaCircularFazendas();
                cad_fazenda->fazendas = cadastrarFazenda(cad_fazenda->fazendas);
                break;
            case 3:
                cad_fazenda->fazendas = buscarFazenda(cad_fazenda->fazendas);
                //cad_fazenda->fazendas->rebanho = criaListaEncadeadaSimplesAnimais();
                cad_fazenda->fazendas->rebanho = cadastrarAnimal(cad_fazenda->fazendas->rebanho);
                break;
            case 4:
                mostrarCriadores(c);
                break;
            case 5:
                c = removerCriador(c);
                break;
            //case 6:
                
            default:
                break;
        }
    }

    return 0;
}