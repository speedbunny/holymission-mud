inherit "obj/monster";
#include "/players/waldo/defs.h"

reset(arg) 
{
  ::reset(arg);
  if(!arg) {
    set_name("orc");
    set_alias("dirty crap");
    set_race("orc");
    set_size(3);
    set_al(-60);
    set_short("An orc");
    set_long("This is one of the great mass of orcs that swarm this world.\n");
    set_ac(0);
    set_aggressive(1);
    set_level(10+random(8)-3);
    MOVE(CLONE(MYAREA+"/weapons/bigknife"),TO);
    init_command("wield knife");
  }
}

