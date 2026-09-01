void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void nextPermutation(int* nums, int numsSize) {
    int k = -1;

    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            k = i;
            break;
        }
    }

    if (k != -1) {
        for (int j = numsSize - 1; j > k; j--) {
            if (nums[k] < nums[j]) {
                swap(&nums[k], &nums[j]);
                break;
            }
        }
    }

    for (int l = k + 1, r = numsSize - 1; l < r; l++, r--) {
        swap(&nums[l], &nums[r]);
    }
}