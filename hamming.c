#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculate_bits(int d, int * r);
void redundantBitPosition(int d, int r);

int main(){
    int d = 0;
    int r = 0;
    printf("Enter Number of Data Bits -> ");
    scanf("%d", &d);
    calculate_bits(d, &r);
    printf("%d\n", r);
    redundantBitPosition(d, r);
}

void calculate_bits(int d, int * r){
    int ri = *r;
    while (pow(2, ri) < d + ri + 1){
        ri++;
    }
    *r = ri;
}

int* redundantBitPosition(int d, int r){
    int pos = 0;
    int * arr = malloc(sizeof(int)*r);
    for (int i = 0; i <= r; i++){
        arr[i] = pow(2,i);
    }
    for (int i = 0; i < r; i++){
        printf("%d ", arr[i]);
    }
    return arr;
}
