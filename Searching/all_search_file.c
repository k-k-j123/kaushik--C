#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct emp {
    char name[20];
    int age;
};
struct emp e[21];
int readfile(){
    FILE *fp;int i=0;
    fp=fopen("employee.txt","r");
    if(fp!=NULL){
        while(fscanf(fp,"%s %d",e[i].name,&e[i].age)!=EOF){
            i++;
        }
    }
    return i;
}
void linearsearch(struct emp e[],int n){
    char x[20];
    printf("\nenter employee name to search");
    scanf("%s",x);
    int i;
    for(i=0;i<n;i++){
        if(strcmp(x,e[i].name)==0){
            printf("\nelement found at index %d",i);
            return ;
        }
    }
    printf("\nelement not found");
}
void sentinelsearch(struct emp e[],int n){
    int i=0;
    char x[20];
    printf("\nenter employee name to search");
    scanf("%s",x);
   strcpy(e[n].name,x);//
    e[n].age=0;//
     for(i=0;i<n;i++){
        if(strcmp(x,e[i].name)==0){
            printf("\nelement found at index %d",i);
            return ;
        }
    }
    printf("\nelement not found");
}
void binarysearch(struct emp e[],int n,int l,int h,int x){
   if(l>h){
    return -1;
   }
    int mid=(l+h)/2;
    if(strcmp(x,e[mid].name)==0)
        return mid;
    if(strcmp(x,e[mid].name)<0)
        binarysearch(e,n,l,mid-1,x);
    if(strcmp(x,e[mid].name)>0)
        binarysearch(e,n,mid+1,h,x);
}