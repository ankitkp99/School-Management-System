#include<stdio.h>
#include<string.h>
FILE *student;
FILE *s_forum;

struct student1
{
	int id;
	char name[20];
	char add[20];
};
struct student1 s1;
//-------------------------------------------Student Login---------------------------------------------------------------------

int student_login(char a[], int b)
{
	student=fopen("clerk.txt","r");
	
	while(fscanf(student,"%d%s%s",&s1.id,&s1.name,&s1.add) != EOF)
	{	
		if( b==s1.id && strcmp(a,s1.name)==0 )
		{
			printf("\nId     : %d\nName   : %s\nAdress : %s",s1.id,s1.name,s1.add);
			return 1;
		}
	}
	fclose(student);
}

//-------------------------------------------Student forum---------------------------------------------------------------------

char forum[500];
void student_forum()
{
	printf("Ask your doubt\n");
	fflush(stdin);
	gets(forum);
	
	s_forum = fopen("Student_forum.txt","a");
	fprintf(s_forum, "%s\n\n", forum);
    printf("\n*** Forum submitted !! ***\n");
    printf("\n%s\n\n",forum);
    fclose(s_forum);
}

//--------------------------------------------Display Student forum Function----------------------------------------------------

void display_student_forum()
{
	s_forum = fopen("Student_forum.txt","r");
	printf("\n*** Doubts ***\n");
	
   		printf("\n");
	while (fscanf(s_forum, "%s", forum) != EOF)
	{
        printf("%s ", forum);
    }
    fclose(s_forum);
}

