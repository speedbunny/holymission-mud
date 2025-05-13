/*Code by Arthur for Holy Mission 140.78.3.1 Date done 11.11.94*/
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"
 
 object plyr;

reset (arg) {
if (arg) return;
   set_id("Oreo");
   set_short("An Oreo");
   set_alias("oreo");
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


  if(sscanf(str, "oreo at %s",player) != 1)
    return 0;

  if (lower_case(player) == "arthur") {
   player =TP()->query_real_name(); }

  plyr = find_living(lower_case(player));
    
    if (!plyr) {
        write("No player with that name.\n");
        return 1;}


  tell_object(plyr,"You see an Oreo Flying directly towards you,\n"+
  "as it comes falling down you turn your head toward the sky and catch\n"+
  "it in your teath and eat it whole.\n"+
  "You see "+capitalize(TP()->query_name())+" cheer you on.\n");
  write("Good Shot.\n");

   destruct(this_object());

  return 1;}
