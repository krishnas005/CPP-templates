#include<stdio.h>
int main()
{
	int a[100][100],b[100][100],c[100][100];
	int rows,columns;
	printf("Enter the number of rows: ");
	scanf("%d",&rows);
	printf("Enetr the number of columns: ");
	scanf("%d",&columns);
	
	printf("\nEnter the elements of 1stmatrix:\n");
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEnter the elements of 2stmatrix:\n");
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			scanf("%d",&b[i][j]);
		}
	}
	printf("\nThe sum of two matrices is:\n");
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			c[i][j]= a[i][j]+ b[i][j];
		}
	}
	printf("\nThe sum of 2 matrices is:\n");
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
