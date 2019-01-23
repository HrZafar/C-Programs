#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a[]={9,4,7,3,8,1,5,6,2,0},i,j=10,temp,k=0;
	while(j>0){
		for(i=0;i<j;i++){
			if(a[i]>a[i+1]){
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				k=1;
			}
		}
		if(k==0)
			break;
		j--;
	}
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	return 0;
}
