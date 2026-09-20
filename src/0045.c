int jump(int* nums, int numsSize) {
    int ans = 0;
    int currEnd = 0;
    int farthest = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        if (i + nums[i] > farthest) {
            farthest = i + nums[i];
        }

        if (i == currEnd) {
            ans++;
            currEnd = farthest;
        }
    }

    return ans;
}