#include <bits/stdc++.h>

using namespace std;

int buscaBinaria (const vector<int>& arr, int alvo) {
    int esq = 0;
    int dir = arr.size() - 1;
    int resultado = -1;

    while (esq <= dir) {
        int meio = (esq + dir) / 2;

        if (arr[meio] == alvo) {
            resultado = meio;
            dir = meio - 1;
        }
        else if (arr[meio] < alvo) esq = meio + 1;
        else dir = meio - 1;
    }

    return resultado;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    int caso = 1;

    while (cin >> n >> q) {
        if (n == 0 && q == 0) break;

        vector<int> marmores(n);
        for (int i = 0; i < n; i++) {
            cin >> marmores[i];
        }

        sort(marmores.begin(), marmores.end());

        cout << "CASE# " << caso++ << ":\n";
        for (int i = 0; i < q; i++) {
            int consulta;
            cin >> consulta;

            int posicao = buscaBinaria(marmores, consulta);
            if (posicao != -1) {
                cout << consulta << " found at " << posicao + 1 << "\n";
            }
            else {
                cout << consulta << " not found\n";
            }
        }
    }

    return 0;
}
