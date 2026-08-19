#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num, esq = 0, dir = 19;
    vector<int> v(20);

    for (int i = 0; i < 20; i++) {
        cin >> num;
        v[i] = num;
    }

    // trocando
    while (esq <= dir) {
        int temp = v[esq];
        v[esq] = v[dir];
        v[dir] = temp;
        esq++;
        dir--;
    }

    for (int i = 0; i < 20; i++) {
        cout << "N[" << i << "] = " << v[i] << "\n";
    }

    return 0;
}
