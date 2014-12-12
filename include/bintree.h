#ifndef __BINTREE_H__
#define __BINTREE_H__

#include "debug.h"

struct conu_node
{
  struct conu_node* lchild;
  struct conu_node* rchild;
  char* str;
};

int conu_tree_insert (struct conu_node* head, const char* in_str, 
  struct conu_err_t* err);
int conu_tree_search (struct conu_node* head, const char* search_str);
int conu_tree_remove (struct conu_node* head, const char* remove_str);
struct conu_node* conu_node_alloc (struct conu_err_t* err);
int conu_init_tree (struct conu_node* tree, const char* head_str);

#endif
