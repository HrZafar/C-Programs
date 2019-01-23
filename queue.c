#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head;
int main(int argc, char *argv[]) {
	int j=0,ch;
	printf("Enter\n1 to enque\n2 to deque\n3 to display\n4 to exit\n");
	while(j==0){
		printf("enter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				enque(&head);
				break;
			case 2:
				deque(&head);
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
enque(struct node **q){
	struct node *temp,*temp1;
	temp=*q;
	printf("enter element: ");
	int num;
	scanf("%d",&num);
	if(head==NULL){
		head=malloc(sizeof(struct node));
		head->data=num;
		head->next=NULL;
	}
	else{
		while(temp!=NULL){
			temp1=temp;
			temp=temp->next;
		}
		temp=malloc(sizeof(struct node));
		temp->data=num;
		temp->next=NULL;
		temp1->next=temp;
		
	}
}
deque(struct node **q){
	if(*q==NULL)
		printf("Queue empyty\n");
	else{
		struct node *temp;
		temp=*q;
		temp=temp->next;
		*q=temp;
	}
}
display(struct node *q){
	printf("\n");
	while(q!=NULL){
		printf("%d ",q->data);
		q=q->next;
	}
	printf("\n");
}
