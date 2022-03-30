#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node{
	int data;
	struct node* next;
}node;

typedef struct linked_list{
	node* head;
}linked_list;

//C is hard, but makes sense
// in portuguese, its like the phrase: "C de Certo"

static void	 delete_head_node(linked_list* linked_list);

static void  delete_tail_node(linked_list* linked_list);

static node* get_new_node(int data);

static void	insert_node_at_head(linked_list* linked_list , int data);

static void	insert_node_at_tail(linked_list* linked_list , int data);

//position 1 is head node
static void	insert_at_nth_position(linked_list* linked_list, int position, int data);

//position 1 is head node
static void	delete_at_nth_position(linked_list* linked_list, int position, int data);

static void	i_reverse_linked_list(linked_list* linked_list);

static void	r_reverse_linked_list(linked_list* linked_list);

//auxiliary function to recursive reverse function
//dynamic programing is hard
static node* reverse_nodes(struct node* node, struct node** head);

static void 	delete_linked_list(linked_list* linked_list);
static bool		has_cicle_in_linked_list(linked_list* linked_list);
#endif
