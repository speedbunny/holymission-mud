inherit "obj/weapon";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

     set_name("giant slayer");
     set_short("A Giant Slayer");
     set_alias("slayer");
     set_long("This fine blade is engraved with magic runes\n");
     set_class(15);
     set_weight(4);
     set_value(5000);
     set_hit_func(this_object());
}

int weapon_hit(object target) 
{
  if (target->id("giant")) 
  {
    write("The slayer delves deeply into "+target->NAME+"'s body.\n");
    return 25 + random(16);
  }
  return 0;
}
