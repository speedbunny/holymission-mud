inherit "obj/monster";
#include "/players/waldo/defs.h"

reset(arg) 
{
object MONEY;

  ::reset(arg);
  if(!arg) {
    set_name("goblin");
    set_alias("dirty crap");
     set_race("goblin");
    set_size(3);
    set_al(-60);
    set_short("A goblin");
   set_long("A evil looking goblin. Kill him quickly.\n");
    set_ac(0);
    set_aggressive(0);
    set_level(11 + random(8) - 4);
    MOVE(CLONE(MYAREA+"/weapons/knife"),TO);
    init_command("wield knife");
  }
}

