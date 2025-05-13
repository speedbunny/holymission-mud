inherit "obj/monster";
#include "/players/waldo/defs.h"

reset(arg) 
{
object MONEY;

  ::reset(arg);
  if(!arg) {
    set_name("ogre");
    set_alias("Ogre");
    set_race("ogre");
    set_size(7);
    set_al(-60);
    set_short("An ogre");
    set_long("This is a huge Ogre ... he is really mad that you have\n"+
             "disturbed him.\n");
    set_aggressive(1);
    set_level(13+random(4)-2);
    MONEY=CLONE("obj/money");
    MONEY->set_money(query_level(this_object()) * 80 );
    MOVE(MONEY,TO);
    MOVE(CLONE(MYAREA+"/weapons/sword"),TO);
    init_command("wield sword");
  }
}

