//Defining a new type node_t
typedef struct node node_t;

//Defining a new type list_t
typedef struct list list_t;

//Creates an empty list_t
list_t *create();

//Inserts i items into list l creating a circular list
void insert(list_t *l, int i);

//Returns the size of the list
int size(list_t *l);

//Prints all the items in the list
void print(list_t *l);

//Returns if item is in the list
boolean_t is_in_list(list_t *l, int item);

//Removes item from the list
boolean_t remove_list(list_t *l, int item);

//Recursive functiona that founds the last standing position in josephus problem
int josephus(int n, int k);

//Returns the position item in the list, as it is a circular list it's possible to use a position greater than the size of the list
int item_in_position(list_t *l, int position);

//Frre all the memory allocated to the list
void erase(list_t *n);