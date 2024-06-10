
# Recursão

- Em programação é quando a função chama a si mesma;
- A função recursiva deve obrigatoriamente um critério de parada (caso base, onde não possui recursão);
Exemplo:
```c
int potencia(int x,int n){
    if(n==0)
        return(1);
    else if(n>0)
        return(x*potencia(x,n-1));
}
```
# Árvore

- Organização hierárquica, bem diferente das listas, acelera o processo de busca;
- Riz: primeiro nó da árvore;
- Grau de um nó: número de sub-árvores/ número de filhos;
- Folha ou terminal: nó com grau = 0;
- Grau de uma árvore: maior grau entre os nós;
- Floresta: zero ou mais árvores disjuntas;
- Níve de um nó: número de nós entre ele e a raiz *(exemplo: raiz-> nível 1, filhas da raiz-> nível 2 e assim por diante)*;
- Altura/profundidade: é seu maior nível;
- Representação parênteses aninhados. Exemplo: (A(B(D)(D))(C(F))) (A-> raiz, B,C,D-> filhos da raiz e assim por diante);

## Árvore binária
- h -> altura
- numero máximo de nós = 2<sup>h</sup> - 1
- numero máximo de folhas = 2<sup>h-1</sup>
- cada nó não terminal ou não tem filhos ou tem a subárvore da direita e esquerda
- Árvore binária completa: todos os nós folhas estão no último ou penúltimo nível
- Árvore binéria cheia: todos os nós exceto as do útimo nível, tem exatamente duas sub-árvores

## Estrutura de dados de Árvores binárias
- pode ser representada por 3 campos: informação, sub-arvore direita e sub-arvore esquerda
- podem ser estáticas ou dinâmicas

### Estática
 Os filhos de um nó na posição i estão nas posições:
 - 2i+1: esquerda
 - 2i+2: direita

```c
typedef struct sNo{
    int info;
}NO;

typedef struct sArvore{
    NO arv[50];
}Arvore;

```

### Dinâmica

```c
typedef struct sNo{
    int info;
    struct sNo* esquerda;
    struct sNo* direita;
}NO;

typedef struct sArvore{
    NO* ptRaiz;
}Arvore;

```

### Percursos de uma árvore

### Pré-Ordem
- Visitar a raiz da árvore;
- Visitar recursivamente sua subárvore da esquerda;
- Visitar recursivamente sua subárvore da direita;

```c
    void pre_ordem(NO* raiz){

    if(raiz != NULL){
        printf("%d\n", raiz->info);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}
```

### Em-Ordem
- Visitar recursivamente sua subárvore da esquerda;
- Visitar a raiz da árvore;
- Visitar recursivamente sua subárvore da direita;

```c
    void em_ordem(NO* raiz){

    if(raiz != NULL){

        em_ordem(raiz->esq);
        printf("%d\n", raiz->info);
        em_ordem(raiz->dir);
    }
}
```

### Pós-Ordem
- Visitar recursivamente sua subárvore da esquerda;
- Visitar recursivamente sua subárvore da direita;
- Visitar a raiz da árvore;


```c
    void pos_ordem(NO* raiz){

    if(raiz != NULL){

        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d\n", raiz->info);
    }
}
```
