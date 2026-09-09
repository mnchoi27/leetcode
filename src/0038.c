char* countAndSay(int n) {
    char* buf = malloc(5000 * sizeof(char));
    char* ans = malloc(5000 * sizeof(char));
    int size = 1;

    memcpy(buf, "1", sizeof("1"));
    memcpy(ans, "1", sizeof("1"));

    for (int i = 0; i < n - 1; i++) {
        int idx = 0;
        int pos = 0;

        while (idx < size) {
            int end = idx;

            while (end < size && buf[end] == buf[idx]) {
                end++;
            }

            ans[pos++] = (end - idx) + '0';
            ans[pos++] = buf[idx];
            idx = end;
        }

        memcpy(buf, ans, pos);
        size = pos;
    }

    free(buf);

    ans[size] = '\0';

    return ans;
}