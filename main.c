#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//BST == Binary Search Tree
//BST implementation


// we need this, try to remove and see what happens

typedef struct bst_node{
	int data;
	struct bst_node* left; // for this
	struct bst_node* right; // for this
}bst_node;


bool search(bst_node* root, int data);
bst_node* get_new_node(int data);
bst_node* r_insert(bst_node* root, int data);
bst_node* i_insert(bst_node* root, int data);

int main() {
  	bst_node* root = NULL; // creat empty tree
	root = i_insert(root, 15);
	root = i_insert(root, 10);
	root = i_insert(root, 20);
	root = i_insert(root, 25);
	root = i_insert(root, 8);
	root = i_insert(root, 12);

	int num;
	
	while( scanf("%d", &num) == 1 ){
	if(search(root, num) ) printf("Found\n");
	else printf("Not found\n");
	}
	return 0;
}

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
	// this shit gets messy brah, not even eanted to do this
	// thanks to https://stackoverflow.com/questions/49308188/iterative-binary-search-tree-insert-in-c
	// yes i needed, but whatch out, i'm doing BST for my first time, give me some bonus
	bst_node **pp = &root;
    while (*pp != NULL) {
        if (data > (*pp)->data)
            pp = &( (*pp)->right );
        else
            pp = &( (*pp)->left );
    }
    *pp = get_new_node(data);
    return root;
}

//recursively, time and space complexity O(h)
bool search(bst_node* root, int data){
	if(root == NULL) return false;
	else if(root->data == data) return true;
	else if(root->data >= data) return search(root->left, data);
	else return search(root->right, data);
}