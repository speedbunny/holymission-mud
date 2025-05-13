/* From /room/store.c , slightly recoded by Matt -- 4/20/93 */
/* Recoded even more - Redsexy 3/99 */

inherit "/room/room";

#include "/players/matt/defs.h"

#define MAX_LIST 30

int value;
string name_of_item;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Store Room";
  long_desc = "All things from the shop are stored here.\n";
  dest_dir = ({
    "/room/main_shop","south",
  });
}

inventory(str) {
  int max;
  object ob;
  if(!str) str = "all";
  max = MAX_LIST;
  ob = first_inventory(TO);
  while(ob && max > 0) {
    if(str == "all") {
      list(ob);
      max -= 1;
    }
    if((str == "weapon" || str == "weapons") && ob->weapon_class()) {
      list(ob);
      max -= 1;
    }
    if((str == "armour" || str == "armours") && ob->armour_class()) {
      list(ob);
      max -= 1;
    }
    ob = next_inventory(ob);
  }
}

list(ob) {
  int value;
  value = call_other(ob, "query_value", 0);
  if(value) write(value * 2 + ":\t" + ob->SHORT + ".\n");
}

value(item) {
  name_of_item = present(item);
  if(!name_of_item) return;
  value = name_of_item->query_value();
  if(!value) return;
  write("The " + item + " would cost you ");
  write((value * 2) + " gold coins.\n");
  return 1;
}

buy(item) {
  name_of_item = present(item);
  if (!name_of_item) {
    write("No such item in the store.\n");
    return;
  }
  value = name_of_item->query_value();
  if (!value) {
    write("Item has no value.\n");
    return;
  }
  value *= 2;
  if (TP->query_money() < value) {
    write("It would cost you " + value);
    write(" gold coins, which you don't have.\n");
    return;
  }
  if (!TP->add_weight(name_of_item->query_weight())) {
    write("You can't carry that much.\n");
    return;
  }
  TP->add_money(-value);
  MOVE(name_of_item, TP);
  write("Ok.\n");
  say(TP->NAME + " buys " + item + ".\n");
}

heart_beat() {
  object ob, next_ob;
  ob = first_inventory(TO);
  while(ob) {
    next_ob = next_inventory(ob);
    destruct(ob);
    ob = next_ob;
  }
}

store(item) {
  string short_desc,name;
  object ob;
  short_desc = item->short();
  name = item->query_name();
  ob = 0;
  if(name) ob=present(name, TO);
  else if(short_desc) ob=present(short_desc, TO);
  if(!ob) ob = first_inventory(TO);
  while(ob) {
    if (ob->SHORT == short_desc || item->id("bottle")) {
      MOVE(item, TO);
      destruct(item);
      return;
    }
    ob = next_inventory(ob);
  }
  MOVE(item, TO);
}
