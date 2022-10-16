#include <stdio.h>
#include <time.h>

#include "bubble.h" // --冒泡
#include "selection.h"  // --选择
#include "insertion.h"  // --插入
#include "merge.h"  // --归并
#include "shell.h"  // --希尔
#include "quick.h"  // --快速
#include "count.h"
#include "radix.h"

// void bubble(int nums[],int numsSize);
// void selection(int nums[],int numsSize);
// void insertion(int nums[],int numsSize);
// void merge(int nums[], int numsSize);
// void shell(int nums[], int numsSize);

int main(){

    FILE *fp = fopen("testfile.txt", "r");
    printf("=================================================================\n");
        
        // printf("请输入待排序数组的长度:\n");
        int numsSize;
        AgainInput:
        fscanf(fp, "%d",&numsSize);
            if (numsSize == 0){
                // printf("请重新输入正确的长度:\n");
                goto AgainInput;
            }
        
        // printf("请输入待排序数组(以空格分割):\n");
        int nums[numsSize];
            for (int i = 0; i < numsSize; ++i){
                fscanf(fp, "%d",&nums[i]);
        }
        printf("请选择排序算法类型:\n");
        printf(" -------------\n");
        printf("|1:bubble     |\n");
        printf("|2:selection  |\n");
        printf("|3:insertion  |\n");
        printf("|4:merge      |\n");
        printf("|5:qucik      |\n");
        printf("|6:count      |\n");
        printf("|7:shell      |\n");
        printf("|8:radix      |\n");
        printf(" -------------\n");
        int choice;
        fscanf(fp, "%d",&choice);
        

//================================================================================  

        switch (choice)
        {
        case 1:
            //————————————冒泡排序——————
            bubble(nums,numsSize);// ｜
            //————————————————————————  
            break;
        case 2:
            //————————————选择排序—————————
            selection(nums,numsSize);// ｜
            //——————————————————————————— 
            break;
        case 3:
            //————————————插入排序—————————
            insertion(nums,numsSize);// ｜
            //——————————————————————————— 
            break;
        case 4:
            //————————————归并排序—————
            merge(nums,numsSize);// ｜
            //———————————————————————
            break;
        case 5:
            //————————————快速排序—————
            quick(nums,numsSize);// ｜
            //———————————————————————
            break;
        case 6:
            //————————————归并排序—————
            count(nums,numsSize);// ｜
            //———————————————————————
            break;
        case 7:
            //————————————归并排序—————
            shell(nums,numsSize);// ｜
            //———————————————————————
            break;
        case 8:
            //————————————归并排序—————
            radix(nums,numsSize);// ｜
            //———————————————————————
            break;
        default:
            break;
        }

//================================================================================  
    printf("=================================================================\n");
        printf("排序后的数组为:\n");
        // 输出排序后的数组
        for (int k = 0; k < numsSize; ++k){
            printf("%d ",nums[k]);
            }
        printf("\n");
    
    printf("=================================================================\n");
    
    return 0;
}