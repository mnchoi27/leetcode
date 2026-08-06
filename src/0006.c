char* convert(char* s, int numRows) {
    int len = strlen(s);
    char* ans = malloc((len + 1) * sizeof(char));

    if (numRows == 1) {
        strcpy(ans, s);
        return ans;
    }

    int cycle = 2 * numRows - 2;
    int pos = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < len; j += cycle) {
            ans[pos++] = s[j];

            int pair = j + cycle - 2 * i;
            if (i > 0 && i < numRows - 1 && pair < len) {
                ans[pos++] = s[pair];
            }
        }
    }
    ans[len] = '\0';

    return ans;
}