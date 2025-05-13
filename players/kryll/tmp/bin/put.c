/*-------------------------------------------------------------------------*/
/* FILE : put.c                                                            */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              put objects in things.                                     */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

int put(string str) {
  int    item_wt;
  string item, only_for, container;
  object item_o, container_o;

  if(sscanf(str, "%s in %s", item, container) != 2) {
    notify_fail("Put what ?\n");
    return 1;
  }

  container = lower_case(container);
  container_o = present(container, TP);
  if(!container_o)
    container_o = present(container, ENV(TP));
  if(!container_o) {
    write("There are no " + container + "s here!\n");
    return 1;
  }

  switch(container_o->can_put_and_get()) {
    case 0:
      write("You can't do that.\n");
    case -1:          // for open/close containers. Llort */
      return 1;
  }

  item = lower_case(item);
  item_o = present(item, TP);
  if(!item_o) {
    write("You have no " + item + "!\n");
    return 1;
  }

  if(item_o == container_o)
    return 0;
  if(item_o->prevent_insert())
    return 1;
  if(item_o->drop())
    return 1;

// To allow containers to contain only one kind of object
  only_for = container_o->query_only_for();
  if(only_for) {
    if(!item_o->id(only_for)) {
      writelw("The " + container + " isn't made to contain the " +
              item + "!\n");
      return 1;
    }
  }

  item_wt = item_o->query_weight();
  if(container_o->add_weight(item_wt)) {
// Remove the weight from us.
    if(container_o->query_container() && TO==ENV(container_o))
      ENV(item_o)->add_weight(container_o->update_weight(-item_wt));
    else
      ENV(item_o)->add_weight(-item_wt);

// perhaps should be transfer
    MOVE(item_o, container_o);
    say(TP->NAME + " puts the " + item + " in the " +
        container + ".\n", 0, TP, "");
    write("Ok.\n");
    return 1;
  }
  write("There is not room for more.\n");
  return 1;
}

int main(string str) {

  notify_fail("Put what ?\n");
  if(!str)
    return 0;
  if(TP->test_dark())
    return 1;
  if(put(str))
    return 1;
  return 0;
}
