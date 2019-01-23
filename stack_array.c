#include <stdio.h>
#include <stdlib.h>

int top=-1;
int main(int argc, char *argv[]) {
	int A[10],c=0,x;
	printf("Enter\n1 for push\n2 for pop\n3 to view\n4 to exit\n");
	while(c!=4){
		printf("enter choice: ");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("enter element: ");
				scanf("%d",&x);
				push(A,x);
				break;
			case 2:
				pop();
				break;
			case 3:
				view(A);
		}
	}
	return 0;
}
pop(){
	if(top==-1)
		printf("stack empty\n");
	else{
		top--;
	}
}
push(int *A,int x){
	if(top==9)
		printf("stack full\n");
	else{
		top++;
		A[top]=x;
	}
}
view(int *A){
	int i;
	if(top==-1){
		printf("stack empty\n");
	}
	else{
		for(i=0;i<=top;i++)
			printf("%d ",A[i]);
	}
	printf("\n");
}
