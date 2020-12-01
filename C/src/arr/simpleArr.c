#include <stdio.h>
#include <stdlib.h>

#define M 3

int main(){
        int i;
        int arr[M] = {1, 2, 3};

        printf("%d\n", sizeof(arr));
        printf("arr = %p\n", arr);

        //for(i = 0; i < M; i++)
        //      scanf("%d", &arr[i]);
        for(i = 0; i < M; i++)
                printf("%p --> %d\n", &arr[i], arr[i]);
        
        arr[3] = 10;
        printf("%p --> %d\n", &arr[3], arr[3]);

        exit(0);
}
