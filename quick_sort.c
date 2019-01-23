#include <stdio.h>
#include <stdlib.h>

int partition(int *A,int start,int end){
	int pivot=A[end],i,temp;
	int pIndex=start;
	for(i=start;i<end;i++){
		if(A[i]<=pivot){
			temp=A[i];
			A[i]=A[pIndex];
			A[pIndex]=temp;
			pIndex++;
		}
	}
	temp=A[pIndex];
	A[pIndex]=A[end];
	A[end]=temp;
	return pIndex;
}
void quickSort(int *A,int start,int end){
	if(start<end){
		int pIndex=partition(A,start,end);
		quickSort(A,start,pIndex-1);
		quickSort(A,pIndex+1,end);
	}
}
int main(int argc, char *argv[]) {
	int A[]={2,0,5,4,7,3,6,1},i;
	quickSort(A,0,7);
	for(i=0;i<8;i++)
		printf("%d ",A[i]);
	return 0;
}
