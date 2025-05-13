inherit "room/room";
#include "/players/meecham/def.h"
reset(arg)
{
  CLONE("guard","b_guard");
  if(!arg)
  {
    set_light(1);
    short_desc="Bridge";
    long_desc=
      "                  ***************************************** \n\
                  *                                       * \n\
                  *                 BRIDGE                * \n\
                  *                                       * \n\
                  ***************************************** \n\
You are at the beginning of a long bridge, stretching to the limits of your\n\
sight.  A huge chasm yawns below, too deep to see the bottom.  A slim path\n\
leads to the east and west, possibly wide enough to travel on.\n";
    items=({
      "bridge","The bridge is made of rope and multiple pieces of wood across\n\
the bottom to stand on.  As you look across the bridge, you see many of\n\
Coldrik's minions, some laborers, some guards, and some just looking for unwary\n\
adventurers to feast upon",
      "chasm","The chasm stretches below the bridge",
      "path","A small path leads east and west around the chasm",
    });
    dest_dir=({
      PM+"col_realm/bridge2","north",
      PM+"col_realm/entrance","south",
      PM+"colrealm/epath1","east",
      PM+"colrealm/wpath1","west",
    });
  }
}
 
init()
{
  ::init();
  add_action("north","north");
}

north()
{
  if(present("guard",TO))
    printf("The guard steps in your path.  However, after glancing over his\n\
shoulder at the atrocities that wait upon the bridge, he snickers at you\n\
and moves aside.\n");
  return 0;
}
