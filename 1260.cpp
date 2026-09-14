#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testes, totalArvores = 0;
    string arvore;
    map<string, int> arvores;

    cin >> testes;
    getline(cin, arvore);
    getline(cin, arvore);

    for (int i = 0; i < testes; i++) {
        while (getline(cin, arvore) && !arvore.empty()) {
            if (arvores[arvore] == 0) arvores[arvore] = 1;
            else arvores[arvore]++;

            totalArvores++;
        }

        for (const auto& [arv, qtd] : arvores) {
            double percentual = (qtd * 100.0) / totalArvores;
            cout << arv << " " << fixed << setprecision(4) << percentual << "\n";
        }

        if (i < testes - 1) cout << "\n";

        totalArvores = 0;
        arvores.clear();
    }

    return 0;
}