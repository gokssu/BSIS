// ConsoleApplication1.cpp : Konsol uygulamasý için giriþ noktasýný tanýmlar.
//

#include "stdafx.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct stu {      //We can explain a lot variables.
	char number[15];
	char name[15];
	char surname[15];
	char exam[15];
}myarray[100];
int x;
char searched[16];
char deleted[15] = "deleted";
int main() {
	FILE *folder; //This command : for opening file.
	int i = -1;
	folder = fopen("Project_3.txt", "a+"); //This open "Project_3.txt".
	while (!feof(folder)) //This function allows reading while end of folder.
	{
		i++;
		fscanf(folder, "%s\t%s\t%s\t%s", myarray[i].name, myarray[i].surname, myarray[i].number, myarray[i].exam);// This function reads datas from folder.
	}
	fclose(folder);// This function closes folder.
	int control = 0;
	while (1) {        // This part shows menu for program.
		printf("1. Add new record\n");
		printf("2. Search ID\n");
		printf("3. search byName\n");
		printf("4. delete ID\n");
		printf("5. update ID\n");
		printf("6 List registers\n");
		printf("7. exit\n");
		printf("Make a choice\n");
		int choice;
		scanf("%d", &choice);
		if (choice == 1)       //This take data from user.
		{
			printf("enter the name:");
			scanf("%s", &myarray[i].name);
			printf(".enter the surname:");
			scanf("%s", &myarray[i].surname);
			printf("enter the number:");
			scanf("%s", &myarray[i].number);
			printf("enter the exam note:");
			scanf("%s", &myarray[i].exam);
			i++; //This functions allows endless loop for adding new records.
		}
		else if (choice == 2) {  //This search with ID number.
			printf("Enter ID number which you want search\n");
			scanf("%s", searched);
			for (x = 0;x<i;x++)
			{
				if (strcmp(myarray[x].number, searched) == 0) //This make comparing all datas for finding ID number with "strcmp" function.
				{
					control = 1;
					printf("Found\n");
					printf("%s - %s - %s - %s\n", myarray[x].name, myarray[x].surname, myarray[x].number, myarray[x].exam);
					break; //This stop comparing when program find ID number.
				}
			}
			if (control == 0)
			{
				printf("Not Found\n");
			}
			control = 0;
		}
		else if (choice == 3) { //This search with Name.
			printf("Enter name which you want search\n");
			scanf("%s", searched);
			for (x = 0;x<i;x++)
			{
				if (strcmp(myarray[x].name, searched) == 0)//This make comparing all datas for finding Name with "strcmp" function.
				{
					control = 1;
					printf("Found\n");
					printf("%s - %s - %s - %s\n", myarray[x].name, myarray[x].surname, myarray[x].number, myarray[x].exam);
					break;//This stop comparing when program find ID number.
				}
			}
			if (control == 0)
			{
				printf("Not Found\n");
			}
			control = 0;
		}

		else if (choice == 4) { // This delete with ID number.
			printf("Enter ID number which you want delete \n");
			scanf("%s", searched);
			for (x = 0;x<i;x++)
			{
				if (strcmp(myarray[x].number, searched) == 0)//This make comparing all datas for deleting with ID number with "strcmp" function.
				{
					control = 1;
					strcpy(myarray[x].name, deleted);//This function "strcpy" delete name.
					strcpy(myarray[x].surname, deleted);//This function "strcpy" delete surname.
					strcpy(myarray[x].exam, deleted);//This function "strcpy" delete exam.
					break;
				}
			}
			if (control == 0)
			{
				printf("Not Found\n");
			}
			control = 0;
		}
		else if (choice == 5) //This function update with ID number
		{
			printf("Enter ID number which you want update \n");
			scanf("%s", searched);
			for (x = 0;x<i;x++)
			{
				if (strcmp(myarray[x].number, searched) == 0)
				{
					control = 1;
					printf("Enter a name\n");
					scanf("%s", myarray[x].name);
					printf("Enter a surname\n");
					scanf("%s", myarray[x].surname);
					printf("Enter a exam\n");
					scanf("%s", myarray[x].exam);
					break;
				}
			}
			if (control == 0)
			{
				printf("Not Found\n");
			}
			control = 0;
		}
		else if (choice == 6)// This part make list register.
		{
			printf("Name-Surname-Number-Exam\n");
			for (x = 0;x<i;x++)
			{
				printf("%s -  %s  -  %s  -   %s\n", myarray[x].name, myarray[x].surname, myarray[x].number, myarray[x].exam);
			}
			printf("");
		}

		else if (choice == 7) {//This part exit from program.
			break;
		}
	}
	folder = fopen("Project_3.txt", "w");//"w" allows writing all command in "Project_3.txt".
	for (x = 0;x<i;x++)
	{
		fprintf(folder, "%s\t%s\t%s\t%s\n", myarray[x].name, myarray[x].surname, myarray[x].number, myarray[x].exam);
	}
	fclose(folder);//This function close folder.
}