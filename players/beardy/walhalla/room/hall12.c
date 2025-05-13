inherit"room/room";
#include "../walhalla.h"

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(0);
    short_desc="Hall of Justice",
    long_desc="The area goes darker and darker. This place is much\n" +
              "frightening than the one before. Hope you have got lots\n" +
              "of good weaponary and food with you.\n";
    
    property =({"no_teleport"});

    dest_dir =({ROOM + "hall11","northeast",
                ROOM + "pris1","south"});

    smell = "Nothing special";
  }
}
