const char* keypad[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(char* digits, int i, char* buf, int* returnSize, char** ans) {
    if (!digits[i]) {
        ans[*returnSize] = malloc((i + 1) * sizeof(char));
        strcpy(ans[(*returnSize)++], buf);
        return;
    }

    const char* curr = keypad[digits[i] - '2'];

    for (int j = 0; curr[j]; j++) {
        buf[i] = curr[j];
        dfs(digits, i + 1, buf, returnSize, ans);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);

    if (len == 0) {
        return NULL;
    }

    char** ans = malloc(256 * sizeof(char*));
    char* buf = malloc((len + 1) * sizeof(char));
    buf[len] = '\0';

    dfs(digits, 0, buf, returnSize, ans);
    free(buf);

    return ans;
}