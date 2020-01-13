#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define rows 5
#define cols 5

//make random generated matrix
void fillMatrix(int matrix[rows][cols]){
    srand(time(0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                matrix[i][j]= rand()% 100 +1;
            }
        }
    }

//print the matrix


    void printMatrix(int matrix[rows][cols]){
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                printf("%d,", matrix[i][j]);
            }
            printf("\n");
        }
    }

//transpose the elements
    void transposeMatrix(int matrix[rows][cols]){
       int a,b;
        
        for(a=1; a<rows; a++){
            for(b=0; b<a; b++){
		int t=*(*(matrix+a)+b);
		*(*(matrix+a)+b)=*(*(matrix+b)+a);
		*(*(matrix+b)+a)=t;
            }
        }
    }
    void multiplyMatrix(int m1[2][cols], int m2[rows][cols], int resultMatrix[rows][cols]){
        //initialize all the elements in result to 0
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
               *(*(resultMatrix+i)+j)=0;
	}
            }
	//find the dot product 
            int sum=0;
            for(int i=0; i<2;i++){
                for(int j=0; j<cols;j++){
                    for(int k=0; k<rows;k++){
                        sum+=(*(*(m1+i)+k)) * *(*(m2+k)+j);
                        
                        
                    }
                    *(*(resultMatrix+i)+j)=sum;
                    sum=0;
                }
        }
    
    }
int main(){
    	int matrix[rows][cols];
    	fillMatrix(matrix);
     	printMatrix(matrix);
    	transposeMatrix(matrix);
	printMatrix(matrix);
    	int matrix2[2][cols]={0,1,2,3,4,5,6,7,8,9};
    	int matrixResult[rows][cols];
   	multiplyMatrix(matrix2, matrix, matrixResult);
    	printMatrix(matrixResult);


    return 0;
}



