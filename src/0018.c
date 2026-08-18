int cmp(const void* a, const void* b) {
    return *(const int*)a - *(const int*)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int cap = 16;
    int** ans = malloc(cap * sizeof(int*));

    *returnSize = 0;
    *returnColumnSizes = malloc(cap * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j - 1] == nums[j]) {
                continue;
            }

            int l = j + 1;
            int r = numsSize - 1;

            while (l < r) {
                long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];

                if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else {
                    if (*returnSize == cap) {
                        cap *= 2;
                        ans = realloc(ans, cap * sizeof(int*));
                        *returnColumnSizes = realloc(*returnColumnSizes, cap * sizeof(int));
                    }

                    ans[*returnSize] = malloc(4 * sizeof(int));
                    ans[*returnSize][0] = nums[i];
                    ans[*returnSize][1] = nums[j];
                    ans[*returnSize][2] = nums[l];
                    ans[*returnSize][3] = nums[r];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                }
            }
        }
    }

    return ans;
}