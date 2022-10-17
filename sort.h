
void swap(int *a, int *b) {int temp = *a;*a = *b; *b = temp;}
int min(int x, int y) {return x <= y ? x : y;}

void selection(int nums[],int numsSize)
{
    for (int i = 0; i < numsSize - 1; i ++)
    {
        int minimum = i;
        for (int j = i + 1; j < numsSize; j ++)
            minimum = nums[minimum] < nums[j] ? minimum : j;
        swap(nums + minimum, nums + i);
    }
}

void bubble(int nums[],int numsSize)
{
    int unsorted = numsSize, swapped;
    do
    {
        swapped = 0;
        for (int i = 0; i < unsorted - 1; i ++)
        {
            if (nums[i] > nums[i+1])
            {
                swap(nums + i, nums + i + 1);
                swapped = 1;
            }
        }
        unsorted --;
    }while(swapped);
}

void insertion(int nums[],int numsSize)
{
    for (int i = 1; i < numsSize; i ++)
    {
        for(int j = i; j > 0 && nums[j-1] > nums[j]; j --)
            swap(nums + j - 1, nums + j);
    }
}

void merge_1(int nums[], int left, int right)
{
    if (left + 1 == right) return;
    int mid = (right + left) / 2, pl = left, pr = mid, end = right, sorted[right - left], i = 0;
    merge_1(nums,pl,mid);
    merge_1(nums,pr,end);
    while (pl < mid && pr < end) sorted[i ++] = nums[pl] < nums[pr] ? nums[pl ++] : nums[pr ++];
    while (pl < mid) sorted[i ++] = nums[pl ++];
    while (pr < end) sorted[i ++] = nums[pr ++];
    for (int i = 0; i < right - left; i ++) nums[i + left] = sorted[i];
}

void merge_2(int nums[],int numSize)
{
    int sorted[numSize];
    for (int i = 1; i < numSize; i *= 2)
        for (int j = 0; j < numSize; j += i*2)
        {
            int mid = min(j + i, numSize), end = min(j + i * 2, numSize), pl = j , pr = mid, k = j;
            while (pl < mid && pr < end) sorted[k++] = nums[pl] < nums[pr] ? nums[pl++] : nums[pr++];
            while (pl < mid) sorted[k++] = nums[pl++];
            while (pr < end) sorted[k++] = nums[pr++];
            for (k = j; k < end; k ++) nums[k] = sorted[k];
        }
}

void quick(int nums[], int numsSize)
{
    if (numsSize < 2) return;

    int randnum = (rand() % numsSize);
    int pivot = 0;
    swap(&nums[pivot],&nums[randnum]);
    int L = pivot + 1;
    int R = pivot + 1;
    for (; R < numsSize; R++)
        if (nums[pivot] > nums[R]) swap(&nums[R], &nums[L++]);
    
    swap(&nums[L-1], &nums[pivot]);
    quick(&nums[pivot],L); // Left
    quick(&nums[L],numsSize - L); // Right
}

void radix(int nums[], int numsSize)
{
    int *buckets[10];
    for (int i = 0; i < 10; i ++) buckets[i] = calloc(numsSize, sizeof(int*));
    int maxnum = nums[0];
    for (int i = 0; i < numsSize; i ++) maxnum = maxnum > nums[i] ? maxnum : nums[i];
    
    for (int decimal = 1; decimal < maxnum; decimal *= 10)
    {
        for (int j = 0; j < numsSize; j ++)
            buckets[(nums[j] / decimal) % 10][++ buckets[(nums[j] / decimal) % 10][0]] = nums[j];
        
        int nums_idx = 0;
        for (int k = 0; k < 10; k ++)
        {
            int bucket_idx = 1;
            for (; buckets[k][0]; buckets[k][0]--)
                nums[nums_idx++] = buckets[k][bucket_idx++];
        }
    }
    for (int i = 0; i < 10; i ++) free(buckets[i]);
}

void shell(int nums[], int numsSize) 
{
    int gap, i, j, temp;
    for (gap = numsSize >> 1; gap; gap >>= 1)
        for (i = gap; i < numsSize; i++) 
        {
            temp = nums[i];
            for (j = i; j >= gap && nums[j - gap] > temp; j -= gap)
                    nums[j] = nums[j - gap];
            nums[j] = temp;
        }
}

void count(int nums[], int numsSize)
{
    for (int i = 0; i < numsSize; i++) if (nums[i] > 999) return; 
    int min = 1000, max = 0;
    int count[1000] = {0};
    int sorted[numsSize];
    for (int i = 0; i < numsSize; i++)
        count[nums[i]]++;
    for (int i = 1; i < 1000; i++)
        count[i] += count[i - 1];
    for (int i = numsSize - 1; i >= 0; i--)
        sorted[-- count[nums[i]]] = nums[i];
    for (int i = 0; i < numsSize; i++)
        nums[i] = sorted[i];
}

