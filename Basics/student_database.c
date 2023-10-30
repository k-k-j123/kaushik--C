#include<stdio.h>
#include<string.h>
struct student{
    int roll_no;
    char name[40];
    int marks;
};
int main()
{
    int n;
    printf("\nenter number of students you want to enter\t");
    scanf("%d",&n);
    struct student s[n];
    printf("\nenter student details\t");
    for(int i=0;i<n;i++)
    {
        printf("\nenter rollno\t");
        scanf("%d",&s[i].roll_no);
        printf("\nenter name\t");
        scanf("%s",s[i].name);
        printf("\nenter percentage\t");
        scanf("%d",&s[i].marks);
    }
    char search[30];
    printf("\nenter student you want to searh\t");
    scanf("%s",search);

    for(int i=0;i<n;i++)
    {
        if(strcmp(search,s[i].name)==0)
        {
            printf("\ndetails of student you searched for are\t");
            printf("\nroll_no:-%d\nname:-%s\npercentage:-%d\n",s[i].roll_no,s[i].name,s[i].marks);
        }
    }
    
    int max=0;
    for(int i=0;i<n;i++)
    {
        
        if(s[i].marks>s[max].marks)
        {
            max=i;
        }
    }
    
    printf("\ndetails of student with maximum percentage is:-");
    printf("\nroll_no:-%d\nname:-%s\npercentage:-%d\n",s[max].roll_no,s[max].name,s[max].marks);
    return 0;
}