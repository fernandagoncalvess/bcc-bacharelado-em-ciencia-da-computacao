# TAD - Tipo abstrato de dados 📑
### Modelo matemático acompanhado das operações definidas sobre o modelo.
Exemplo:
<br>
Conjunto de números inteiros: ...., -200, -199,..., 0, 200, 199,...
<br>
Operações: somar, subtrair, multiplicar, dividir,....

#### Dados organizados em uma forma coerente representam uma estrutura de dados(estudo de diferentes tipos de organizações).
# Lista Linear Estática
- Flexíveis, crescem ou diminuem durante a execução do programa de acordo com a demanda;
- Sequência de zero ou mais elementos de um mesmo tipo;
- Os elementos tem relações de ordem;
- Desordenada: insere elemento na última posição;
- Ordenada: insere elemento na posição n, causando o deslocamento de todos os lementos após o ponto de inserção, mesma lógica ao retirar elemento;
- **int n** refere-se ao índice do último elemento inserido, **n == -1** significa que a lista está vazia.

```c
#define TAMF 10
typedef struct lista
{
    char valor[TAMF];
    int n;
}LISTA;
```

```c
void lista_inicializar(LISTA *L)
{
    L->n = -1;
}
```
<br>

```c
char lista_acessar(LISTA *L, int k){
    if((k<0) || (k>(L->n))
        printf("Erro - elemento fora dos limites");
    else
        return L->valor[k];
}
```
Obs.: Por posição.
<br>
```c
void lista_buscar(LISTA *L, char valor_b)
{
    int elemento = -1;
    int i = 0;
    while(i<=(L->n)){
      if(valor_b == L->valor[i]){
        elemento = i;
        i++;
        break;
    }
  }
  return elemento;
}
```
Obs.: Por elemento.
<br>
```c
int lista_cheia(LISTA *L)
{
    if(L->n+1 == TAMF)
        return 1;
    else
        return 0;
}
```
<br>

```c
int lista_vazia(LISTA *L)
{
   if( L->n == -1)
      return 1;
    else
      return 0;
}
```
<br>


