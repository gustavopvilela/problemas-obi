#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> yes;
    set<string> no;
    string amigo = "", nome, opcao;

    while (cin >> nome) {
        if (nome == "FIM") break;

        cin >> opcao;

        if (opcao == "YES") {
            yes.insert(nome);

            if (nome.size() > amigo.size()) {
                amigo = nome;
            }
        }
        else if (opcao == "NO") {
            no.insert(nome);
        }
    }

    for (const string& n : yes) {
        cout << n << "\n";
    }

    for (const string& n : no) {
        cout << n << "\n";
    }

    cout << "\nAmigo do Habay:\n" << amigo << "\n";

    return 0;
}