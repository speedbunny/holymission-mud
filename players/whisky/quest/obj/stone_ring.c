#include "../monkway.h"
inherit "obj/armour";
     
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_id("stone ring");
     set_alias("ring");
     set_type("ring");
     set_short("A stone ring");
     set_long("A big heavy stone-ring.\n");
     set_weight(20);
     set_ac(0);      
     set_value(800);
  }
}
wear(str) {
     if (!id(str) || environment()!=this_player())
         return 0;
  write("You put the big heavy ring around your neck.\n");
  say(TPN+" puts the stone ring around "+TPP+" neck.\n");
  worn_by = TP;
  worn = 1;
  return 1;
 }
remove(str) {
  write("You take the stone ring from your neck.\n");
  say(TPN+" takes the stone ring from "+TPP+" neck.\n");
  worn_by = 0;
  worn = 0;
 return 1;
 }
query_quest_item() { return 1; }
