char* longestPalindrome(char* s) {
    int len = strlen(s);
    int bg = 0, mx = 1;
    int i, l, r, len1, len2, cl, st;
    char *ans;

    for (i = 0; i < len; i++) {
        l = i;  r = i;
        while (l >= 0 && r < len && s[l] == s[r]) { l--; r++; }
        len1 = r - l - 1;

        l = i;  r = i + 1;
        while (l >= 0 && r < len && s[l] == s[r]) { l--; r++; }
        len2 = r - l - 1;

        cl = (len1 > len2) ? len1 : len2;
        st = i - (cl - 1) / 2;

        bg = (cl > mx) ? st : bg;
        mx = (cl > mx) ? cl : mx;
    }

    ans = (char *)malloc((size_t)(mx + 1));
    if (ans == NULL) return NULL;

    memcpy(ans, s + bg, (size_t)mx);
    ans[mx] = '\0';

    return ans;
}