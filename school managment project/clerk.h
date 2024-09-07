#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE *clerk;
struct student
{
	int id;
	char name[20];
	char address[20];
};
struct student s,temp;
int choice1,choice3;// for clerk section odd choice is used

//-------------------------------------------Auth clerk-------------------------------------------
int auth_clerk(char x[],char y[])
{
	if(strcmp("admin",x)==0 )
	{
		if(strcmp("admin",y)==0)
			return 2; // strcmp give op as 1 -1 0;
		else
			return 0;
	}
}

//--------------------------------------add student function--------------------------------------

void add_student()
{
	int roll,flag =0;
	clerk=fopen("clerk.txt","r");
	printf("\nEnter student information\n");
	printf("\nEnter roll no of student\n");
	scanf("%d",&roll);
	while(fscanf(clerk,"%d%s%s",&s.id,&s.name,&s.address) != -1)//EOF or -1
	{
		if(s.id==roll)
		flag =1;
    }
    if(flag==0)
    {
		clerk=fopen("clerk.txt","a");
		s.id=roll;
		fprintf(clerk,"%d\t",s.id);
		printf("Enter name of student\n");
		_flushall();
		gets(s.name);
		fprintf(clerk,"%s\t",s.name);
		printf("Enter address of student\n");
		_flushall();
		gets(s.address);
		fprintf(clerk,"%s\n",s.address);
		
		printf("\n\n%d\t%s\t%s\n",s.id,s.name,s.address);
		printf("\n*** Student record added successfully ***\n");
		fclose(clerk);
	}
	else
	{
		printf("\n!!! Id %d is alredy exist !!!\n",roll);
	}
	fclose(clerk);
}

//----------------------------------------------array size fot student--------------------------------------------

int counter_array()
{
	int counter =0;
	clerk=fopen("clerk.txt","r");
	
	while(fscanf(clerk,"%d%s%s",&s.id,&s.name,&s.address) != -1)
	{
		counter++;
	//	printf("%d\t%s\t%s\n",s.id,s.name,s.address);
	}
	
	fclose(clerk);
	return counter;
}

//-------------------------------------update student fuction--------------------------------------------

void update_student()
{
	int array_size = counter_array();
	struct student ptr[array_size];
	int roll,count=0;
	char name[20];
	clerk=fopen("clerk.txt","r");
		
	printf("\nEnter roll no and name of student to update\n");
	scanf("%d",&roll);
	_flushall();
	gets(name);
	

//	ptr = (struct student *) malloc(sizeof(struct student)*counter);
	int i=0;
	
	while(fscanf(clerk,"%d%s%s",&s.id,&s.name,&s.address) != -1)
	{
		if(strcmp(name,s.name)==0 && s.id==roll)
		{
			ptr[i] = s;
			printf("\n%d\t%s\t%s\n",ptr[i].id,ptr[i].name,ptr[i].address);
			
			count++; // if count is zero it will print student not found
			do
			{
				printf("\n1:Update Name\n2:Update Roll No\n3:Update Address\n4:Exit\n");
				printf("\nEnter a choice ");
				scanf("%d",&choice1);
				switch(choice1)
				{
					case 1:
						char new_name[10];
						printf("Enter new name\n");
						fflush(stdin);
						gets(new_name);
						strcpy(ptr[i].name,new_name);
						printf("\n%d\t%s\t%s\n",ptr[i].id,ptr[i].name,ptr[i].address);
						printf("\n*** Name Updated Successfully ***\n");
						
						break;
						
					case 2:
						int new_id,count1;
						count1=0;
						printf("Enter new Id\n");
						scanf("%d",&new_id);
						for(int j=0; j<array_size; j++)
						{
							if(ptr[i].id != new_id)
							{
								count1++;
								ptr[i].id = new_id;
								printf("\n%d\t%s\t%s\n",ptr[i].id,ptr[i].name,ptr[i].address);
								printf("\n*** Id Updated Successfully ***\n");							
							}
						}
						if(count1==0)
						{
							printf("\n%d Id is alredy exist\n",ptr[i].id);
						}						
						break;
					
					case 3:
						char new_add[10];
						printf("Enter new Address\n");
						fflush(stdin);
						gets(new_add);
						strcpy(ptr[i].address,new_add);
						printf("\n%d\t%s\t%s\n",ptr[i].id,ptr[i].name,ptr[i].address);
						printf("\n*** Address Updated Successfully ***\n");
						break;
					
					default :
						printf("\nExit\n");		
				}
				
			}while(choice1>0 && choice1<4);	
		}
		else
		{
			ptr[i] = s;
		}
		i++;
	
	}
	fclose(clerk);
	
	clerk=fopen("clerk.txt","w");
	for(int i=0;i<array_size;i++)
	{
		fprintf(clerk,"%d\t%s\t%s\n",ptr[i].id,ptr[i].name,ptr[i].address);
	}
	
	if(count==0)
	{
		printf("\n!!! Student not found !!!\n");
	}
	fclose(clerk);	
}

//-------------------------------------------------Delete Student Function--------------------------------------------

void delete_student()
{
	int array_size = counter_array();
	int roll,i=0,counts=0;
	char name[20];
	struct student ptr[array_size];
	printf("\nEnter roll no and name of student to delete\n");
	scanf("%d",&roll);
	_flushall();
	gets(name);
	
	clerk=fopen("clerk.txt","r");
	while(fscanf(clerk,"%d%s%s",&s.id,&s.name,&s.address) != -1)
	{

		if(strcmp(name,s.name)==0 && s.id==roll)
		{
			printf("\n%d\t%s\t%s\n",s.id,s.name,s.address);
			printf("\n*** Student record deleted successfully ***\n");
			counts++;
		}
		else
		{
			ptr[i] = s;
			i++;
		}
	}
	fclose(clerk);

	clerk=fopen("clerk.txt","w");
	for(int b=0; b<i; b++)
	{
		fprintf(clerk,"%d\t%s\t%s\n",ptr[b].id,ptr[b].name,ptr[b].address);
	}
	
	if(counts==0)
	{
		printf("\n!!! Student not found !!!\n");
	}
	fclose(clerk);		
}

//-------------------------------------------------Display Student Function--------------------------------------------

void display_student()
{
	int array_size = counter_array();
	int i=0,j,k;
	struct student ptr[array_size];
	clerk=fopen("clerk.txt","r");
	
	while(fscanf(clerk,"%d%s%s",&s.id,&s.name,&s.address) != -1)
	{
		ptr[i++] = s;
	
	}

	fclose(clerk);
	
	for(k=0; k<array_size; k++)
	{
		for(j=k+1; j<array_size; j++)
		{
			if(ptr[k].id > ptr[j].id)
			{
				temp = ptr[k];
				ptr[k] = ptr[j];
				ptr[j] = temp;
			}
		}
	}

//	for(i=0; i<array_size; i++)
//	{
//		printf("%d\t%s\t%s\n",ptr[i].id,ptr[i].name,ptr[i].address);
//	}
	
	clerk=fopen("clerk.txt","w+");
	for(i=0;i<array_size;i++)
	{
		fprintf(clerk,"%d\t%s\t%s\n",ptr[i].id,ptr[i].name,ptr[i].address);
	}
	rewind(clerk);
	while(fscanf(clerk,"%d%s%s",&s.id,&s.name,&s.address) != -1)
	{
		printf("\t%d\t%s\t%s\n",s.id,s.name,s.address);
	
	}
	fclose(clerk);
	
}

//**************************************************                 ***********************************************************
//************************************************** Teacher section ***********************************************************


FILE *clerk1;
struct teacher
{
	int id;
	char name[20];
	char address[20];
	int salary;
};
struct teacher t,temp1;

//--------------------------------------add teacher function--------------------------------------

void add_teacher()
{
	int id,flag =0;
	clerk1=fopen("clerk1.txt","r");
	printf("\nEnter teacher information\n");
	printf("\nEnter id of teacher\n");
	scanf("%d",&id);
	while(fscanf(clerk1,"%d%s%s%d",&t.id,&t.name,&t.address,&t.salary) != -1)
	{
		if(t.id==id)
		flag =1;
	}	
	if(flag==0)	
	{
		clerk1=fopen("clerk1.txt","a");
		t.id=id;
		fprintf(clerk1,"%d\t",t.id);
		printf("Enter name of teacher\n");
		_flushall();
		gets(t.name);
		fprintf(clerk1,"%s\t",t.name);
		printf("Enter address of teacher\n");
		_flushall();
		gets(t.address);
		fprintf(clerk1,"%s\t",t.address);
		printf("Enter salary of teacher \n");
		scanf("%d",&t.salary);
		fprintf(clerk1,"%d\n",t.salary);
		
		printf("\n\n%d\t%s\t%s\t%d\n",t.id,t.name,t.address,t.salary);
		printf("\n*** Teacher record added successfully ***\n");
		fclose(clerk1);
	}
	else
	{
		printf("\n!!! Id %d is alredy exist !!!\n",id);
	}
	fclose(clerk1);
}

//----------------------------------------------array size for teachers--------------------------------------------


int counter_data()
{
	int counter1 = 0;
	clerk1=fopen("clerk1.txt","r");
	
	while(fscanf(clerk1,"%d%s%s%d",&t.id,&t.name,&t.address,&t.salary) != -1)
	{
		counter1++;
		
	}
	fclose(clerk1);
	return counter1;
}

//-------------------------------------update teacher fuction--------------------------------------------

void update_teacher()
{
	int array_size1 = counter_data();
	struct teacher ptr[array_size1];
	int id,count=0;
	char name[20];
	clerk1=fopen("clerk1.txt","r");
	
	printf("\nEnter ID and name of teacher to update\n");
	scanf("%d",&id);
	fflush(stdin);
	gets(name);
	
	int i=0;
	
	while(fscanf(clerk1,"%d%s%s%d",&t.id,&t.name,&t.address,&t.salary) != -1)
	{
		if(strcmp(name,t.name)==0 && t.id==id)
		{
			ptr[i] = t;
			printf("\n%d\t%s\t%s\t%d\n",ptr[i].id,ptr[i].name,ptr[i].address,ptr[i].salary);
			
			count++; // if count is zero it will print student not found
			do
			{
				printf("\n1:Update Name\n2:Update ID\n3:Update Address\n4:Update Salary\n5:Exit\n");
				printf("\nEnter a choice ");
				scanf("%d",&choice3);
				switch(choice3)
				{
					case 1:
						char new_name[10];
						printf("Enter new name\n");
						fflush(stdin);
						gets(new_name);
						strcpy(ptr[i].name,new_name);
						printf("\n%d\t%s\t%s\t%d\n",ptr[i].id,ptr[i].name,ptr[i].address,ptr[i].salary);
						printf("\n*** Name Updated Successfully ***\n");
						
						break;
						
					case 2:
						int new_id,count1;
						count1=0;
						printf("Enter new Id\n");
						scanf("%d",&new_id);
						for(int j=0; j<array_size1; j++)
						{
							if(ptr[i].id != new_id)
							{
								count1++;
								ptr[i].id = new_id;
								printf("\n%d\t%s\t%s\t%d\n",ptr[i].id,ptr[i].name,ptr[i].address,ptr[i].salary);
								printf("\n*** Id Updated Successfully ***\n");
								
							}
						}
						if(count1==0)
						{
							printf("\n%d Id is alredy exist\n",ptr[i].id);
						}
						
						break;
					
					case 3:
						char new_add[10];
						printf("Enter new Address\n");
						fflush(stdin);
						gets(new_add);
						strcpy(ptr[i].address,new_add);
						printf("\n%d\t%s\t%s\t%d\n",ptr[i].id,ptr[i].name,ptr[i].address,ptr[i].salary);
						printf("\n*** Address Updated Successfully ***\n");
						break;
						
					case 4:
						int new_salary;
						printf("\nEnter a new  salary\n");
						scanf("%d",&new_salary);
						ptr[i].salary = new_salary;
						printf("\n%d\t%s\t%s\t%d\n",ptr[i].id,ptr[i].name,ptr[i].address,ptr[i].salary);
						printf("\n*** Salary Updated Successfully ***\n");
						break;
					
					default :
						printf("\nExit\n");		
				}
				
			}while(choice3>0 && choice3<5);	
		}
		else
		{
			ptr[i] = t;
		}
		i++;
	
	}
	fclose(clerk1);
	
	clerk1=fopen("clerk1.txt","w");
	for(int i=0;i<array_size1;i++)
	{
		fprintf(clerk1,"%d\t%s\t%s\t%d\n",ptr[i].id,ptr[i].name,ptr[i].address,ptr[i].salary);
	}
	
	if(count==0)
	{
		printf("\n!!! Teacher not found !!!\n");
	}
	fclose(clerk1);	
}

//-------------------------------------------------Delete Teacher Function -------------------------------------------

void delete_teacher()
{
	int array_size1 = counter_data();
	int id,i=0,counts=0;
	char name[20];
	struct teacher ptr[array_size1];
	printf("\nEnter roll no and name of teacher to delete\n");
	scanf("%d",&id);
	_flushall();
	gets(name);
	
	clerk1=fopen("clerk1.txt","r");
	while(fscanf(clerk1,"%d%s%s%d",&t.id,&t.name,&t.address,&t.salary) != -1)
	{

		if(strcmp(name,t.name)==0 && t.id==id)
		{
			printf("\n%d\t%s\t%s\t%d\n",t.id,t.name,t.address,t.salary);
			printf("\n*** Teacher record deleted successfully ***\n");
			counts++;
		}
		else
		{
			ptr[i] = t;
			i++;
		}
	}
	fclose(clerk1);

	clerk1=fopen("clerk1.txt","w");
	for(int b=0; b<i; b++)
	{
		fprintf(clerk1,"%d\t%s\t%s\t%d\n",ptr[b].id,ptr[b].name,ptr[b].address,ptr[b].salary);
	}
	
	if(counts==0)
	{
		printf("\n!!! Teacher not found !!!\n");
	}
	fclose(clerk1);		
}

//-------------------------------------------------Display Teacher Function--------------------------------------------

void display_teacher()
{
	int array_size1 = counter_data();
	int i=0,j,k;
	struct teacher ptr[array_size1];
	clerk1=fopen("clerk1.txt","r");
	
	while(fscanf(clerk1,"%d%s%s%d",&t.id,&t.name,&t.address,&t.salary) != -1)
	{
		ptr[i++] = t;
	}

	fclose(clerk1);
	
	for(k=0; k<array_size1; k++)
	{
		for(j=k+1; j<array_size1; j++)
		{
			if(ptr[k].id > ptr[j].id)
			{
				temp1 = ptr[k];
				ptr[k] = ptr[j];
				ptr[j] = temp1;
			}
		}
	}
	
	clerk1=fopen("clerk1.txt","w+");
	for(int i=0;i<array_size1;i++)
	{
		fprintf(clerk1,"%d\t%s\t%s\t%d\n",ptr[i].id,ptr[i].name,ptr[i].address,ptr[i].salary);
	}
	rewind(clerk1);
	while(fscanf(clerk1,"%d%s%s%d",&t.id,&t.name,&t.address,&t.salary) != -1)
	{
		printf("\t%d\t%s\t%s\t%d\n",t.id,t.name,t.address,t.salary);
	}
	fclose(clerk1);	
}





