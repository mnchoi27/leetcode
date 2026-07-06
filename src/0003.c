int lengthOfLongestSubstring(char* s) {
    int freq[256] = {0};
    int l = 0, r = 0;
    int ans = 0;

    for (r = 0; s[r] != '\0'; r++) {
        unsigned char c = (unsigned char) s[r];
        freq[c]++;

        while (freq[c] > 1) {
            freq[(unsigned char) s[l]]--;
            l++;
        }

        ans = (r - l + 1 > ans) ? r - l + 1 : ans;
    }

    return ans;
}