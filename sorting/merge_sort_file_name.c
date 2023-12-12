#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[50];
    int age;
};

int read_file(struct Employee a[]) {
    int i = 0;
    FILE *fp;
    if ((fp = fopen("employees.txt", "r")) != NULL) {
        while (fscanf(fp, "%s %d", a[i].name, &a[i].age) != EOF) {
            i++;
        }
        fclose(fp); // Close the file when done reading
    }
    return i;
}
void merge(struct Employee arr[],int low,int high,int mid){
    int i,j,k;
    i=low,j=mid+1,k=low;
    struct Employee B[100];
    while(i<=mid && j<=high){
        if(strcmp(arr[i].name,arr[j].name)<0){//arr[i].age<arr[j].age
            B[k]=arr[i];
            k++,i++;
        }
        else{
            B[k]=arr[j];
            j++,k++;
        }
    }
    while(i<=mid){
        B[k]=arr[i];
        k++;i++;
    }
    while(j<=high){
        B[k]=arr[j];
        k++;j++;
    }
    for(i=low;i<=high;i++){
        arr[i]=B[i];
    }
}
void merge_sort(struct Employee arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}
void print_file(struct Employee arr[], int n) {
    // Open the file for writing (replace "emp.txt" with the name of your file)
    FILE *file = fopen("employees.txt", "w");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    // Write the sorted data back to the file
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %d\n", arr[i].name, arr[i].age);
    }

    // Close the file
    fclose(file);
}

int main() {
    struct Employee employees[100]; // Assuming a maximum of 100 employees
    int n = read_file(employees);

    if (n > 0) {
        
        merge_sort(employees,0,n-1);
        print_file(employees,n);
        printf("Employees sorted by name and saved back to the file.\n");
    } else {
        printf("No employee data found in the file.\n");
    }

    return 0;
}
