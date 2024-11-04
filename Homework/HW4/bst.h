

#ifndef BST_H
#define BST_H

typedef struct data_item {

	char name[1024];  // 1023 byte string plus trailing null
	struct data_item *next;

}  data_item_type;


typedef struct bst_node {

	data_item_type *data;
	unsigned long key;
	unsigned int data_count;
	struct bst_node *right;
	struct bst_node *left;

} bst_node_type;


typedef struct bst_stats {

	unsigned int node_count;
	unsigned int percent_left;
	unsigned int percent_right;


} bst_stats_type;


unsigned long str_token( char *str);
unsigned long make_key_from_name(void *data_item);

int insert_node(bst_node_type **head, data_item_type *data, unsigned long make_key());
int delete_node(bst_node_type **head, char *str, unsigned long key);
void *find_node_by_key(bst_node_type *head, unsigned long key); 
int walk_tree(bst_node_type *node);
int count_nodes(bst_node_type *node, bst_stats_type *stats);
int count_bst_stats(bst_node_type *head, bst_stats_type *stats);

#endif
