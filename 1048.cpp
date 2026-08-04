#include <bits/stdc++.h>

using namespace std;

int main() {
    double salario, percentual;

    scanf("%lf", &salario);

    if (salario <= 400.0) percentual = 0.15;
    else if (salario <= 800.0) percentual = 0.12;
    else if (salario <= 1200.0) percentual = 0.10;
    else if (salario <= 2000.0) percentual = 0.07;
    else percentual = 0.04;

    double reajuste = percentual * salario;
    double novoSalario = reajuste + salario;

    printf("Novo salario: %.2lf\n", novoSalario);
    printf("Reajuste ganho: %.2lf\n", reajuste);
    printf("Em percentual: %.0lf %%\n", percentual * 100.0);

    return 0;
}