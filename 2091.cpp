#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    unsigned long long int a;
    set<unsigned long long int> s;

    while (cin >> n) {
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> a;

            if (!s.contains(a)) s.insert(a);
            else s.erase(a);
        }

        cout << *s.begin() << "\n";
        s.clear();
    }

    return 0;
}