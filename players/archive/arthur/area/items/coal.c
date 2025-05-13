/*Code by Arthur for Holy Mission 140.78.3.1 Date done 11.11.94*/
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"
 
 object plyr;

reset (arg) {
if (arg) return;
   set_id("Coal");
   set_short("A lump of Coal");
   set_alias("coal");
   set_long("You must have been very bad to have recieved a lump of coal!\n");
   set_value(0);
   set_weight(0);
}
init() {
   add_action("throw", "throw");
   ::init();
   }

throw(str) {
 string player;

  if(!TP()->query_immortal()) {return 0;}
  if (!str) 
    return 0;


  if(sscanf(str, "coal at %s",player) !=1)
    return 0;

  if (lower_case(player) == "arthur") {
   player =TP()->query_real_name(); }

  plyr = find_living(lower_case(player));
    
    if (!plyr) {
        write("No player with that name.\n");
        return 1;}

  write("You give"+capitalize(player)+" a lump of coal!\n");
  tell_object(plyr,"You must have been a bad person, You just recieved a lump of coal!!!!\n");
  transfer(this_object(),plyr);

  return 1;}
