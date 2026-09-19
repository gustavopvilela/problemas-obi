#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nc, n, altura;
    priority_queue<int, vector<int>, greater<>> alturas;

    cin >> nc;

    for (int i = 0; i < nc; i++) {
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> altura;
            alturas.push(altura);
        }

        bool primeiro = true;
        while (!alturas.empty()) {
            if (primeiro) {
                cout << alturas.top();
                primeiro = false;
            }
            else cout << " " << alturas.top();
            alturas.pop();
        }
        cout << "\n";
    }

    return 0;
}