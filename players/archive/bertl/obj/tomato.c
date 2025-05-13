/*Code by Arthur for Holy Mission 140.78.3.1 Date done 11.11.94*/
/* modified to Tomato by Bertl 25.11.94 */
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"
 
 object plyr;

reset (arg) {
if (arg) return;
   set_id("Tomato");
   set_short("A Tomato");
   set_alias("tomato");
   set_long("This is a half-rotten tomato. You have the feeling that there is only one use\n"+
   "for it.\n");
   set_value(300);
   set_weight(1);
}
init() {
   add_action("throw", "throw");
   ::init();
   }

throw(str) {
 string player;

  if (!str) 
    return 0;


  if(sscanf(str, "tomato at %s",player) != 1)
    return 0;

  if (lower_case(player) == "bertl") {
   player =TP()->query_real_name(); }

  plyr = find_living(lower_case(player));
    
    if (!plyr) {
        write("No player with that name.\n");
        return 1;}

  shout(capitalize(TP()->query_real_name())+" sends a half-rotten tomato"+
  " into the sky!\n"+
 capitalize(player)+" is hit and the jam spreads all over his face.\n");

  tell_object(plyr,"You are hit in the face with a half-rotten tomato.\n"+
  "You hear "+capitalize(TP()->query_real_name())+" laughing at you!\n");
  write("You hit "+capitalize(player)+" dead center in the face.\n");

   destruct(this_object());

  return 1;}
