#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void insert(); 
void display();
void search();
void delet();
void update();
void bill();

	struct medical_record_management
	{
		char medicine[30];
		int price,id;
		char md[100],ed[100];
	}m;
main()
{
	int i,ch,n;char s[20];
	printf("\t\tARE YOU USER OR ADMIN ?\n");
	printf("\t\tPRESS 1 FOR ADMIN\t PRESS 2 FOR USER \t");	
	scanf("%d",&n);
	if(n==1)
	{ 
		printf("enter the password=\t");
		scanf("%s",s);
		if(stricmp(s,"kalki")==0)
		{
		printf("\n\t\t\t\t\t      You are successfully logged in !!!!!!"); 
		printf("\n\n\t\t\tWELCOME TO LOVELY MEDICINES\n\t\t");
         for(i=0;i<40;i++)
        printf("*");	
        printf("\n\t\t\tpress 1 for DISPLAY   ITEMS");
  		printf("\n\t\t\tpress 2 for SEARCH    ITEMS");
  		printf("\n\t\t\tpress 3 for INSERTING ITEMS");
  		printf("\n\t\t\tpress 4 for DELETE    ITEMS");
  		printf("\n\t\t\tpress 5 for UPDATE    ITEMS");
  		printf("\n\t\t\tpress 6 for BILLING   ITEMS");
  		printf("\n\tenter your choice  =  \t");
  		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			display();
			break;
			case 2:
			search();
         	break;
			case 3:
			insert();
			break;
			case 4:
			delet();
			break;
		    case 5:
		    update();
		    break;
			case 6:
			bill();
			break;			
		}
        }
    else
    printf("incorrect password\n");
    }
    else if(n==2)
    {
         printf("\n\n\t\t\tWELCOME TO LOVELY MEDICINES\n\t\t");
         for(i=0;i<40;i++)
        printf("*");	
        printf("\n\t\t\tpress 1 for DISPLAY   ITEMS");
  		printf("\n\t\t\tpress 2 for SEARCH    ITEMS");
  		printf("\n\t\t\tpress 3 for BILLING   ITEMS");
  		printf("\n\tenter your choice  =  \t");
  		scanf("%d",&ch);
  		switch(ch)
  		{
  			case 1:
			display();
			break;
			case 2:
			search();
			case 3:
			bill();
			break;
		}

    }
}
	void insert()
		{
			int c,z,ch;
			printf("how many medicines you want to insert\n");
			scanf("%d",&z);
			FILE*med;
			med=fopen("med1.txt","a");
			if(med==NULL)
			{
				printf("\n cannot open file");
				
			}
			for(c=1;c<=z;c++)
			{
			printf("enter id =\t");
			scanf("%d",&m.id);
			printf("enter name of medicine=");
			scanf("%s",m.medicine);
			printf("enter price =");
			scanf("%d",&m.price);
			printf("enter manufacturing date=");
			scanf("%s",m.md);
			printf("enter expiry date=");
			scanf("%s",m.ed);
			fwrite(&m,sizeof(m),1,med);
		    }
			printf("DATA WRITTEN SUCCESSFULLY");	
		    fclose(med);
		    display();
		    printf("\npress 1 to see options\npress 2 for exit\n");
		    scanf("%d",&ch);
		    system("cls");
		    switch(ch)
		    {
		    	case 1:
		    	main();
		    	break;
		    	case 2:
		    	exit(0);
		    	break;
			}
		}
		void display()
		{
			   int ch;
			printf("\t\t\tyour medicines  are\n");
			FILE*med;
		    med=fopen("med1.txt","r");
		    if(med==NULL)
			{
				printf("\n cannot open file");
			}
			printf("\t\tsr.no\t\tMEDICINES\tPRICE\t\tMANU.DATE\t\tEXP.DATE\n\n");
		    while(fread(&m,sizeof(m),1,med)>0)
		    printf("\t\t%d\t\t%s\t\t%d\t\t%s\t\t%s\n",m.id,m.medicine,m.price,m.md,m.ed);
		    fclose(med);
		    printf("\npress 1 to see options\npress 2 for exit\n");
		    scanf("%d",&ch);
		    system("cls");
		    switch(ch)
		    {
		    	case 1:
		    	main();
		    	break;
		    	case 2:
		    	exit(0);
		    	break;
			}
		}
		
	    void search()
        {
	        int i,n,ch;
	        printf("enter the medicine id you want to search=\n ");
	        scanf("%d",&i);
	            FILE*med;
		        if(med==NULL)
		        printf("file not found");
		        else
		        {
		        med=fopen("med1.txt","r");
		        while(fread(&m,sizeof(m),1,med))
	              {
	              	n=m.id;
	              	if(n==i)
	                  {
	            	    printf("you medicine is \n");
	            	    printf("name :%s\t",m.medicine);
	            	    printf("\nprice :%d\n",m.price);
	            	    printf("\nmanufacturing date:%s",m.md);
	            	    printf("\nexpiry date:%s",m.ed);
				      }
				  }
		          fclose(med);
		          printf("\npress 1 to see options\npress 2 for exit\n");
		    scanf("%d",&ch);
		    system("cls");
		    switch(ch)
		    {
		    	case 1:
		    	main();
		    	break;
		    	case 2:
		    	exit(0);
		    	break;
			}
	            }
	    }
	    void delet()
       {
	         int i,n,ch;
	          printf("enter the medicine id  you want to delete\n");
	          scanf("%d",&i);
	          FILE*med;
	          FILE*med1;
		      med=fopen("med1.txt","r");
		      med1=fopen("med2.txt","w");
		        if(med==NULL)
				printf("sorry , no medicines are there to delete\n");
				else
				{
					med=fopen("med1.txt","r");
					med1=fopen("med2.txt","w");
					while(fread(&m,sizeof(m),1,med))
					{
						n=m.id;
						if(n!=i)
						fwrite(&m,sizeof(m),1,med1);
					}
					fclose(med1);
					fclose(med);
					med=fopen("med1.txt","w");
					med1=fopen("med2.txt","r");
					while(fread(&m,sizeof(m),1,med1))
					fwrite(&m,sizeof(m),1,med);
					fclose(med1);
					fclose(med);
						printf("\n record deleted successfully");
						fclose(med);
						fclose(med1);
						printf("\npress 1 to see options\npress 2 for exit\n");
		    scanf("%d",&ch);
		    system("cls");
		    switch(ch)
		    {
		    	case 1:
		    	main();
		    	break;
		    	case 2:
		    	exit(0);
		    	break;
			}
				}
		}
		void update()
		{
			FILE*med;
			FILE*med1;
			int i,n,ch;
			printf("enter medicine id to update= \t");
			scanf("%d",&i);
			 if(med==NULL)
				printf("sorry , no medicines are there to update\n");
			 else
			 {
			 	med=fopen("med1.txt","r");
			    med1=fopen("med2.txt","w");
			 	while(fread(&m,sizeof(m),1,med))
			 	{
			 	n=m.id;
			 	if(n!=i)
			 	fwrite(&m,sizeof(m),1,med1);
			 	else
			 	{
			 		printf("\n\t\tCHOOSE ONE OPTION PLEASE\n");
			 		printf("\n\tpress 1.To update name of   %d item       \t",i);
			 		printf("\n\tpress 2.To update price of  %d item       \t",i);
			 		printf("\n\tpress 3.To update manf.date of  %d item       \t",i);
			 		printf("\n\tpress 4.To update expi.date of  %d item       \t",i);
			 		printf("\n\tpress 5.To update all details of %d item  \n",i);
			 		scanf("\n%d",&ch);
			 		switch(ch)
			 		{
			 			case 1: 
			 				printf("\nenter name= \t");
			 				scanf("%s",m.medicine);
			 				break;
			 			case 2:
			 				printf("enter price= \t");
			 				scanf("%d",&m.price);
			 				break;
			 			case 3:
			 				printf("enter manf.date= \t");
			 				scanf("%s",m.md);
			 				break;
			 			case 4:
			 				printf("enter expi.date= \t");
			 				scanf("%s",m.ed);
			 				break;
			 			case 5:
			 				printf("enter name = \t");
			 				scanf("%s",m.medicine);
			 				printf("enter price =\t");
			 				scanf("%d",&m.price);
			 				printf("enter manf.date= \t");
			 				scanf("%s",m.md);
			 				printf("enter expi.date= \t");
			 				scanf("%s",m.ed);
			 				break;
			 			default:
			 				printf("\nenter your choice correctly");
							 break;	
							 exit(0);
					 }
					 fwrite(&m,sizeof(m),1,med1);
				 }
			}
			 fclose(med1);
			 fclose(med);
			 med=fopen("med1.txt","w");
			 med1=fopen("med2.txt","r");
			 while(fread(&m,sizeof(m),1,med1))
			 {
			 	fwrite(&m,sizeof(m),1,med);
			 }
		fclose(med1);
		fclose(med);
		printf("record updated");
		printf("\npress 1 to see options\npress 2 for exit\n");
		    scanf("%d",&ch);
		    system("cls");
		    switch(ch)
		    {
		    	case 1:
		    	main();
		    	break;
		    	case 2:
		    	exit(0);
		    	break;
			}
	}
	    }
	     void bill()
{
	int id,c,f=0,amount=0,a,an,q,qt=0;
	FILE *med,*bill;
	med=fopen("med1.txt","r");
	bill=fopen("med3.txt","a");
	printf("\t\tsr.no\t\tMEDICINE \t\t PRICE\t\tMANF.DATE\t\tEXPI.DATE\n\n");
	while(fread(&m,sizeof(m),1,med))
	printf("\t\t%d\t\t%s\t\t\t%d\t\t%s\t\t%s\n",m.id,m.medicine,m.price,m.md,m.ed);
	fclose(med);
	med=fopen("med1.txt","r");
	a:
	printf("enter id of medicine\n");
	scanf("%d",&id);
	while(fread((&m),sizeof(m),1,med))
	  {
	  	if(id==m.id)
	        {
	        	printf("\nEnter the Quantity of Item you want\n");
	        	scanf("%d",&q);
	        	qt=qt+q;
			    a=q*m.price;
			    f=1;
			    amount=amount+a;
			 fwrite((&m),sizeof(m),1,bill);             
			}
			else
		    { 
			  fwrite((&a),sizeof(a),1,bill);
			}
			
			printf("press 1 to add another item\n\npress 2 to stop adding\n");
			scanf("%d",&an);
			if(an==1)
			goto a;
			else
			break;
		}
		fclose(med);
	    fclose(bill);
	    printf("se.no\t\tname\t\tprice\n");
	    bill=fopen("med3.txt","r");
	    {
	    while(fread((&m),sizeof(m),1,bill))
		printf("%d\t\t%s\t\t%d\n",m.id,m.medicine,m.price);
		}
		fclose(bill);
	   	printf("\n\n***********************\n");
	printf("Total quantity u bought: %d\nTotal Amount: %d",qt,amount);
		printf("\n\n***********************\n");
		remove("med3.txt");
	  
}
