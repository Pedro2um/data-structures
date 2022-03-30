#include <stdio.h>
#include "funcs.c"
//04:12 30/03/2022

//i dont wanna implement a doubly linked list, because is just a linked list with two pointers, prev and next.
//Save some time, have some fun with data structures
int main(){
	linked_list* my_list = malloc(sizeof(linked_list));
	
	for(int i = 1; i <= 5; i++){
		insert_node_at_head(my_list, i);
	}
	insert_at_nth_position(my_list, 6, 11);

	// some "mistakes" hand made, very messy i know , just wanted to test everything AFAP
	printf("%d\n", my_list->head->data);
	printf("%d\n", my_list->head->next->data);
	printf("%d\n", my_list->head->next->next->data);
	printf("%d\n", my_list->head->next->next->next->data);
	printf("%d\n", my_list->head->next->next->next->next->data);
	printf("%d\n", my_list->head->next->next->next->next->next->data);
	printf("##################################################\n");

	i_reverse_linked_list(my_list);
	//delete_head_node(my_list);
	
	printf("%d\n", my_list->head->data);
	printf("%d\n", my_list->head->next->data);
	printf("%d\n", my_list->head->next->next->data);
	printf("%d\n", my_list->head->next->next->next->data);
	printf("%d\n", my_list->head->next->next->next->next->data);
	printf("%d\n", my_list->head->next->next->next->next->next->data);
	printf("##################################################\n");

	//delete_head_node(my_list);
	r_reverse_linked_list(my_list);

	printf("%d\n", my_list->head->data);
	printf("%d\n", my_list->head->next->data);
	printf("%d\n", my_list->head->next->next->data);
	printf("%d\n", my_list->head->next->next->next->data);
	printf("%d\n", my_list->head->next->next->next->next->data);
	printf("%d\n", my_list->head->next->next->next->next->next->data);

	printf("##################################################\n");

	delete_at_nth_position(my_list, 6, 11);
	printf("%d\n", my_list->head->data);
	printf("%d\n", my_list->head->next->data);
	printf("%d\n", my_list->head->next->next->data);
	printf("%d\n", my_list->head->next->next->next->data);
	printf("%d\n", my_list->head->next->next->next->next->data);
		
	delete_linked_list(my_list);
	return 0;
}