#include "/players/tamina/defs.h"

inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 
  set_name("blue wand");
  set_alias("wand");
  set_short("A blue wand");
  set_long("A small, blue wand, with a spidery scrawl etched on it.\n"); 
  set_class(3);
  set_type(3);
  set_value(100);
  set_weight(2);
  set_hit_func(TO);
}

weapon_hit(attacker) {
   if(attacker->id("merlin")) {
    write("You see sparks fly from the tip of your wand to -=>SLAY<=- Merlin!\n");
    say(TPN+" -=>SLAYS<=- Merlin!!\n");
   return 500 + random(501);

    }

}
