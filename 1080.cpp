#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numero, maior = -1, posicao = -1;

    for (int i = 1; i <= 100; i++) {
        cin >> numero;

        if (numero > maior) {
            maior = numero;
            posicao = i;
        }
    }

    cout << maior << "\n" << posicao << "\n";

    return 0;
}
