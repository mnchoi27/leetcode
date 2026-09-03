int longestValidParentheses(char* s) {
    int n = strlen(s);

    int* buf = malloc((n + 1) * sizeof(int));
    int top = 0;
    buf[top++] = -1;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            buf[top++] = i;
        } else {
            top--;

            if (top == 0) {
                buf[top++] = i;
            } else if (i - buf[top - 1] > ans) {
                ans = i - buf[top - 1];
            }
        }
    }

    free(buf);

    return ans;
}