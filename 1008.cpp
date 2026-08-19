#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numero, horasTrabalhadas;
    float salarioHora;

    cin >> numero;
    cin >> horasTrabalhadas;
    cin >> salarioHora;

    cout << "NUMBER = " << numero << "\n";
    cout << fixed << setprecision(2) << "SALARY = U$ " << salarioHora * horasTrabalhadas << "\n";

    return 0;
}
