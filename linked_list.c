#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};
struct node *p;
int main(int argc, char *argv[]) {
	p=NULL;
	int j=0,ch,num,po;
	printf("1 for insert at any position\n2 for insert at last\n3 for insert at begining\n4 for delete\n5 to view linked list\n6 to exit\n");
	while(j==0){
		printf("enter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("enter element: ");
				scanf("%d",&num);
				printf("enter position: ");
				scanf("%d",&po);
				if(count(p)<po-1)
					printf("invalid position\n");
				else
					insert(&p,num,po);
				break;
			case 2:
				printf("enter element: ");
				scanf("%d",&num);
				append(&p,num);
				break;
			case 3:
				printf("enter element: ");
				scanf("%d",&num);
				add_beg(&p,num);
				break;
			case 4:
				printf("enter element: ");
				scanf("%d",&num);
				delete(&p,num);
				break;
			case 5:
				display(p);
				break;
			case 6:
				j=1;
		}
	}
	return 0;
}
append(struct node **q,int num){
	struct node *temp,*r;
	temp=*q;
	if(*q==NULL){
		temp=malloc(sizeof(struct node));
		temp->data=num;
		temp->link=NULL;
		*q=temp;
	}
	else{
		temp=*q;
		while(temp->link!=NULL){
			temp=temp->link;
		}
		r=malloc(sizeof(struct node));
		r->data=num;
		r->link=NULL;
		temp->link=r;

	}
}
add_beg(struct node **q,int num){
	struct node *temp;
	temp=*q;
	if(*q==NULL){
		temp=malloc(sizeof(struct node));
		temp->data=num;
		temp->link=NULL;
		*q=temp;
	}
	else{
		temp=malloc(sizeof(struct node));
		temp->data=num;
		temp->link=*q;
		*q=temp;
	}
}
display(struct node *q){
	printf("\n");
	while(q!=NULL){
		printf("%d ",q->data);
		q=q->link;
	}
}
count(struct node *q){
	int c=0;
	while(q!=NULL){
		q=q->link;
		c++;
	}
	return c;
}
delete(struct node **q,int num){
	struct node *old,*temp;
	temp=*q;
	while(temp!=NULL){
		if(temp->data==num){
			if(temp==*q){
				*q=temp->link;
				free(temp);
				return;
			}
			else{
				old->link=temp->link;
				free(temp);
				return;
			}
		}
		else{
			old=temp;
			temp=temp->link;
		}
	}
	printf("\nElement %d not found",num);
}
insert(struct node **q,int num,int pos){
	struct node *old,*temp,*next,*ins;
	if(pos==1)
		add_beg(&p,num);
	else{
	temp=*q;
	next=temp->link;
	int i=1;
	while(i<pos-1){
		old=next;
		next=old->link;
		i++;
	}
	ins=malloc(sizeof(struct node));
	ins->data=num;
	ins->link=next;
	old->link=ins;
	}
}
