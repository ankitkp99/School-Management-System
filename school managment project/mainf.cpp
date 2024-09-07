#include<stdio.h>
#include "principal.h"
#include "clerk.h"
#include "teacher.h"
#include "student.h"

int choice;
int pass2;
int main()
{	
	do
	{
		printf("\n1:Principal\n2:Clerk\n3:Teacher\n4:Student\n5:Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
//-----------------------------------------------------Case 1 Principal------------------------------------------------------------------
			case 1:
				int choice6;
				char uid[10],pass[10];
				printf("\nEnter username\n");
				_flushall();
				gets(uid);
				printf("\nEnter password\n");
				_flushall();
				gets(pass);                  
				
				if(auth_principal(uid,pass)==2)
				{
					printf("\n*** Logged in as Principal ***\n");
					do
					{
						printf("\n1:View all student record\n2:View all Teacher record\n3:View Time Table\n4:Set Notice\n5:Exit\n");
						printf("\nEnter a choice\n");
						scanf("%d",&choice6);
						
						switch(choice6)
						{
							case 1:
								display_student();
								break;
								
							case 2:
								display_teacher();
								break;
									
							case 3:
								time_table();
								break;
								
							case 4:
								int choice8;
								do
								{
									printf("\n1:Notice for all school\n2:Notice for teacher\n3:Display notice for all\n4:Display teachers notice\n");
									printf("5:Exit\n\nEnter a choice ");
									scanf("%d",&choice8);
									
									switch(choice8)
									{
										case 1:
											set_notice();
											break;
											
										case 2:
											teacher_notice();
											break;
											
										case 3:
											display_notice_all();
											break;
											
										case 4:
											display_notice_teacher();
											break;
												
										default :
											printf("\nExit\n");
									}
									
								}while(choice8>0 && choice8<5);
								break;
								
							default :
								printf("\nExit\n");
							 
						}
						
					}while(choice6>0 && choice6<5);
				}
				else
				printf("\n*** Login Failed ***\n");
				break;

//----------------------------------------------------------Case 2 Clerk---------------------------------------------------------------				
			case 2:
				int choice2,choice4;
				printf("\nEnter username\n");
				_flushall();
				gets(uid);
				printf("\nEnter password\n");
				_flushall();
				gets(pass);                  
				
				if(auth_clerk(uid,pass)==2)
				{
					printf("\n*** Logged in as clerk ***\n");
					do
					{
						printf("\n1:Student Section\n2:Teacher section\n3:Exit\n\nEnter a choice\n");
						scanf("%d",&choice);
						switch(choice)
						{
							case 1:
								do
								{
								printf("\n1:Add new student\n2:Update student details\n3:Delete Student\n4:Display student record\n");
								printf("5:Exit\n\nEnter a choice\n");
								scanf("%d",&choice2);
								
								switch(choice2)
								{
									case 1:
										add_student();
										break;
										
									case 2:
										update_student();
										break;
										
									case 3:
										delete_student();
										break;
										
									case 4:
										display_student();
										break;
								}
								}while(choice2>0 && choice2 <5);
							break;
						//------------------------------------------------------------------------------------------------------------------	
							case 2:
								do
								{
									printf("\n1:Add new Teacher\n2:Update Teacher Details\n3:Delete Teacher\n4:Dispaly Teachers details\n5:Exit\n");
									printf("\nEnter a choice ");
									scanf("%d",&choice4);
									
									switch(choice4)
									{
										case 1:
											add_teacher();
											break;
											
										case 2:
											update_teacher();
											break;
											
										case 3:
											delete_teacher();
											break;
											
										case 4:
											display_teacher();
											break;
									}
								}while(choice4>0 && choice4<5);
								break;
						}
					}while(choice>0 && choice<3);
				}
				else
				printf("\n*** Login Failed ***\n");
				break;
//------------------------------------------------------Case 3 Teacher---------------------------------------------------------------			
			case 3:
				int pass1,choice10;
				printf("\nEnter username\n");
				_flushall();
				scanf("%s",&uid);
				printf("\nEnter password\n");
				_flushall();
				scanf("%d",&pass1);
		
				if(teacher_login(uid,pass1)==1)
				{
					printf("\n\n*** Logged in as Teacher ***\n");
					
					do
					{
						printf("\n1:Time table\n2:Display Student\n3:Student Homework\n4:View Notice\n5:Set Notice for Student\n6:View Forum\n");
						printf("7:Exit\n\nEnter a choice ");
						scanf("%d",&choice10);
						
						switch(choice10)
						{
							case 1:
								time_table();
								break;
								
							case 2:
								display_student();
								break;
								
							case 3:
								student_homework();
								break;
								
							case 4:
								do
								{
									printf("\n1:Notice for All\n2:Notice for Teacher\n3:Exit");
									printf("\nEnter a choice ");
									scanf("%d",&choice10);
									
									switch(choice10)
									{
										case 1:
											display_notice_all();
											break;
											
										case 2:
											display_notice_teacher();
											break;
											
										default:
											printf("\nExit\n");		
									}
								}while(choice10>0 && choice10<3);
								break;
								
							case 5:
								int choice12;
								do
								{
									printf("\n1:Set notice for student\n2:Display student notice\n3:Exit\n");
									printf("\nEnter a choice ");
									scanf("%d",&choice12);
									
									switch(choice12)
									{
										case 1:
											set_student_notice();
											break;
											
										case 2:
											display_student_notice();
											break;
											
										default:
											printf("\nExit\n");
									}
								}while(choice12>0 && choice12<3);
								break;
								
							case 6:
								display_student_forum();
								break;
								
							default:
								printf("\nExit\n");
						}
						
						
					}while(choice10>0 && choice10<7);
				}
				else
				printf("\n*** Login Failed ***\n");
				break;
//------------------------------------------------------Case 4 Student---------------------------------------------------------------				
			case 4:
				
				char uid1[10];
				int choice9;
				printf("\nEnter username\n");
				_flushall();
				scanf("%s",&uid1);
				printf("\nEnter password\n");
				_flushall();
				scanf("%d",&pass2);
		
				if(student_login(uid1,pass2)==1)
				{
					printf("\n\n*** Logged in as Student ***\n");
					do
					{
						printf("\n1 :View Timetable\n2 :View Homework\n3 :View notice for all\n4 :View notice from teacher\n5 :Student forum\n");
						printf("6 :Exit\n\nEnter your choice :");
						scanf("%d",&choice9);
						
						switch(choice9)
						{
							case 1:
								time_table();
								break;
								
							case 2:
								display_student_homework();
								break;
								
							case 3:
								display_notice_all();
								break;
								
							case 4:
								display_student_notice();
								break;
								
							case 5:
								student_forum();
								break;
								
							default:
								printf("\nExit\n");
						}
					}while(choice9>0 && choice9<6);
				}
				else
				printf("\n*** Login Failed ***\n");
				break;

//--------------------------------------------------------------------------------------------------------------------------------------	
			default:
				printf("\nExit\n");
				break;
		}
	}while(choice>0 && choice<5);
	fclose(principal);
	fclose(clerk);
	fclose(teacher);
	fclose(student);	
}
