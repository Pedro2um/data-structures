#ifndef	BST_C
#define BST_C

#include <stdio.h>
#include "bst.h"

// O(1)
bst_node* get_new_node(int data){
	bst_node* new_node = malloc(sizeof(bst_node));
	if(new_node == NULL){
		assert(0);
	}
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	
	return new_node;
}

//recursively, time and space complexity O(h)
bst_node* r_insert(bst_node* root, int data){
	if(root == NULL){
		root = get_new_node(data);
	}
	else if (data <= root->data){
		root->left = r_insert(root->left,data);
	}
	else {
		root->right = r_insert(root->right,data);
	}
	return root;
}


// time complexity still O(h) but space complexity is now O(1)
//yes you need the address of the poiter to root
bst_node* i_insert(bst_node* root, int data) {
	
	if(root == NULL){
		return get_new_node(data);
	}
	
	// this gets messy, not even wanted to do this
	// ponteirs are the data we need to manipulate
	bst_node **pt_to_pt = &root;
	
    while (*pt_to_pt != NULL) {
	    
        if (data > (*pt_to_pt)->data){
		
            pt_to_pt = &( (*pt_to_pt)->right );	
	}
	else{
		
            pt_to_pt = &( (*pt_to_pt)->left );
	}
    }
	
    *pt_to_pt = get_new_node(data);
    return root;
}

//recursively, time and space complexity O(h)
bool r_search(bst_node* root, int data){
	if(root == NULL) return false;
	else if(root->data == data) return true;
	else if(root->data >= data) return r_search(root->left, data);
	else return r_search(root->right, data);
}

//time complexity still O(h) but space complexity is now O(1)
bool i_search(bst_node* root, int data){
	bst_node* curr = root;
	bst_node* prev = NULL;
	while(curr != NULL){
		prev = curr;
		if(curr->data == data){
			return true;
		}
		else if(data > curr->data){
			curr = curr->right;
		}
		else{
			curr = curr->left;
		}
	}
	return false;
}

//time complexity still O(h) but space complexity is now O(1)
int i_find_min(bst_node* root){
	bst_node* curr = root;
	if(curr == NULL){
		assert(0);
	}
	while(curr->left != NULL){
		curr = curr->left;
	}
	return curr->data;
}

//recursively, time and space complexity O(h)
int r_find_min(bst_node* root){
	if(root == NULL) assert(0);
	else if(root->left != NULL) return r_find_min(root->left);
	else return root->data;
}

//you dont need curr, but this improves code readability
int i_find_max(bst_node* root){
	bst_node* curr = root;
	if(curr == NULL){
		assert(0);
	}
	while(curr->right != NULL){
		curr = curr->right;
	}
	return curr->data;
}

int r_find_max(bst_node* root){
	if(root == NULL) assert(0);
	
	int data = root->data;
	
	if(root->right != NULL) return r_find_max(root->right);
	else return root->data;
}

// this function works for any binary tree, not only BST
int r_find_height(bst_node* root){
	if(root == NULL)
		return -1; 
// return -1 because we are counting number of edges,  if you want to count number of nodes, you should change to 0.

	return ( MAX(r_find_height(root->left), r_find_height(root->right)) + 1);
}

#endif // FUNCS_C
