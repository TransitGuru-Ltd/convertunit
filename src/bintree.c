// Practice with a binary search tree. Will potentially be good practice
// if this program uses a b-tree for unit conversion look-ups.

#include <string.h>
#include "bintree.h"

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

struct conu_node* conu_tree_init (const char* head_str, struct conu_err_t* err)
{
  struct conu_node* tree;

  // allocate new node for head of tree
  tree = conu_node_alloc (err);
  if (tree == NULL) return NULL; // memory allocation failed. check err->msg.

  // allocate memory for string to store
  size_t n = sizeof (char) * (strlen (head_str) + 1);
  tree -> str = (char *) malloc (n);
  _CHECK_MEM_ALLOC (tree -> str, err, {
    free (tree);
    return NULL;
  });

  // copy memory from string passed to function into our tree node
  memcpy (new_str, head_str, n);

  // the node does not yet have children. set children to NULL
  tree -> lchild = NULL;
  tree -> rchild = NULL;

  return tree;
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

  struct conu_node** ins_loc = &head;

  // search for insertion location
  while (*ins_loc != NULL)
  {
    // if insertion string is less than current node go to left child
    if (strcmp (in_str, *ins_loc -> str) < 0)
      *ins_loc = *ins_loc -> lchild;
    else
      *ins_loc = *ins_loc -> rchild;  // greater than or equal goes to right
  }

  // finally, put new node into insertion location
  *ins_loc = new_node;
}

//! Search for node in tree
//
// \param head Pointer to head of tree
// \param search_str String to search for in tree
// \return NULL if not found, pointer to node if found
struct conu_node* conu_tree_search (struct conu_node* head, 
  const char* search_str)
{
  int cmp;
  struct conu_node* curr_loc = head;

  // search for insertion location
  while (curr_loc != NULL)
  {
    // compare search string to current location
    cmp = strcmp (search_str, curr_loc -> str);

    if (cmp == 0) return curr_loc; // string found! return current node

    // if insertion string is less than current node go to left child
    if (cmp < 0)
      curr_loc = curr_loc -> lchild;
    else
      curr_loc = curr_loc -> rchild;  // greater than or equal goes to right
  }
}

//! Search for node in tree and remove it
//
// \param head Pointer to head of tree
// \param remove_str String to remove from tree
// \return 1 if found and removed, 0 if not found
int conu_tree_remove (struct conu_node* head, const char* remove_str)
{
  // TODO: implement

  return 0;
}

//! Recursively free memory allocated for tree
//
// \param head Pointer to head of tree
void conu_tree_destroy (struct conu_node* head)
{
  if (head == NULL) return;
  conu_tree_destroy (head -> lchild);
  conu_tree_destory (head -> rchild);
  free (head);
}

//! Recursively print tree in preorder
//
// \param head Pointer to head of tree
void conu_tree_print (struct conu_node* head)
{
  if (head == NULL) return;

  conu_tree_print (head -> lchild);

  fputs (head -> str, stdout);
  fputc (' ', stdout);

  conu_tree_print (head -> rchild);
}

//! Recursively print tree in postorder
//
// \param head Pointer to head of tree
void conu_tree_print_postord (struct conu_node* head)
{
  if (head == NULL) return;

  conu_tree_print (head -> lchild);

  conu_tree_print (head -> rchild);

  fputs (head -> str, stdout);
  fputc (' ', stdout);
}
