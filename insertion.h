void insertion(int nums[],int numsSize){
    for (int sorted = 1; sorted < numsSize; ++sorted){
        int j = sorted;
        int popped = nums[j];
        while (j > 0 && nums[j-1] > popped){
            nums[j] = nums[j-1];
            --j;
        }
        nums[j] = popped;
    }
}