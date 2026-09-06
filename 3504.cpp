#include <bits/stdc++.h>

using namespace std;

int main() {
    string frase;
    bool palindromo = true;
    getline(cin, frase);

    unsigned long long esq = 0, dir = frase.length() - 1;

    while (esq <= dir) {
        if (frase[esq] != frase[dir]) {
            palindromo = false;
            break;
        }

        esq++;
        dir--;
    }

    if (palindromo) {
        cout << "A frase [" << frase << "] eh palindrome\n";
    }
    else {
        cout << "A frase [" << frase << "] nao eh palindrome\n";
    }

    return 0;
}