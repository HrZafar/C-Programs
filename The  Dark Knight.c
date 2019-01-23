#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("enter board size: ");
    int n;
    scanf("%d",&n);
    int c[n][n],m=n-1,i,j,conf=1;
    printf("Enter board configuration:\n");
    for(i=0;i<n;i++){
		for(j=0;j<n;j++)
            scanf("%d",&c[i][j]);
    }
    for(i=0;i<n;i++){
		if(conf==0)
            break;
		for(j=0;j<n;j++){
            int k=i,l=j;
            if(c[i][j]==1){
                if(i<m&&j<m-1&&c[k+1][l+2]==1){
                    conf=0;
				}
				else if(i>0&&j<m-1&&c[k-1][l+2]==1){
                    conf=0;
				}
				else if(i<m-1&&j<m&&c[k+2][l+1]==1){
                    conf=0;
				}
				else if(i<m-1&&j>0&&c[k+2][l-1]==1){
                    conf=0;
				}
      		}
		}
    }
    if(conf==1)
		printf("knight valid");
    else if(conf==0)
		printf("knight invalid");    
	return 0;
}
