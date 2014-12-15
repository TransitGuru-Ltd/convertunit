#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "bintree.h"
#include "debug.h"

int main (int argc, char* argv[])
{
  int i = 0;

  struct conu_node *head;
  const struct conu_node *s_node, *sibling = NULL, *parent = NULL;
  struct conu_err_t err;

  head = conu_tree_init ("head string", &err);
  if (head == NULL) // initialization failed, print error msg and exit
    goto clean;

  // build tree
  if ( !conu_tree_insert (head, "some leaf", &err) )        goto clean;
  if ( !conu_tree_insert (head, "some other leaf", &err) )  goto clean;
  if ( !conu_tree_insert (head, "another leaf", &err) )     goto clean;
  if ( !conu_tree_insert (head, "leaf city", &err) )        goto clean;
  if ( !conu_tree_insert (head, "applesauce", &err) )       goto clean;
  if ( !conu_tree_insert (head, "whatevs", &err) )          goto clean;

  puts ("Print tree in preorder...");
  conu_tree_print (head);
  puts ("\n\n");

  puts ("Print tree in postorder...");
  conu_tree_print_postord (head);
  puts ("\n\n");

  puts ("Searching for nodes...\n");
  for (i = 1; i < argc; i++)
  {
    printf ("Searching for %s in tree... ", argv [i]);
    s_node = conu_tree_search_parent (head, argv [i], &parent);
    if (s_node == NULL)
      printf ("%s not found.\n", argv [i]);
    else
    {
      printf ("%s found.\n", s_node -> str);
      if (parent == NULL)
        printf ("%s is the root. no parent or siblings\n", s_node -> str);
      else
      {
        // find sibling
        if (parent -> lchild != NULL)
          if (strcmp (s_node -> str, parent -> lchild -> str) == 0)
            sibling = parent -> rchild;
          else
            sibling = parent -> lchild;
        else
          sibling = NULL;

        if (sibling != NULL)
          printf ("%s has parent %s, and has sibling %s\n", s_node -> str,
            parent -> str, sibling -> str);
        else
          printf ("%s has parent %s, and has sibling %s\n", s_node -> str,
            parent -> str, "NULL");
      }
    }

    fputc ('\n', stdout);
    assert (s_node == conu_tree_search (head, argv [i]));
  }

  clean:
    if (head != NULL) 
      conu_tree_destroy (head);
    if (err . code != CONU_SUCCESS)
      fputs (err . msg, stderr);

    return err . code;
}
