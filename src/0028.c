int strStr(char* haystack, char* needle) {
    for (int i = 0; haystack[i]; i++) {
        int j = 0;
        while (needle[j]) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
            j++;
        }
        if (!needle[j]) {
            return i;
        }
    }

    return -1;
}