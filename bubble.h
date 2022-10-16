void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b; 
    *b = temp;
}
void bubble(int nums[],int numsSize)
{
    int unsorted = numsSize;
    int swapped = 0;
    do
    {
        swapped = 0;
        for (int i = 0;i < unsorted - 1; ++i)
        {
            if (nums[i] > nums[i+1])
            {
                swap_int(&nums[i], &nums[i + 1]);
                swapped = 1;
            }
        }
        --unsorted;
    }while(swapped == 1);
}
