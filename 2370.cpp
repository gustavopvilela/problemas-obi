#include <bits/stdc++.h>

using namespace std;

struct Operador {
    bool operator()(const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

struct Time {
    bool operator()(const auto& a, const auto& b){
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, h;
    string nome;
    priority_queue<pair<string, int>, vector<pair<string, int>>, Operador> pessoas;
    priority_queue<pair<string, int>, vector<pair<string, int>>, Time> times;
    
    cin >> n >> t;
    
    for (int i = 0; i < n; i++) {
        cin >> nome >> h;
        pessoas.push({nome, h});
    }
    
    // dividindo em times
    int timeAtual = 1;
    while (!pessoas.empty()) {
        pair<string, int> p = pessoas.top();
        pessoas.pop();
        
        times.push({p.first, timeAtual++});
        if (timeAtual > t) timeAtual = 1;
    }
    
    // Imprimindo
    timeAtual = 1;
    cout << "Time " << timeAtual << "\n";
    while (!times.empty()) {
        pair<string, int> a = times.top();
        times.pop();
        
        if (a.second != timeAtual) {
            timeAtual = a.second;
            cout << "\nTime " << timeAtual << "\n";
        }
        
        cout << a.first << "\n";
    }
    cout << "\n";
    
    return 0;
}