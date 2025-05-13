#include "/players/gareth/define.h"
inherit "obj/treasure";

reset(arg)
{
  if(arg) return;
  set_name("potion of clear thoughts");
  set_alias("potion");
  set_id("potion");
  set_weight(1);
  set_value(0);
  set_short("Potion of clear thoughts.");
  set_long("Potion of clear thoughts.\n");
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
  else if(str !="clear")
    return 0;
  TP->heal_self(2);
  TP->add_intoxication(-7);
  destruct(TO);
  write("The world now seems clearer to you.\n");
  say(TPN+" guzzles down a potion.\n");
  return 1;
}
 
