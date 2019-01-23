#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

/*run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long int i,conv=0,j,k=0,a,dr[50],b,choice,d,R,NS;
	char cd,RA[20],dc,di[50];
	printf("enter 1 to convert decimal number to any other number system,\nenter 2 to convert number of any number system to decimal:\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("enter number:\n");
		scanf("%d",&d);
		printf("enter number system in which number is to be converted:\n");
		scanf("%d",&NS);
		while (d>0&&i<20)
		{
			R=d%NS;
			d=d/NS;
			if(R<=9)
			cd=R+'0';
			else
			cd=R+'A'-10;
			RA[i]=cd;
			i++;
		}
		printf("base %d number is ",NS);
		for(i=i-1;i>=0;i--)
		{
			printf("%c",RA[i]);
		}
	}
	else
	{
	printf("enter number to convert it in decimal:\n");
	dc='0';
	dc=getche();
	for(i=0;dc!='\n'&&dc!='\r';i++)
	{
		di[i]=dc;
		dc=getche();
	}
	for(j=i-1;j>=0;j--)
	{
		a=di[j]+0;
		if(a>64)
		dr[j]=a-55;
		else
		dr[j]=a-48;
	}
	printf("enter base of your number:\n");
	scanf("%d",&b);
	for(j=i-1;j>=0;j--)
	{
		conv=conv+dr[k]*pow(b,j);
		k++;
	}
	printf("decimal number is %d",conv);
	}
	getch();
	return 0;
}
