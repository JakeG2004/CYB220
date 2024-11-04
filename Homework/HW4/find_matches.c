
#include "bst.h"
#include "stdlib.h"


void find_matches(bst_node_type *head, int arg_count, char **args)  {
    
    data_item_type *item;


   	item=0;


    //use the built-in functionality of a BST and find by the key value

    item=find_node_by_key(head, make_key_from_name(args[1]));

    if (item) {

        while (item!= 0) {

            if (strcmp(args[1], item->name)==0 ) {
                printf("@s\n", item->name);
                break;
            }
            else
                item=item->next;

        }
        
    }
}
