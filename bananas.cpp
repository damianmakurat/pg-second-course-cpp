#include <iostream>
#include <string>
#include <vector>

using namespace std;

void bananaHunting(const int a, const string& data) {

    vector<vector<char>> bananaMatrix(a, vector<char>(a));
    vector<int> bananaNodes(a);

    int index = 0;
    int bananasNumber = 0;
    int columns = 0;
    bool banana = true;

    for (int i = 0; i < a; i++) {
        int checkingPoint = 0;
        for (int j = 0; j < a; j++) {
            bananaMatrix[i][j] = data[index++];
            if (bananaMatrix[i][j] == '1') {
                checkingPoint++;
            }
        }
        if (checkingPoint == 1) {
            bananasNumber++;
            for (int j = 0; j < a; j++) {
                if (bananaMatrix[i][j] == '1') {
                    bananaNodes[j]++;
                }
            }
        }
    }

    int temp = 0;
    for (int j = 0; j < a; j++) {
        if (bananaNodes[j] != 0) {
            columns++;
            if (temp == 0) {
                temp = bananaNodes[j];
            }
            else if (bananaNodes[j] != temp) {
                banana = false;
                break;
            }
        }
    }

    if (columns == bananasNumber && banana && a < 3) {
        cout << bananasNumber << " bananas :)" << endl;
    }
    else if (columns == 1 && bananasNumber + 1 == a && banana) {
        cout << bananasNumber << " bananas :)" << endl;
    }
    else if ((bananasNumber + columns + 1) == a && banana) {
        cout << bananasNumber << " bananas :)" << endl;
    }
    else {
        cout << "0 bananas :(" << endl;
    }

}

int main() {

    int rows = 0;
    cin >> rows;

    if (rows < 1) {
        return 1;
    }

    int points = 0;
    string data;

    for (int i = 0; i < rows; i++) {
        cin >> points >> data;
        bananaHunting(points, data);
    }

    return 0;
}
