#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while (cin >> n) {
        if (n == 0) break;

        queue<int> cartas;
        vector<int> descartadas;

        for (int i = 1; i <= n; i++) {
            cartas.push(i);
        }

        while (cartas.size() > 1) {
            descartadas.push_back(cartas.front());
            cartas.pop();

            cartas.push(cartas.front());
            cartas.pop();
        }

        cout << "Discarded cards:";
        for (int i = 0; i < descartadas.size(); i++) {
            cout << (i == 0 ? " " : ", ") << descartadas[i];
        }
        cout << "\n";

        cout << "Remaining card: " << cartas.front() << "\n";
    }

    return 0;
}
