#include<stdio.h>
#include<string.h>
FILE *principal;
FILE *notice_all;
FILE *notice_teacher;

//-----------------------------------------------------------Authentication Principal------------------------------------------------
int auth_principal(char x[],char y[])
{
	char name[]="admin";
	if(strcmp(name,x)==0 )
	{
		if(strcmp(name,y)==0)
			return 2;
		else
			return 0;
	}
	else
		return 0;
}
//-----------------------------------------------------------Notice all function --------------------------------------------------------
char notice[500];
char notice1[500];
void set_notice()
{
	printf("Write a notice for all\n");
	fflush(stdin);
	gets(notice);
	
	notice_all = fopen("Notice_all.txt","w");
	fprintf(notice_all, "%s\n", notice);
    printf("\n*** Notice sent!! ***\n");
    fclose(notice_all);
}
//-----------------------------------------------------------Display notice all function----------------------------------------------------
void display_notice_all()
{
	notice_all = fopen("Notice_all.txt","r");
	printf("\n*** NOTICE ***\n");
	
	while (fscanf(notice_all, "%s", notice) != EOF)
	{
        printf("%s ", notice);
    }
    printf("\n");
    fclose(notice_all);
}
//-----------------------------------------------------------Notice for teacher function ------------------------------------------------------
void teacher_notice()
{
	notice_teacher = fopen("techaer_notice.txt","w");
	printf("Write a notice teacher\n");
	fflush(stdin);
	fprintf(notice_teacher,"%s",gets(notice1));
	printf("\n*** Notice send!! ***\n");
	fclose(notice_teacher);
}
//-----------------------------------------------------------Display notice all function--------------------------------------------------------
void display_notice_teacher()
{
	notice_teacher = fopen("techaer_notice.txt","r");
	printf("\n*** NOTICE ***\n");
	while (fscanf(notice_teacher, "%s", notice1) != EOF)
	{
        printf("%s ", notice1);
    }
    printf("\n");
    fclose(notice_teacher);
}
