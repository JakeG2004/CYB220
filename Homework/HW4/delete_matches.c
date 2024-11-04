

#include "bst.h"
#include "stdlib.h"


void delete_matches(bst_node_type **head, int arg_count, char **args)  {
    


    delete_node(head, args[1], make_key_from_name(args[1]));
 
}
