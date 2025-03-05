#include <stdio.h>

#define TAMANHO_TABULEIRO 10

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se uma posição é válida e não está ocupada
int posicaoLivre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int direcao) {
    for (int i = 0; i < 3; i++) {
        int novoX = x, novoY = y;

        // Se o navio for horizontal
        if (direcao == 0) {
            novoY += i;
        }
        // Se o navio for vertical
        else if (direcao == 1) {
            novoX += i;
        }
        // Se o navio for diagonal para cima e para a direita
        else if (direcao == 2) {
            novoX += i;
            novoY += i;
        }
        // Se o navio for diagonal para baixo e para a direita
        else if (direcao == 3) {
            novoX += i;
            novoY -= i;
        }

        if (novoX < 0 || novoX >= TAMANHO_TABULEIRO || novoY < 0 || novoY >= TAMANHO_TABULEIRO || tabuleiro[novoX][novoY] == 3) {
            return 0; // posição inválida ou já ocupada
        }
    }
    return 1; // posição válida
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int direcao) {
    for (int i = 0; i < 3; i++) {
        int novoX = x, novoY = y;

        // Se o navio for horizontal
        if (direcao == 0) {
            novoY += i;
        }
        // Se o navio for vertical
        else if (direcao == 1) {
            novoX += i;
        }
        // Se o navio for diagonal para cima e para a direita
        else if (direcao == 2) {
            novoX += i;
            novoY += i;
        }
        // Se o navio for diagonal para baixo e para a direita
        else if (direcao == 3) {
            novoX += i;
            novoY -= i;
        }

        tabuleiro[novoX][novoY] = 3; // Marca a posição do navio com 3
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Definir manualmente as coordenadas e direções dos navios
    // Primeiro navio (horizontal)
    int x1 = 2, y1 = 3, direcao1 = 0; // x1, y1 são as coordenadas de início, direcao1 = 0 (horizontal)
    if (posicaoLivre(tabuleiro, x1, y1, direcao1)) {
        posicionarNavio(tabuleiro, x1, y1, direcao1);
    }

    // Segundo navio (vertical)
    int x2 = 5, y2 = 6, direcao2 = 1; // x2, y2 são as coordenadas de início, direcao2 = 1 (vertical)
    if (posicaoLivre(tabuleiro, x2, y2, direcao2)) {
        posicionarNavio(tabuleiro, x2, y2, direcao2);
    }

    // Terceiro navio (diagonal para cima e à direita)
    int x3 = 7, y3 = 7, direcao3 = 2; // x3, y3 são as coordenadas de início, direcao3 = 2 (diagonal para cima e direita)
    if (posicaoLivre(tabuleiro, x3, y3, direcao3)) {
        posicionarNavio(tabuleiro, x3, y3, direcao3);
    }

    // Quarto navio (diagonal para baixo e à direita)
    int x4 = 1, y4 = 8, direcao4 = 3; // x4, y4 são as coordenadas de início, direcao4 = 3 (diagonal para baixo e direita)
    if (posicaoLivre(tabuleiro, x4, y4, direcao4)) {
        posicionarNavio(tabuleiro, x4, y4, direcao4);
    }

    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}

