int lengthOfLongestSubstring(char* s) {
    int freq[256] = {0};
    int ans = 0;
    int l = 0;

    for (int r = 0; s[r]; r++) {
        unsigned char c = (unsigned char)s[r];
        freq[c]++;

        while (freq[c] > 1) {
            freq[(unsigned char)s[l]]--;
            l++;
        }

        if (ans < r - l + 1) {
            ans = r - l + 1;
        }
    }

    return ans;
}