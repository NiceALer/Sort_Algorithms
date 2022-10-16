
#include <stdlib.h>
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void quick(int nums[], int numsSize){
    if (numsSize <= 1)
        return;

    int randnum = (rand() % numsSize);
    int pivot = 0;
    swap(&nums[pivot],&nums[randnum]);
    int L = pivot + 1;
    int R = pivot + 1;
    while (R < numsSize){
        if (nums[R] < nums[pivot]){
            swap(&nums[R], &nums[L]);
            ++L;
        }
        ++R;
    }
    swap(&nums[L-1], &nums[pivot]);
    quick(&nums[pivot],L); // Left
    quick(&nums[L],numsSize - L); // Right
}