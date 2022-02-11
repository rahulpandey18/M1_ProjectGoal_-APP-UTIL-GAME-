#include<>
struct ad
{
    char name[30];
    char disease[30];
    int phone,age;
} x[100];
int n,i,j=0,a=0,sum=0,g,num;
void read();
void add();
void view();
void del();
void show();
int main()
{
    read();
    int c,i,q;
    printf("\t\t\t\t************************************************\n");
    printf("\t\t\t\t*************#~~Geeta Hospital~~#***************\n");
    printf("\t\t\t\t************************************************\n\n");
    int m,n;

    while(c!=4)
    {
        printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\n\t\t\t\t\t\t**Enter your choice**\n");
        printf("\n\t\t\t\t\t\t 1. Add Patient Details");
        printf("\n\t\t\t\t\t\t 2. View Patient Details");
        printf("\n\t\t\t\t\t\t 3. Delete Patient Details");
        printf("\n\t\t\t\t\t\t 4. Exit");
        printf("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n\n\t\t\t\t\t\t Enter Choice=\n");
        
        
        scanf("%d",&c);//choice for option
        fflush(stdin);//making it clear
        if(c==1)//add
        {
            system("cls");
            add();
        }
        else if(c==2)//view
        {
            system("cls");
            view();
        }
        else if(c==3)//delete
        {
            system("cls");
            del();
        }
        else if(c==4)
        {
            write();
            return 0;
        }
        else
        {
            system("cls");
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}
void add()
{
    printf("\n\n");
    printf("\n\t\t\t\t\t\tNumber of Previous Data in Database =%d\n\n",num);    //how many inputs
    printf("\n\t\t\t\t\t\tNumber of Patient you want to add=\n");
    scanf("%d",&n);
    sum=n+num;

    for(i=num,j=0; i<sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("\n\t\t\t\t\t\tEnter patient's Name = ");
        gets(x[i].name);
        fflush(stdin);
        printf("\n\t\t\t\t\t\tEnter disease = ");
        gets(x[i].disease);
        fflush(stdin);
        printf("\n\t\t\t\t\t\tEnter the age = ");
        scanf("%d",&x[i].age);
        fflush(stdin);
        fflush(stdin);
        printf("\n\t\t\t\t\t\tEnter phone number = ");
        scanf("%d",&x[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}

void view()
{
    for(i=0; i<num; i++)
    {
        printf("\n");
        printf("\n\t\t\t\t\t\tSerial Number=%d\n",i);
        printf("\n\t\t\t\t\t\tName = ");
        puts(x[i].name);
        printf("\n\t\t\t\t\t\tDisease = ");
        puts(x[i].disease);
        printf("\n\t\t\t\t\t\tPhone number = 0%d",x[i].phone);
        printf("\n\t\t\t\t\t\tAge=%d",x[i].age);
        printf("\n\n");
    }
}

void del()
{
    int f,h;
    printf("Enter Serial No. For Delete");
    scanf("%d",&f);
    if(f<num)
    {
        printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\t\t\t\t\t\t 1. Remove the whole record");
        printf("\n\t\t\t\t\t\t 2. Remove Name");
        printf("\n\t\t\t\t\t\t 3. Remove Disease");
        printf("\n\t\t\t\t\t\t 4. Remove age");
        printf("\n\t\t\t\t\t\t 5. Remove phone number");
        printf("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n\n\t\t\t\t\t\t**Enter your choice**\n");
        scanf("%d",&h);
        if(h==1)
        {
            while(f<num)
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].disease,x[f+1].disease);
                x[f].age=x[f+1].age;
                x[f].phone=x[f+1].phone;
                f++;
            }
            num--;
        }
        else if(h==2)
        {
            strcpy(x[f].name,"Cleared");

        }
        else if(h==3)
        {
            strcpy(x[f].disease,"Cleared");
        }
        else if(h==4)
        {
            x[f].age=0;
        }
        
        else if(h==5)
        {
            x[f].phone=0;
        }

    }
    else
        printf("\n\nInvalid Serial number\n");

}
void read()
{
    FILE *fp = fopen("patient.txt","r");
    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("patient.txt","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }

    num = fread(x, sizeof(struct ad),100, fp);
    fclose(fp);
}
void write()
{
    FILE *fp = fopen("patient.txt","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct ad),num, fp);

    fclose(fp);
}
