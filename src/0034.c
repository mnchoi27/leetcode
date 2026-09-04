int lowerBound(int* nums, int numsSize, int target) {
    int lo = 0;
    int hi = numsSize - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] >= target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* ans = malloc(*returnSize * sizeof(int));

    int bound = lowerBound(nums, numsSize, target);

    if (bound == numsSize || nums[bound] != target) {
        ans[0] = -1;
        ans[1] = -1;

        return ans;
    }

    ans[0] = bound;
    ans[1] = lowerBound(nums, numsSize, target + 1) - 1;

    return ans;
}