
/* coded by tinman 6/25/95 */

inherit "obj/weapon";
#include "/players/tinman/ansi.h"
  int wis;

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

    set_name(GREEN+"Emerald Claws"+RESET);
    set_alias("claws");
    set_short(GREEN+"Emerald Claws"+RESET);
    set_long(
  "This set of claws is Moose's family jewel. It is made from strange sparkling\n"+
  "green stones formed into three 1.5 feet blades. The glove part of the claws\n"+
  "is made of iron and gold plates for more flexability. The blades are\n"+
  "vibrating powerfully.\n");
    set_class(20);
    set_value(4000);
    set_weight(8);
    set_hit_func(this_object());
}

int weapon_hit(object attacker)
{
  wis = this_player()->query_wis();

  if (random(151) > (wis + 50))
  {
    write("The "+GREEN+"green blades"+RESET+" shoots out rays of bright light making ");
    say("The "+GREEN+"green blades"+RESET+" shoots out rays of bright light making ");

    attacker->reduce_hit_point(this_player()->query_wis());
    return (5 + random(wis));
}
}
wield (str) {
   ::wield(str);
   if(id(str));
     write("The "+GREEN+"blades"+RESET+" shines "+YELLOW+"bright"+RESET+"!!!\n");
    say("The "+GREEN+"blade"+RESET+" shines "+YELLOW+"bright"+RESET+" as "+this_player()->query_name()+" wields the "+GREEN+"claws"+RESET+".\n");
return 1;
}
