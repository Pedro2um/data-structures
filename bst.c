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


bool r_search(bst_node* root, int data);
bool i_search(bst_node* root, int data);
bst_node* get_new_node(int data);
bst_node* r_insert(bst_node* root, int data);
bst_node* i_insert(bst_node* root, int data);
int r_find_min(bst_node* root);
int i_find_min(bst_node* root);
int r_find_max(bst_node* root);
int i_find_max(bst_node* root);

int main() {
  	bst_node* root = NULL; // creat empty tree
	root = i_insert(root, 15);
	root = i_insert(root, 10);
	root = i_insert(root, 20);
	root = i_insert(root, 25);
	root = i_insert(root, 8);
	root = i_insert(root, 12);

	int num;
	printf("%d\n", r_find_max(root));
	printf("%d\n", i_find_max(root));
	/*while( scanf("%d", &num) == 1 ){
	if(i_search(root, num) ) printf("Found\n");
	else printf("Not found\n");
	}*/
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
	// this shit gets messy brah, not even wanted to do this
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
