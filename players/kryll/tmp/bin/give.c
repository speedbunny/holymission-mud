/*-------------------------------------------------------------------------*/
/* FILE : give.c                                                           */
/*                                                                         */
/* Decription : This file is a bin system call that allows players to      */
/*              give objects or money to other people.                     */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
May 29 1997  Kryll        Converted to a bin system call.

*/

#include "/sys/defs.h"

object tp;

int give_object(string str) {
  string item, dest, rec_name, item_desc;
  object item_ob, dest_ob, player_env;
  int    weight, coins;

// Due to the amount of calls to this_player(), made a variable to store
// it instead. Is it helpful do you think?

  item = 0;
  if(sscanf(str, "%d coins to %s", coins, dest) == 2) {}
  else if(sscanf(str, "1 coin to %s", dest) == 1)
    coins = 1;
  else if(sscanf(str, "coin to %s", dest) == 1)
    coins = 1;
  else if(sscanf(str, "one coin to %s", dest) == 1)
    coins = 1;
  else if(sscanf(str, "%s to %s", item, dest) != 2) {
    write("Give what to whom ?\n");
    return 1;
  }

  dest = lower_case(dest);
  if(item) {
    item = lower_case(item);
    item_ob = present(item, tp);
    if(!item_ob) {
      write("There is no " + item + " here.\n");
      return 1;
    }

    it = item;
    if(ENV(item_ob)==tp && call_other(item_ob, "drop", 0)==1) {
      return 1;
    }
    else {
      if(!call_other(item_ob, "get")) {
        write("You can't get that !\n");
        return 1;
      }
    }
  }

  dest_ob = present(dest, ENV(tp));
  if(!dest_ob) {
    write("There is no " + CAP(dest) + " here.\n");
    return 1;
  }

  if(!living(dest_ob)) {
    write("You can't do that.\n");
    return 1;
  }

  if(!item) {
    if(coins<=0 && !tp->IMM)
      return 0;
    if(tp->query_money() < coins) {
      write("You don't have that much money.\n");
      return 1;
    }
    tp->add_money(-coins);

    /* Checkpoint the character, to prevent cheating */
    if(coins>500 && !tp->IMM)
      save_me(1);
    TELL(dest_ob, tp->NAME + " gives you " + coins +
                  " gold coins.\n");
    say(tp->NAME + " gives " + coins + " coin(s) to " +
        dest_ob->NAME + ".\n", dest_ob, tp,
        INVNAME + " gives " + coins + " coin(s) to " +
        dest_ob->NAME + ".\n");
    dest_ob->add_money(coins);      /* revert the msg sequence */
    write("Ok.\n");
    return 1;
  }

  weight = call_other(item_ob, "query_weight", 0);
  if(!call_other(dest_ob, "add_weight", weight)) {
    write(CAP(dest) + " can't carry any more.\n");
    return 1;
  }

  if(dest_ob->query_ghost()) {
    rec_name = lower_case(dest_ob->NAME);
    item_desc = item_ob->short();
    write("You toss " + item_desc + " through " + rec_name + ".\n");
    say(tp->NAME + " tossed " + item_desc + " through " + rec_name + ".\n",
        dest_ob, tp, INVNAME + " tossed " + item_desc + " through " +
        rec_name + ".\n");
    TELL(dest_ob, tp->NAME + " tossed " + item_desc + " through you.\n");
    TELLR(player_env=ENV(tp), CAP(item_desc) + " falls on the floor.\n");
    MOVE(item_ob, player_env);
    return 1;
  }

  if(!tp->add_weight(-weight)) {
    write("You have to give something else first!\n");
    return 0;
  }
// transfer??
  MOVE(item_ob, dest_ob);
  say(tp->NAME + " gives " + item + " to " + CAP(dest) + ".\n", 0, tp,
      INVNAME + " gives " + item + " to " + CAP(dest) + ".\n");
  write("Ok.\n");
  dest_ob->enter_inventory(item_ob);
  return 1;
}

int main(string str) {
  notify_fail("Give what ?\n");
  if(!str)
    return 0;
  tp = TP;
  if(tp->test_dark())
    return 1;
  if(give_object(str))
    return 1;
  return 0;
}
