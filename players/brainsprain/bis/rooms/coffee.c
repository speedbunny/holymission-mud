inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

int do_lis(string arg)
{
  if(arg != "to poet"){
    write("Listen to whom?\n");
    return 1;
  }
  else {
    write("The poet clears his throat.\n");
    call_out("l1",5);
    call_out("l2",10);
    call_out("l3",15);
    return 1;
  }
}
int l1(){
  remove_call_out("l1");
  write("Big Pond.\n");
  return 1;
}
int l2(){
  remove_call_out("l2");
  write("Frog Jumping.\n");
  return 1;
}
int l3(){
  remove_call_out("l3");
  write("Plop!\n");
  return 1;
}


int order(string str)
{
  object drink;
  string name, short_desc, mess;
  int value, cost, strength, heal;
  
  if (!str) {
    write("Order what ?\n");
    return 1;
  }
  if (str == "coffee") {
    name = str;
    short_desc = "A mug of coffee";
    mess = "Warm coffee clears your head";
    heal = 0;
    value = 10;
    strength = -1;
  }
  else if (str == "double" || str == "double espresso") {
    name = "double";
    short_desc = "A Double Espresso";
    mess = "The caffeine rushes through your veins";
    heal = 10;
    value = 400;
    strength = -30;
  }
  else if (str == "espresso"){
    name = str;
    short_desc = "A small cup of espresso";
    mess = "Wow thats strong!";
    heal = 5;
    value = 50;
    strength = -10;
  }
  else if (str == "cappucino"){
    name = str;
    short_desc = "A frothing cup of cappucino";
    mess = "You drink the cup, leaving a milk mustache";
    heal = 5;
    value = 40;
    strength = 3;
  }
  else {
    write("What ?\n");
    return 1;
  }
  if (call_other(this_player(), "query_money", 0) < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  drink = clone_object("obj/drink");
  if (!call_other(this_player(), "add_weight",
		  call_other(drink, "query_weight"))) {
    write("You can't carry more.\n");
    destruct(drink);
    return 1;
  }
  if (!call_other(drink, "set_value", name + "#" + short_desc + "#" + mess
		  +
		  "#" + heal + "#" + value + "#" + strength)) {
    write("Error in creating drink.\n");
    destruct(drink);
    return 1;
  }
  
  drink->set_empty_container("cup");
  call_other(drink, "set_pub");
  move_object(drink, this_player());
  call_other(this_player(), "add_money", - value);
  write("You pay " + value + " for a " + name + ".\n");
  say(call_other(this_player(), "query_name", 0) + " orders a " +
      name + ".\n");
  return 1;
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_light( 1);
  short_desc = "The Coffee Shop";
  long_desc =
    "The smell of gourmet coffee fills the room.  A counter sits against "+
    "the eastern wall.  On the counter is a cappucino machine.  Several "+
    "Avant-garde citizens sit at tables listening to a poet perform on stage.\n"+
    "           Here are the things you can order:\n"+
    "                 Coffee:           10 coins\n"+
    "                 Cappucino:        40 coins\n"+
    "                 Espresso:         50 coins\n"+
    "                 Double Espresso: 400 coins\n";
  
  items = ({
    "wall",
    "A grease smeared wall",
    "machine",
    "A cappucino machine, frothing milk",
    "counter",
    "A smooth iron counter",
    "citizens",
    "Well dressed people, snapping their fingers",
    "poet",
    "An old beat poet, 'listen' to him",
  });
  dest_dir = ({
    br+"/bar.c","north",
    br+"/tr-11.c","west",
  });
}
void init(){
  ::init();
  add_action("order", "order");
  add_action("order", "buy");
  add_action("do_lis","listen");
}

