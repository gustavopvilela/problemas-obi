#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    vector<unsigned long long> fib;
    fib.emplace_back(0);
    fib.emplace_back(1);

    for (int i = 0; i < t; i++) {
        cin >> n;

        if (n > fib.size() - 1) {
            for (unsigned long long j = fib.size(); j <= n; j++) {
                fib.emplace_back(fib[j - 1] + fib[j - 2]);
            }
        }

        cout << "Fib(" << n << ") = " << fib[n] << '\n';
    }

    return 0;
}