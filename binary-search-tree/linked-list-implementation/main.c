#include <stdio.h>
#include "bst.h"
#include "bst.c"

int main() {
  	bst_node* root = NULL; // creat empty tree
	root = i_insert(root, 15);
	root = i_insert(root, 10);
	root = i_insert(root, 20);
	root = i_insert(root, 25);
	root = i_insert(root, 8);
	root = i_insert(root, 12);

	int num = r_find_height(root);
	printf("number of edges in longest path: %d\n", num);
	printf("number of nodes in longest path: %d\n", num+1);
	//printf("%d\n", i_find_max(root));
	/*while( scanf("%d", &num) == 1 ){
	if(i_search(root, num) ) printf("Found\n");
	else printf("Not found\n");
	}*/
	return 0;
}
