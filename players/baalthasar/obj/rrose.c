inherit "obj/treasure";
#include "/players/baalthasar/shadows/path.h"

object plyr;

reset(arg) {
if(arg) return;
  set_id("Rose");
  set_short("A black rose");
  set_alias("rose");
  set_long("This is a lovely black rose with an imprint on a petal that \n"+
"resembles a horned demon.  (not horny you perv!) \n");
  set_value(100);
  set_weight(1);
}

init() {
  add_action("send", "send");
  add_action("smell", "smell");
::init();
}

send(str) {
  string player;

 if (!str)
 return 0;

if(sscanf(str, "rose to %s",player) != 1)
 return 0;

plyr = find_living(lower_case(player));
  if (!plyr) {
   write("No player with that name.\n");
   return 1; }

write("You have sent "+capitalize(player)+" a black rose.\n");

move_object(this_object(),plyr);
tell_object(plyr,"A black portal suddenly materializes before you!\n");
tell_object(plyr,"A little red demon pops out and hands you a single flower.\n"+
"The small red demon giggles and jumps back into the hole and vanishes!\n\n");
say("A black portal suddenly materializes before you! \n");
say("A little red demon pops out and hands "+capitalize(player)+" a flower. \n");
say("The demon giggles and jumps back into the hole and vanishes!\n\n");

return 1; }

smell(str) {
  string rose;
if(str!="rose") return 0;

say(TPN+" sniffs at a black rose.\n");
write("You put the flower to your nose and take a deep breath...\n"+
"The sweet smell relaxes you.\n");
return 1; }
