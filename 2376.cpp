#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<char> times{deque<char>{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'}};
    int placar1, placar2;

    for (int i = 0; i < 15; i++) {
        cin >> placar1 >> placar2;
        char time1 = times.front();
        times.pop();
        char time2 = times.front();
        times.pop();

        if (placar1 > placar2) {
            times.push(time1);
        }
        else {
            times.push(time2);
        }
    }

    cout << times.front() << "\n";

    return 0;
}