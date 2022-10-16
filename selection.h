void selection(int nums[],int numsSize){
    int min;
    int head = 0;
    
    while(head < numsSize - 1){
        
        min = head;
        
        for (int j = head + 1; j < numsSize; ++j){
            if (nums[j] < nums[min]){
                min = j;
            }
        }
        
        int t = nums[min];
        nums[min] = nums[head];
        nums[head] = t;
        ++head;
    }
}
