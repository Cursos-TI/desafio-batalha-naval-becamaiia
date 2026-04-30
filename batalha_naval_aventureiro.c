#include <stdio.h>

#define TAM 10 
#define AGUA 0 
#define NAVIO 3 

void inicializarTabuleiro(int tab[TAM][TAM]) {
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      tab[i][j] = AGUA;
    }
  }
}


int dentroLimite(int linha, int coluna) {
  return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}


int posicaoLivre(int tab[TAM][TAM], int linha, int coluna) {
  return dentroLimite(linha, coluna) && tab[linha][coluna]
  == AGUA;
}


int navioHorizontal(int tab[TAM][TAM], int linha, int coluna) {
  for (int i = 0; i < 3; i++) {
    if (!posicaoLivre(tab, linha, coluna + i))
      return 0;
  }
  for (int i = 0; i < 3; i++) {
    tab[linha][coluna + i] = NAVIO;
  }
  return 1;
}


int navioVertical(int tab[TAM][TAM], int linha, int coluna) {
  for (int i = 0; i < 3; i++) {
    if (!posicaoLivre(tab, linha + i, coluna))
      return 0;
  }
  for (int i = 0; i < 3; i++) {
    tab[linha + i][coluna] = NAVIO;
  }
  return 1;
}


int navioDiagonalPrincipal(int tab[TAM][TAM], int linha, int coluna) {
  for (int i = 0; i < 3; i++) {
    if (!posicaoLivre(tab, linha + i, coluna + i))
      return 0;
  }
  for (int i = 0; i < 3; i++) {
    tab[linha + i][coluna + i] = NAVIO;
  }
  return 1;
}


int navioDiagonalSecundaria(int tab[TAM][TAM], int linha, int coluna) {
  for (int i = 0; i < 3; i++) {
    if (!posicaoLivre(tab, linha + i, coluna - i))
      return 0;
  }
  for (int i = 0; i < 3; i++) {
    tab[linha + i][coluna - i] = NAVIO;
  }
  return 1;
}


void mostrarTabuleiro(int tab[TAM][TAM]) {
  printf("TABULEIRO: \n");
  
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      printf("%d ", tab[i][j]);
    }
    printf("\n");
  }
}


int main() {
  int tabuleiro[TAM][TAM];
  
  inicializarTabuleiro(tabuleiro);
  
  // Posicionar os navios 
  navioHorizontal(tabuleiro, 2, 1);
  navioVertical(tabuleiro, 5, 4);
  navioDiagonalPrincipal(tabuleiro, 0, 0);
  navioDiagonalSecundaria(tabuleiro, 0, 9);
  
  mostrarTabuleiro(tabuleiro);
  
  return 0;
  
}
