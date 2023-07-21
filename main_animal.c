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
    printf("7 - Remover Animal\t8 - Tem Fazenda\n");
    printf("\nEscolha uma opcao: ");
    int op;
    scanf("%d", &op);

    return op;
}

int main() {

    Criador *listaCriadores = criarListaDuplaCriadores();

    Criador *c;
    Fazenda *f, *f2;
    Animal *a;

    listaCriadores = cadastrarCriador(listaCriadores);

    c = buscarCriador(listaCriadores);

    c->fazendas = cadastrarFazenda(c->fazendas);
    c->fazendas = cadastrarFazenda(c->fazendas);

    c = buscarCriador(listaCriadores);

    f = buscarFazenda(c->fazendas);
    f->rebanho = cadastrarAnimal(f->rebanho);
    f->rebanho->id_fazenda = f->id_fazenda;

    f2 = buscarFazenda(c->fazendas);
    f2->rebanho = cadastrarAnimal(f2->rebanho);
    f2->rebanho->id_fazenda = f2->id_fazenda;

    //mostrarAnimal(f->rebanho);
    printf("F1--------------------\n");
    mostrarTodosAnimais(f);
    printf("F2--------------------\n");
    mostrarTodosAnimais(f2);

    a = permutasAnimais(f, f2, 1);

    printf("F1--------------------\n");
    mostrarTodosAnimais(f);
    printf("F2--------------------\n");
    mostrarTodosAnimais(f2);

    //contAnimaisSexo(f);
    //a = buscarAnimal(f->rebanho);

    //mostrarAnimal(a);

    //calcularPatrimonio(c);

    //mostrarCriadores(listaCriadores);


   
    return 0;
}

// \Trabalhos-Estruturas-de-Dados>teste.exe
