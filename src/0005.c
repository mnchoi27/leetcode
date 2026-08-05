int extend(char* s, int len, int l, int r) {
    while (l >= 0 && r < len && s[l] == s[r]) {
        l--;
        r++;
    }

    return r - l - 1;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    int begin = 0;
    int best = 1;

    for (int i = 0; i < len; i++) {
        int odd = extend(s, len, i, i);
        int even = extend(s, len, i, i + 1);
        int curr = (odd > even) ? odd : even;

        if (curr > best) {
            begin = i - (curr - 1) / 2;
            best = curr;
        }
    }

    char* ans = malloc((best + 1) * sizeof(char));
    memcpy(ans, s + begin, best);
    ans[best] = '\0';

    return ans;
}