#include <stdio.h>

int DPDkickboxing(int P[], int W[], const int parcels, const int C) {

    int** sortedParcels = new int* [parcels];
    for (int i = 0; i < parcels; ++i) {
        sortedParcels[i] = new int[2];
    }

    int maxTag = 0;
    for (int i = 0; i < parcels; i++) {
        for (int j = 0; j < parcels; j++) {
            if (sortedParcels[i][0] < P[j]) {
                sortedParcels[i][0] = P[j];
                sortedParcels[i][1] = W[j];
                maxTag = j;
            }
        }
        if (sortedParcels[i][1] > 100) {
            sortedParcels[i][0] -= 5;
        }
        P[maxTag] = 0;
        W[maxTag] = 0;
    }

    int* weight = new int[C + 1];
    for (int i = 0; i <= C; ++i) {
        weight[i] = 0;
    }

    for (int i = 0; i < parcels; ++i) {
        int a = sortedParcels[i][0];
        int b = sortedParcels[i][1];
        for (int j = C; j >= b; --j) {
            if (weight[j - b] + a > weight[j]) {
                weight[j] = weight[j - b] + a;
            }
        }
    }

    int maxRevenue = 0;
    for (int i = 0; i <= C; ++i) {
        if (weight[i] > maxRevenue) {
            maxRevenue = weight[i];
        }
    }

    delete[] weight;

    for (int i = 0; i < parcels; ++i) {
        delete[] sortedParcels[i];
    }
    delete[] sortedParcels;

    if ((maxRevenue - 20) > 0) {
        return (maxRevenue - 20);
    }
    else {
        return 0;
    }
}

int main() {

    int queries = 0;
    scanf_s("%d", &queries);

    if (queries < 1) {
        return 1;
    }

    for (int i = 0; i < queries; i++) {
        int n;
        scanf_s("%d", &n);

        if (n < 1) {
            printf_s("0\n");
            continue;
        }

        int* P = new int[n];
        int* W = new int[n];
        int C = 0;

        for (int j = 0; j < n; j++) {
            scanf_s("%d", &P[j]);
        }

        for (int j = 0; j < n; j++) {
            scanf_s("%d", &W[j]);
        }

        scanf_s("%d", &C);

        if (C < 1) {
            printf("0\n");
            delete[] P;
            delete[] W;
            continue;
        }

        printf("%d\n", DPDkickboxing(P, W, n, C));
        delete[] P;
        delete[] W;
    }

    return 0;
}
