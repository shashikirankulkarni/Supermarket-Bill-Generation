/*C Program to generate Bill from Super Market*/
     #include<stdio.h>
     #include<conio.h>
     #include<time.h>
    
       void main()

    {

    struct bill
    {
	char name[25];
	int qty;
	int price;
	} b[50];


    int i,n,ans,total=0;

    time_t t;
    time(&t);
    clrscr();
    
    printf("\t\t\t WELCOME TO SUPER MARKET\n");


    printf("\t\t\t\t\t\t\t%s",ctime(&t));

    getch();
    printf("Enter no of item purchased");
    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
	printf("\nEnter item name purchased=");
	scanf("%s",&b[i].name);
	printf("\nEnter price of item Rs.");
	scanf("%d",&b[i].price);
	printf("\nEnter quantity of item=");
	scanf("%d",&b[i].qty);
    }

    printf("\t\t   Item name   Quantity   Price\n");
    
     for(i=1; i<=n; i++)
    {
	ans=b[i].price*b[i].qty;
	printf("\t\t\t%s\t%dx%d\t=Rs.%d\n",b[i].name,b[i].price,
             b[i].qty,ans);
	total=total+ans;

    }
    printf("\t\t----------------------------------\n");
    printf("\n \t\tTotal price to be paid is Rs.%d\n",total);
    printf("\t\t----------------------------------\n");
    printf("\n\t\t\tThank you Visit again!!!");
    getch();
    }
