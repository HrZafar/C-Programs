#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head;
int main(int argc, char *argv[]) {
	head=NULL;
	int ch,j=0;
	printf("Enter\n1 for push\n2 for pop\n3 to view\n4 to exit\n");
	while(j==0){
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				push(&head);
				break;
			case 2:
				pop(&head);
				break;
			case 3:
				display(head);
				break;
			case 4:
				j=1;
		}
	}
	return 0;
}
push(struct node **s){
	struct node *temp;
	temp=*s;
	int num;
	printf("enter element: ");
	scanf("%d",&num);
	if(*s==NULL){
		head=malloc(sizeof(struct node));
		head->data=num;
		head->next=NULL;
	}
	else{
		temp=malloc(sizeof(struct node));
		temp->data=num;
		temp->next=*s;
		*s=temp;
	}
}
pop(struct node **s){
	struct node *temp,*temp1;
	if(*s==NULL)
		printf("stack empty\n");
	else{
		temp=*s;
		temp1=temp->next;
		free(temp);
		*s=temp1;
	}
}
display(struct node *s){
	printf("\n");
	while(s!=NULL){
		printf("%d ",s->data);
		s=s->next;
	}
	printf("\n");
}
