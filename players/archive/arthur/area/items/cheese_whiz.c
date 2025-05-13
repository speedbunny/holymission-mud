/*Code by Arthur for Holy Mission - 140.78.3.1 Date Done 11.4.94 */
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"


reset (arg) {
if (arg) return;
   set_id("Cheese Whiz");
   set_short("A can of Cheese Whiz");
   set_alias("cheese");
    set_long("A small can of Cheese Whiz\n");
   set_value(0);
   set_weight(0);
}
init() {
     add_action("wf","squirt");
     ::init();
}
no_see() {
  write("You try to look around, but alas you are blinded by slimy egg\n"+
  "yolk. Maybe you should try wiping your face to remove the egg yolk.\n");
  return 1;}

wf(str) {

  if(!str) return 0;
  
  if(str !="cheese whiz") return 0;
  
  write("You empty the can of cheeze whiz in your mouth.\n");
   say(TP()->query_name()+" downs a can of cheesewhiz.\n");
  destruct(this_object()); return 1;
  }
