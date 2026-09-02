#include <bits/stdc++.h>

using namespace std;

struct Aluno {
    string nome;
    char regiao;
    int custo;
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;

    while (cin >> q) {
        vector<Aluno> alunos(q);

        for (int i = 0; i < q; i++) {
            cin >> alunos[i].nome >> alunos[i].regiao >> alunos[i].custo;
        }

        sort(alunos.begin(), alunos.end(), [](const Aluno &x, const Aluno &y) {
            if (x.custo != y.custo) return x.custo < y.custo;
            if (x.regiao != y.regiao) return x.regiao < y.regiao;
            return x.nome < y.nome;
        });

        for (const Aluno &aluno : alunos) {
            cout << aluno.nome << '\n';
        }
    }

    return 0;
}