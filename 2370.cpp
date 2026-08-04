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
    int n, t, h;
    char nome[501];
    priority_queue<pair<string, int>, vector<pair<string, int>>, Operador> pessoas;
    priority_queue<pair<string, int>, vector<pair<string, int>>, Time> times;
    
    scanf("%d %d", &n, &t);
    
    for (int i = 0; i < n; i++) {
        scanf(" %s %d", nome, &h);
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
    printf("Time %d\n", timeAtual);
    while (!times.empty()) {
        pair<string, int> a = times.top();
        times.pop();
        
        if (a.second != timeAtual) {
            timeAtual = a.second;
            printf("\nTime %d\n", timeAtual);
        }
        
        printf("%s\n", a.first.c_str());
    }
    printf("\n");
    
    return 0;
}