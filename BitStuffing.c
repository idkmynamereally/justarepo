#include<stdio.h>
#include<stdlib.h>

int * stuff(int *, int*);
int * destuff(int *, int*);

int main(){
    int size = 7;
    //printf("Enter Size of Message -> ");
    //scanf("%d", &size);
    int input[7] = {0,1,1,1,1,1,0};
    int * nums;
    nums = stuff(input, &size);
    printf("Size after stuffing -> %d\n", size);
    for (int i = 0; nums[i]!=-1; i++){
        printf("%d ", nums[i]);
    }
    nums = destuff(nums, &size);
    printf("\nSize after destuffing -> %d", size);
    printf("\n");
    for (int i = 0; nums[i]!=-1; i++){
        printf("%d ", nums[i]);
    }
}

int* stuff(int * arr, int* size){
    int * tempArr = (int*)malloc(sizeof(arr)*2);
    int count = 0;
    int j = 0;
    int stuffs = 0;
    for (int i = 0; i < *size; i++,j++){
        if (arr[i] == 0){
            tempArr[j] = 0;
            count  = 0;
            continue;
        }
        if (arr[i] == 1){
            count++;
            tempArr[j] = 1;
        }
        if (count == 5){
            count = 0;
            tempArr[++j] = 0;
            stuffs++;
        }
    }
    *size = j;
    tempArr[j] = -1;
    return tempArr;
}

int* destuff(int * arr, int* size){
    int* tempArr = (int *)malloc(sizeof(int)*(*size));
    int count = 0;
    int j = 0;
    for (int i = 0; i < *size; i++,j++){
        if (arr[i] == 0){
            tempArr[j] = 0;
            count = 0;
            continue;
        }
        if (arr[i] == 1){
            tempArr[j] = 1;
            count++;
        }
        if (count == 5){
            count = 0;
            i++;
        }
    }
    tempArr[j] = -1;
    *size = j;
    return tempArr;
}
