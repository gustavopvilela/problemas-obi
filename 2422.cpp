#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n;
    vector<int> casas(n);

    for (int i = 0; i < n; i++) {
        cin >> casas[i];
    }
    cin >> k;

    int esq = 0, dir = n - 1;

    while (esq < dir) {
        if (casas[esq] + casas[dir] == k) {
            cout << casas[esq] << " " << casas[dir] << "\n";
            break;
        }

        if (casas[esq] + casas[dir] > k) dir--;
        else esq++;
    }

    return 0;
}