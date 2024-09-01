#include <stdio.h>

int main() {
    int vet_1[10], vet_2[10], vet_3[20], t1 = 10, t2 = 20, i, j, a;

    for(i = 0; i < t1; i++) {
        printf("Digite o %d° número do primeiro vetor: ", i+1);
        scanf("%d", &vet_1[i]);
        vet_3[i] = vet_1[i];
    }
    for (i = 0; i < t1; i++) {
        printf("Digite o %d° número do segundo vetor: ", i+1);
        scanf("%d", &vet_2[i]);
        vet_3[i + t1] = vet_2[i];
    }
    for (i = 0; i < t2; i++) {
        for (j = i + 1; j < t2; j++) {
            if (vet_3[i] < vet_3[j]) {
                a = vet_3[i];
                vet_3[i] = vet_3[j];
                vet_3[j] = a;
            }
        }
    }
    printf("O terceiro vetor ordenado de maneira decrescente é: ");
    for(i = 0; i < 20; i++) {
        printf("%d ", vet_3[i]);
    }
}

