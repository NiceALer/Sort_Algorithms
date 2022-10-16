#include <stdlib.h>

int max_num(int nums[],int numsSize){
    int maxnum = nums[0];
    for (int i = 0; i<numsSize; i++) {
        if (nums[i] > maxnum)
            maxnum = nums[i];
    }
    return maxnum;
}
void CreateDoubleArry(int * buckets[],int numsSize){
    for (int i=0; i<10; i++){
        buckets[i] = (int *)malloc(sizeof(int *)*numsSize);
        buckets[i][0]=0;
    }
}

void radix(int nums[], int numsSize){
    int * buckets[10];
    CreateDoubleArry(buckets,numsSize);
    int maxnum = max_num(nums,numsSize);
    
    for (int i = 1; i<maxnum; i*=10){
        //分类装桶
        for (int j=0; j<numsSize; j++){
            int pos = (nums[j]/i)%10;
            buckets[pos][buckets[pos][0]+1] = nums[j];
            buckets[pos][0]++;
        }
        //排序
        int index_for_nums = 0;
        for (int k=0; k<10; k++){
            int index_for_bucket = 1;
            for (int seq=buckets[k][0]; seq>0; seq--){
                nums[index_for_nums]=buckets[k][index_for_bucket];
                index_for_bucket++;
                index_for_nums++;
                buckets[k][0]--;
            }
        }
        
    }
}