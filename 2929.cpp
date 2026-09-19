#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long v, min = 0;
    string operacao;
    stack<long long> presentes;
    multiset<long long> naPilha;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cin >> operacao;

        if (operacao == "PUSH") {
            cin >> v;

            if (presentes.empty()) {
                min = v;
            }
            else {
                if (v < min) {
                    min = v;
                }
            }

            presentes.push(v);
            naPilha.insert(v);
        }

        else if (operacao == "POP") {
            if (presentes.empty()) {
                cout << "EMPTY\n";
            }
            else {
                if (presentes.top() == min) {
                    presentes.pop();
                    naPilha.erase(naPilha.find(min));
                    min = *naPilha.begin();
                }
                else {
                    long long excluido = presentes.top();
                    presentes.pop();
                    naPilha.erase(naPilha.find(excluido));
                }
            }
        }

        else if (operacao == "MIN") {
            if (presentes.empty()) {
                cout << "EMPTY\n";
            }
            else {
                cout << min << "\n";
            }
        }
    }

    return 0;
}