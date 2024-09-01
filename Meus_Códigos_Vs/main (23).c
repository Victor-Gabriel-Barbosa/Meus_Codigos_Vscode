#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define x 15
#define y 5

int main() {
    int matriz[x][y], contador[100], i, j;
    srand(time(0));
    for (i = 0; i < 100; i++) 
      contador[i] = 0;
    for (i = 0; i < x; i++) {
      printf("\n");
      for (j = 0; j < y; j++) {
        matriz[i][j] = rand() % 100; 
        contador[matriz[i][j]]++;
        if (j == 0)
          printf("%d",  matriz[i][j]);
        else 
          printf(", %d",  matriz[i][j]);
    
      }
    }
    printf("\n");
    for (i = 0; i < 100; i++) {
        if (contador[i] > 1) {
            printf("\nO número %d se repete %d vezes\n", i, contador[i]);
        }
    }

    return 0;
}
