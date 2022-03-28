#ifndef MAIN_H
#define MAIN_H

#define MAX(a,b)	a>b?a:b
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//Linked list implementation
typedef struct bst_node{
	int data;
	struct bst_node* left;
	struct bst_node* right;
}bst_node;

static  bst_node* get_new_node(int data);

//revursive functions
static  bool r_search(bst_node* root, int data);
static  bst_node* r_insert(bst_node* root, int data);
static  int r_find_min(bst_node* root);
static  int r_find_max(bst_node* root);
static  int r_find_height(bst_node* root); // this function works for any binary tree, not only BST

//iterative functions
static  bool i_search(bst_node* root, int data);
static  bst_node* i_insert(bst_node* root, int data);
static  int i_find_min(bst_node* root);
static  int i_find_max(bst_node* root);
//int i_find_height(bst_node* root); //requieres use of queue

#endif // MAIN_H
