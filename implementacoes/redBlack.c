#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Cor;

typedef struct NO {
    int valor;
    Cor cor;
    struct NO *noEsquerda;
    struct NO *noDireita;
} NO;

NO *insereNo(NO *arvore, int valorNovoNo) {
    if (arvore == NULL) {
        NO *novoNo;
        novoNo = malloc(sizeof(NO));
        novoNo->valor = valorNovoNo;
        novoNo->noDireita = NULL;
        novoNo->noEsquerda = NULL;
        novoNo->cor = RED;
        return novoNo;
    }
    if (arvore->valor < valorNovoNo) {
        arvore->noDireita = insereNo(arvore->noDireita, valorNovoNo);
    } else {
        arvore->noEsquerda = insereNo(arvore->noEsquerda, valorNovoNo);
    }

    return arvore;
}
// regras de inserção
//  1. O nó inserido sempre vermelho
//  2. A raiz é sempre preta
//  3. Se o pai é preto, o filho é vermelho
//  4. Se o pai é vermelho, o filho é preto
//  (ou seja, nao pode dois vermelhos a esquerda seguidos)
//  5. Todo caminho da raiz até a folha tem o mesmo número de nós pretos (ALTURA
//  NEGRA)

//  validação do nó -> verificar para balancear X* -> NO VERMELHO
//                          14
//              10*                        18
//          7           12             15*     NULL
//      3*     NULL    11*     NULL   NULL
// NULL      NULL    NULL  NULL

// INSERE 20
//                          14
//              10*                      18
//          7           12           15*     20* NAO PODE VERMELHO A DIREITA
//      3*     NULL    11*     NULL   NULL
// NULL      NULL    NULL  NULL
//

// operação -> subir a cor
//   18* PAI PASSA A SER VERMELHO
// 15     20 NOS FILHOS PASSAM A SER PRETOS

// recursivo
//         14  raiz passa a ser vermelho (embora nao importe)
//   10*      18*
//  ...    15     20

// fim da inserção

// insere 17
//            18
//       15        20
//   null  17* NAO PODE VERMELHO A DIREITA

// ROTACIOONA
//                18
//          17*        20 -> 17 MANTEM A COR
//      15*      NULL  -> 15 CAI PARA ESQUERDA (sempre vermelho!)
// NULL     NULL

// insere 1 => problema: 2 vermelhos seguidos a esquerda
//          7
//      3*     NULL
//  1*     NULL

// operação o no vermelho mais acima passa a ser a cabeça
// filho que era pai vira vermelho
//           3
//      1*        7*
// NULL  NULL NULL  NULL

// SOBE COR
//            3*
//       1        7
//  NULL  NULL NULL  NULL
//  fim da inserção
