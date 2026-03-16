// C program that converts from a base 10 to any base B 

#include <stdio.h>

int main() {
    int Noriginal, N, B, digits[100], count = 0, R; 

    // Demander à l'utilisateur d'entrer N et B
    printf("Entrez un nombre entier (N) en base 10 : ");
    scanf("%d", &N);
    Noriginal = N;
    printf("Entrez une base (B > 1) : ");
    scanf("%d", &B);

    // Vérification que B > 1
    if (B <= 1) {
        printf("La base doit être supérieure à 1.\n");
        return 1;
    }

    // Conversion 
    do {
        R = N % B; // Reste
        N = N / B; // Mettre à jour N
        digits[count] = R; 
        count = count + 1;
    } while (N > 0);

    // Affichage
    printf("La représentation de N en base %d est : ", B);
    for (int j = count - 1; j >= 0; j--) { 
        printf("%d", digits[j]);
    }
    printf("\n");

    // Affichage des variables
    printf("Valeurs utilisées : N = %d, B = %d ", Noriginal, B);
    
    printf("\n");

    return 0;
}
