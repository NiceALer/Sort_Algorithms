void merge_sort_1(int nums[], int numsCopy[], int start, int end){
//----------------------------------------------------------------------------------------------------
    //递归边界
    if (start >= end) {
        return;
    }
//----------------------------------------------------------------------------------------------------
    //初始化一系列变量
    int len = end - start;
    int mid = (len >> 1) + start;
    int start1 = start,     end1 = mid;
    int start2 = mid + 1,   end2 = end;
    int i = start;
//----------------------------------------------------------------------------------------------------  
    //递归
    merge_sort_1(nums,numsCopy,start1,end1);
    merge_sort_1(nums,numsCopy,start2,end2);
//----------------------------------------------------------------------------------------------------
    //拿出来排序
    while (start1 <= end1 && start2 <= end2){
        numsCopy[i++] = nums[start1] < nums[start2] ? nums[start1++] : nums[start2++];
    }
    while (start1 <= end1){
        numsCopy[i++] = nums[start1++];
    }
    while (start2 <= end2){
        numsCopy[i++] = nums[start2++];
    }
//----------------------------------------------------------------------------------------------------  
    //排序后放回
    for (i = start; i <= end; ++i){
        nums[i] = numsCopy[i];
    }
//----------------------------------------------------------------------------------------------------
}

int min(int x, int y){
    return x <= y ? x : y;
}
void merge_sort_2(int nums[],int end){
    
    int numsCopy[end];
    
    for (int i = 1; i < end; i *= 2){
        
        for (int start = 0; start < end; start += i*2){

            int left_1 = start,                      right_1 = min(start + i, end);
            int left_2 = min(start + i, end),        right_2 = min(start + i * 2, end);
            int j = left_1;

                while (left_1 < right_1 && left_2 < right_2){
                    numsCopy[j++] = nums[left_1] < nums[left_2] ? nums[left_1++] : nums[left_2++];
                }
                while (left_1 < right_1){
                    numsCopy[j++] = nums[left_1++];
                }
                while (left_2 < right_2){
                    numsCopy[j++] = nums[left_2++];
                }
            for (int l = start; l < right_2; ++l){
                nums[l] = numsCopy[l];
                }    
            
        }
    }
}
//i:        ------- 1 -------                --- 2 ---
//          |   |   |   |   |             |   |   |
//start:    0   2   4   6   8         0   4   8
//start1:   0
//end1:     1
//start2:   2
//end2:     3     


void merge(int nums[], int numsSize){
//------------------------------------
    printf("实现方法:\n");
    printf("---------------\n");
    printf("|1:递归 |2:迭代 |\n");
    printf("---------------\n");
    int choice;
    scanf("%d",&choice);
//------------------------------------

    int numsCopy[numsSize];
    switch (choice)
    {
    case 1:
        merge_sort_1(nums,numsCopy,0,numsSize - 1);
        break;
    case 2:
        merge_sort_2(nums,numsSize);
        break;
    }
    
}   