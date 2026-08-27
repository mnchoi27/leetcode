int removeDuplicates(int* nums, int numsSize) {
    int ans = 1;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] != nums[i + 1]) {
            nums[ans++] = nums[i + 1];
        }
    }

    return ans;
}