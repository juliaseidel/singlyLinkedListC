//
// Created by Julia Seidel on 07/11/2019.
//

#ifndef UNTITLED1_DEFINITIONS_H
#define UNTITLED1_DEFINITIONS_H

#endif //UNTITLED1_DEFINITIONS_H

typedef struct book * node_pointer;
typedef struct book {
    char authors_name[60];
    char title[100];
    long int isbn;
    node_pointer next;
}node;

node_pointer create_node(char new_authors_name[60], char new_title[100], long int new_isbn);

void insert_on_top(node_pointer * ptr_to_existing_head, node_pointer new_node_pointer);

void insert_on_tail(node_pointer * ptr_to_existing_head, node_pointer new_node_pointer);

void display_list(node_pointer list_pointer);

void search_book (node_pointer list_pointer);

