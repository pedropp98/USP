#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER 4096
#define MAX_BOOKS 10

#define and &&

typedef struct books{
    char *book_name;
    int rent_days;
}books_t;

typedef struct user{
    books_t **user_books;
    int rented_books;
}user_t;

typedef struct library{
    books_t **library_books;
    int q_books;
}library_t;

typedef enum boolean{
    false, true
}boolean_t;

char *readline(FILE*);
library_t *create_library(int);
books_t *create_books();
user_t *create_user();
void erase_library(library_t*);
void erase_books(books_t*);
void erase_user(user_t*);
void print_books(user_t*);
books_t *search_book(books_t **, char*, int);
int string_compare(char*, char*);

int main(void){
    int q_books;
    scanf("%d", &q_books);
    getchar();
    getchar();
    library_t *lib = create_library(q_books);
    user_t *user = create_user();
    // for(int i = 0; i < q_books; i++){
    //     printf("book: %s days: %d\n", lib->library_books[i]->book_name, lib->library_books[i]->rent_days);
    // }

    int operation;
    do{
        scanf("%d", &operation);
        getchar();
        getchar();

        switch(operation){
            char *search;
            case 1:
                printf("Digite o livro que voce procura:\n");
                search = readline(stdin);
                books_t *search_lib = search_book(lib->library_books, search, lib->q_books);
                if(search_lib == NULL){
                    printf("Livro nao encontrado na biblioteca\n");
                }
                else{
                    if(user->rented_books == MAX_BOOKS){
                        printf("Voce ja tem 10 livros alugados\n");
                    }
                    else{
                        books_t *search_user = search_book(user->user_books, search, user->rented_books);
                        if(search_user == NULL){
                            printf("%s alugado com sucesso\n", search);
                            user->user_books[user->rented_books++] = search_lib;
                        }
                        else{
                            printf("Livro ja alugado\n");
                        }
                    }
                }
                free(search);
                break;
            case 2:
                print_books(user);
                break;
            case 3:
                printf("Digite o livro que deseja devolver:\n");
                search = readline(stdin);
                boolean_t returned = false;
                for(int i = 0; i < user->rented_books; i++){
                    if(returned){
                        user->user_books[i-1] = user->user_books[i];
                    }
                    if(string_compare(user->user_books[i]->book_name, search) == 0){
                        printf("Livro %s foi devolvido com sucesso\n", search);
                        returned = true;
                    }
                }
                if(!returned){
                    printf("Voce nao possui esse livro\n");
                }
                else{
                    user->rented_books--;
                }
                free(search);
                break;
            default:
                printf("Programa finalizado\n");
                break;
        }
    }while(operation != 4);
    erase_library(lib);
    erase_user(user);
    return 0;
}

char *readline(FILE *in){
    char *string = NULL;
    int pos = 0, character;
    do{
        if(pos % BUFFER == 0)
            string = (char*)realloc(string, (pos / BUFFER + 1) * BUFFER * sizeof(char));
        character = fgetc(in);
        if(character != 13)
            string[pos++] = character;
    }while(character != 10 and !feof(in));
    string[pos-1] = 0;
    string = (char*)realloc(string, pos * sizeof(char));
    return string;
}

library_t *create_library(int q_books){
    library_t *lib = (library_t*)malloc(sizeof(library_t));
    lib->library_books = (books_t**)malloc(q_books * sizeof(books_t*));
    for(int i = 0; i < q_books; i++){
        lib->library_books[i] = create_books();
    }
    lib->q_books = q_books;
    return lib;
}

books_t *create_books(){
    books_t *b = (books_t*)malloc(sizeof(books_t));
    b->book_name = readline(stdin);
    scanf("%d", &b->rent_days);
    getchar();
    getchar();
    return b;
}

user_t *create_user(){
    user_t *u = (user_t*)malloc(sizeof(user_t));
    u->user_books = (books_t**)malloc(MAX_BOOKS * sizeof(books_t*));
    u->rented_books = 0;
    return u;
}

void erase_library(library_t *lib){
    for(int i = 0; i < lib->q_books; i++){
        erase_books(lib->library_books[i]);
    }
    free(lib->library_books);
    free(lib);
}

void erase_books(books_t *book){
    free(book->book_name);
    free(book);
}

void erase_user(user_t *user){
    free(user->user_books);
    free(user);
}

void print_books(user_t *user){
    if(user->rented_books == 0){
        printf("Voce nao tem livros alugados\n");
    }
    else{
        printf("Voce tem %d livro(s) alugado(s)\n", user->rented_books);
        for(int i = 0; i < user->rented_books; i++){
            printf("Livro nome: %s\n", user->user_books[i]->book_name);
            printf("Devolve-lo daqui %d dias\n", user->user_books[i]->rent_days);
        }
    }
}

books_t *search_book(books_t **books, char *search_book, int q_book){
    for(int i = 0; i < q_book; i++){
        if(string_compare(books[i]->book_name, search_book) == 0)
            return books[i];
    }
    return NULL;
}

int string_compare(char *str1, char *str2){
    int size1 = strlen(str1), size2 = strlen(str2);
    for(int i = 0; i < size1 and i < size2; i++){
        if(str1[i] > str2[i])
            return 1;
        else if(str1[i] < str2[i])
            return -1;
    }
    if(size1 > size2)
        return 1;
    else if(size1 < size2)
        return -1;
    return 0;
}