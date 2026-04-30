#include <stdio.h>
#include <stdlib.h>

#define TAM 10 
#define VAZIO 0
#define NAVIO 3
#define EFEITO 1

int valorAbsoluto (int x) {
  if (x < 0)
    return -x;
  return x;
}

void inicializar(int tab[TAM][TAM]) {
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      tab[i][j] = VAZIO;
    }
  }
}

void criarCone(int cone[5][5]) {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      
      if (j >= 2 - i && j <= 2 + i)
       cone[i][j] = 1;
      else
       cone[i][j] = 0;
    }
  }
}

void criarCruz(int cruz[5][5]) {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      
      if ( i == 2 || j == 2)
       cruz[i][j] = 1;
      else
       cruz[i][j] = 0;
      
    }
  }
}

void criarOctaedro(int oct[5][5]) {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
     if (valorAbsoluto(i - 2) + valorAbsoluto (j - 2) <= 2)
        oct[i][j] = 1;
      else
        oct[i][j] = 0;
    }
    }
  }
  
void aplicar(int tab[TAM][TAM], int habilidade[5][5], int origemL, int origemC) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      
      int l = origemL + i - 2;
      int c = origemC + j - 2;
      
      if (l >= 0 && 1 < TAM && c >= 0 && c < TAM) {
        if (habilidade[i][j] == 1) {
          tab[1][c] = 1;
        }
      }
    }
  }
}

void mostrar(int tab[TAM][TAM]) {
  printf("TABULEIRO:\n");
  
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      
      if (tab[i][j] == 0)
        printf(". ");  // água
      else if (tab[i][j] == 3)
        printf("N ");  // navio
      else if (tab[i][j] == 1)
        printf("* ");  // efeito
    }
     printf("\n");
    }
  }
  
int main() {
  int tab[TAM][TAM];
  
  int cone[5][5];
  int cruz[5][5];
  int oct[5][5];
  
  inicializar(tab);
  
  criarCone(cone);
  criarCruz(cruz);
  criarOctaedro(oct);
  
  // Origens fixas
  aplicar(tab, cone, 4, 4);
  aplicar(tab, cruz, 4, 4);
  aplicar(tab, oct, 4, 4);
  
  mostrar(tab);
  
  return 0;
  
}
