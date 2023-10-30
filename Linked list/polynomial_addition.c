#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    char var;
    struct node* next;
};

struct node* start1 = NULL;
struct node* last1 = NULL;
struct node* start2 = NULL;
struct node* last2 = NULL;
struct node* result = NULL;
struct node* result_last = NULL;

struct node* create(int coeff, char var) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->coeff = coeff;
    n->var = var;
    n->next = NULL;
    return n;
}

void pol1(int data, char var) {
    struct node* t1 = create(data, var);
    if (start1 == NULL) {
        start1 = t1;
        last1 = t1;
    } else {
        last1->next = t1;
        last1 = t1;
    }
}

void pol2(int data, char var) {
    struct node* t2 = create(data, var);
    if (start2 == NULL) {
        start2 = t2;
        last2 = t2;
    } else {
        last2->next = t2;
        last2 = t2;
    }
}

void add() {
    struct node* t1 = start1;
    struct node* t2 = start2;

    while (t1 != NULL && t2 != NULL) {
        struct node* newNode = create(t1->coeff + t2->coeff, t1->var);
        if (result == NULL) {
            result = newNode;
            result_last = newNode;
        } else {
            result_last->next = newNode;
            result_last = newNode;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d%c", temp->coeff, temp->var);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int coeff;
    char var;
    int n;
    
    printf("\nEnter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter terms of expression 1 (coeff var): ");
        scanf("%d %c", &coeff, &var);
        pol1(coeff, var);
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter terms of expression 2 (coeff var): ");
        scanf("%d %c", &coeff, &var);
        pol2(coeff, var);
    }

    add();

    printf("\nResult is: ");
    display(result);

    return 0;
}
