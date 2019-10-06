#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int date ;
	int month ;
	int year ;
}d;
typedef struct{
	int s;
	int e;
}em;
typedef struct{
	char name[20];
	d dob ;
	em id ; 
	char dep[20]; 
	int sal ;
}emp1,emp;
void input (emp1 *s , int cnt)
{
	FILE *ptr ;
	ptr = fopen("E:\\newprogram.txt","a");
	fflush(stdin);
	if (cnt==0)
	s=(emp *)calloc(1,sizeof(emp));
	else
	s=(emp *)realloc(s,(cnt+1)*sizeof(emp));
	printf("Enter the name of the Employee\n");
	gets((s+cnt)->name);
	fprintf(ptr,"%s",(s+cnt)->name);
	fflush(stdin);
	printf("Enter the DATE OF BIRTH(1/1/2014)\n");
	scanf("%d/%d/%d",&(s+cnt)->dob.date,&(s+cnt)->dob.month,&(s+cnt)->dob.year);
	fprintf(ptr,"\t%d/%d/%d",(s+cnt)->dob.date,(s+cnt)->dob.month,(s+cnt)->dob.year);
	printf("Enter the ID of the Employee(12-1235)\n");
	fflush(stdin);
	scanf("%d-%d",&(s+cnt)->id.s,&(s+cnt)->id.e);
	fprintf(ptr,"\t%d-%d",(s+cnt)->id.s,(s+cnt)->id.e);
	fflush(stdin);
	printf("Enter the DEPARTMENT of the Employee\n");
	gets((s+cnt)->dep);
	fprintf(ptr,"\t%s",(s+cnt)->dep);
	fflush(stdin);
	printf("Enter the SALARY of the Employee\n");
	scanf("%d",&(s+cnt)->sal);
	fprintf(ptr,"\t%d\n",(s+cnt)->sal);
	fflush(stdin);
	fclose(ptr) ;
}
void display()
{
	printf("\nNAME\tD-O-B\tID\tDEPRAT\tSALARY\n");
	FILE *fptr ;
	char ch ;
	fptr = fopen("E:\\newprogram.txt","r");
	ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf ("%c", ch);
        ch = fgetc(fptr);
	}
    fclose(fptr);
}
void del()
{
	char ch[10],ch1[15],ch2; FILE *fptr,*ptr; int temp=0 , a ;
	printf("ENTER THE NAME OF THE EMPLOYEE\n");
	fflush(stdin);
	gets(ch);
	fptr = fopen("E:\\newprogram.txt","r");
	fscanf(fptr,"%s",&ch1);
    while (ch2!= EOF)
    {
        if (strcmp(ch,ch1)==0)
        {
        	a = temp ;
        	temp = 100 ;
        	break ;
		}
		fscanf(fptr,"%s",&ch1);
		ch2 = getc(fptr);
		if (ch2=='\n')
		++temp ;
	}
	if (temp==100){
    temp = 0 ;
	rewind(fptr) ;
	ptr = fopen("E://NEW.txt","w");
	ch2 = getc(fptr);
	while (ch2!=EOF){
		if (temp!=a){
			putc(ch2,ptr);
		}
		if (ch2=='\n')
		++temp ;
		ch2 = getc(fptr);	
	}
	fclose(fptr);
	fclose(ptr);
    remove("E:\\newprogram.txt");
    strcpy(ch,"NEW.txt");
    strcpy(ch1,"newprogram.txt");
	rename(ch,ch1);
	printf("SUCCESSFULLY DELETED\n");
	}
	else{
	fclose(fptr);
	printf("WRONG INPUT\n");
	del();	
	}
}
void name(){
	char ch2[20] , ch1[50]  = {0},ch;
	int f=1 ;
	FILE *fptr;
	printf("\nENTER THE NAME OF THE EMPLOYEE\n");
	fflush(stdin);
	gets(ch2);
	fptr = fopen("E:\\newprogram.txt","r");
	fscanf(fptr,"%s",&ch1) ;
    while (ch!= EOF)
    {
        if ((strcmp(ch1,ch2))==0)
        {
        	f=0 ;
        	printf("%s\t",ch2);
        	ch = fgetc(fptr);
   			while (ch != '\n')
   			{
        		printf ("%c", ch);
        		ch = fgetc(fptr);
			}
   			fclose(fptr);
   			break ;
		}
		fscanf(fptr,"%s",ch1);
		ch = getc(fptr);
	}
	if (f==1){
	fclose(fptr);
	printf("WRONG INPUT\n");
	name();	
	}
}
void update(){
	int q=0,f=0,a=0 ;
	char ch1[50]  = {0} ,ch,ch2[15];
	printf("ENTER THE NAME OF THE EPMLOYEE TO UPDATE HIS REOCRD\n");
	fflush(stdin);
	gets(ch2);
	FILE *fptr,*ptr;
	fptr = fopen("E:\\newprogram.txt","r");
	ptr = fopen("E://NEW.txt","w");
    while (ch!= EOF)
    {
        if ((strcmp(ch1,ch2))==0)
        {
        	fscanf(fptr,"%s",&ch1) ;
        	fprintf(ptr,"%s\t",ch1);
        	fscanf(fptr,"%s",&ch1) ;
        	fprintf(ptr,"%s\t",ch1);
        	fscanf(fptr,"%s",&ch1) ;
        	fprintf(ptr,"%s\t",ch1);
			printf("ENTER THE SALARY : ");
			scanf("%d",&a);
			fprintf(ptr,"%d",a);
			fscanf(fptr,"%s",&ch1) ;
			f=1;
			a=1;
		}
		else if (f!=1){
			q = fscanf(fptr,"%s",ch1);
			if (q==1)
			fprintf(ptr,"%s",ch1);
		}
		f=0 ;
		ch = getc(fptr);
		if(ch=='\n')
		fprintf(ptr,"\n");
		else if (ch=='\t')
		fprintf(ptr,"\t");
	}
	fclose(fptr);
	fclose(ptr);
    remove("E:\\newprogram.txt");
    strcpy(ch2,"NEW.txt");
    strcpy(ch1,"newprogram.txt");
	rename(ch2,ch1);
	if (a!=1){
	printf("WRONG INPUT\n");
	update();	
	}
}
void main ()
{
	int u  ,cnt=0;
	emp *ptr ;
	do{
	printf("\n1:ADD AN EMPLOYEE\n2:DELETE AN EMPLOYEE\n3:DISPLAY ALL EMPLOYEE\n4:FIND EMPLOYEE BY NAME\n5:UPDATE AN EMPLOYEE\n6:EXIT\n");
	scanf("%d",&u);
		if (u==1)
		{
			input(ptr,cnt);
			++cnt;
		}
		else if (u==2)
		del();
		else if (u==3)
		display();
		else if (u==4)
		name();
		else if (u==5)
		update();
	}while (u!=6);
}
