#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 4
#define m 2
#define n 3
#define p 3

//行列互换
static int exchange(void){
    int arr[ROW][COL]={{1,2,3},{4,5,6},{7,8,9,10}};
    int switchedArr[COL][ROW];
    int i,j;

    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            switchedArr[j][i] = arr[i][j];
            printf("%d ", arr[i][j]);
        }
        printf("\n");
	}

    for(i = 0; i < COL; i++){
        for(j = 0; j < ROW; j++){
            printf("%d ", switchedArr[i][j]);
        }
        printf("\n");
    }
}

//求最大值及其所在位置
static int max(void){
    int arr[ROW][COL]={{15,27,3},{14,59,61},{57,28,49,10}};
    int i,j,max_num,max_i,max_j;
	
	max_num = arr[0][0];
	for(i = 0; i < ROW; i++)
		for(j = 0; j < COL; j++)
			if(arr[i][j] > max_num){
				max_num = arr[i][j];
				max_i = i;
				max_j = j;
			}
	
	printf("maximun num is %d\nthe position in arr is (%d, %d)\n", max_num, max_i, max_j);
}

//求各行与各列的和
static int sum(void){
    int arr[ROW][COL]={{1,2,3},{4,5,6},{7,8,9,10}};
	int i,j,sum, sum_row = 0, sum_col = 0;

	for(i = 0; i < ROW; i++){
		for(j = 0; j < COL; j++)
			sum_row += arr[i][j];
		printf("sum_row[%d] = %d\n", i + 1, sum_row);
		sum_row = 0;
	}
	
	for(i = 0; i < COL; i++){
		for(j = 0; j < ROW; j++)
			sum_col += arr[j][i];
			sum += sum_col;
		printf("sum_col[%d] = %d\n", i + 1, sum_col);
		sum_col = 0;
	}
	printf("sum = %d\n", sum);
}

//通过类似表格来求各行与各列的和
static int sum_pro(void){
    int arr[ROW + 1][COL + 1]={{1,2,3},{4,5,6},{7,8,9,10}};
	int i, j;

	for(i = 0; i < ROW; i++)
	{
		for(j = 0; j < COL; j++)
		{
			arr[ROW][COL] += arr[i][j];
			arr[ROW][j] += arr[i][j];
			arr[i][COL] += arr[i][j];
		}
	}

	for(i = 0; i <= ROW; i++){
		for(j = 0; j <= COL; j++)
			printf("%4d ", arr[i][j]);
		printf("\n");
	}
}

//矩阵相乘
static int multip(void){
	int arrM[m][n] = {{1, 2, 3}, {4, 5, 6}};
	int arrP[n][p] = {{7, 8, 9}, {9, 10, 11}, {11, 12, 13}};
	int i,j,k,arrNew[m][p],sum=0;

	for(i = 0; i < m; i++){
		//printf("i = %d\n\n", i);	//学会用输出标记来理清思路
		for(k = 0; k < p; k++){
			//printf("k = %d\n", k);
			for(j = 0; j < n; j++){ 
				sum += arrM[i][j] * arrP[j][k];
				//printf("%d, %d, multip = %d\n", arrM[i][j], arrP[j][k], arrM[i][j] * arrP[j][k]);
			}
			arrNew[i][k] = sum;
			//printf("arrNew[%d][%d] = %d\n", i, k, sum);
			sum = 0;	//将每行和每列的乘积和清零
			printf("%d ", arrNew[i][k]);
		}
		printf("\n");
	}
}

int main(){

//	exchange();	
//	max();
//	sum();
	sum_pro();
//	multip();

	exit(0);
}



