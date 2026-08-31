int cmp(const void* a, const void* b) {
    return strcmp(*(char* const*)a, *(char* const*)b);
}

int findIdx(char** words, int size, const char* ptr, int wordLen) {
    int lo = 0;
    int hi = size - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int diff = strncmp(ptr, words[mid], wordLen);

        if (diff == 0) {
            return mid;
        }

        if (diff < 0) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return -1;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int sLen = strlen(s);
    int wordLen = strlen(words[0]);
    int windowLen = wordLen * wordsSize;

    *returnSize = 0;

    if (sLen < windowLen) {
        return NULL;
    }

    qsort(words, wordsSize, sizeof(char*), cmp);

    int* need = malloc(wordsSize * sizeof(int));
    int uniqueSize = 0;

    for (int i = 0; i < wordsSize; i++) {
        if (uniqueSize == 0 || strcmp(words[uniqueSize - 1], words[i]) != 0) {
            char* temp = words[uniqueSize];
            words[uniqueSize] = words[i];
            words[i] = temp;
            need[uniqueSize] = 1;
            uniqueSize++;
        } else {
            need[uniqueSize - 1]++;
        }
    }

    int* have = malloc(uniqueSize * sizeof(int));
    int* map = malloc(sLen * sizeof(int));

    int* ans = malloc((sLen - windowLen + 1) * sizeof(int));

    for (int offset = 0; offset < wordLen; offset++) {
        int l = offset;
        int count = 0;

        memset(have, 0, uniqueSize * sizeof(int));

        for (int r = offset; r + wordLen <= sLen; r += wordLen) {
            int idx = findIdx(words, uniqueSize, s + r, wordLen);
            map[r] = idx;

            if (idx == -1) {
                memset(have, 0, uniqueSize * sizeof(int));
                count = 0;
                l = r + wordLen;
                continue;
            }

            have[idx]++;
            count++;

            while (have[idx] > need[idx]) {
                have[map[l]]--;
                count--;
                l += wordLen;
            }

            if (count == wordsSize) {
                ans[(*returnSize)++] = l;

                have[map[l]]--;
                count--;
                l += wordLen;
            }
        }
    }

    free(need);
    free(have);
    free(map);

    return ans;
}