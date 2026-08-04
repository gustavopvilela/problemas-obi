#include <bits/stdc++.h>

using namespace std;

int main() {
    int num, esq = 0, dir = 19;
    vector<int> v(20);

    for (int i = 0; i < 20; i++) {
        scanf("%d", &num);
        v[i] = num;
    }

    // trocando
    while (esq <= dir) {
        int temp = v[esq];
        v[esq] = v[dir];
        v[dir] = temp;
        esq++;
        dir--;
    }

    for (int i = 0; i < 20; i++) {
        printf("N[%d] = %d\n", i, v[i]);
    }

    return 0;
}