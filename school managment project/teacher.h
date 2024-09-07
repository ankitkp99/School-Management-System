#include<stdio.h>
#include<string.h>
FILE *teacher;
FILE *notice_student;
FILE *homework;
struct teacher1
{
	int id;
	char name[20];
	char add[20];
	int salary;
};
struct teacher1 t1;
//-------------------------------------------Teacher Login---------------------------------------------------------------------

int teacher_login(char a[], int b)
{
	int flag=0;
	teacher=fopen("clerk1.txt","r");
	
	while(fscanf(teacher,"%d%s%s%d",&t1.id,&t1.name,&t1.add,&t1.salary) != -1)
	{
		if(strcmp(a,t1.name)==0 && b==t1.id)
		{
			printf("\nId     : %d\nName   : %s\nAdress : %s",t1.id,t1.name,t1.add);
			return 1;
		}
	}
	fclose(teacher);
}

//-------------------------------------------Time Table---------------------------------------------------------------------

void time_table()
{
	char time_table[500];
	printf("\n-------------------------------------------------Time-table-----------------------------------------------\n");
	printf("\nDay\t\tMonday   \tTuesday  \tWednesday\tThursday \tFriday   \tSaturday \nTime\n\n");
	printf("8-9   AM\tMarathi  \tMaths    \tHindi    \tScience  \tEnglish  \tP.T.     \n");
	printf("9-10  AM\tMaths    \tScience  \tGeography\tHistory  \tMaths    \tHindi    \n");
	printf("10-11 AM\tScience  \tHindi    \tMaths    \tEnglish  \tHistoty  \tMaths    \n");
	printf("\n11-12 PM\t\t\t\t\t**** Break ****\n\n");
	printf("12-1  PM\tGeography\tP.T.     \tScience  \tMarathi  \tScience  \tGeography\n");
	printf("1-2   PM\tP.T.     \tHistory  \tEnglish  \tMaths    \tMarathi  \tP.T.     \n");
	printf("\n----------------------------------------------------------------------------------------------------------\n");
}

//-------------------------------------------Notice for Student---------------------------------------------------------------------

char notice2[500];
void set_student_notice()
{
	printf("Write a notice for student\n");
	fflush(stdin);
	gets(notice2);
	
	notice_student = fopen("Student_notice.txt","w");
	fprintf(notice_student, "%s\n", notice2);
    printf("\n*** Notice sent!! ***\n");
    fclose(notice_student);
}

//-----------------------------------------------------------Display notice all function----------------------------------------------------
void display_student_notice()
{
	notice_student = fopen("Student_notice.txt","r");
	printf("\n*** NOTICE FOR STUDENT ***\n");
	
	while (fscanf(notice_student, "%s", notice2) != EOF)
	{
        printf("%s ", notice2);
    }
    printf("\n");
    fclose(notice_student);
}

//-------------------------------------------Homework for Student---------------------------------------------------------------------

char notice3[500];
void student_homework()
{
	printf("Give Homework to student \n");
	fflush(stdin);
	gets(notice3);
	
	homework = fopen("Homework.txt","w");
	fprintf(homework, "%s\n", notice3);
    printf("\n*** Homework assigned!! ***\n");
    printf("\n%s\n\n",notice3);
    fclose(homework);
}

//-----------------------------------------------------------Display homework function----------------------------------------------------
void display_student_homework()
{
	homework = fopen("Homework.txt","r");
	printf("\n*** HOMEWORK ***\n");
	
	while (fscanf(homework, "%s", notice3) != EOF)
	{
        printf("%s ", notice3);
    }
    printf("\n");
    fclose(homework);
}














