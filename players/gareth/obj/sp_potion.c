inherit "obj/treasure";
#include "/players/gareth/define.h"
reset(arg)
{
  if(arg) return;
  set_name("potion of mental endurance");
  set_alias("potion");
  set_id("potion");
  set_weight(1);
  set_value(0);
  set_short("Potion of mental endurance.");
  set_long("Potion of mental endurance.\n");
}
 
init()
{
  ::init();
  add_action("drink_fnc","drink");
}
 
drink_fnc(str)
{
  if(!str) return 0;
  if(str=="potion")
  {
    write("Syntax: drink <heal> <xtra> <remove> <mental>\n"+
          "<invul> <resist> <clear>\n");
    return 1;
  }
  else if(str !="mental")
    return 0;
  TP->restore_spell_points(200);
  TP->add_intoxication(13);
  destruct(TO);
  write("Whoa! Your mind runs wild with new power.\n");
  say(TPN+" guzzles down a potion.\n");
  return 1;
}
 
