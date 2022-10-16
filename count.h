#include <stdlib.h>
void minmax(int nums[], int numsSize, int *min, int *max)
{
    for (int i = 0; i < numsSize;++i)
    {
        if (nums[i] > *max)
        {
            *max = nums[i];
        }
        if (nums[i] < *min)
        {
            *min = nums[i];
        }
    }
}

void count(int nums[], int numsSize)
{
    int min = 100, max = -100;
    minmax(nums, numsSize, &min, &max);
    if (max > 100 || min < 0) {printf("Out of board."); return 0;}
    int N = max - min;
    int count[N];
    int sorted[numsSize];
    for (int i = 0; i < 100; i++)
        count[i] = 0;
    for (int i = 0; i < numsSize; i++)
        count[nums[i]]++;
    for (int i = 1; i < 100; i++)
        count[i] += count[i - 1];
    for (int i = numsSize - 1; i >= 0; i--)
        sorted[--count[nums[i]]] = nums[i];
    for (int i = 0; i < numsSize; i++)
        nums[i] = sorted[i];
}
