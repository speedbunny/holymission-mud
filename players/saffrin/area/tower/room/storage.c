#include "/players/saffrin/defs.h"
#define MAX_LIST	30

int value;
string name_of_item;

short() {
  return "The store room for Hafoc Traders";
}

init() {
  AA("east", "east");
}

inventory(str) {
  object ob;
  int max;

  if (!str)

  str = "all";
  max = MAX_LIST;
  ob = first_inventory(TO);

  while(ob && max > 0) {
      if (str == "all") {
          list(ob);
          max -= 1;
      }
      if (str == "weapons" && call_other(ob, "weapon_class", 0)) {
         list(ob);
         max -= 1;
      }
      if (str == "armours" && call_other(ob, "armour_class", 0)) {
         list(ob);
         max -= 1;
      }
     ob = next_inventory(ob);
  }
}

list(ob) {
  int value;

  value = call_other(ob, "query_value", 0);

  if (value) {
      ME(value*2 + ":\t" + call_other(ob, "short") + ".\n");
  }
}

value(item) {
  name_of_item = present(item);

  if (!name_of_item) {
      return 0;
  }
    
  value = call_other(name_of_item, "query_value", 0);
    
  if (!value) {
      return 0;
  }
    
  ME("The ");
  ME(item); 
  ME(" would cost you ");
  ME(value*2);
  ME(" gold coins.\n");
    return 1;
}

buy(item) {
  name_of_item = present(item);

  if (!name_of_item) {
      ME("No such item in the store.\n");
  return;
  }
    
  value = call_other(name_of_item, "query_value", 0);
   
  if (!value) {
       ME("Item has no value.\n");
  return;
  }
    
  value *= 2;
  
  if (call_other(TP, "query_money", 0) < value) {
      ME("It would cost you ");
      ME(value);
      ME(" gold coins, which you don't have.\n");
  return;
  }
 
  if (!call_other(TP, "add_weight",
       call_other(name_of_item, "query_weight"))) {
         ME("You can't carry that much.\n");
       return;
       }
       call_other(TP, "add_money", 0 - value);
       MOVE(name_of_item, TP);
       ME("Ok.\n");
      say(call_other(TP,"query_name")+" buys "+item+".\n");
}

east() {
  call_other(TP, "move_player",
      "leaves#"+TOWER+"room/store");
    return 1;
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

reset(arg) {
  if (!arg)
      set_light(1);

  if (!present("lantern")) {
      object torch;
      torch = CLONE("obj/torch");
      call_other(torch, "set_name", "lantern");
      call_other(torch, "set_fuel", 2000);
      call_other(torch, "set_weight", 1);
      MOVE(torch, TO);
   }

  if (!present("ball")) {
      object ball;
      ball = CLONE(TOWER+"obj/magicball");
      MOVE(ball, TO);
   }
}

long(){
  ME("The storage room of Hafoc Traders.  You should NOT be in here.\n");
}

store(item){
  string short_desc;
  object ob;

  short_desc = call_other(item, "short");
  ob = first_inventory(TO);
   
  while(ob) {
      if (call_other(ob, "short") == short_desc || item->id("bottle")) {
         MOVE(item, TO);
         DEST(item);
      return;
      }
      ob = next_inventory(ob);
  }
  MOVE(item, TO);
}
