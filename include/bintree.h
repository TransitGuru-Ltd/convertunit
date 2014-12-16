#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <stdbool.h>
#include "debug.h"

struct conu_node
{
  struct conu_node* lchild;
  struct conu_node* rchild;
  char* str;
};

bool conu_tree_insert (struct conu_node* head, const char* in_str, 
  struct conu_err_t* err);
const struct conu_node* conu_tree_search (const struct conu_node* head, 
  const char* search_str);
const struct conu_node* conu_tree_search_parent (const struct conu_node* head, 
  const char* search_str, const struct conu_node** parent);
bool conu_tree_remove (struct conu_node* head, const char* remove_str);
struct conu_node* conu_node_alloc (struct conu_err_t* err);
struct conu_node* conu_tree_init (const char* head_str, struct conu_err_t* err);
void conu_tree_destroy (struct conu_node* head);
void conu_tree_print (const struct conu_node* head);
void conu_tree_print_postord (const struct conu_node* head);

#endif
