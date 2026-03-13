#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// func para verificar menor numero
double verify(double a, double b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    double numA, numB;

    printf("informe num a: ");
    scanf("%lf", &numA);

    printf("informe num b: ");
    scanf("%lf", &numB);

    double maior = verify(numA, numB);

    printf("o menor numero eh: %.2lf\n", maior);

    return 0;
}
