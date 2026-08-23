void dfs(int n, int open, int close, char* buf, int* returnSize, char** ans) {
    if (open + close == 2 * n) {
        ans[*returnSize] = malloc((2 * n + 1) * sizeof(char));
        strcpy(ans[(*returnSize)++], buf);
        return;
    }

    if (open < n) {
        buf[open + close] = '(';
        dfs(n, open + 1, close, buf, returnSize, ans);
    }
    if (close < open) {
        buf[open + close] = ')';
        dfs(n, open, close + 1, buf, returnSize, ans);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char* buf = malloc((2 * n + 1) * sizeof(char));
    buf[2 * n] = '\0';

    char** ans = malloc(1430 * sizeof(char*));
    *returnSize = 0;

    dfs(n, 0, 0, buf, returnSize, ans);
    free(buf);

    return ans;
}