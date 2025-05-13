
/* s13e2n.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "On the Shore of Mordor";
        long_desc = BS(
                    SHOREDESC+
                    "Far to the south you can see the outline of a "+
                    "big island.");
        items = ITEMDESC + 
                ({ 
                   "island","Far to the south you can see the outline\n"+
                            "of a big island",
                });
        dest_dir = ({
        _dir+"s13e3n","north",
        _dir+"s12e2n","west",
        _dir+"s14e3n","northeast",
        _dir+"s12e1n","southwest",
        });
        
      }
}

