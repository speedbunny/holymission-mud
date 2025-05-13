
/* s5e2n.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "On a dark Shore";
        long_desc = BS(
                    SHOREDESC+" Far to the north you can see a small path "+
                    "winding itself towards big earthy hills.");
        items = ITEMDESC + 
                ({ "path","Far to the north you can see a small, light path",
                   "hills","A big hilland is far to the south"
                });
        dest_dir = ({
        _dir+"s4e2n","west",
        _dir+"s5e1n","south",
        });
        
      }
}

