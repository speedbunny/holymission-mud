#define MUST_STAY_WITH_DRINKS

query_property(str) { return str=="no_teleport"; }

reset (arg) {
  if (arg) return;
  set_light(2);
}
short() {return "goblin pub"; }
init() {
     add_action("move","up"); 
     add_action("order","order");
     add_action("buy","buy");
}
move() {
#ifdef MUST_STAY_WITH_DRINKS
       if(has_drink(this_player())) {
       tell_object(this_player(),"Sorry, you have to drink that here.\n");
 return 1;
}
#endif
call_other(this_player(),"move_player","up#players/jake/goblin/gob3");
return 1;
}
long () {
   write ("You are in the Goblin Pub.\n");
   write ("Drinks available are:        \n\n");
   write ("     Goblin Beer       : 15 coins\n");
   write ("     Goblin Tickler    : 50 coins\n");
   write ("     Goblin Dreamer    : 150 coins\n\n");
   write (" A stairway leads back up to the surface\n");
}
order (str) {
object drink;
  string name, short_desc, mess;
    int value, cost, strength, heal;
if (!str) {
  write ("We don't have that here!\n");
return 1;
}
if (str=="beer") {
name = str;
short_desc = "A bottle of green beer";
 mess = "That is some good beer!";
heal = 1;
value = 14;
strength = 2;
}
else if (str=="tickler" || str=="goblin tickler"){
name="tickler";
short_desc = "A goblin tickler";
mess = "Your lips pucker up to the tangy flavor";
heal = 10;
value = 50;
strength = 8;
}
else if (str=="dreamer" || str=="goblin dreamer"){
name = "goblin dreamer";
short_desc = "A dreamy looking blue bottle";
mess = "You gaze off into space";
heal = 25;
value = 150;
strength = 12;
}
else {
 write ("We don't serve that here!\n");
return 1;
}
if (call_other(this_player(), "query_money", 0) < value)
{ write ("That costs " + value + "gold coins, which you don't have.\n");
return 1;
}
drink = clone_object ("obj/drink");
 if(!call_other(this_player(), "add_weight",
   call_other(drink,"query_weight"))){
 write ("You can;'t carry more.\n");
 destruct(drink);
return 1;
}
if (!call_other(drink,"set_value",name + "#" + short_desc + "#" + mess + "#" + heal + "#" + value + "#" + strength)) {
write ("Error in creating drink.\n");
destruct (drink);
return 1;
}
call_other (drink,"set_pub");
move_object(drink,this_player());
call_other(this_player(),"add_money",-value);
write ("You pay " + value + " for a " + name + ".\n");
say(call_other(this_player(),"query_name", 0) + "orders a " + name + ".\n");
return 1;
}
#ifdef MUST_STAY_WITH_DRINKS
has_drink (obj) {
   status drink;
   object ob;
ob = first_inventory(obj);
while(ob) {
   if(call_other(obj,"can_put_and_get")) {
  if (has_drink(ob))
      drink = 1;
}
ob = next_inventory(ob);
}
return drink;
}
#endif
