#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double salario, percentual;

    cin >> salario;

    if (salario <= 400.0) percentual = 0.15;
    else if (salario <= 800.0) percentual = 0.12;
    else if (salario <= 1200.0) percentual = 0.10;
    else if (salario <= 2000.0) percentual = 0.07;
    else percentual = 0.04;

    double reajuste = percentual * salario;
    double novoSalario = reajuste + salario;

    cout << fixed << setprecision(2);
    cout << "Novo salario: " << novoSalario << "\n";
    cout << "Reajuste ganho: " << reajuste << "\n";
    cout << setprecision(0) << "Em percentual: " << percentual * 100.0 << " %\n";

    return 0;
}
