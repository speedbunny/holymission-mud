inherit "room/room";

object potion, top_list;
string name, short_desc, mess;
int value, cast, heal;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Ye Olde Alchemist Shoppe";
    long_desc =
"You are in Ye Olde Alchemist Shoppe.\n"+
"The shelves are packed with potions of every size and color.\n"+
"A list of prices hanging over the counter reads:\n"+
"potion of cure light wounds...........:   450 coins\n"+
"potion of cure serious wounds.........:  1800 coins\n"+
"potion of cure critical wounds........:  3600 coins\n"+
"potion of complete heal...............: 12000 coins\n"+
"These potions are portable and you CAN take 'em with you.\n";
    dest_dir = ({
"players/ted/path/road1", "south"
    });
  }
  if(!present("list")) {
    top_list = clone_object("obj/level_list");
    move_object(top_list, this_object());
  }
}

init() {
  ::init();
 add_action("order"); add_verb("order");
 add_action("order"); add_verb("buy");
}

order(str) {
 if(!str) {
 write("What is it you want to buy?\n");
 return 1;
 }
 else if(str == "light" ) {
 potion = clone_object("players/ted/items/potion");
 call_other(potion, "set_name", "cure light");
 call_other(potion, "set_alias", "light");
 call_other(potion, "set_short", "Potion of Cure Light Wounds");
 call_other(potion, "set_heal", 15);
 call_other(potion, "set_mess", "You feel a little better.\n");
 call_other(potion, "set_weight", 1);
 call_other(potion, "set_value", 150 );
  value = 450;
  name = "light";
 }
 else if(str == "serious") {
  potion = clone_object("players/ted/items/potion");
 call_other(potion, "set_name", "cure serious");
 call_other(potion, "set_alias", "serious");
 call_other(potion, "set_short", "Potion of Cure Serious Wounds");
 call_other(potion, "set_heal", 30);
 call_other(potion, "set_mess", "You feel better.\n");
 call_other(potion, "set_weight", 1);
 call_other(potion, "set_value", 600 );
  value = 1800;
  name = "serious";
 }
 else if(str == "critical") {
  potion = clone_object("players/ted/items/potion");
 call_other(potion, "set_name", "cure critical");
 call_other(potion, "set_alias", "critical");
 call_other(potion, "set_short", "Potion of Cure Critical Wounds");
 call_other(potion, "set_heal", 60);
 call_other(potion, "set_mess", "You feel a lot better.\n");
 call_other(potion, "set_weight", 1);
 call_other(potion, "set_value", 1350 );
  value = 3600;
  name = "critical";
 }
 else if(str == "heal") {
  potion = clone_object("players/ted/items/potion");
 call_other(potion, "set_name", "Heal");
 call_other(potion, "set_alias", "heal");
 call_other(potion, "set_short", "Potion of Compleat Heal");
 call_other(potion, "set_heal", 1000);
 call_other(potion, "set_mess", "You are totaly healed.\n");
 call_other(potion, "set_weight", 1);
 call_other(potion, "set_value", 6000 );
  value = 12000;
  name = "heal";
 }
 else {
  write("what?\n");
  return 1;
 }
 if(this_player()->query_money() < value) {
  write("That costs "+value+" coins, which you do not have.\n");
  return 1;
 }
 if(!this_player()->add_weight(potion->query_weight())) {
   write("You can't carry anymore.\n");
   destruct(potion);
   return 1;
 }
 move_object(potion, this_player());
 call_other(this_player(),"add_money", -value);
 write("You pay "+value+" for a "+name+".\n");
 say(capitalize(this_player()->query_name())+" purchases a "+name+".\n");
 return 1;
}
