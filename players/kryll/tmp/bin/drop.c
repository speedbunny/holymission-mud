/*-------------------------------------------------------------------------*/
/* FILE : drop.c                                                           */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              drop objects or money.                                     */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"
#include "/sys/player_defs.h"

int drop_one_item(object ob) {
  int weight;

  if(call_other(ob, "drop", 0))
    return 0;
  weight = call_other(ob, "query_weight", 0);
  if(!weight)
    weight = 0;
  if(!TP->add_weight(-weight)) {
    write("You have to drop something else first!\n");
    return 0;
  }
  MOVE(ob, ENV(TP));
  return 1;
}

void drop_all(int val) {
  object ob, next_ob;
  string out, item_desc;

  if(!TP || !living(TP))
    return;
  ob = first_inventory(TP);
  while(ob) {
    next_ob = next_inventory(ob);
    item_desc = call_other(ob, "short", 0);
    if(drop_one_item(ob) && val) {
      out = item_desc + ".\n";
      say(lw(TP->NAME + " drops " + out), 0, TP,
          CAP(item_desc) + " appears from thin air.\n");
      TELL(TP, "drop: " + out);
    }
    ob = next_ob;
  }
  return;
}

int drop_thing(string str) {
  int amt;
  object ob;

  if(sscanf(str, "%d coins", amt)==1 || sscanf(str, "%d coin", amt)==1 ) {
    if(TP->query_money() < amt) {
      write("You don't have that much money.\n");
      return 1;
    }
    if(amt < 1)
      return 0;
    TP->add_money(-amt);
    ob = clone_object("obj/money");
    ob->set_money(amt);
    MOVE(ob, ENV(TP));
    say(TP->NAME + " drops " + amt + " gold coin" + (amt>1 ? "s.\n" : ".\n"),
        0, TP, amt + " gold coin" + (amt>1 ? "s" : "") +
        " appear out of thin air.\n");
    write("Ok.\n");
    return 1;
  }

  if(str=="money" || str=="all money") {
    write("You don't want to do that.\n");
    return 1;
  }

  ob  = present(lower_case(str), TP);
  if(!ob) {
    write("That is not here.\n");
    return 1;
  }

  if(drop_one_item(ob)) {
    write("Ok.\n");
    say(TP->NAME + " drops the " + str + ".\n", 0, TP,
        CAP(str) + " appears out of thin air.\n");
  }
  return 1;
}

int main(string str) {
  string tmp, tmp2;

  if(!obj) {
    notify_fail("Drop what ?\n");
    return 0;
  }

  if(str == "all") {
    drop_all(1);
    return 1;
  }

  if(sscanf(str, "%s in %s", tmp, tmp2) == 2) {
    if((PLAYER + "put")->main(str))
      return 1;
    return 0;
  }

  if(drop_thing(str))
    return 1;
  return 0;
}

