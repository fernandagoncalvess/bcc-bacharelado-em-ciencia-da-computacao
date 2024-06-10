#include<stdio.h>
#include<stdlib.h>


typedef struct sNO{

    int info;
    struct sNO* esq;
    struct sNO* dir;

}NO;

typedef struct sArvore{
    NO* raiz;
}Arvore;

Arvore* getnode(){
    return(Arvore*) malloc(sizeof(Arvore));
}

void inicializar(NO** raiz){
    *raiz = NULL;
}

NO* insere_no(NO* raiz, int x){

    if(raiz == NULL){
        NO* novoNo;
        novoNo = getnode();
        novoNo->info = x;
        novoNo->dir = NULL;
        novoNo->esq = NULL;
        return;
    }
        if(x<raiz->info){
        raiz->esq = insere_no(raiz->esq, x);
    }else if(x>raiz->info){
        raiz->dir = insere_no(raiz->dir, x);

        }
         return raiz;

}

void pre_ordem(NO* raiz){

    if(raiz != NULL){
        printf("%d\n", raiz->info);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void em_ordem(NO* raiz){

    if(raiz != NULL){

        em_ordem(raiz->esq);
        printf("%d\n", raiz->info);
        em_ordem(raiz->dir);
    }
}

void pos_ordem(NO* raiz){

    if(raiz != NULL){

        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d\n", raiz->info);
    }
}

int menu(){

    int op;
    printf("\n0-Sair");
    printf("\n1-Inserir um no na arvore");
    printf("\n2-Exibir pre ordem");
    printf("\n3-Exibir em ordem");
    printf("\n4-Exibir pos ordem");
    printf("\n\nDigite a opcao desejada: ");
    scanf("%d", &op);
    return op;
}

void main(){

    int op, x;
    NO *raiz;
    inicializar(&raiz);

    do{
        op = menu();
        switch(op){
        case 0:
            printf("Obrigado por usar nosso sistema!");
            break;
        case 1:
            printf("Digite o numero que deseja inserir\n");
            scanf("%d", &x);
            raiz= insere_no(raiz, x);
            break;
        case 2:
            pre_ordem(raiz);
            break;
        case 3:
            em_ordem(raiz);
            break;
        case 4:
            pos_ordem(raiz);
            break;
        default:
            printf("Digite uma opcao existente");
        }
    }while(op != 0);
}
