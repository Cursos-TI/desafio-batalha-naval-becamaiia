#include <stdio.h>
 
 int main() {
   
   int tabuleiro[10][10];
   
   int navioHorizontal[3] = {3, 3, 3};
   int navioVertical[3] = {3, 3, 3};
   
   int linha, coluna;
   
   
   // INICIALIZAR TABULEIRO //
   for (int i = 0; i < 10; i++) {
     for(int j = 0; j < 10; j++) {
       tabuleiro[i][j] = 0;
     }
   }
   
   
   // POSICIONAR NAVIO HORIZONTAL //
   linha = 2;
   coluna = 1;
   
   for (int i = 0; i < 3; i++) {
     tabuleiro[linha][coluna + i] =
     navioHorizontal[i];
   }
   
   
   // POSICIONAR NAVIO VERTICAL 
   linha = 5;
   coluna = 5;
   
   for (int i = 0; i < 3; i++) {
     tabuleiro[linha + i][coluna] =
     navioVertical[i];
   }
   
   
   // EXIBIR TABULEIRO
   printf("TABULEIRO BATALHA NAVAL\n");
   
   for (int i = 0; i < 10; i++) {
     for (int j = 0; j <10; j++) {
       printf("%d ", tabuleiro[i][j]);
     }
     printf("\n");
     }
     
     return 0;
   }
