#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string assassino, assassinado;
    set<string> assassinados;
    map<string, int> matanca;

    while (cin >> assassino >> assassinado) {
        matanca[assassino]++;
        assassinados.insert(assassinado);
    }

    cout << "HALL OF MURDERERS\n";
    for (const auto& [killer, killCount] : matanca) {
        if (!assassinados.contains(killer)) {
            cout << killer << " " << killCount << "\n";
        }
    }

    return 0;
}