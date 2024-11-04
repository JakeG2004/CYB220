
#include <libcgc.h>
#include "stdlib.h"
#include "service.h"
#include "bst.h"


int main(void) {
    
    bst_node_type *head;
    data_item_type *item;
    bst_stats_type stats;
    long value;
    char buffer[2048];  
    size_t size;
    char **args;
    int arg_count;
    int i;



    // loop forever receiving command strings from STDIN.
    while (1) {

        size=getline(buffer, sizeof(buffer));

        // ignore that a blank line was entered
        if (size==0)
            continue;

        // break the command into an array 
        arg_count=parse_command(buffer, '/', &args);

        if (arg_count == -1)
            continue;
        
        // add a new element to the database
        if (args[0][0]=='a' && arg_count==2 ) {

            // if the string to add is less than 10 chars, ignore the add command
            if (strlen(args[1]) < 10) {

                free(args);
                continue;
            }

            item=calloc(1, sizeof(data_item_type));

            if (!item) {

                printf("Unable to allocate memory\n");
                return(-1);
            }

            strncpy(item->name, args[1], sizeof(item->name)-1);
            item->next = 0;

            insert_node(&head, item, make_key_from_name);

        }
        // search for elements of the database
        else if (args[0][0]=='f' && arg_count==2) {

            find_matches(head, arg_count, args);

        }
        // delete an element from the database
        else if (args[0][0]=='d' && arg_count==2) {

            delete_matches(&head, arg_count, args);

        }
        // time to exit
        else if (args[0][0]=='x') {

            return(0);
        }
        // walk the database and show all entries
        else if (args[0][0]=='w' ) {

            walk_tree(head);
        }
        else if (args[0][0]=='s' ) {

            // clear the stats
            bzero(&stats, sizeof(stats));

            count_bst_stats(head, &stats);

            printf("# of Nodes: @d\n", stats.node_count);
            printf("\% left nodes: @d\n", stats.percent_left);
            printf("\% right nodes: @d\n", stats.percent_right);

        }
        
        free(args);
    }

 
}  // main  

