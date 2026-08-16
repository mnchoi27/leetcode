int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int ans = nums[0] + nums[1] + nums[2];

    for (int i = 0; i + 2 < numsSize; i++) {
        int l = i + 1;
        int r = numsSize - 1;

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum == target) {
                return sum;
            }
            if (abs(sum - target) < abs(ans - target)) {
                ans = sum;
            }

            if (sum > target) {
                r--;
            } else {
                l++;
            }
        }
    }

    return ans;
}