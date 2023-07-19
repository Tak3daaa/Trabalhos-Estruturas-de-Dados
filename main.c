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
    int op;
    scanf("%d", &op);

    return op;
}

int main() {

    Criador *c, *cad_fazenda;// *cad_animal;
    //cad_animal = NULL;
    int r = 1;

    while(r != 0){
        r = menu();
        switch (r){
            case 1:
                c = criarListaDuplaCriadores();
                c = cadastrarCriador(c);
                //printf("Tem fazenda %d\n", tem(c));
                break;
            case 2:
                cad_fazenda = buscarCriador(c);
                cad_fazenda->fazendas = criarListaEncadeadaCircularFazendas();
                cad_fazenda->fazendas = cadastrarFazenda(cad_fazenda->fazendas);
                //printf("Tem fazenda %d\n", tem(cad_fazenda));
                break;
            case 3:
                //cad_animal->fazendas = buscarFazenda(cad_fazenda->fazendas);
                cad_fazenda->fazendas = buscarFazenda(cad_fazenda->fazendas);
                cad_fazenda->fazendas->rebanho = criaListaEncadeadaSimplesAnimais();
                cad_fazenda->fazendas->rebanho = cadastrarAnimal(cad_fazenda->fazendas->rebanho);
                break;
            case 4:
                mostrarCriadores(c);
                // buscarAnimal(cad_fazenda->fazendas->rebanho);
                mostrarTudo(c);
                break;
            default:
                break;
        }
    }

    //mostrarCriadores(c);
    //mostrarTudo(c);
    
    return 0;
}