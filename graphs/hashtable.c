#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 


int hash(int key)
{
    return key % TABLE_SIZE; 
}


void insert(int table[], int key)
{
    int index = hash(key);      
    int original_index = index; 

 
    while (table[index] != -1)
    {                                   
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index)
        { 
            printf("Error: Hash table is full.\n");
            return;
        }
    }


    table[index] = key;
}

void print_table(int table[])
{
    printf("Hash table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] == -1)
        {
            printf("%d: Empty\n", i);
        }
        else
        {
            printf("%d: %d\n", i, table[i]);
        }
    }
}

int main()
{

    int hash_table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = -1;
    }

    // Insert some elements into the hash table
    insert(hash_table, 12);
    insert(hash_table, 22);
    insert(hash_table, 32);
    insert(hash_table, 5);
    insert(hash_table, 15);

    // Print the hash table
    print_table(hash_table);

    return 0;
}
