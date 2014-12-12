// Practice with a binary search tree. Will potentially be good practice
// if this program uses a b-tree for unit conversion look-ups.

#include <string.h>
#include "bintree.h"

int conu_tree_insert (struct conu_node* head, const char* in_str, 
  struct conu_err_t* err);
int conu_tree_search (struct conu_node* head, const char* search_str);
int conu_tree_remove (struct conu_node* head, const char* remove_str);

//! Allocates a new tree node on the heap
//
// \param err Pointer to an error struct
// \return Pointer to new tree node
struct conu_node* conu_node_alloc (struct conu_err_t* err)
{
  // try to allocate a binary search tree node on the heap
  struct conu_node* new_node = 
    (struct conu_node*) malloc (sizeof (struct conu_node));

  // this macro checks to see if a memory allocation is successful or not
  // the macro can be found in "debug.h"
  // the args are as follows:
  // \param arg1 pointer to new memory to check if allocation was successful
  // \param arg2 pointer to an error data type to populate if allocation was unsuccessful
  // \param arg3 a "finally" block of code to be executed if allocation failed.
  //    NOTE: the finally block generally returns something so that we exit function,
  //      and cleans up any dynamically allocated memory so that we don't have leaks
  _CHECK_MEM_ALLOC (new_node, err, {
    return NULL;
  });

  err->code = CONU_SUCCESS;
  return new_node;
}

int conu_init_tree (struct conu_node* tree, const char* head_str, 
  struct conu_err_t* err)
{
  // allocate new node for head of tree
  tree = conu_node_alloc (err);
  if (tree == NULL) return 0; // memory allocation failed. check err->msg.

  // allocate memory for string to store
  size_t n = sizeof (char) * (strlen (head_str) + 1);
  tree -> str = (char *) malloc (n);
  _CHECK_MEM_ALLOC (tree -> str, err, {
    return 0;
  });

  // copy memory from string passed to function into our tree node
  memcpy (new_str, head_str, n);

  // the node does not yet have children. set children to NULL
  tree -> lchild = NULL;
  tree -> rchild = NULL;
}

//! Inserts new node into the tree
//
// \param head Pointer to head of tree
// \param in_str String to insert into tree
// \param err Pointer to error type
// \return 0 if insertion fails
int conu_tree_insert (struct conu_node* head, const char* in_str, 
  struct conu_err_t* err)
{
  struct conu_node* new_node = conu_node_alloc (err);
  if (new_node == NULL) return 0; // memory allocation failed. check err->msg.

  struct conu_node* ins_loc = head;

  // search for insertion location
  while (ins_loc != NULL)
  {
    // if insertion string is less than current node go to left child
    if (strcmp (in_str, ins_loc -> str) < 0)
      ins_loc = ins_loc -> lchild;
    else
      ins_loc = ins_loc -> rchild;  // greater than or equal goes to right
  }

  // finally, but new node into insertion location
  ins_loc = new_node;
}