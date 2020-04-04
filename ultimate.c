#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
int indexOf(FILE *fptr, char *new,int *line, int *col);
int indexOf2(FILE *fptr, const char *new, int *line, int *col);
int exist(char new[11]);
void createc();
void editc();
int existc();
void createi();
int existi(char new[11]);
int indexOfi(FILE *fptr, char *n,int *line, int *col);
void updi();
struct custo
{
	char mobileno[51];
	char customername[50];
}custo;
struct item
{
	char productno[8];
	char productname[10];
	int quantity;
	int price;
}
item;
int main()
{
	char ch,password[10],q[10]="kedars";
	int s,y=0,w=1,i,n,o=0;
	FILE *quan;
	quan=fopen("Quantity1.txt","r");
	fscanf(quan,"%d",&n);
	fclose(quan);
	printf("\n");
	w:printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("--------------------------------------------    WELCOME   -------------------------------------------------------------\n");
    //printf("\t\t\t\t\t      Reference Number: %d\n",n);
    printf("\t---------------------------\n");
    printf("\t|Please Select an Option: |\n");
    printf("\t---------------------------\n");
	printf("\t01. LOGIN\n");
	printf("\t02. EXIT\n\n");
	printf("\tPlease Enter an Option: ");
	scanf("%d",&s);
    switch(s)
	{
	          case 1: printf("\tEnter Password:\t");
              for(i=0;i<6;i++)
              {
              ch = getch();
              password[i] = ch;
              ch = '*' ;
               printf("%c",ch);
              }
              password[i]='\0';
              if(strcmp(password,q))
              {
                printf("\n\t");
                printf("Wrong Password Please Try Again");
                printf("\n\n");
                goto w;
             }
            printf("\n\t");
            printf("Access Granted\n\n\n");
            q: printf("\t----------------------------\n");
            printf("\tPlease Select an Option: \n");
            printf("\t----------------------------\n");
		    printf("\t01.ADMIN\n");
		    printf("\t02.BILLING\n");
		    printf("\t03.EXIT\n");
		    printf("\tPlease Enter an Option: ");
		    scanf("%d",&y);
		    switch(y)
		        {
                  case 1:printf("\t----------------------------\n");
               printf("\tPlease Select an Option: \n");
               printf("\t----------------------------\n");
		       printf("\t01.CREATE CUSTOMER\n");
		       printf("\t02.DISPLAY CUSTOMER\n");
		       printf("\t03.CREATE ITEM\n");
		       printf("\t04.DELETE/MODIFY ITEM\n");
		       printf("\t05.DISPLAY ITEM\n");
		       printf("\t06.MAIN MENU\n\n");
		       printf("\tPlease Enter an Option: ");
		       scanf("%d",&o);
		       switch(o)
		        {
        		    case 1:createc();
        			      goto q;
  			        case 2:editc();
  			             goto q;
                    case 3:createi();
        			      goto q;
  			        /*case 4:edit();
  			             goto q;
                    case 5:display();
                         goto q;*/     
                    case 6: goto q;
                  default : printf("error\n");
				  goto q;
        		}
		         
        

      case 2: printf("\tExiting...\n");
          break;
      default : printf("error\n");
        break;
	}
}
}

void createc()
{
	int i=0;int n=0;char new[11];
	FILE *fp;
	fp=fopen("CUSTOMER_DETAILS.txt","a");
	if(fp==NULL)
	{
		printf("Error\n");
	}
	else {
	    printf("\n\tEnter Mobile Number: ");
	    scanf("%s",&custo.mobileno); 
        strcpy(new,&custo.mobileno);
        switch(exist(new)){
	    case 1 :printf("\tEnter Customer Name: ");
	            scanf("%s",custo.customername);
	            printf("\n");
    	        fprintf(fp,"\n%s|%s",custo.mobileno,custo.customername);
                printf("\tCustomer Record is Created\n\n");           
        case 2:printf("\tCustomer Already Exists\n");        
    }}
	fclose(fp);
	
}
int exist(char new[11])
{
    FILE *fptr;
    int line, col;
    fptr = fopen("CUSTOMER_DETAILS.txt", "r");
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("SORRY for the Inconvenience\n");
        exit(EXIT_FAILURE);
    }
    indexOf(fptr, new, &line, &col);
    fclose(fptr);
    if (line == -1){
        return 1;}
    else{
        return 2;}
        
}
int indexOf(FILE *fptr, char *new,int *line, int *col)
{
    char str[1000];
    char *pos;
    *line = -1;
    *col  = -1;
    while ((fgets(str,1000, fptr)) != NULL)
    {
        *line += 1;
        pos = strstr(str, new);
        if (pos != NULL){
            *col = (pos - str);
            break;
        }
    }
    if (*col == -1){
        *line = -1;}
    return *col;
}
void editc(){
    int i=0;int n=0;char new[11];int yn=0,yna=0;
	FILE *fp;
	fp=fopen("CUSTOMER_DETAILS.txt","a");
	if(fp==NULL)
	{
		printf("Error\n");
	}
	else {
	    aa: printf("\n\tEnter Mobile Number: ");
	    scanf("%s",&custo.mobileno); 
        strcpy(new,&custo.mobileno);
        switch(exist(new)){
	    case 1 : printf("\tNo account exist.\n\tDo you want to create new??\n");
                printf("\tPlease Select an Option: \n");
                printf("\t1.YES\n");
                printf("\t2.NO\n");
                printf("\tPlease Enter an Option: \n");
                scanf("%d",&yn);
                switch (yn)
                {
                case 1: createc();
                    break;
                
                default:
                    break;
                }
        case 2: printf("\tDisplaying Details\n");
                printf("\tMobile__No|Customer___Name\n");
                existc(new);    
                break;
        default:
                break;
                     
    }}
	fclose(fp);
	
}
#define MAX 256
#define BUFFER_SIZE 1000
int indexOf2(FILE *fptr, const char *new, int *line, int *col);
int existc(char new[11])
{
    FILE *fptr;
    int line, col;
    fptr = fopen("CUSTOMER_DETAILS.txt", "r");
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");
        exit(EXIT_FAILURE);
    }
    indexOf2(fptr, new, &line, &col);
    fclose(fptr);
    /*FILE *fle = fopen("CUSTOMER_DETAILS.txt", "r");
    char lne[256];
    int i = 0;
    while (fgets(lne, sizeof(lne), fle)) {
        i++;
        if(i==line)
        {
            printf("%s", lne);   
        }
    }
    fclose(fle);*/
    FILE *file = fopen("CUSTOMER_DETAILS.txt", "r");
    int count = 0;
    if ( file != NULL )
    {   
        char lne[256]; /* or other suitable maximum line size */
        while (fgets(lne, sizeof lne, file) != NULL) /* read a line */
        {   
            if (count == line)
            {   
                //use line or in a function return it
                //            //in case of a return first close the file with "fclose(file);"
            printf("\t%s\n", lne);
            fclose(file);
            }   
            else{
                count++;}   
        }   
        fclose(file);
    }   
}

int indexOf2(FILE *fptr, const char *NEW, int *line, int *col)
{
    char str[BUFFER_SIZE];
    char *pos;
    *line = -1;
    *col  = -1;
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        *line += 1;
        pos = strstr(str, NEW);
        if (pos != NULL)
        {
            *col = (pos - str);
            break;
        }
    }
    if (*col == -1)
        *line = -1;
    return *col;
}

void createi()
{	int in=0,i=0,ynn=0;char newi[8];
	FILE *fp;
	fp=fopen("ITEMS.txt","a");
    if(fp==NULL)
	{
		printf("Error\n");
	}
	printf("\n");
	printf("\tEnter Product Code(7-digit): ");
	scanf("%s",&item.productno);
    strcmp(newi,item.productno);
    switch (existi(newi))
    {
    case 1:printf("\tEnter Product Name: ");
	    scanf("%s",item.productname);
	    printf("\tEnter Quantity: ");
	    scanf("%d",&item.quantity);
	    printf("\tEnter Price: ");
	    scanf("%d",&item.price);
	    printf("\n");
	    i++;
	    fprintf(fp,"\n%d|%s|%d|%d",item.productno,item.productname,item.quantity,item.price);
    	printf("\tRecord is Created\n\n");
        break;
    case 2 :  printf("\tITEM EXIST,DO YOU WANT TO UPDATE THE STOCK:\n");
              printf("\t1.YES\n");  
              printf("\t2.NO\n");
              printf("\tENTER your Choice: ");
              scanf("%d",&ynn);
              switch (ynn)
              {
              case 1:
                    updi();  
                    printf("\tRecord is Updated\n\n");
                  break;
              case 2:break;
              default:
                  break;
              }
         break; 
    default:
        break;}
	fclose(fp);
}
int existi(char newi[8])
{
    FILE *fptr;
    int line, col;
    fptr = fopen("ITEMS.txt", "r");
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("SORRY for the Inconvenience\n");
        exit(EXIT_FAILURE);
    }
    indexOfi(fptr, newi, &line, &col);
    fclose(fptr);
    if (line == -1){
        return 1;}
    else{
        return 2;}
        
}
int indexOfi(FILE *fptr, char *newi,int *line, int *col)
{
    char str[1000];
    char *pos;
    *line = -1;
    *col  = -1;
    while ((fgets(str,1000, fptr)) != NULL)
    {
        *line += 1;
        pos = strstr(str, newi);
        if (pos != NULL){
            *col = (pos - str);
            break;
        }
    }
    if (*col == -1){
        *line = -1;}
    return *col;
}
void updi(char newi[8])
{
    FILE *fptr;
    int line, col;
    fptr = fopen("ITEMS.txt", "r");
              printf("\tq1\n");  
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("SORRY for the Inconvenience\n");
        exit(EXIT_FAILURE);
    }
    indexOfi(fptr, newi, &line, &col);
    fclose(fptr);
    FILE *fileptr1, *fileptr2;
    char filechar[40]="ITEMS.txt";
    char c;
    int delete_line=line, temp = 1;
 	fileptr1 = fopen(filechar, "r");
    rewind(fileptr1);
    fileptr2 = fopen("replicai.txt", "w");
    c = getc(fileptr1);
    while (c != EOF)
    {
        if (c == 'n')
        {
            temp++;
        }
        if (temp != delete_line)
        {
            putc(c, fileptr2);
        }
        else
        {
            while ((c = getc(fileptr1)) != 'n')
            {
            }
            printf("Enter updated version of item_num(7)|name|present-quan|price(if updated)");
            fflush(stdin);
            putc('n', fileptr2);
            while ((c = getchar()) != 'n')
                putc(c, fileptr2);
            fputs("n", fileptr2);
            temp++;
        }
        c = getc(fileptr1);
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filechar);
    rename("replicai.txt", filechar);
}
int indexOfi2(FILE *fptr, char *newi,int *line, int *col)
{
    char str[1000];
    char *pos;
    *line = -1;
    *col  = -1;
    while ((fgets(str,1000, fptr)) != NULL)
    {
        *line += 1;
        pos = strstr(str, newi);
        if (pos != NULL){
            *col = (pos - str);
            break;
        }
    }
    if (*col == -1){
        *line = -1;}
    return *col;
}