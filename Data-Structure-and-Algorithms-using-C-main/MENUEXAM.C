#include<stdio.h>
#include<conio.h>
#define MAX 100
struct student
{
   int id;
   char name[50];
   int roll;
   char phone[10];
   char grade[20];
};
struct student list[MAX];
int counter=0;//initially no student is there
void addStudent(){
  printf("Welcome to Student Registration Part:");
  printf("\nEnter your Id: ");
  scanf("%d",&list[counter].id);
  fflush(stdin);
  printf("\nEnter your name: ");
  gets(list[counter].name);
  printf("\nEnter your roll number: ");
  scanf("%d",&list[counter].roll);
  printf("\nEnter your phone number: ");
  scanf("%s",list[counter].phone);
  fflush(stdin);
  printf("\nEnter your grade: ");
  gets(list[counter].grade);
  counter++;
  printf("\n\nRegistration successful.");
}
void removeStudent()
{
	int id,i,j;
	{
  printf("id of student:");
  scanf("%d",&id);
  for(i=0;i<counter;i++);
  {
   if(list[i].id==id)//student found with the given id
{
   //delete the record by shifting all remaining by one position left
   for(j=i+1;j<counter;j++)
{
list[j-1]=list[j];//copy jth record to its left
}
counter--;
printf("Student record removed sucessfully.");
}
return;
}
printf("Student record with the given id does not exists.");
}
}
void editStudent()
{
int id,i;
printf("Enter the id to update: ");
scanf("%d",&id);
for(i=0;i<counter;i++);
{
	if(list[i].id==id)// if id is matched
	{
		printf("Enter Name: ");
		scanf("%s",list[i].name);
		printf("Enter roll no: ");
		scanf("%d",&list[i].roll);
		printf("Enter Phone:");
		scanf("%s",list[i].phone);
		printf("Enter grade:");
		scanf("%s",list[i].grade);
		return;
	}
	 printf("update sucessful...");
}
}
void listStudents()
{
   int i;
   if(counter==0)
     printf("List is empty.");
   else
   {
      printf("List of Student\n\n");
      printf("Id\tName of Student\tRoll No.\tPhone No.\tGrade\n");
      for(i=0;i<counter;i++)
      {
	 printf("%d\t%s\t%d\t%s\t\t%s\n",list[i].id,list[i].name,list[i].roll,list[i].phone,list[i].grade);
      }
   }
}
void saveStudent()
{
   FILE *fp;
   fp=fopen("stdlist","wb");
   if(fp!=NULL)
   {
     fwrite(list,sizeof(struct student),counter,fp);
     fclose(fp);
   }
}
void readStudent()
{
   FILE *fp;
   fp=fopen("stdlist","rb");
   if(fp!=NULL)
   {
     while(feof(fp)==0)
     {
	if(fread(&list[counter],sizeof(struct student),1,fp)==1)
	  counter++;
     }
     fclose(fp);
   }
}
int main()
{
   char choice;
   readStudent();//read everything from file just before showing anything
   while(1)
   {
      printf("Select an option:\n");
      printf("1. Register New Student\n2. Update Student Record\n");
      printf("3. Remove A Student\n4. List All Student\n5. Exit");
      choice=getche();
      
      	switch(choice)
      {
	 case '1': addStudent();break;
	 case '2':break;
	 case '3':removeStudent();break;
	 case '4':listStudents();break;
	 case '5':readStudent();break;
	 printf("Are you sure to quit[Y|N]");
	 choice=getche();
	 if(choice=='Y' ||choice=='y')
	 {
	   saveStudent();//save everything to disk before closing
	   return 0;
	 }
      }
      getch();
   }
}
