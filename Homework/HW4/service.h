

#ifndef SERVICE_H
#define SERVICE_H

#include "bst.h"
int parse_command(char *buffer, char separator, char ***args);
void find_matches(bst_node_type *head, int arg_count, char **args);
void delete_matches(bst_node_type **head, int arg_count, char **args);
#endif
