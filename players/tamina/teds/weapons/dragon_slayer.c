inherit "obj/weapon";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

     set_name("dragon slayer");
     set_short("A Dragon Slayer");
     set_alias("slayer");
     set_long("This fine blade is engraved with magic runes and two words\n"+
              "\tDraconis Executis\n");
     set_class(14);
     set_weight(4);
     set_value(4500);
     set_hit_func(this_object());
}

int weapon_hit(object target) 
{
  if (target->id("dragon")) 
  {
    write("The Slayer slashes deep into "+target->NAME+"'s flesh.\n");
    return 20 + random((TP->INT + TP->LVL)/2);
  }
  return 0;
}
