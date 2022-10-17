#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
int main(){

    FILE *fp = fopen("testfile.txt", "r");
    int numsSize = 0, mode = 0, *nums;
    fscanf(fp, "NUMSSIZE: %d\nNUMS: \n",&numsSize);
    if (numsSize < 10000) nums = malloc(sizeof(int) * numsSize);
    else return 0;
    for (int i = 0; i < numsSize; ++i) fscanf(fp, "%d",&nums[i]);
    fscanf(fp, "\nMODE: %d\n", &mode);

    switch (mode)
    {
    case 1:
        bubble(nums,numsSize);
        break;
    case 2:
        selection(nums,numsSize);
        break;
    case 3:
        insertion(nums,numsSize);
        break;
    case 4:
        merge_1(nums,0,numsSize);
        break;
    case 5:
        merge_2(nums,numsSize);
        break;
    case 6:
        quick(nums,numsSize);
        break;
    case 7:
        count(nums,numsSize);
        break;
    case 8:
        shell(nums,numsSize);
        break;
    case 9:
        radix(nums,numsSize);
        break;
    default:
        break;
    }

    printf("SORTED NUMS: ");
    for (int k = 0; k < numsSize; ++k)
        printf("%d ",nums[k]);
    free(nums);
    return 0;
}