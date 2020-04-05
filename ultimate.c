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
int indexOfi(FILE *fptr,char *n,int *line, int *col);
void updi();
void iname(int line);
void iquan(int line);
void iprice(int line);
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
	float price;
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
                printf("\tCustomer Record is Created\n\n");break;           
        case 2:printf("\tCustomer Already Exists\n");break;        
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
    printf("%d",line);
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
               printf("\t----------------------------\n");
                printf("\tPlease Select an Option: \n");
               printf("\t----------------------------\n");
                printf("\t1.YES\n");
                printf("\t2.NO\n");
                printf("\tPlease Enter an Option: ");
                scanf("%d",&yn);
                switch (yn)
                {
                case 1: createc();
                    break;
                
                default:
                    break;
                }break;
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
        char lne[256];
        while (fgets(lne, sizeof lne, file) != NULL)
        {   
            if (count == line)
            {
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
{	int in=0,ynn=0;char newi[8];
	FILE *fp,*fp2,*fp3,*fp4;
	fp=fopen("INUM.txt","a");
	if(fp==NULL)
	{
		printf("Error\n");
	}else{
    fclose(fp);
	printf("\n");
	printf("\tEnter Product Code(7-digit): ");
	scanf("%s",item.productno);
    strcpy(newi,item.productno);
    switch (existi(newi))
    {
    case 1 :fp2=fopen("INAME.txt","a");
	    fp=fopen("INUM.txt","a");
	    fp3=fopen("IQ.txt","a");
	    fp4=fopen("IP.txt","a");
        printf("\tEnter Product Name: ");
	    scanf("%s",item.productname);
	    printf("\tEnter Quantity: ");
	    scanf("%d",&item.quantity);
	    printf("\tEnter Price: ");
	    scanf("%f",&item.price);
	    printf("\n");
	    fprintf(fp,"%s\n",item.productno);
	    fprintf(fp2,"%s\n",item.productname);
	    fprintf(fp3,"%d\n",item.quantity);
	    fprintf(fp4,"%.2f\n",item.price);
    	printf("\tRecord is Created\n\n");
        fclose(fp);
        fclose(fp2);
	    fclose(fp3);
	    fclose(fp4);
        break;
    case 2 :  printf("\tITEM EXIST,DO YOU WANT TO UPDATE THE STOCK:\n");
              printf("\t----------------------------\n");
              printf("\t1.YES\n");  
              printf("\t2.NO\n");
              printf("\tENTER your Choice: ");
              scanf("%d",&ynn);
              switch (ynn)
              {
              case 1:
                    updi(newi);  
                    printf("\tRecord is Updated\n\n");
                  break;
              case 2:break;
              default:
                  break;
              }
         break; 
    default:
        break;}}
}
int existi(char newi[8])
{
    FILE *fptr;
    int line, col;
    fptr = fopen("INUM.txt", "r");
    if (fptr == NULL)
    {
        printf("Unable to process.\n");
        printf("SORRY for the Inconvenience\n");
        exit(EXIT_FAILURE);
    }
    indexOfi(fptr, newi, &line, &col);
    fclose(fptr);
    if (line==-1){
        return 1;}
    else{
        return 2;}
        
}
int indexOfi(FILE *fptr,char *newi,int *line, int *col)
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
    FILE *fptr,*fptr2,*fptr3,*fptr4;
    int line, col,y3;
    fptr=fopen("INUM.txt","r");
	//fptr2=fopen("INAME.txt","a");
	//fptr3=fopen("IQ.txt","a");
	//fptr4=fopen("IP.txt","a");
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("SORRY for the Inconvenience\n");
        exit(EXIT_FAILURE);
    }
    indexOfi2(fptr, newi, &line, &col);
    fclose(fptr);
    line=line+1;
    printf("\t----------------------------\n");
    printf("\tPLEASE SELECT THE TYPE YOU WANT TO UPDATE:\n");
    printf("\t----------------------------\n");
    printf("\t1.NAME\n");  
    printf("\t2.QUANTITY\n");
    printf("\t3.PRICE\n");
    printf("\tENTER your Choice: ");
    scanf("%d",&y3);
    switch (y3)
    {
    case 1: iname(line);
        break;
    case 2: iquan(line);
        break;
    case 3: iprice(line);
        break;
    default:
        break;
    }
    
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
    return *col,*line;
}
void iname(int line)
{
    char s[1000],f[100]="INAME.txt",c;
    FILE *fptr, *f1ptr;
    int d=line,temp=1;
    fptr=fopen(f,"r");
    f1ptr=fopen("temp.txt","w");
    printf("\tEnter Name to be replaced with: ");
    scanf("%s",s);
    while((c=getc(fptr))!=EOF){
        if(c=='\n'){
            temp++;
            putc(c,f1ptr);}
        else if(temp==d){
            fputs(s,f1ptr);
            while((c=getc(fptr))!='\n');
            putc(c,f1ptr);
            temp++;}
        else if (temp!=d){
            putc(c,f1ptr);
        }
    }
    fclose(fptr);
    fclose(f1ptr);
    char ch, source_file[20]="temp.txt", target_file[20]="INAME.txt";
    FILE *source, *target;
    source = fopen(source_file, "r");
    if( source == NULL )
    {
      printf("\t\t\t\tNOT UPDATED...\n");
      exit(EXIT_FAILURE);
   }
    target = fopen(target_file, "w");
 
   if( target == NULL )
   {
      fclose(source);
      printf("\t\t\t\tNOT UPDATED...\n");
      exit(EXIT_FAILURE);
   }
   else{ while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);
   printf("\n\tITEM NAME UPDATED SUCCESSFULLY.\n");}
   fclose(source);
   fclose(target);
   remove("temp.txt");
}
void iquan(int line)
{
    char s[1000],f[100]="IQ.txt",c;
    FILE *fptr, *f1ptr;
    int d=line,temp=1;
    fptr=fopen(f,"r");
    f1ptr=fopen("temp.txt","w");
    printf("\tEnter Quantity to be updated: ");
    scanf("%s",s);
    while((c=getc(fptr))!=EOF){
        if(c=='\n'){
            temp++;
            putc(c,f1ptr);}
        else if(temp==d){
            fputs(s,f1ptr);
            while((c=getc(fptr))!='\n');
            putc(c,f1ptr);
            temp++;}
        else if (temp!=d){
            putc(c,f1ptr);
        }
    }
    fclose(fptr);
    fclose(f1ptr);
    char ch, source_file[20]="temp.txt", target_file[20]="IQ.txt";
    FILE *source, *target;
    source = fopen(source_file, "r");
    if( source == NULL )
    {
      printf("\t\t\t\tNOT UPDATED...\n");
      exit(EXIT_FAILURE);
   }
    target = fopen(target_file, "w");
 
   if( target == NULL )
   {
      fclose(source);
      printf("\t\t\t\tNOT UPDATED...\n");
      exit(EXIT_FAILURE);
   }
   else{ while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);
   printf("\n\tITEM NAME UPDATED SUCCESSFULLY.\n");}
   fclose(source);
   fclose(target);
   remove("temp.txt");
}
void iprice(int line)
{
    char s[1000],f[100]="IP.txt",c;
    FILE *fptr, *f1ptr;
    int d=line,temp=1;
    fptr=fopen(f,"r");
    f1ptr=fopen("temp.txt","w");
    printf("\tEnter Price to be updated with: ");
    scanf("%s",s);
    while((c=getc(fptr))!=EOF){
        if(c=='\n'){
            temp++;
            putc(c,f1ptr);}
        else if(temp==d){
            fputs(s,f1ptr);
            while((c=getc(fptr))!='\n');
            putc(c,f1ptr);
            temp++;}
        else if (temp!=d){
            putc(c,f1ptr);
        }
    }
    fclose(fptr);
    fclose(f1ptr);
    char ch, source_file[20]="temp.txt", target_file[20]="IP.txt";
    FILE *source, *target;
    source = fopen(source_file, "r");
    if( source == NULL )
    {
      printf("\t\t\t\tNOT UPDATED...................\n");
      exit(EXIT_FAILURE);
   }
    target = fopen(target_file, "w");
 
   if( target == NULL )
   {
      fclose(source);
      printf("\t\t\t\tNOT UPDATED................\n");
      exit(EXIT_FAILURE);
   }
   else{ while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);
   printf("\n\tITEM NAME UPDATED SUCCESSFULLY..............\n");}
   fclose(source);
   fclose(target);
   remove("temp.txt");
}
