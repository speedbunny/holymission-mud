inherit "obj/monster";
#include "/players/waldo/defs.h"

reset(arg) 
{

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
    set_aggressive(0); /*Non - attack */
    set_level(13+random(4)-2);
    MOVE(CLONE(MYAREA+"/weapons/sword"),TO);
    init_command("wield sword");
  }
}
init()
{
  ::init();
  AA("_down","down");
  }

_down()
{
  ME("The Ogre prevents you from going that way.\n");
  return 1;
  }

