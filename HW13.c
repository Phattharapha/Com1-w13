#include <stdio.h>
//menu
void menu()
{
	printf ("\n====================================================\n");
	printf ("+   List of menu                                   +\n");
	printf ("+   1. Calculator (get integers from user)         +\n");
	printf ("+   2. Calculator (get integers from integer file) +\n");
	printf ("+   3. Exit program                                +\n");
	printf ("====================================================\n");
}

//operator
int user(int num1,int num2)
{
	char op;
	int total=0 ;
	printf("Enter number1 : ");
	scanf("%d",&num1);
	printf("Enter number2 : ");
	scanf("%d",&num2);
	printf("Enter an operator(+,-,*,/,%) : ");
	scanf(" %c",&op);
		if ( op == '+' )
		{
			total = num1 + num2 ; 
		}
		else if (op == '-')
		{
			total = num1 - num2 ;
		}
		else if (op == '*')
		{
			total = num1 * num2 ;
		}
		else if (op == '/')
		{
			total = num1 / num2 ;
		}
		else if (op == '%')
		{
			total = (num2*num1) / 100;
		}
		else 
		{
			printf(" INVALID CODE >>>>> <<<<< !!!!! .....");
		}
		
		printf("The answer if : %d \n",total);
		printf("====================================================\n");
	return (total);
}

//integer file
int file(int num1,int num2)
{
	FILE *inf;
	float total=0;
	int i=0;
	char op ; 	
	inf = fopen("list.txt","r");
	
	printf("\nList of all transactions \n");
	printf("==========================");
	
	while(!feof(inf))
	{
		fscanf(inf,"%d %c %d",&num1,&op,&num2);
		if ( op == '+' )
		{
			total = num1 + num2; 
		}
		else if (op == '-')
		{
			total = num1- num2 ;
		}
		else if (op == '*')
		{
			total = num1* num2 ;
		}
		else if (op == '/')
		{
			total = num1 / num2 ;
		}
		else if (op== '%')
		{
			total = (num2*num1) / 100;
		}
		i++ ;
		printf("\nTransaction #%d : Num1 = %d , Num2 = %d \n",i,num1,num2);
		printf("The answer is %.1f",total);
	}
		printf("\n\nTotal of transactions = %d",i);
		
	fclose(inf);
	return(total);
}
//main func.
int main()
{
	int type=0,Calculator1=0,Calculator2=0,num1[5],num2[5]; 
	while(type != 3)
	{
		menu () ;
		printf("Please select menu : ");
		scanf("%d",&type);
		
		if (type == 1)
		{
			Calculator1 = user(num1,num2);
		}
		else if (type == 2)
		{
			Calculator2 = file(num1,num2);
		}
		else if (type == 3 )
		{
		printf("This program is terminated.");
		}
		else
		{
		printf("Invalid Code !!!! .... Try again please");
		}
	}
	return 0 ;
}
