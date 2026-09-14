#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    bool certo;
    string a;
    stack<char> s;

    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++) {
        certo = true;
        getline(cin, a);

        for (char& c : a) {
            if (c == '(' || c == '[' || c == '{') {
                s.push(c);
                continue;
            }

            if (s.empty()) {
                certo = false;
                break;
            }

            if ((c == ')' && s.top() != '(') ||
                (c == ']' && s.top() != '[') ||
                (c == '}' && s.top() != '{')) {
                certo = false;
                break;
            }

            s.pop();
        }

        if (!s.empty()) {
            cout << "N\n";
        }
        else if (!certo) {
            cout << "N\n";
        }
        else if (certo) {
            cout << "S\n";
        }

        while (!s.empty()) s.pop();
    }

    return 0;
}