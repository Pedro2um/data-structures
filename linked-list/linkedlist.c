#ifndef FUNCS_C
#define FUNCS_C

#include <stdio.h>
#include "linkedlist.h"


void	delete_head_node(linked_list* linked_list){
	if(linked_list == NULL){
		assert(0);
	}
	else if(linked_list->head == NULL){
		return;
	}
	node* temp = linked_list->head;
	linked_list->head = linked_list->head->next;
	free(temp);
}

void  	delete_tail_node(linked_list* linked_list){
	if(linked_list == NULL){
		assert(0);
	}
	else if(linked_list->head == NULL){
		return;
	}
	else if(linked_list->head->next == NULL){
		delete_head_node(linked_list);
		return;
	}

	node* temp = linked_list->head;
	while(temp->next->next != NULL){
		 temp = temp->next;
	}

	free(temp->next);
	temp->next = NULL;
}

node* 	get_new_node(int data){
	node* new_node = (node*)malloc( sizeof(node) );
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void	insert_node_at_head(linked_list* linked_list , int data){
	if(linked_list == NULL){
		assert(0);
	}
	else if(linked_list->head == NULL){
		node* new_node = get_new_node(data);
		linked_list->head = new_node;
		return;
	}
	
	node* new_node = get_new_node(data);
	new_node->next = linked_list->head;
	linked_list->head = new_node;
}

void	insert_node_at_tail(linked_list* linked_list , int data){
	if(linked_list == NULL){
		assert(0);
	}
	else if(linked_list->head == NULL){
		insert_node_at_head(linked_list, data);
		return;
	}

	node* temp = linked_list->head;
	while(temp->next != NULL){
		 temp = temp->next;
	}

	node* new_node = get_new_node(data);
	temp->next = new_node;
	new_node->next = NULL;
}

//position 0 is head node
void	insert_at_nth_position(linked_list* linked_list, int position, int data){
	if(linked_list == NULL){
		assert(0);
	}
	node** curr = &(linked_list->head);
	 while (position--) {
 
            if (position == 0) {
 
                node* new_node = get_new_node(data);
 
                new_node->next = *curr;

                *curr = new_node;
            }
            else
              curr = &(*curr)->next;
        }
	
}
//position 0 is head node
void	delete_at_nth_position(linked_list* linked_list, int position, int data){
	if(linked_list == NULL){
		assert(0);
	}
	node** curr = &(linked_list->head);
	 while (position--) {
 
            if (position == 1) {

				(*curr)->next = (*curr)->next->next;

            }
            else
              curr = &(*curr)->next;
        }
	
}
void	i_reverse_linked_list(linked_list* linked_list){
	struct node* temp, *curr, *prev, *next;
	curr = (linked_list->head);
	prev = NULL;

	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	linked_list->head = prev;
}
void	r_reverse_linked_list(linked_list* linked_list){
	node* temp = reverse_nodes(linked_list->head, &(linked_list->head) );
	//useless variable
}

//dynamic programing is hard
//this function uses the stack memory as tool , if you return the address to the previous function call, you can solve the problem
node* 	reverse_nodes(struct node* node, struct node** head){

	if(node->next == NULL){
		*head = node;
		goto Exit;
	}

	struct node* temp = reverse_nodes(node->next, head);
	temp->next = node;
	node->next = NULL;

	Exit:
	return node;
}

void 	delete_linked_list(linked_list* linked_list){
		while( (linked_list->head) != NULL){
				delete_head_node(linked_list);
		}
		free(linked_list);
}

static bool		has_cicle_in_linked_list(linked_list* linked_list){
	if(head == NULL) return false;

	node* slow = linked_list->head;
	node* fast = linked_list->head->next;

	while(fast != slow){
		if(fast == NULL || fast->next == NULL) return false;
		//slow goes in 1 "jump" at a time
		slow = slow->next;

		//fast goes in 2 "jumps" at a time
		fast = fast->next->next;
	}
	return true;
}

#endif /* FUNCS_C*/
