inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int have_cloak;


int _get(string arg){
  object cloak;
  if(!arg){
    return 0;
  }
  if(arg != "cloak"){
    return 0;
  }
  if(have_cloak == 0){
    write("You get the dwarven cloak.\n");
    say(capitalize(TP->query_name())+" gets a dwarven cloak.\n");
    cloak = clone_object("/players/brainsprain/bis/quest2/qcloak.c");
    move_object(cloak,TP);
    have_cloak = 1;
    long_desc =
      "The smell of alcohol dominates this room.  Inadequate lighting barely "+
      "  reveals several tables at the center of the room.  Along the western\n"+
      "  wall is a bar from behind which a one-eyed woman watches you intently\n"+
      "  Along the eastern wall is a stage where the newest act is performing.\n"+
      "  To the south is an entrance to the coffee shop.\n"+
      "           Here are the things you can order:\n"+
      "                 Beer:          12 coins\n"+
      "                 Ale:           40 coins\n"+
      "                 Mead:          40 coins\n"+
      "                 House special: 50 coins\n"+
      "                 Gin:          100 coins\n"+
      "\n";
    
    return 1;
  }
  return 0;
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
  if (str == "beer") {
    name = str;
    short_desc = "A bottle of beer";
    mess = "That feels good";
    heal = 0;
    value = 12;
    strength = 2;
  }
  else if (str == "special" || str == "special of the house") {
    name = "special";
    short_desc = "A special of the house";
    mess = "A tingling feeling goes through your body";
    heal = 10;
    value = 50;
    strength = 8;
  }
  else if (str == "ale"){
    name = str;
    short_desc = "A bottle of ale";
    mess = "MMMM!! That is smooth";
    heal = 5;
    value = 40;
    strength = 3;
  }
  else if (str == "gin"){
    name = str;
    short_desc = "A container of gin";
    mess = "The gin burns as you swallow it";
    heal = 7;
    value = 100;
    strength = 5;
  }
  else if (str == "mead"){
    name = str;
    short_desc = "A bottle of mead";
    mess = "Mead!!! Thats good!!";
    heal = 5;
    value = 40;
    strength = 3;
  }    else {
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
  if (str != "coffee") {
    if (!call_other(drink, "set_value", name + "#" + short_desc + "#" + mess
		    +
		    "#" + heal + "#" + value + "#" + strength)) {
      write("Error in creating drink.\n");
      destruct(drink);
      return 1;
    }
  }
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

  set_light(1);
  short_desc = "The Towpath Town Pub";
  have_cloak = 0;
  long_desc =
    "The smell of alcohol dominates this room.  Inadequate lighting barely "+
    "reveals several tables at the center of the room.  Along the western "+
    "wall is a bar from behind which a one-eyed woman watches you intently "+
    "Along the eastern wall is a stage where the newest act is performing. "+
    "To the south is an entrance to the coffee shop.  Right next to the door "+
    "is a coat rack.\n"+
    "           Here are the things you can order:\n"+
    "                 Beer:          12 coins\n"+
    "                 Ale:           40 coins\n"+
    "                 Mead:          40 coins\n"+
    "                 House special: 50 coins\n"+
    "                 Gin:          100 coins\n";
  
  items = ({
    "woman",
    "The bar owner",
    "room",
    "The bar room",
    "wall",
    "A bar sits along the western wall",
    "table",
    "Old tables with burn marks and spill stains on them",
    "alcohol",
    "This bar has a very standard selection",
    "tables",
    "Old tables with burn marks and spill stains on them",
    "bar",
    "A beautiful mahogany bar with a brass rail",
    "stage",
    "A stage to rival any opera house in the land",
    "act",
    "The latest nude dance review",
    "act",
    "A poet reading zen poetry",
    "entrance",
    "The entrance to the coffee shop",
    "shop",
    "A coffee shop",
    "rack",
    "There is one cloak hanging on the rack",
    "cloak",
    "This is a thick cloak that makes anyone look like a dwarf",
  });
  dest_dir = ({
    br+"/tr-8.c","north",
    br+"/coffee.c","south",
  });
}
void init() {
  ::init();
  add_action("order", "order");
  add_action("order", "buy");
  add_action("_get","get");
  add_action("_get","take");
}

