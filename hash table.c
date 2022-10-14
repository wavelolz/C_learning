# include <stdlib.h>
# include <stdio.h>
# include <string.h>



/*create hash table item*/

typedef struct HT_item{
    char *key;
    char *value;
} HT_item;

/*create hash table: count is used to store numbers of elements in
 hash table, and size is used to store size of hash table
*/

typedef struct HT_table{
    HT_item **item;
    int count;
    int size;
} HT_table;


unsigned long int hash_function(char *arr);
HT_item *create_item(char *key, char *value);
HT_table *create_table(int size);


void insert(HT_table *table, char *key, char *value);
char *search(HT_table *table, char *key);
void print_search(HT_table *table, char *key);
void print_table(HT_table *table);




int main(){
    HT_table *ht = create_table(50000);
    insert(ht, "123", "Hello");
    insert(ht, "456", "World");
    print_table(ht);
    print_search(ht, "456");

}


unsigned long int hash_function(char *arr){
    unsigned long count = 0;
    for (unsigned long int i = 0; arr[i]; i ++){
        count += arr[i];
    }
    return count % 50000;
}



/*
This function create a item and return its address
*/
HT_item *create_item(char *key, char *value){
    HT_item *item = malloc(sizeof(HT_item));
    item -> key = (char*) malloc(strlen(key) + 1);
    item -> value = (char*) malloc(strlen(value) + 1);

    strcpy(item -> key, key);
    strcpy(item -> value, value);

    return item;
}


/*
This function creates a table based on input of size, and it sets every
item to NULL
*/
HT_table *create_table(int size){
    HT_table *table = malloc(sizeof(HT_table));
    table -> size = size;
    table -> count = 0;
    table -> item = malloc(sizeof(HT_item) * size);
    for (int i = 0; i < size; i ++){
        table -> item[i] = NULL;
    }

    return table;
}

void insert(HT_table *table, char *key, char *value){

    /*First step: create item*/
    HT_item *item = create_item(key, value);

    /*compute the hash value*/
    unsigned long int index = hash_function(key);

    /*insert the item to table*/
    table -> item[index] = item;

    /*increase the numbers of item by one*/
    table -> count ++;
}

char *search(HT_table *table, char *key){

    /*calculate the value of hash value*/
    unsigned long int index = hash_function(key);

    /*find the item corresponds to the key*/
    HT_item *item = table -> item[index];

    return item -> value;
}

void print_search(HT_table *table, char *key){
    char *value;
    unsigned long int index = hash_function(key);
    printf("The item with key : %s has been searched with value : %s", table -> item[index] -> key, table -> item[index] -> value);
}

void print_table(HT_table *table){
    printf("The hash table has %d elements\n", table -> count);
    printf("---------------\n");
    for (int i = 0; i < table -> size; i ++){
        if (table -> item[i]){
            printf("Key [%s], Value [%s] \n", table -> item[i] -> key, table -> item[i] -> value);
        }
    }
    printf("\n---------------\n");

}

