inherit "obj/weapon";
#include "/players/blaarg/defs.h"
int wis;

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

    set_name("Emerald Claws");
    set_alias("claws");
    set_short("Emerald Claws");
    set_long(
  "This set of claws is Moose's family jewel. It is made from strange sparkling\n"+
  "green stones formed into three 1.5 feet blades. The glove part of the claws\n"+
  "is made of iron and gold plates for more flexability. The blades are\n"+
  "vibrating powerfully.\n");
    set_class(20);
    set_value(4000);
    set_weight(8);
}

}
wield (str) {
   ::wield(str);
   if(id(str));
   write("The blades shine brightly!!!\n");
   say("The blades shine brightly as "+this_player()->capitalize(query_real_name())+" wields the claws.\n");
   return 1;
}
