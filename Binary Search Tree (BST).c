#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

struct  node{
  int  data ;
  struct  node  *left , *right ;
} ;

void  insert(struct  node  **proot , int  x){
  struct  node *pnode , *p , *follow ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL){
     printf("\nMemory overflow. Unable to create.") ;
     return ;
  }

  pnode->data=x ;

  pnode->left=pnode->right=NULL ;

  if(*proot==NULL) 
	 *proot=pnode ;
  else{
    p=*proot ;
    follow=NULL ;
    while(p!=NULL){
      follow=p ;
      if(pnode->data<p->data)
	   p=p->left ;
      else
	   p=p->right ;
    }

    if(pnode->data<follow->data)
      follow->left=pnode ;
    else
      follow->right=pnode ;
  }
}

void  create(struct  node  **proot){
  int  x , i , n ;

  printf("Enter the number of nodes required:\n") ;
  scanf("%d",&n) ;

  printf("Enter the data value of each node:\n") ;
  for(i=1 ; i<=n ; i++){
    scanf("%d",&x) ;
    insert(proot,x) ;
  }
}

void  deletenode(struct  node  **proot , int  k){
  struct  node *p , *follow , *t , *f ;

  p=*proot ;
  follow=NULL ;
  while(p!=NULL){
    if(p->data==k)
      break ;
    follow=p ;
    if(k<p->data)
      p=p->left ;
    else
      p=p->right ;
  }

  if(p==NULL)
     printf("Required node not found. \n") ;
  else{
    if(p->left==NULL)
      if(p!=*proot)
	   if(follow->left==p)
	     follow->left=p->right ;
	   else
	     follow->right=p->right ;
      else
	  *proot=p->right ;

    else if(p->right==NULL)
	   if(p!=*proot)
	     if(follow->left==p)
	       follow->left=p->left ;
	     else
	       follow->right=p->left ;
	   else
	     *proot=p->left ;

    else{
     t=p->right ; 
     f=p ;
     while(t->left!=NULL){ 
        f=t ; 
	   t=t->left ;
     }
      p->data=t->data ;
       
      if(f!=p)
	      f->left=t->right ;
      else
	      f->right=t->right ;
	
	p=t ; 
    }
    free(p) ;
  }
}

void  search(struct  node  *root , int  k){
  struct  node  *p ;

  p=root ;
  while(p!=NULL){
    if(p->data==k)
      break ;
    if(k<p->data)
      p=p->left ;
    else
      p=p->right ;
  }

  if(p==NULL)
      printf("Required node not found. \n") ;
  else
      printf("Node found at address %X. \n",p) ;
}

void main(){
  int x , k , ch , ncount , lcount ;

  struct  node  *root = NULL ;
 
  do{
    printf("1.Create. \n") ;
    printf("2.Insert. \n") ;
    printf("3.Delete Node. \n") ;
    printf("4.Search \n") ;
    printf("5.Exit\n");

    printf("Enter your choice: ") ;
    scanf("%d",&ch) ;

    switch(ch){
      case 1:
      create(&root) ;
      break ;

      case 2:
      printf("Enter the data value of new node: ") ;
      scanf("%d",&x) ;
      insert(&root,x) ;
      break ;

      case 3:
      printf("Enter data of the node to be deleted: ") ;
      scanf("%d",&k) ;
      deletenode(&root,k) ;
      break ;

	case 4:
      printf("Enter data of the node to be searched: ") ;
      scanf("%d",&k) ;
      search(root,k) ;
      break ;
      
    case 5:
      break;
    }
  }
  while(ch!=5) ;
  getch() ;
}
