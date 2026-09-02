#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;

    while (cin >> a >> b && (a != 0 || b != 0)) {
        vector<int> alice(a), beatriz(b);

        for (int i = 0; i < a; i++) cin >> alice[i];
        for (int i = 0; i < b; i++) cin >> beatriz[i];

        sort(alice.begin(), alice.end());
        sort(beatriz.begin(), beatriz.end());

        alice.erase(unique(alice.begin(), alice.end()), alice.end());
        beatriz.erase(unique(beatriz.begin(), beatriz.end()), beatriz.end());

        int soAlice = 0, soBeatriz = 0;
        size_t i = 0, j = 0;

        while (i < alice.size() && j < beatriz.size()) {
            if (alice[i] < beatriz[j]) {
                soAlice++;
                i++;
            }
            else if (alice[i] > beatriz[j]) {
                soBeatriz++;
                j++;
            }
            else {
                i++;
                j++;
            }
        }

        soAlice += (int) (alice.size() - i);
        soBeatriz += (int) (beatriz.size() - j);
        cout << min(soAlice, soBeatriz) << '\n';
    }

    return 0;
}