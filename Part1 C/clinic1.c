#include <stdio.h>
#include <stdlib.h>
#define password 1234
#define var1 1
#define var2 2
typedef unsigned char u8;
typedef unsigned short u16; 

struct paitent
{
	u16 id;
	u8 age;
	u8 gender;
	u8 name[10];
	u8 date;
	struct paitent * nextptr;
};
struct paitent *head=NULL;
struct paitent *tail=NULL;
struct paitent * arr[5]={NULL};
struct paitent * idsearch(u16 key);
void AddNode (void);
void DisplayNode (void); 
void EditNode (void);
//This Function will be used To Display  in case we will edit Node 
void EdDis (u16 key);
//This Function To Print avilable Slots  
void CheckPrint (void);
//This Function To check if the slot is already reserved
void CheckReserv (u16 key); 
void Reservation (u16 key, u8 choice ); 
void CancelReserv (u16 key,u8 choice); 
void UserDis(u16 key);

void main (void)
{
	u8 x,i,a,choice,choice1;
	u16 kk,uv,aa,bb,pass,key,key1;
	printf("To Enter Admin Mode Enter : 1\n");
	printf("To Enter User Mode Enter : 2\n");
	scanf("%d",&x);
	switch (x)
	{
		case var1:
		printf("Welcome Admin \n");
		printf("Please Enter Your Password :");
	    scanf("%d",&pass);
		if (pass==password)
		{
			while (1)
			{
			    printf("To Add New Patient Enter 1 \n");
				printf("To Display Paitent File Enter 2 \n");
	            printf("To Edit Patient Enter 3 \n");
	            printf("To Reserve Date Enter 4 \n");
				printf("To Cancel Reservation Enter 5\n");
		        printf("To Exit Enter 6 \n");
			    scanf("%d",&a);
				switch (a)
				{
					case 1 :
					AddNode();
					break;
					case 2:
					DisplayNode();
					break;
					case 3:
					printf("Please Enter The Paitent ID \n");
					EditNode();
					break;
					case 4:
					CheckPrint();
					printf("Please Enter The Paitent ID : ");				
					scanf("%d",&key);
					if(idsearch(key)!=NULL)
					{
					    printf("Please Enter The Date : ");
					    scanf("%d",&choice);
					    CheckReserv(key);
					    Reservation(key,choice);
					} 
					else if (idsearch(key)==NULL)
					{
						printf("This ID Is Not Exist -_-\n");
					}
					
					break;
					case 5:
					printf("Please Enter paitent ID : ");
					scanf("%d",&key1);
					if (idsearch(key1)!=NULL)
					{
						printf("Please Enter The Date You Want To Cancel ");
						scanf("%d",&choice1);
						CancelReserv(key1,choice1);
					}
					else if (idsearch(key1)==NULL)
					{
						printf("This ID Is Not Exist -_-\n");
					}
					break;
				}
				if(a==6)
				{
					printf("Thank You :)");
					break;
				}
				
			}
			
		}
		else if (pass!=password)//in case of wrong pass
		{
			for (i=0;i<3;i++)
			{
				printf("Please Enter Password Again : ");
				scanf("%d",&pass);
				if (pass==password)// in case he enter correct passs in trial 
				{
			        while (1)
			        {
			            printf("To Add New Patient Enter 1 \n");
				        printf("To Display Paitent File Enter 2 \n");
	                    printf("To Edit Patient Enter 3 \n");
	                    printf("To Reserve Date Enter 4 \n");
						printf("To Cancel Reservation Enter 5 \n");
		                printf("To Exit Enter 6 \n");
			            scanf("%d",&a);
				        switch (a)
				        {
					        case 1 :
					        AddNode();
					        break;
					        case 2:
					        DisplayNode();
					        break;
					        case 3:
					        printf("Please Enter The Paitent ID \n");
					        EditNode();
					        break;
					        case 4:
					        printf("Please Enter The Paitent ID : ");
					        scanf("%d",&key);
							break;	
                            case 5: 
                    	    printf("Please Enter paitent ID : ");
					        scanf("%d",&key1);
					        if (idsearch(key1)!=NULL)
					        {
						        printf("Please Enter The Date You Want To Cancel ");
						        scanf("%d",&choice1);
						        CancelReserv(key1,choice1);
					        }
					        else if (idsearch(key1)==NULL)
					        {
						        printf("This ID Is Not Exist -_-\n");
					        }
					        break;        							
				        }
                        //to Exit From Program 						
						if (a==6)
						{
							printf("Thank You :) ");
							break;
						}
				
			        }
				}
			}
			//to test the condition after the for loop
			if (pass!=password)
			{
			    printf("Incorrect password for 3 times : No more tries :(");				
			}
		}
		//for var1
		break;
		//User Part 
	    case var2:
		printf("Welcome You Entered As A User :) \n");
		while (1)
		{
		    printf("To Display Paitent Enter : 1 \n");
		    printf("To View Today's Reservation Enter : 2\n");
			printf("To Exit Enter : 3\n");
		    scanf("%d",&bb); 
		    switch (bb)
			{
				case 1:
                EdDis(bb);
				break;
				case 2:
				UserDis(bb);
				break;
            }
            if (bb==3)
			{
				printf("Thank You :)");
				break;
			}				
		}
	}
}

struct paitent * idsearch(u16 key)
{
	struct paitent * ptr;
	ptr=head;
	while (ptr!= NULL)
	{
		if (ptr->id==key)
		{
			return ptr;
		}
		ptr=ptr->nextptr;
	}
	return NULL;
}

void AddNode (void)
{
	struct paitent * ptr;
	u8 i;u16 key;
	ptr=(struct paitent *)malloc(sizeof(struct paitent));
	printf("Please Enter The ID Number To Add Paitent  : ");
	scanf("%d",&key);
	if (ptr!=NULL)
	{
		if (idsearch(key)==NULL)
		{
			ptr->id=key;
			printf("Please Enter Paitent Age : ");
			scanf("%d",&(ptr->age));
			printf("Please Enter Paitent M for Males and F for Females :");
			scanf(" %c",&(ptr->gender));
			printf("Please Enter Paitent Name :");
			for (i=0;i<8;i++)
			{
				scanf("%c",&(ptr->name[i]));
			}
			//here i will think in reservation case 
			if(head==NULL)
			{
				head = ptr;
				tail = ptr;
				ptr->nextptr=NULL;
			}
			else 
			{
				tail->nextptr=ptr;
				tail=ptr;
				tail->nextptr=NULL;
			}
		}
		else if (idsearch(key)!=NULL)
		{
			printf("This ID Is Already Existed! \n");
		}
	}
}

void DisplayNode (void)
{
	struct paitent * ptr;
	u16 key;u8 i;
	printf("To Display Paitenet File Please Enter The Paitent ID : ");
	scanf("%d",&key);
	if (idsearch(key)!=NULL)
	{
		ptr=idsearch(key);
		printf("The Paitent ID Is : %d\n",ptr->id);
		printf("The Paitent Age Is : %d\n",ptr->age);
		printf("The Paitent Gender Is : %c\n",ptr->gender);
		printf("The Paitent Name is : ");
		for(i=0;i<8;i++)
		{
			printf("%c",ptr->name[i]);			
		}
		printf("\n");
		printf("The Paitent Date Is : %d\n",ptr->date);
	}
	else if (idsearch(key)==NULL)
	{
		printf("This Paitent Is Not Avalible \n");
	}
}
//------------------------------------------//
void EdDis (u16 key)
{
	struct paitent * ptr;
	u8 i;
	printf("The Paitent Old File ");
	if(idsearch(key)!=NULL)
	{
        ptr=idsearch(key);
		printf("The Paitent ID Is : %d\n",ptr->id);
		printf("The Paitent Age Is : %d\n",ptr->age);
		printf("The Paitent Gender Is : %c\n",ptr->gender);
		printf("The Paitent Name is : ");
		for(i=0;i<8;i++)
		{
			printf("%c",ptr->name[i]);			
		}
		printf("\n");
		printf("The Paitent Date Is : %d\n",ptr->date);
	}
    else if (idsearch(key)==NULL)
	{
		printf("This Paitent Is Not Avalible \n");
	}	
}

void EditNode (void)
{
	struct paitent * ptr;
	u16 key ; 
    u8 i,choice;
	scanf("%d",&key);
	if(idsearch(key)!=NULL)
	{
		// to display the old data 
		EdDis(key);
		//to make ptr hold the user pointer
		ptr=idsearch(key);
		printf("The Paitent New Age : ");
		scanf("%d",&(ptr->age));
		printf("The Paitent New Gender : ");
		scanf(" %c",&(ptr->gender));
		printf("The Paitent New name : ");
		for (i=0;i<8;i++)
		{
			scanf("%c",&(ptr->name[i]));
		}
		printf("\n");
		printf("The Paitent New Date : ");
		CheckPrint();
		scanf("%d",&choice);
		CheckReserv(key);
		Reservation(key,choice);
	}
	else if (idsearch(key)==NULL)
	{
		printf("This Paitent Is Not Registered -_-\n");
	}
}

void CheckPrint(void)
{

	if (arr[0]==NULL)
	{
		printf("The First Date from 2PM T0 2:30PM To Choice Enter  1 : \n");
	}
	if (arr[1]==NULL)
	{
		printf("The Second Date From 2:30PM To 3PM To Choice Enter 2 : \n");
	}
	if (arr[2]==NULL)
	{
		printf("The Third Date From 3PM To 3:30PM To Choice Enter  3 : \n");
	}
	if (arr[3]==NULL)
	{
		printf("The Fourth Date From 3:30PM To 4PM To Choice Enter 4 : \n");
	}
	if (arr[4]==NULL)
	{
		printf("The Fifth Date From 4PM To 4:30PM To Choice Enter  5 : \n");
	}
}

void CheckReserv(u16 key)
{
	struct paitent * ptr ;
    ptr=idsearch(key);
	if(ptr!=NULL)
	{
		if(arr[0]==ptr)
		{
			printf("This ID Is Already Reserved\n");
			EdDis(key); 
		}
		else if (arr[1]==ptr)
		{
			printf("This ID Is Already Reserved\n");
			EdDis(key);
		}
		else if (arr[2]==ptr)
		{
			printf("This ID Is Already Reserved\n");
			EdDis(key);
		}
		else if (arr[3]==ptr)
		{
			printf("This ID Is Already Reserved\n");
			EdDis(key);
		}
		else if (arr[4]==ptr)
		{
			printf("This ID Is Already Reserved\n");
			EdDis(key);
		}
	}
	else if (ptr==NULL)
	{
		printf("This ID Is Not Exist -_-\n");
	}
}

void Reservation (u16 key,u8 choice)
{
	struct paitent * ptr;
	if(idsearch(key)!=NULL)
	{  
		if (choice==1)
		{
			ptr->date=choice;
			arr[0]=ptr;	
		}
		else if (choice==2)
		{
			ptr->date=choice;
			arr[1]=ptr;
		}
		else if (choice==3)
		{
			ptr->date=choice;
			arr[2]=ptr;
		}
		else if (choice==4)
		{
			ptr->date=choice;
			arr[3]==ptr;
		}
		else if (choice==5)
		{
			ptr->date=choice;
			arr[4]==ptr;
		}
	}
	else if (idsearch(key)==NULL)
	{
		printf("This Paitent Is Not Registered -_-\n");
	}
}

void CancelReserv (u16 key,u8 choice)
{
	struct paitent * ptr;
	ptr=idsearch(key);
	ptr->date=choice;
	if (ptr->date==1)
	{
		arr[0]=NULL;
	}
	else if (ptr->date==2)
	{
		arr[1]=NULL;
	}
	else if (ptr->date==3)
	{
		arr[2]=NULL;
	}
	else if (ptr->date==4)
	{
		arr[3]=NULL;
	}
	else if (ptr->date==5)
	{
		arr[4]=NULL;
	}
	
}

void UserDis (u16 key)
{
	struct paitent * ptr;
	if (idsearch(key)!=NULL)
	{
		ptr=idsearch(key);
		CheckPrint();
		printf("The paitent Reserve Slot Number : %d",ptr->date);
		if (arr[0]!=NULL)
		{
			printf("The paitent Reserve Slot Number : %d",arr[0]->date);
		}
		if (arr[1]!=NULL)
		{
			printf("The paitent Reserve Slot Number : %d",arr[1]->date);
		}
		if(arr[2]!=NULL)
		{
			printf("The paitent Reserve Slot Number : %d",arr[2]->date);
		}
		if(arr[3]!=NULL)
		{
			printf("The paitent Reserve Slot Number : %d",arr[3]->date);
		}
		if (arr[4]!=NULL)
		{
			printf("The paitent Reserve Slot Number : %d",arr[4]->date);
		}
	}
	else if (idsearch(key)==NULL)
	{
		printf("This ID Is Not Existed\n");
	}
}