/*-------------------------------------------------------------------------*/
/* FILE : take.c                                                           */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              take item(s) into his/her possession.                      */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

nomask private static void get_all(object from_ob) {
  object ob, next_ob;
  string item;
  int weight;

  ob = first_inventory(from);
  while(ob) {
    next_ob = next_inventory(ob);
    item = ob->short();
    if(item && ob->get()) {
      weight = ob->query_weight();
      if(from->query_container() && TP==ENV(from_ob))
        weight = -from_ob->update_weight(-weight);
      if(TP->add_weight(weight)) {
        from->add_weight(-ob->query_weight());
        write(item + ": Ok.\n");
        say(TP->RNAME + " takes: " + item + ".\n", 0, TP,
            INVNAME + " takes: " + item + ".\n");
// transfer?
        MOVE(ob, TP);
      }
      else 
        write(item + ": Too heavy.\n");
      it = item;
    }
    ob = next_ob;
  }
  return;
}

nomask private static int pick_item(string str) {
  object ob;
  int i;

  str = lower_case(str);
  if(ENV(TP)->id(str)) {
    write("You can't take that.\n");
    return 1;
  }

  ob = present(str, ENV(TP));
  if(!ob) {
    write("That is not here.\n");
    return 1;
  }

  if(ENV(ob) == TP) {
    write("You already have it!\n");
    return 1;
  }

  if(call_other(ob, "get", 0) == 0) {
    write("You cannot take that!\n");
    return 1;
  }

  i = call_other(ob, "query_weight", 0);
  if(TP->add_weight(i)) {
// transfer?
    MOVE(ob, TP);
    say(TP->RNAME + " takes " + str + ".\n", 0, TP,
        INVNAME + " takes " + str + ".\n");
    write("Ok.\n");
    return 1;
  }

  write("You can't carry that much.\n");
  return 1;
}


int main(string str) {
  string item, container;
  object item_o, container_o;
  int    weight;

  if(!str) {
    notify_fail("Take what ?\n");
    return 1;
  }
  if(TP->query_ghost()) {
    write("Your incorporeal hand passes right through it.\n");
    return 1;
  }
  if(TP->test_dark())
    return 1;

  if(str == "all") {
    get_all(ENV(TP));
    return 1;
  }

  if(sscanf(str, "%s from %s", item, container) != 2) {
    pick_item(str);
    return 1;
  }

  container_o = present(lower_case(container));
  if(!container_o) {
    write("There is no " + container + " here.\n");
    return 1;
  }

  switch(container_o->can_put_and_get()) {
    case 0:
      write("You can't do that!\n");
    case -1:
      return 1;
  }

  if(item == "all") {
    get_all(container_o);
    return 1;
  }

  item_o = present(item, container_o);
  if(!item_o) {
    write("There is no " + item + " in the " + container + ".\n");
    return 1;
  }

  if(!item_o->get(item)) {
    write("You can not take " + item + " from " + container + ".\n");
    return 1;
  }

  weight = item_o->query_weight();
  if(container_o->query_container() && TP==ENV(container_o))
    weight = -container_o->update_weight(-weight);

  if(!TP->add_weight(weight)) {
    write("You cannot carry more.\n");
    return 1;
  }

  container_o->add_weight(-item_o->query_weight());
// perhaps should be a transfer
  MOVE(item_o, TP);
  write("Ok.\n");
  say(TP->RNAME + " takes " + item + " from " + container + ".\n", 0, TP, "");
  return 1;
}

