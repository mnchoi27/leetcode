int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int cap = 16;
    int** ans = malloc(cap * sizeof(int*));

    *returnSize = 0;
    *returnColumnSizes = malloc(cap * sizeof(int));

    for (int i = 0; i < numsSize - 2 && nums[i] <= 0; i++) {
        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }

        int l = i + 1;
        int r = numsSize - 1;

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum < 0) {
                l++;
            } else if (sum > 0) {
                r--;
            } else {
                if (*returnSize == cap) {
                    cap *= 2;
                    ans = realloc(ans, cap * sizeof(int*));
                    *returnColumnSizes = realloc(*returnColumnSizes, cap * sizeof(int));
                }

                ans[*returnSize] = malloc(3 * sizeof(int));
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[l];
                ans[*returnSize][2] = nums[r];
                (*returnColumnSizes)[*returnSize] = 3;
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

    return ans;
}