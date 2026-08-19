#include <bits/stdc++.h>

using namespace std;

pair<int, int> buscaBinaria (vector<int> &parafusos, int alvo) {
    int esq = 0, esq1, esq2;
    int dir = parafusos.size() - 1, dir1, dir2;
    int meio = -1, meio1, meio2;
    int resultado, resultado1 = -1, resultado2 = -1;

    // encontrando o primeiro elemento com o valor do alvo
    while (esq <= dir) {
        meio = (esq + dir) / 2;

        if (parafusos[meio] == alvo) {
            resultado1 = meio;
            resultado2 = meio;
            break;
        }

        if (parafusos[meio] < alvo) esq = meio + 1;
        else dir = meio - 1;
    }

    if (resultado1 == -1 && resultado2 == -1) {
        return {resultado1, resultado2};
    }

    // definindo as variáveis
    esq1 = esq; dir1 = meio - 1;
    esq2 = meio + 1; dir2 = dir;

    // encontrando a primeira ocorrência do alvo no vetor
    while (esq1 <= dir1) {
        meio1 = (esq1 + dir1) / 2;
        if (parafusos[meio1] == alvo) {
            resultado1 = meio1;
            dir1 = meio1 - 1;
        }
        else if (parafusos[meio1] < alvo) esq1 = meio1 + 1;
        else dir1 = meio1 - 1;
    }

    // encontrando a última ocorrência do alvo no vetor
    while (esq2 <= dir2) {
        meio2 = (esq2 + dir2) / 2;
        if (parafusos[meio2] == alvo) {
            resultado2 = meio2;
            esq2 = meio2 + 1;
        }
        else if (parafusos[meio2] < alvo) esq2 = meio2 + 1;
        else dir2 = meio2 - 1;
    }

    return {resultado1, resultado2};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int lotes, inicio, fim, alvo;
    vector<int> parafusos;

    while (cin >> lotes) {
        for (int i = 0; i < lotes; i++) {
            cin >> inicio >> fim;

            for (int j = inicio; j <= fim; j++) {
                parafusos.push_back(j);
            }
        }
        cin >> alvo;

        sort(parafusos.begin(), parafusos.end());

        pair<int, int> intervalo = buscaBinaria(parafusos, alvo);

        if (intervalo.first == -1 && intervalo.second == -1) {
            cout << alvo << " not found\n";
        }
        else {
            cout << alvo << " found from " << intervalo.first << " to " << intervalo.second << "\n";
        }

        parafusos.clear();
    }

    return 0;
}