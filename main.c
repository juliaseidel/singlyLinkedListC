#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "definitions.h"

typedef node_pointer;

node_pointer create_node(char new_authors_name[60], char new_title[100], long int new_isbn){
    node_pointer new_node_ptr;
    new_node_ptr = malloc(sizeof(node));

    if (new_node_ptr == NULL){
        return NULL;
    } else {
        strcpy(new_node_ptr -> authors_name, new_authors_name);
        strcpy(new_node_ptr -> title, new_title);
        new_node_ptr -> isbn = new_isbn;
        new_node_ptr -> next = NULL;
        return new_node_ptr;
    }
}

void insert_on_top(node_pointer * ptr_to_existing_head, node_pointer new_node_pointer){
    new_node_pointer -> next = * ptr_to_existing_head;
    *ptr_to_existing_head = new_node_pointer;
}

void insert_on_tail(node_pointer * ptr_to_existing_head, node_pointer new_node_pointer){
    node_pointer * temp_ptr;
    temp_ptr = ptr_to_existing_head;

    while (*temp_ptr != NULL){
        temp_ptr = &((*temp_ptr) -> next);
    }

    new_node_pointer -> next = * temp_ptr;
    *temp_ptr = new_node_pointer;
}

void display_list(node_pointer list_pointer){
    printf("The nodes in the list are as follows.\n");
    while (list_pointer != NULL){
        printf("node data is: \n Title: %sAUTHOR: %sISBN %ld\n", list_pointer -> title, list_pointer -> authors_name, list_pointer -> isbn);
        list_pointer = list_pointer -> next;
    }
}

void search_book (node_pointer list_pointer){
    printf("Provide a ISBN of a book you would like to display\n");
    long int key_isbn;
    scanf("%ld", &key_isbn);
    while (list_pointer!=NULL){
        if (list_pointer -> isbn == key_isbn) {
            printf("Node data is:\nTITLE: %sAUTHOR: %sISBN: %ld\n", list_pointer->title, list_pointer->authors_name,
                   list_pointer->isbn);
            break;
        }
        list_pointer = list_pointer -> next;
    }
}

int main() {
    node_pointer head = NULL;

    char title_read[100];
    char author_read[60];
    long int isbn_read;

    printf("Please enter filename");
    char filename[20];
    scanf(" %s", filename);
    FILE * fp = fopen(filename, "rw");

    if (fp != NULL) {
        while (!feof(fp)) {
            fgets(author_read, sizeof(author_read), fp);
            fgets(title_read, sizeof(title_read), fp);

            char temp_isbn[12];
            fgets(temp_isbn, sizeof(temp_isbn), fp);
            isbn_read = atol(temp_isbn);

            char empty_line[1024];
            fgets(empty_line, sizeof(empty_line), fp);

            node_pointer temp_node_ptr;
            temp_node_ptr = create_node(author_read, title_read, isbn_read);
            insert_on_top(&head, temp_node_ptr);
        }
        bool answer = true;
        while (answer) {
            printf("What do you wanna do?\n 1- print the whole list\n 2 – print the book data matching a given ISBN\n 3 - exit the program\n");
            int c;
            scanf("%d", &c);
            switch (c) {
                case 1:
                    display_list(head);
                    break;
                case 2:
                    search_book(head);
                    break;
                case 3:
                    answer = false;
                    break;
            }
        }
    } else {
        printf("empty file");
    }
    fclose(fp);
}