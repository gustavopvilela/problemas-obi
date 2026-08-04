#include <bits/stdc++.h>

using namespace std;

int main() {
    int numero, horasTrabalhadas;
    float salarioHora;

    scanf("%d", &numero);
    scanf("%d", &horasTrabalhadas);
    scanf("%f", &salarioHora);

    printf("NUMBER = %d\n", numero);
    printf("SALARY = U$ %.2f\n", salarioHora * horasTrabalhadas);

    return 0;
}