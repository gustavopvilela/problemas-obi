#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c, pi = 3.14159;

    cin >> a >> b >> c;

    double triangulo = (a * c) / 2.0;
    double circulo = pi * c * c;
    double trapezio = ((a + b) * c) / 2.0;
    double quadrado = b * b;
    double retangulo = a * b;

    cout << fixed << setprecision(3);
    cout << "TRIANGULO: " << triangulo << "\n";
    cout << "CIRCULO: " << circulo << "\n";
    cout << "TRAPEZIO: " << trapezio << "\n";
    cout << "QUADRADO: " << quadrado << "\n";
    cout << "RETANGULO: " << retangulo << "\n";

    return 0;
}
