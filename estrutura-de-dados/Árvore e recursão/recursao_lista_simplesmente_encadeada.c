#include<stdio.h>
#include<stdlib.h>

typedef struct CELULA{

    int info;
    struct CELULA *next;

}CELULA;

CELULA* getnode(){
    return(CELULA *) malloc(sizeof(CELULA));
}

void freenode(CELULA *q){
    free(q);
}

CELULA* init(CELULA *lista){
    lista = NULL;
    return lista;
}

int empty(CELULA *lista){

    if(lista == NULL)
        return 1;
    return 0;

}

CELULA* insere_inicio(CELULA *lista, int x){

    CELULA *q;

    q = getnode();
    if(q != NULL){
        q->info = x;
        q->next = lista;
        lista = q;
        return lista;

    }
    else{
        printf("\nERRO na alocacao do no");
        return NULL;
    }

}

void pares_inversa(CELULA *lista){

    if (lista == NULL){
        return;
    }

        if(lista->info%2 == 0){
            pares_inversa(lista->next);
            printf("%d\t", lista->info);

        }
        else{
            pares_inversa(lista->next);
        }

}

void somar_elementos(CELULA *lista, int elementos){


    if(lista == NULL){
        printf("A soma dos elementos na lista e: %d", elementos);
        return;
    }else{
        elementos = elementos+lista->info;
        somar_elementos(lista->next,elementos);
    }
}

void exibe_lista_recursao(CELULA *lista){

    if(lista == NULL)
    {
        return;
    }
        printf("%d\t", lista->info);
        exibe_lista_recursao(lista->next);
}
int menu(){

    int op;
    printf("\n0-Sair");
    printf("\n1-Inserir no incio");
    printf("\n2-Somar todos os elementos da lista");
    printf("\n3-Imprimir os elementos pares da lista na ordem inversa");
    printf("\n4-Exibir lista com recursao");
    printf("\n\nDigite a opcao desejada: ");
    scanf("%d", &op);
    return op;
}

void main(){

    CELULA *lista;
    lista = init(lista);

    int op, x, elem, elementos = 0;

    do{
            op = menu();
        switch(op){
        case 0:
            break;
        case 1:
            printf("Digite o numero inteiro que deseja inserir: ");
            scanf("%d", &x);
            lista = insere_inicio(lista,x);
            break;
        case 2:
            somar_elementos(lista, elementos);
            break;
        case 3:
            pares_inversa(lista);
            break;
        case 4:
            exibe_lista_recursao(lista);
            break;
        default:
            printf("Opcao invalida");
            printf("\nDigite uma opcao valida\n");
            break;
        }
    }while(op != 0);

}

