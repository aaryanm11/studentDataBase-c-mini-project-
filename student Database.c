#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void insert_record();
void display_record();
void search_record();
void del_record();
void update_record();
void sort_record();

struct student{
    int roll;
    char sec[10];
    char name[40];
    int marks;
    float grade;
};
    struct student s;
void main()
{
    int ch;
    char get;
   // clrscr();
    while(ch!=7){
        //clrscr();
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############              MINI PROJECT IN C                    ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\n\n");
    printf("\n\t\t\t\t  *------------------*\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t\t        =                   TO                      =");
    printf("\n\t\t\t\t        =             STUDENT RECORD                =");
    printf("\n\t\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t  *------------------*\n");
                          
                        printf("\n\n");  
                        printf("\t  ** AVAILABLE FUNCTIONALITIES ARE **\n\n\n");
                        printf("\t\t1: Insert student record\n");
                        printf("\t\t2: Display student record\n");
                        printf("\t\t3: Search student record\n");
                        printf("\t\t4: Delete student record\n");
                        printf("\t\t5: Update student Record\n");
                        printf("\t\t6: Sort student record\n");
                        printf("\t\t7: Exit\n\n");
                        printf("\t\tEnter Your Choice : ");
                        scanf("%d",&ch);
                        switch(ch){
                                    case 1://clrscr();
                                           insert_record();
                                           break;
                                    case 2://clrscr();
                                           display_record();
                                           break;
                                    case 3://clrscr();
                                           search_record();
                                           break;
                                    case 4://clrscr();
                                           del_record();
                                           break;
                                    case 5://clrscr();
                                           update_record();
                                           break;
                                    case 6://clrscr();
                                           sort_record();
                                           break;
                                    case 7:exit(1);
                                    default:
                                            printf("\n\t\tWrong choice Entered");
                        }
                       /* printf("\n\t\tPress any key to continue ");
                        scanf("%c",&get);*/
    }
    
}
void insert_record(){
    FILE *fp;
    fp=fopen("stu.txt","ab+");
    
    if(fp==NULL){
        printf("\n\t\tError : Cannot Open the File!!!");
        return;
    }
   // printf("\t * Previous Stored Data *");
    display_record();
    
    printf("\n\n\t** ENTER NEW STUDENT DATA **\n\n");
    printf("\n\t\tEnter Student Roll Number: ");
    scanf("%d",&s.roll);
    fflush(stdin);
    printf("\n\t\tEnter Student Name: ");
    scanf("%s",s.name);
    printf("\n\t\tEnter Student Section: ");
    scanf("%s",s.sec);                                                         //gets(s.sec);
    printf("\n\t\tEnter student Total marks: ");
    scanf("%d",&s.marks);
    printf("\n\t\tEnter Student Grade: ");
    scanf("%f",&s.grade);
    fwrite(&s,sizeof(s),1,fp);
    {
        printf("\n\n\t !!! Student Record Inserted Sucessfully\n");
    }
    fclose(fp);
    printf("\n\t\t Updated Record !!\n");
    display_record();
}
void display_record(){
    FILE *fp;
    fp=fopen("stu.txt","rb");
    
    if(fp==NULL){
        printf("\n\t\tError : Cannot open the File !!!");
        return;
    }
    
    printf("\n\n\t * Students Details Are As Follows *\n");
    printf("\nRoll No.\tName of Student\t\tSection\t\tMarks\t\tGrade\n\n");
    while(fread(&s,sizeof(s),1,fp)==1){
        printf("%d\t\t%s\t\t\t%s\t\t%d\t\t%f\n",s.roll,s.name,s.sec,s.marks,s.grade);
    }
    fclose(fp);
}
void search_record(){
    int ro,flag=0;
    FILE *fp;
    fp=fopen("stu.txt","rb");
    if(fp==NULL){
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\n\tEnter Student Roll Number Which You Want To Search: ");
    scanf("%d",&ro);
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0){
        if(s.roll==ro){
            flag=1; 
            printf("\n\n\tSearch Sucessful And Student Records Is as Follows: \n\n");
            printf("\nRoll No\t\tName of Student\t\tSection\t\tMarks\t\tGrade\n\n");
            printf("%d\t\t%s\t\t\t%s\t\t%d\t\t%f\n",s.roll,s.name,s.sec,s.marks,s.grade);
        }
    }    
        if(flag==0){
            printf("\n\n\t\tNo Such Record Found !!!!\n");
        }
        fclose(fp);
    
}
void del_record(){

    int rn,flag=0;
    FILE *fp,*ft;
    fp=fopen("stu.txt","r");
    
    if(fp==NULL)
    {
        printf("\n\tFile not found");
        return;
    }
    printf("\n\t Previously stored records in database");
    printf("\n\t~~~~~~");
    display_record();
    printf("\n\tEnter The Roll No. Of The Student Which You Want To Delete: ");
    scanf("%d",&rn);
    
    ft=fopen("stu1.txt","a+");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(s.roll!=rn)
        {
            fwrite(&s,sizeof(s),1,ft);
        }
        else
            flag=1;
    }
    if(flag==0)
    {
        printf("\n\tNO SUCH RECORD FOUND.PLEASE TRY AGAIN.");
    }
    else
        printf("\n\tRECORD DELETED SUCCESSFULLY!");
        //disrec();
    fclose(fp);
    fclose(ft);
    remove("stu.txt");
    rename("stu1.txt","stu.txt");
    //printf("\n\tUpdated records: ");
    //disrec();
}

void update_record(){
    int ro,flag=0;
    FILE *fp;
    fp=fopen("stu.txt","rb+");
    if(fp==NULL){
        printf("\n\t\tError: Cannot Opean The File!!!");
        return;
        }
        printf("\n\n\tEnter Roll Number of Student Whose Record You Want To Update: ");
        scanf("%d",&ro);
        printf("\n\t\t** Previously Stored Record of Given Roll Number ** ");
        
        while(fread(&s,sizeof(s),1,fp)>0 && flag==0){
            if(s.roll==ro){
                flag=1;
                printf("\nRoll No\t\tName of Student\t\tSection\t\tMarks\t\tGrade\n\n");
            printf("%d\t\t%s\t\t\t%s\t\t%d\t\t%f\n",s.roll,s.name,s.sec,s.marks,s.grade);
                printf("\n\t\t** Now Enter The New Record **\n\n");
                
                printf("\n\t\tUpdated student Roll Number: ");
                scanf("%d",&s.roll);
                fflush(stdin);
                printf("\n\t\tUpdated Student Name: ");
                scanf("%s",s.name);                                                                         //getc(s.name);
                printf("\n\t\tUpdated student section: ");
                scanf("%s",s.sec);                                                                                            //gets(s.sec);
                printf("\n\t\tUpdated Student Mark: ");
                scanf("%d",&s.marks);
                printf("\n\t\tUpdated Student Grade: ");
                scanf("%f",&s.grade);
                fseek(fp,-(long)sizeof(s),1);
                fwrite(&s,sizeof(s),1,fp);
                printf("\n\n\t\tRecord Updated Successfully Check The Display \n");
                
            }
        }
        if(flag==0){
            printf("\n\t\tError : Something Went Wrong!!!");
        }
        fclose(fp);
}
void sort_record(){
    struct student temp;
    struct student arr[50];
    int i,j,k=0;
    FILE *fp;
    fp=fopen("stu.txt","rb");
    if(fp==NULL){
        printf("\n\t\tError: Cannot Open File !!!\n");
    }
    i=0;
    while(fread(&arr[i],sizeof(arr[i]),1,fp)==1){
        i++;k++;
    }
    for(i=0;i<k;i++){
        for(j=0;j<k-i-1;j++){
            if(arr[j].roll>arr[j+1].roll){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\n\t\tAfter Sorting Student Details !!\n\n");
    for(i=0;i<k;i++){
        printf("%d\t\t%s\t\t%s\t\t%d\t\t%f\n",arr[i].roll,arr[i].name,arr[i].sec,arr[i].marks,arr[i].grade);
    }
    fclose(fp);
}
