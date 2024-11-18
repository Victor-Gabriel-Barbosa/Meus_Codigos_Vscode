#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define VAZIO ' '
#define PEAO_BRANCO 'P'
#define TORRE_BRANCO 'T'
#define CAVALO_BRANCO 'C'
#define BISPO_BRANCO 'B'
#define RAINHA_BRANCO 'D'
#define REI_BRANCO 'R'
#define PEAO_PRETO 'p'
#define TORRE_PRETO 't'
#define CAVALO_PRETO 'c'
#define BISPO_PRETO 'b'
#define RAINHA_PRETO 'd'
#define REI_PRETO 'r'

char tabuleiro[8][8];

// Funções auxiliares para validação de movimento
int dentroDoTabuleiro(int linha, int coluna) {
    return linha >= 0 && linha < 8 && coluna >= 0 && coluna < 8;
}

int caminhoLivre(int linhaOrig, int colunaOrig, int linhaDest, int colunaDest) {
    int deltaLinha = (linhaDest - linhaOrig) ? (linhaDest - linhaOrig) / abs(linhaDest - linhaOrig) : 0;
    int deltaColuna = (colunaDest - colunaOrig) ? (colunaDest - colunaOrig) / abs(colunaDest - colunaOrig) : 0;
    
    int linha = linhaOrig + deltaLinha;
    int coluna = colunaOrig + deltaColuna;
    
    while (linha != linhaDest || coluna != colunaDest) {
        if (tabuleiro[linha][coluna] != VAZIO) {
            return 0;
        }
        linha += deltaLinha;
        coluna += deltaColuna;
    }
    return 1;
}

// Funções de validação para cada peça
int validarPeao(int linhaOrig, int colunaOrig, int linhaDest, int colunaDest, int vezBrancas) {
    int direcao = vezBrancas ? -1 : 1;
    int linhaInicial = vezBrancas ? 6 : 1;
    
    // Movimento simples para frente
    if (colunaOrig == colunaDest) {
        if (linhaDest == linhaOrig + direcao && tabuleiro[linhaDest][colunaDest] == VAZIO) {
            return 1;
        }
        // Movimento duplo inicial
        if (linhaOrig == linhaInicial && 
            linhaDest == linhaOrig + 2 * direcao && 
            tabuleiro[linhaDest][colunaDest] == VAZIO &&
            tabuleiro[linhaOrig + direcao][colunaOrig] == VAZIO) {
            return 1;
        }
    }
    // Captura diagonal
    else if (abs(colunaDest - colunaOrig) == 1 && linhaDest == linhaOrig + direcao) {
        if (tabuleiro[linhaDest][colunaDest] != VAZIO) {
            return 1;
        }
    }
    return 0;
}

int validarTorre(int linhaOrig, int colunaOrig, int linhaDest, int colunaDest) {
    // Movimento apenas na vertical ou horizontal
    if (linhaOrig == linhaDest || colunaOrig == colunaDest) {
        return caminhoLivre(linhaOrig, colunaOrig, linhaDest, colunaDest);
    }
    return 0;
}

int validarCavalo(int linhaOrig, int colunaOrig, int linhaDest, int colunaDest) {
    int deltaLinha = abs(linhaDest - linhaOrig);
    int deltaColuna = abs(colunaDest - colunaOrig);
    
    return (deltaLinha == 2 && deltaColuna == 1) || (deltaLinha == 1 && deltaColuna == 2);
}

int validarBispo(int linhaOrig, int colunaOrig, int linhaDest, int colunaDest) {
    // Movimento apenas na diagonal
    if (abs(linhaDest - linhaOrig) == abs(colunaDest - colunaOrig)) {
        return caminhoLivre(linhaOrig, colunaOrig, linhaDest, colunaDest);
    }
    return 0;
}

int validarRainha(int linhaOrig, int colunaOrig, int linhaDest, int colunaDest) {
    // Combinação dos movimentos da torre e do bispo
    if ((linhaOrig == linhaDest || colunaOrig == colunaDest) ||
        (abs(linhaDest - linhaOrig) == abs(colunaDest - colunaOrig))) {
        return caminhoLivre(linhaOrig, colunaOrig, linhaDest, colunaDest);
    }
    return 0;
}

int validarRei(int linhaOrig, int colunaOrig, int linhaDest, int colunaDest) {
    // Movimento de uma casa em qualquer direção
    return abs(linhaDest - linhaOrig) <= 1 && abs(colunaDest - colunaOrig) <= 1;
}

void inicializarTabuleiro() {
    // Inicializar peças pretas
    tabuleiro[0][0] = TORRE_PRETO;
    tabuleiro[0][1] = CAVALO_PRETO;
    tabuleiro[0][2] = BISPO_PRETO;
    tabuleiro[0][3] = RAINHA_PRETO;
    tabuleiro[0][4] = REI_PRETO;
    tabuleiro[0][5] = BISPO_PRETO;
    tabuleiro[0][6] = CAVALO_PRETO;
    tabuleiro[0][7] = TORRE_PRETO;
    
    for(int i = 0; i < 8; i++) {
        tabuleiro[1][i] = PEAO_PRETO;
    }

    // Inicializar espaços vazios
    for(int i = 2; i < 6; i++) {
        for(int j = 0; j < 8; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }

    // Inicializar peças brancas
    for(int i = 0; i < 8; i++) {
        tabuleiro[6][i] = PEAO_BRANCO;
    }

    tabuleiro[7][0] = TORRE_BRANCO;
    tabuleiro[7][1] = CAVALO_BRANCO;
    tabuleiro[7][2] = BISPO_BRANCO;
    tabuleiro[7][3] = RAINHA_BRANCO;
    tabuleiro[7][4] = REI_BRANCO;
    tabuleiro[7][5] = BISPO_BRANCO;
    tabuleiro[7][6] = CAVALO_BRANCO;
    tabuleiro[7][7] = TORRE_BRANCO;
}

void imprimirTabuleiro() {
    printf("\n  a b c d e f g h\n");
    printf("  ---------------\n");
    for(int i = 0; i < 8; i++) {
        printf("%d|", 8-i);
        for(int j = 0; j < 8; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("|%d\n", 8-i);
    }
    printf("  ---------------\n");
    printf("  a b c d e f g h\n\n");
}

int validarMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, int vezBrancas) {
    // Verificações básicas
    if (!dentroDoTabuleiro(linhaOrigem, colunaOrigem) || !dentroDoTabuleiro(linhaDestino, colunaDestino)) {
        return 0;
    }

    char peca = tabuleiro[linhaOrigem][colunaOrigem];
    
    // Verificar se é a vez correta
    if (vezBrancas && islower(peca)) return 0;
    if (!vezBrancas && isupper(peca)) return 0;
    
    // Verificar se há uma peça na posição de origem
    if (peca == VAZIO) return 0;
    
    // Verificar se está tentando capturar uma peça da mesma cor
    if (vezBrancas && isupper(tabuleiro[linhaDestino][colunaDestino])) return 0;
    if (!vezBrancas && islower(tabuleiro[linhaDestino][colunaDestino])) return 0;

    // Validar movimento específico para cada peça
    switch(toupper(peca)) {
        case 'P':
            return validarPeao(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, vezBrancas);
        case 'T':
            return validarTorre(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
        case 'C':
            return validarCavalo(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
        case 'B':
            return validarBispo(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
        case 'D':
            return validarRainha(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
        case 'R':
            return validarRei(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
        default:
            return 0;
    }
}

void realizarMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    tabuleiro[linhaDestino][colunaDestino] = tabuleiro[linhaOrigem][colunaOrigem];
    tabuleiro[linhaOrigem][colunaOrigem] = VAZIO;
}

int encontrarRei(int vezBrancas, int *linha, int *coluna) {
    char rei = vezBrancas ? REI_BRANCO : REI_PRETO;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabuleiro[i][j] == rei) {
                *linha = i;
                *coluna = j;
                return 1;
            }
        }
    }
    return 0;
}

int estaEmXeque(int vezBrancas) {
    int linhaRei, colunaRei;
    if (!encontrarRei(vezBrancas, &linhaRei, &colunaRei)) return 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((vezBrancas && islower(tabuleiro[i][j])) || (!vezBrancas && isupper(tabuleiro[i][j]))) {
                if (validarMovimento(i, j, linhaRei, colunaRei, !vezBrancas)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int estaEmXequeMate(int vezBrancas) {
    if (!estaEmXeque(vezBrancas)) {
        return 0;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((vezBrancas && isupper(tabuleiro[i][j])) || (!vezBrancas && islower(tabuleiro[i][j]))) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (validarMovimento(i, j, k, l, vezBrancas)) {
                            char pecaTemp = tabuleiro[k][l];
                            realizarMovimento(i, j, k, l);
                            int aindaEmXeque = estaEmXeque(vezBrancas);
                            realizarMovimento(k, l, i, j);
                            tabuleiro[k][l] = pecaTemp;
                            if (!aindaEmXeque) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    int vezBrancas = 1;
    int vitoria = 0;
    char entrada[5];
    
    inicializarTabuleiro();
    
    while (!vitoria) {
        imprimirTabuleiro();
        
        if (estaEmXeque(vezBrancas)) {
            if (estaEmXequeMate(vezBrancas)) {
                printf("Xeque-mate! %s vencem!\n", vezBrancas ? "Pretas" : "Brancas");
                vitoria = 1;
                continue;
            } else {
                printf("Xeque!\n");
            }
        }
        
        printf("Vez das %s (ex: e2e4): ", vezBrancas ? "Brancas" : "Pretas");
        scanf("%s", entrada);
        
        if(entrada[0] == 'q') break;
        
        int colunaOrigem = entrada[0] - 'a';
        int linhaOrigem = 8 - (entrada[1] - '0');
        int colunaDestino = entrada[2] - 'a';
        int linhaDestino = 8 - (entrada[3] - '0');
        
        if(validarMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, vezBrancas)) {
            char pecaTemp = tabuleiro[linhaDestino][colunaDestino];
            realizarMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
            
            if (estaEmXeque(vezBrancas)) {
                printf("Movimento inválido! Seu rei ficaria em xeque.\n");
                realizarMovimento(linhaDestino, colunaDestino, linhaOrigem, colunaOrigem);
                tabuleiro[linhaDestino][colunaDestino] = pecaTemp;
            } else {
                vezBrancas = !vezBrancas;
            }
        } else {
            printf("Movimento inválido! Tente novamente.\n");
        }
    }
    
    return 0;
}