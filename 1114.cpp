#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int senha;

    while (cin >> senha) {
        if (senha == 2002) {
            cout << "Acesso Permitido\n";
            break;
        }

        cout << "Senha Invalida\n";
    }

    return 0;
}
