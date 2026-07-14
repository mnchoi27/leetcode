char* convert(char* s, int numRows) {
    int n = strlen(s);
    int i, r, pos, d;
    char** row;
    int* cnt;
    char* ans;

    if (numRows == 1 || numRows >= n) {
        ans = (char*)malloc(n + 1);
        strcpy(ans, s);
        return ans;
    }

    row = (char**)malloc(sizeof(char*) * numRows);
    cnt = (int*)malloc(sizeof(int) * numRows);
    for (i = 0; i < numRows; i++) {
        row[i] = (char*)malloc(sizeof(char) * (n + 1));
        cnt[i] = 0;
    }

    r = 0;
    d = 0;
    for (i = 0; i < n; i++) {
        row[r][cnt[r]] = s[i];
        cnt[r]++;

        if (r == 0) d = 1;
        else if (r == numRows - 1) d = 0;

        r += d ? 1 : -1;
    }

    ans = (char*)malloc(sizeof(char) * (n + 1));
    pos = 0;
    for (i = 0; i < numRows; i++) {
        memcpy(ans + pos, row[i], cnt[i]);
        pos += cnt[i];
        free(row[i]);
    }
    ans[n] = '\0';

    free(row);
    free(cnt);
    return ans;
}