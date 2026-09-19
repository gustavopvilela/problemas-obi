#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testes;
    cin >> testes;

    for (int i = 0; i < testes; i++) {
        string teste;
        cin >> teste;

        stack<char> pilha;
        int diamantes = 0;

        for (char c : teste) {
            if (c == '<') {
                pilha.push(c);
            }
            else if (c == '>' && !pilha.empty()) {
                pilha.pop();
                diamantes++;
            }
        }

        cout << diamantes << "\n";
    }

    return 0;
}
