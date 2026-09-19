#include <bits/stdc++.h>

using namespace std;

struct Comparador {
    bool operator() (pair<string, int>& a, pair<string, int>& b) {
        if (a.first.length() == b.first.length()) {
            return a.second > b.second;
        }
        return a.first.length() < b.first.length();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, contador = 0;
    string linha, palavra;
    priority_queue<pair<string, int>, vector<pair<string, int>>, Comparador> pq;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        getline(cin, linha);
        stringstream ss(linha);

        while (ss >> palavra) {
            pq.emplace(palavra, contador++);
        }

        bool primeiro = true;
        while (!pq.empty()) {
            if (primeiro) {
                cout << pq.top().first;
                primeiro = false;
            }
            else cout << " " << pq.top().first;
            pq.pop();
        }
        cout << "\n";
        contador = 0;
    }

    return 0;
}