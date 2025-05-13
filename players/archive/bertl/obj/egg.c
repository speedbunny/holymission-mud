/*Code by Arthur for Holy Mission 140.78.3.1 Date done 11.11.94*/
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"
 
 object plyr;

reset (arg) {
if (arg) return;
   set_id("Egg");
   set_short("An Egg");
   set_alias("egg");
   set_long("This is a dinosour egg. You have the feeling that there are many uses for\n"+
   "it.\n");
   set_value(300);
   set_weight(1);
}
init() {
   add_action("throw", "throw");
   add_action("eat", "eat");
   ::init();
   }

throw(str) {
 string player;

  if (!str) 
    return 0;


  if(sscanf(str, "egg at %s",player) != 1)
    return 0;

  if (lower_case(player) == "bertl") {
   player =TP()->query_real_name(); }

  plyr = find_living(lower_case(player));
    
    if (!plyr) {
        write("No player with that name.\n");
        return 1;}

  shout(capitalize(TP()->query_real_name())+" hurls a giant egg into the sky!\n"+
  capitalize(player)+" is hit dead center in the face by the egg.\n");

  tell_object(plyr,"You are hit in the face with a giant egg.\n"+
  "You hear "+capitalize(TP()->query_real_name())+" laughing at you!\n");
  write("You hit "+capitalize(player)+" dead center in the face.\n");

   destruct(this_object());

  return 1;}
