int removeElement(int* nums, int numsSize, int val) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[ans++] = nums[i];
        }
    }

    return ans;
}