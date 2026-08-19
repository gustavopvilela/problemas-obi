#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, primo = 1;
    cin >> n;

    for (int j = 0; j < n; j++) {
        int num;
        cin >> num;

        if (num < 2) primo = 0;
        else if (num == 2) primo = 1;
        else {
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    primo = 0;
                    break;
                }
            }
        }

        if (primo) cout << num << " eh primo\n";
        else cout << num << " nao eh primo\n";
        primo = 1;
    }

    return 0;
}
