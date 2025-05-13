/*Code by Arthur for Holy Mission 140.78.3.1 Date done 11.11.94*/
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"
 
 object plyr;

reset (arg) {
if (arg) return;
   set_id("Super Soaker squirt gun");
   set_short("A Super Soaker squirt gun");
   set_alias("gun");
    set_long("This is a giant Super Soaker squirt gun.\n");
   set_value(300);
   set_weight(1);
}
init() {
   add_action("squirt", "squirt");
   ::init();
   }

squirt(str) {

  if (!str) 
    return 0;



  plyr = find_living(lower_case(str));
    
    if (!plyr) {
        write("No player with that name.\n");
        return 1;}

  say(capitalize(TP()->query_name())+" aims the squirt gun.\n"+
  capitalize(str)+" gets hosed by "+capitalize(TP()->query_name())+".\n");

  tell_object(plyr,"You get drenched by "+capitalize(TP()->query_name())+".\n");
  write("You drench "+capitalize(str)+".\n");

  return 1;}
