int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= 0 || nums[i] > numsSize) {
            nums[i] = numsSize + 1;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        int val = abs(nums[i]);

        if (val <= numsSize && nums[val - 1] > 0) {
            nums[val - 1] = -nums[val - 1];
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }

    return numsSize + 1;
}