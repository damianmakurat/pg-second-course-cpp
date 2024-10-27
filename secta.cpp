#include <iostream>
#include <vector>

using namespace std;

int killerRoulette(int n, int k) {

    vector<int> unluckyCircle(n);
    for (int i = 0; i < n; ++i) {
        unluckyCircle[i] = i + 1;
    }

    if (k < 0) {
        k = abs(k) - 1;
        k = n - k;

    }

    int shotOff = 0;
    int lastEliminated = 0;

    int currentPos = 0;
    while (shotOff != k) {
        int count = 0;
        while (count < 2) {
            if (unluckyCircle[currentPos] != -1) {
                count++;
            }
            if (count < 2) {
                currentPos++;
                if (currentPos >= n)
                    currentPos = 0;
            }
        }
        lastEliminated = unluckyCircle[currentPos];
        unluckyCircle[currentPos] = -1;
        shotOff++;
    }

    return lastEliminated;
}

int main() {
    int lines_number;
    cin >> lines_number;

    for (int i = 0; i < lines_number; ++i) {
        int n, k;
        cin >> n >> k;

        cout << killerRoulette(n, k) << endl;
    }

    return 0;
}
