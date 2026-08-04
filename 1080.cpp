#include <bits/stdc++.h>

using namespace std;

int main() {
    int numero, maior = -1, posicao = -1;

    for (int i = 1; i <= 100; i++) {
        scanf("%d", &numero);

        if (numero > maior) {
            maior = numero;
            posicao = i;
        }
    }

    printf("%d\n%d\n", maior, posicao);

    return 0;
}