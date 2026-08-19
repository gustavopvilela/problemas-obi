#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, c, coposQuebrados = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l >> c;

        if (l > c) coposQuebrados += c;
    }

    cout << coposQuebrados << "\n";

    return 0;
}
