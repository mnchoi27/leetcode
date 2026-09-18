char* multiply(char* num1, char* num2) {
    int num1Size = strlen(num1);
    int num2Size = strlen(num2);
    int totalSize = num1Size + num2Size;

    int totalSum[totalSize];
    memset(totalSum, 0, totalSize * sizeof(int));

    for (int i = num1Size - 1; i >= 0; i--) {
        for (int j = num2Size - 1; j >= 0; j--) {
            totalSum[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    for (int i = totalSize - 1; i > 0; i--) {
        totalSum[i - 1] += totalSum[i] / 10;
        totalSum[i] %= 10;
    }

    int idx = 0;

    while (idx < totalSize - 1 && totalSum[idx] == 0) {
        idx++;
    }

    char* ans = malloc((totalSize - idx + 1) * sizeof(char));
    int pos = 0;

    while (idx < totalSize) {
        ans[pos++] = totalSum[idx++] + '0';
    }
    ans[pos] = '\0';

    return ans;
}