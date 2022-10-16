
void shell(int nums[], int numsSize) {
        int gap, i, j;
        int temp;
        for (gap = numsSize - 2; gap > 0; gap -= 2)
                for (i = gap; i < numsSize; i++) {
                        temp = nums[i];
                        for (j = i - gap; j >= 0 && nums[j] > temp; j -= gap)
                                nums[j + gap] = nums[j];
                        nums[j + gap] = temp;
                }
}
