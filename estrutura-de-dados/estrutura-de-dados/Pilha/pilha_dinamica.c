#include<stdio.h>
#include<stdlib.h>

struct PRATO
{
    char formato[20];
    char cor[20];
};

typedef struct cell
{
    struct PRATO info;
    struct cell *next;
} CELULA;


CELULA* getnode()
{
    return (CELULA *) malloc(sizeof(CELULA));
}

void freenode(CELULA *q)
{
    free(q);
}

void inicializar(CELULA **pilha)
{
    *pilha = NULL;
}

int empty(CELULA *pilha)
{
    if(pilha == NULL)
        return 1;
    return 0;
}

void push(CELULA **pilha, struct PRATO prato)
{
    CELULA *q;
    q = getnode();
    if(q != NULL)
    {
        q->info = prato;
        q->next = *pilha;
        *pilha = q;
    }
    else
    {
        printf("\nERRO na alocacao do no\n");
        exit(1);
    }
}

void pop(CELULA **pilha)
{
    CELULA *q;
    q = *pilha;
    if(!empty(*pilha))
    {
        *pilha = q->next;
        freenode(q);
    }
    else
    {
        printf("\nERRO: lista vazia \n");
        exit(1);
    }
}

void exibe_pilha_pop(CELULA *pilha)
{
    CELULA *aux, *q;
    aux = pilha;
    while(!empty(aux))
    {
        printf("\nFormato: %s", aux->info.formato);
        printf("\nCor: %s", aux->info.cor);
        aux = aux->next;
        pop(&pilha);
    }
    printf("\n");
}

void exibe_pilha(CELULA *pilha)
{

    CELULA *aux;

    aux = pilha;
    while (aux != NULL)
    {
        printf("\nFormato: %s", aux->info.formato);
        printf("\nCor: %s", aux->info.cor);
        aux = aux->next;
    }
    printf("\n");
}

void inverter_pilha(CELULA **pilha)
{
    CELULA *pilha_aux = NULL;
    if(!empty(*pilha))
    {
        while (*pilha != NULL)
        {
            struct PRATO prato = (*pilha)->info;
            pop(pilha);
            push(&pilha_aux, prato);
        }
        exibe_pilha(pilha_aux);
    }
    else
    {
        printf("\nERRO: lista vazia \n");
        exit(1);
    }
}

void inverter_topo_base(CELULA **pilha)
{
    CELULA *pilha_aux = NULL;
    struct PRATO base;
    struct PRATO topo;
    if(!empty(*pilha))
    {
        topo = (*pilha)->info;
        pop(pilha);
        if((*pilha) != NULL)
        {
            while((*pilha) != NULL)
            {
                struct PRATO prato = (*pilha)->info;
                pop(pilha);
                push(&pilha_aux, prato);
            }
            base = pilha_aux->info;
            pop(&pilha_aux);
        }
        push(pilha, topo);
        while(!empty(pilha_aux))
        {
            push(pilha, pilha_aux->info);
            pop(&pilha_aux);
        }
        push(pilha, base);
        exibe_pilha(*pilha);
    }
    else
    {
        printf("\nERRO: lista vazia \n");
        exit(1);
    }
}

int menu()
{
    int op;
    printf("\nMenu principal: ");
    printf("\n0 - Sair");
    printf("\n1 - Inserir um prato");
    printf("\n2 - Remover um prato da pilha");
    printf("\n3 - Inverter pratos");
    printf("\n4 - Inverter topo da pilha pela base");
    printf("\n5 - Exibir pratos com a funcao pop");
    printf("\n6 - Exibir pratos");
    printf("\nOpcao: ");
    scanf("%d",&op);
    return op;
}

void main()
{
    CELULA *pilha;
    struct PRATO prato;
    inicializar(&pilha);
    int op, pos, x;
    do
    {
        op = menu();
        switch (op)
        {
        case 0:
            printf("Obrigado por usar nosso sistema!");
            break;
        case 1:
            printf("\nDigite o formato do prato que deseja inserir na pilha: \n");
            scanf("%s",prato.formato);
            fflush(stdin);

            printf("\nDigite a cor do prato que deseja inserir na pilha: \n");
            scanf("%s",prato.cor);
            fflush(stdin);
            push(&pilha, prato);
            break;
        case 2:
            pop(&pilha);
            break;
        case 3:
            inverter_pilha(&pilha);
            break;
        case 4:
            inverter_topo_base(&pilha);
            break;
        case 5:
            exibe_pilha_pop(pilha);
            break;
        case 6:
            exibe_pilha(pilha);
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    }
    while(op != 0);
}

