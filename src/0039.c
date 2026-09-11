int dfs(int* candidates, int candidatesSize, int target, int start, int* buf, int bufSize, int count, int* columnSizes, int** ans) {
    if (target == 0) {
        ans[count] = malloc(bufSize * sizeof(int));
        memcpy(ans[count], buf, bufSize * sizeof(int));
        columnSizes[count] = bufSize;

        return count + 1;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target) {
            continue;
        }

        buf[bufSize] = candidates[i];
        count = dfs(candidates, candidatesSize, target - candidates[i], i, buf, bufSize + 1, count, columnSizes, ans);
    }

    return count;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int buf[40];
    int** ans = malloc(150 * sizeof(int*));
    int* columnSizes = malloc(150 * sizeof(int));

    *returnSize = dfs(candidates, candidatesSize, target, 0, buf, 0, 0, columnSizes, ans);
    *returnColumnSizes = columnSizes;

    return ans;
}