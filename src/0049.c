typedef struct {
    int counts[26];
    int id;
} Entry;

int cmp(const void* a, const void* b) {
    const Entry* x = a;
    const Entry* y = b;

    return memcmp(x->counts, y->counts, sizeof(x->counts));
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Entry* entries = calloc(strsSize, sizeof(Entry));
    char*** ans = malloc(strsSize * sizeof(char**));
    int* columnSizes = malloc(strsSize * sizeof(int));
    int count = 0;

    for (int i = 0; i < strsSize; i++) {
        entries[i].id = i;

        for (int k = 0; strs[i][k]; k++) {
            entries[i].counts[strs[i][k] - 'a']++;
        }
    }

    qsort(entries, strsSize, sizeof(Entry), cmp);

    int idx = 0;

    while (idx < strsSize) {
        int end = idx;

        while (end < strsSize && cmp(&entries[end], &entries[idx]) == 0) {
            end++;
        }

        int groupSize = end - idx;

        ans[count] = malloc(groupSize * sizeof(char*));

        for (int i = 0; i < groupSize; i++) {
            char* word = strs[entries[idx + i].id];

            ans[count][i] = malloc((strlen(word) + 1) * sizeof(char));
            strcpy(ans[count][i], word);
        }

        columnSizes[count] = groupSize;
        count++;
        idx = end;
    }

    free(entries);

    *returnSize = count;
    *returnColumnSizes = columnSizes;

    return ans;
}