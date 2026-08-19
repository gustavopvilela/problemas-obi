#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> tamanhos;
    int n, num, k = 0;
    int area1, area2;

    cin >> n;

    // preenchendo o vetor
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (i == 0) tamanhos.push_back(num);
        else {
            tamanhos.push_back(num + tamanhos[i - 1]);
        }
    }

    // calculando os tamanhos
    for (int i = 0; i < tamanhos.size(); i++) {
        area1 = tamanhos[i];
        area2 = tamanhos[tamanhos.size() - 1] - tamanhos[i];

        if (area2 - area1 == 0) {
            k = i + 1;
            break;
        }
    }

    cout << k << "\n";

    return 0;
}