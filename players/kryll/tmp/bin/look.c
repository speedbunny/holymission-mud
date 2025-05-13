/*-------------------------------------------------------------------------*/
/* FILE : look.c                                                           */
/*                                                                         */
/* Decription : This file is a bin system call that allows the player to   */
/*              look, either around or at something.                       */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

private static int do_look(string str, string item) {
  object ob, ob_tmp, *all, *inv, special;
  string short_str, msg, position, extra_str;
  int    max, i, sz, weight;

  item = lower_case(item);
  ob = present(item, TP);
  if(!ob && call_other(ENV(TP), "id", item))
    ob = ENV(TP);
  if(!ob)
    ob = present(item, ENV(TP));
  if(!ob) {
    notify_fail("You see nothing of interest.\n");
    return 0;
  }
  it = item;
  call_other(ob, "long", item);
  weight = ob->query_weight();
  if(ob->can_put_and_get(item) < 1)   /* <1 for container */
    return 1;
  if(living(ob)) {
    special = first_inventory(ob);
    while(special) {
      extra_str = call_other(special, "extra_look");
      if(extra_str)
        writelw(extra_str + ".\n");
      special = next_inventory(special);
    }
  }
  ob_tmp = first_inventory(ob);
  while(ob_tmp && call_other(ob_tmp, "short")==0)
    ob_tmp = next_inventory(ob_tmp);
  if(ob_tmp) {
    if(living(ob)) {
      write("\t" + CAP(item) + " is carrying:\n");
    }
    else
      write("\t" + CAP(item) + " contains:\n");
  }

// only thieves and wizards see the full inventory of a player
// why????

  if(!living(ob) || ob->query_npc() || TP->IMM || TP->query_guild()==1) {
    max = MAX_LIST;
    msg = "";
    ob = first_inventory(ob);

    while(ob && max>0) {
      if(short_str = ob->short())
        msg += CAP(short_str) + ".\n";
        ob = next_inventory(ob);
        max -= 1;
    }
    if(ob && !max)
      msg += "\n";
    write(msg);
  }
  else {
    // lightsources
    inv = all_inventory(ob);
    all = ({});
    all += filter_objects(inv, "query_is_lit");
    inv = inv - all;
    // worn armour
    all += filter_objects(inv, "query_worn");
    inv = inv - all;
    // wielded weapons
    all += filter_objects(inv, "query_wielded");
    msg = "";
    for(sz=sizeof(all), i=0; i<sz; i++) {
      if(short_str = all[i]->short())
        msg += CAP(short_str) + "\n";
    }
    if(strlen(msg) > 1)
      write(msg);
  }
  if(TP->INV<L_APPR && (ob=find_player(item)) && ob!=TP) {
    TELL(ob, TP->NAME + " looks at you.\n", TP);
    say(TP->RNAME + " looks at " + ob->NAME + ".\n", ob, TP, "");
  }
  return 1;
}

int main(string str) {
  object ob, ob_tmp, *all, *inv;
  string item, short_str, msg, position;
  int    max, i, sz, weight;

  if(TP->test_dark()) {
    write("It's too dark.\n");
    return 1;
  }

  if(!str)
    return TP->mylook(0);

  if(sscanf(str, "at %s", item)==1 || sscanf(str, "in %s", item)==1) {
    if(do_look(str, item))
      return 1;
    return 0;
  }
  write("Look AT something, or what?\n");
  return 1;
}

