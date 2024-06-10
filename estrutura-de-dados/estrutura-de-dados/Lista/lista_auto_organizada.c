#include<stdio.h>
#include<stdlib.h>

typedef struct CELULA{

    int info;
    int acessos;
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
        q->acessos = 0;
        lista = q;
        return lista;

    }
    else{
        printf("\nERRO na alocacao do no");
        return NULL;
    }

}

CELULA* insere_fim(CELULA *lista, int x)
{
    CELULA *q;
    CELULA *aux;

    q = getnode();

    if(q!= NULL)
    {
        q->info= x;
        q->next = NULL;
        q->acessos = 0;

        if(empty(lista))
        {
            lista = q;
        }


        else
        {
            aux = lista;
            while(aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = q;
        }

        return lista;
    }
    else
    {
        printf("\nErro na alocacao do no.\n");
        return NULL;
    }

}

CELULA* remove_inicio(CELULA *lista)
{
    CELULA *q;

    q = lista;

    if(!empty(lista))
    {
        lista = q->next;
        freenode(q);
        return lista;
    }
    else
    {
        printf("\nErro: LISTA VAZIA\n");
        return NULL;
    }
}

CELULA* pesquisa(CELULA *lista, int x)
{
    CELULA *q;

    if(!empty(lista))
    {
        q = lista;
        while( q != NULL)
        {
            q->acessos++;
            if(q->info == x)
            {
                return q;
            }
            q = q->next;
        }
    }

    return NULL;
}



CELULA* remove_valor(CELULA *lista, int x)
{
    CELULA *q;
    CELULA *aux;

    if((q = pesquisa(lista, x )) != NULL)
    {
        aux = lista;

        if(aux == q)
        {
            remove_inicio(lista);
        }
        else
        {
            while(aux->next != q)
            {
                aux = aux->next;
            }

            aux->next = q->next;
            freenode(q);
        }
        return lista;
    }
    return NULL;
}

CELULA* inserir_na_posicao(CELULA *lista,int elem,int x){

    CELULA *aux;
    CELULA *aux1;
    CELULA *q;
    int atualposicao = 0;

    q = getnode();

    q->info = elem;
    q->acessos = 0;

    aux = lista;

     if (x == 0) {
       lista = insere_inicio(lista,elem);
       freenode(q);
     }
     else{
        while(atualposicao< x){
            aux1=aux;
            aux = aux->next;
            atualposicao++;
        }
        aux1->next = q;
        q->next = aux;

        return lista;
     }

    return NULL;
}

CELULA* remover_fim(CELULA *lista)
{
    CELULA *aux;


    if(lista!= NULL)
    {
        if(empty(lista))
        {
            printf("LISTA VAZIA");
        }
        else
        {
            aux = lista;
            while(aux->next != NULL)
            {
                aux = aux->next;
            }
            freenode(aux);
        }
        return lista;
    }
    else
    {
        printf("\nErro na alocacao do no.\n");
        return NULL;
    }

}

CELULA* mover_frente(CELULA *lista, int x){

    CELULA *aux;
    CELULA *q;

    printf("LISTA ANTIGA: ");
    exibe_lista(lista);

    aux = lista;
    q = getnode();

    if(!empty(lista))
    {
    while(aux->info != x){

        aux = aux->next;
    }

    q = remove_valor(lista,aux->info);
    q = insere_inicio(lista,x);
    q->acessos++;

    printf("\nNOVA LISTA: ");
    exibe_lista(q);

    return q;
    }
    else{
        printf("Lista vazia!");
    }
    return NULL;

}

CELULA* transposicao(CELULA *lista, int x){

    CELULA *aux;
    CELULA *aux3;
    CELULA *q;


    if((q = pesquisa(lista, x )) != NULL)
    {
        aux = lista;

        if(aux->info == x)
        {
            printf("ELEMENTO E O PRIMEIRO DA LISTA");
        }
        else{

            while(aux->next->info != x){
                aux3 = aux;
                aux = aux->next;
            }
                if(aux3 != NULL){
                    aux3->next= aux->next;
                    aux->next = aux3->next->next;
                    aux3->next->next = aux;
                }
                return lista;
            }

        }
    else{
        printf("ELEMENTO NAO ENCONTRADO");
    }
    return NULL;

}

void trocar(CELULA *a, CELULA *b) {
    int temp_data = a->info;
    int temp_acessos = a->acessos;
    a->info = b->info;
    a->acessos = b->acessos;
    b->info = temp_data;
    b->acessos = temp_acessos;
}

CELULA* contagem(CELULA *lista) {
    if (lista == NULL) {
        printf("LISTA VAZIA\n");
        return NULL;
    }

    CELULA *aux = lista;
    int check;

    do {
        check = 0;
        aux = lista;

        while (aux->next != NULL) {
            if (aux->acessos > aux->next->acessos) {
                trocar(aux, aux->next);
                check = 1;
            }
            aux = aux->next;
        }
    } while (check);

    return lista;
}

void exibe_lista(CELULA *lista){

    CELULA *aux;
    aux = lista;
    while(aux != NULL){
        printf("%d\t", aux->info);
        printf("%d\t", aux->acessos);
        aux = aux->next;
    }
}

int menu(){

    int op;
    printf("\n0-Sair");
    printf("\n1-Inserir no incio");
    printf("\n2-Inserir no fim");
    printf("\n3-Inserir na posicao x");
    printf("\n4-Remover inicio");
    printf("\n5-Remover fim");
    printf("\n6-Remover elemento x");
    printf("\n7-Pesquisar elemento x");
    printf("\n8-Mover para frente");
    printf("\n9-Transposicao");
    printf("\n10-Contagem");
    printf("\n11-Exibir lista");
    printf("\n\nDigite a opcao desejada: ");
    scanf("%d", &op);
    return op;
}

void main(){

    CELULA *lista;
    lista = init(lista);

    int op, x, elem;

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
            printf("Digite o numero inteiro que deseja inserir: ");
            scanf("%d", &x);
            lista = insere_fim(lista,x);
            break;
        case 3:
            printf("Digite o numero da posicao: ");
            scanf("%d", &x);
            printf("Digite o numero inteiro que deseja inserir: ");
            scanf("%d", &elem);
            lista = inserir_na_posicao(lista, elem, x);
            break;
        case 4:
            lista = remove_inicio(lista);
            break;
        case 5:
            lista = remover_fim(lista);
            break;
        case 6:
            printf("Digite o numero inteiro que deseja remover: ");
            scanf("%d", &x);
            lista = remove_valor(lista,x);
            break;
        case 7:
            printf("Digite o numero inteiro que deseja pesquisar: ");
            scanf("%d", &x);
            pesquisa(lista,x);
            break;
        case 8:
            printf("Digite o numero inteiro que deseja mover para frente: ");
            scanf("%d", &x);
            lista = mover_frente(lista, x);
            break;
        case 9:
            printf("Digite o numero inteiro que deseja mover: ");
            scanf("%d", &x);
            lista = transposicao(lista,x);
            break;
        case 10:
            lista = contagem(lista);
            break;
        case 11:
            exibe_lista(lista);
            break;
        default:
            printf("Opcao invalida");
            printf("\nDigite uma opcao valida\n");
            break;
        }
    }while(op != 0);

}
